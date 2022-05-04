#include "GameStateMachine.h"
#include "Scene.h"
#include "InputManager.h"
#include "SDL.h"
#include "../UIManager/UIManager.h"
//#include "checkML.h"

GameStateMachine* GameStateMachine::_instance = nullptr;

GameStateMachine::GameStateMachine() {}

void GameStateMachine::initScene(const std::string& sceneFile, const std::string& scene) {
	_sceneStack.push((new Scene(sceneFile, scene, _instance)));
	InputManager::getInstance()->setListenersVector(_sceneStack.top()->getListeners());
	_sceneStack.top()->start();
	_sceneStack.top()->showUI();
	//UIManager::getInstance()->start();
	_sceneStack.top()->onEnable();
}

GameStateMachine* GameStateMachine::getInstance()
{
	return _instance;
}

bool GameStateMachine::setUpInstance()
{
	if (_instance == nullptr) {
		try {
			_instance = new GameStateMachine();
		}
		catch (...) {
			return false;
		}
	}

	return true;
}

void GameStateMachine::deleteInstance()
{
	delete _instance;
}

void GameStateMachine::clearScenes() {
	while (!_sceneStack.empty()) {
		delete _sceneStack.top();
		_sceneStack.pop();
	}
}

void GameStateMachine::popScene() {
	_pop = true;
}


void GameStateMachine::changeScene(std::string file, std::string name, bool push) {
	//UIManager::getInstance()->clearOverlay();
	if (_sceneStack.empty()) {
		Scene* scene = new Scene(file, name, _instance);
		_sceneStack.push(scene);
		InputManager::getInstance()->setListenersVector(_sceneStack.top()->getListeners());
		scene->start();
		scene->onEnable(); //comprobar que funciona bien
	}
	else {
		if (!push) {
			_load = true;
		}
		else {
			_push = true;
		}
		_name = name;
		_file = file;
	}
}

void GameStateMachine::fixedUpdate() {
	if (!_sceneStack.empty())
		_sceneStack.top()->fixedUpdate();
}

void GameStateMachine::update() {
	if (!_sceneStack.empty())
		_sceneStack.top()->update();
}

void GameStateMachine::lateUpdate()
{
	if (!_sceneStack.empty())
		_sceneStack.top()->lateUpdate();
}

Scene* GameStateMachine::getScene() { return _sceneStack.top(); }

bool GameStateMachine::lastUpdate()
{
	if (!_sceneStack.empty()) {
		_sceneStack.top()->clearEntities();
		if (_pop) {
			_sceneStack.top()->hideUI();
			delete _sceneStack.top();
			_sceneStack.pop();
			if (_sceneStack.empty())
				return false;
			getScene()->setSceneActive(true);
			_sceneStack.top()->showUI();
			//_sceneStack.top()->onEnable();
			InputManager::getInstance()->setListenersVector(_sceneStack.top()->getListeners());
			_pop = false;
			//UIManager::getInstance()->clearOverlay();
		}
		else if (_load || _push) {
			if (_load)
				clearScenes();
			_sceneStack.top()->hideUI();
			//_sceneStack.top()->onDisable();

			//UIManager::getInstance()->clearOverlay();
			getScene()->setSceneActive(false);

			Scene* scene = new Scene(_file, _name, _instance);
			_sceneStack.push(scene);
			InputManager::getInstance()->setListenersVector(_sceneStack.top()->getListeners());
			scene->start();
			scene->onEnable();
			//UIManager::getInstance()->start();
			_sceneStack.top()->showUI();
			_load = false;
			_push = false;
		}
		return true;
	}
	return false;
}

GameStateMachine::~GameStateMachine() {
	clearScenes();
}