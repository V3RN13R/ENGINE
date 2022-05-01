#include "GameStateMachine.h"
#include "Scene.h"
#include "SDL.h"
#include "../UIManager/UIManager.h"

void GameStateMachine::initScene(const std::string& sceneFile, const std::string& scene) {
	_sceneStack.push((new Scene(sceneFile, scene, instance())));
	InputManager::instance()->setListenersVector(_sceneStack.top()->getListeners());
	_sceneStack.top()->start();
	UIManager::getInstance()->start();
	_sceneStack.top()->onEnable();
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
	if (_sceneStack.empty()) {
		Scene* scene = new Scene(file, name, instance());
		_sceneStack.push(scene);
		InputManager::instance()->setListenersVector(_sceneStack.top()->getListeners());
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
			delete _sceneStack.top();
			_sceneStack.pop();
			if (_sceneStack.empty())
				return false;
			getScene()->setSceneActive(true);
			_sceneStack.top()->onEnable();
			InputManager::instance()->setListenersVector(_sceneStack.top()->getListeners());
			_pop = false;
		}
		else if(_load || _push) {
			if (_load)
				clearScenes();
			_sceneStack.top()->onDisable();
			Scene* scene = new Scene(_file, _name, instance());
			_sceneStack.push(scene);
			InputManager::instance()->setListenersVector(_sceneStack.top()->getListeners());
			scene->start();
			scene->onEnable();
			_load = false;
			_push = false;
		}
		return true;
	}
	return false;
}