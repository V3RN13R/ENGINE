
#include "OgreRoot.h"
#include <iostream>
#include <cstdlib>


#include "ENGINE.h"
#include "RenderMain.h"
#include "PhysicsManager.h"
#include "FactoryManager.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "MeshRenderer.h"
#include "Camera.h"
#include "Light.h"
#include "ResourceManager.h"
#include "Entity.h"
#include <Windows.h>
#include "UIManager.h"
#include "InputManager.h"
#include "Scene.h"
#include "GameStateMachine.h"
#include "InitFactories.h"
#include "Callbacks.h"
#include "SoundManager.h"
#include "UIManager.h"
#include "UIImage.h"
#include "VernierTime.h"

//LUA
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <SDL_render.h>
}

VernierEngine* VernierEngine::_instance = nullptr;

VernierEngine::VernierEngine(const std::string& appName, const std::string& sceneFile, const std::string& scene) : _appName(appName) {

	// Render Manager
	if (!RenderMain::setUpInstance(_appName)) {
		throw std::exception("ERROR: Couldn't load RenderMain\n");
	}
	_ogre = getRenderMain();
	_ogre->init(appName);

	FactoryManager::setUpInstance();
	setupFactories();

	SoundManager::setUpInstance();
	_soundManager = getSoundMng();
	////Resources
	readAssetsPath();
	ResourceManager::init(_assetsPath);
	getResourceMng()->setUp(); //Carga de recursos

	Callbacks::init();

	//Physics
	if (!PhysicsManager::setUpInstance()) {
		throw std::exception("ERROR: Couldn't load PhysicsManager\n");
	}
	_physics = getPhysicsMng();

	InputManager::setUpInstance();
	_input = InputManager::getInstance();

	GameStateMachine::setUpInstance();
	_gSM = GameStateMachine::getInstance();

	UIManager::setUpInstance();
	getUIMng()->initOverlaySystem();

	_vernierTime = new VernierTime();
}

VernierTime* VernierEngine::getTime()
{
	return _vernierTime;
}

RenderMain* VernierEngine::getRenderMain()
{
	return RenderMain::getInstance();
}

FactoryManager* VernierEngine::getFactoryMng()
{
	return FactoryManager::getInstance();
}

SoundManager* VernierEngine::getSoundMng()
{
	return SoundManager::getInstance();
}

ResourceManager* VernierEngine::getResourceMng()
{
	return ResourceManager::getInstance();
}

InputManager* VernierEngine::getInputMng()
{
	return InputManager::getInstance();
}

PhysicsManager* VernierEngine::getPhysicsMng()
{
	return PhysicsManager::getInstance();
}

UIManager* VernierEngine::getUIMng()
{
	return UIManager::getInstance();
}

GameStateMachine* VernierEngine::getGSM()
{
	return GameStateMachine::getInstance();
}

Callbacks* VernierEngine::getCbs() {
	return Callbacks::instance();
}

bool VernierEngine::processFrame(double dt)
{
	deltaTime = dt;
	if (getInputMng()->pollEvents()) {

		if (_vernierTime)_vernierTime->frameStarted();
		if (_physics)_physics->stepPhysics(dt);
		if (_soundManager)_soundManager->update();
		if (_gSM) {
			_gSM->firstUpdate();
			_gSM->update();
			_gSM->lateUpdate();
			_gSM->lastUpdate();
		}

		if (_ogre)_ogre->updateWindow();
		if (_input)InputManager::getInstance()->resetMousePosRel();

	}
	else return false;

}


void VernierEngine::startGame(int (*a)()) {
	a();
}
bool VernierEngine::update()
{
	double t = _vernierTime->getTime(); // Obtener el tiempo actual
	deltaTime = t - lastFrameTime;		// Resta entre el tiempo actual y el del último frame
	lastFrameTime = t;
	bool b = processFrame(deltaTime);
	return b;
}
VernierEngine::~VernierEngine()
{
	delete _vernierTime;
	InputManager::deleteInstance();
	_input = nullptr;

	GameStateMachine::deleteInstance();
	_gSM = nullptr;

	SoundManager::deleteInstance();
	_soundManager = nullptr;

	PhysicsManager::deleteInstance();
	_physics = nullptr;

	UIManager::deleteInstance();
	FactoryManager::deleteInstance();

	RenderMain::deleteInstance();//borra el RenderMain
	_ogre = nullptr;

}

void VernierEngine::readAssetsPath()
{
	std::ifstream file;
	try
	{
		file.open("AssetsPath.txt"); //Ver que contiene la ruta correcta desde el juego
		std::getline(file, _assetsPath);
		file.close();
	}
	catch (std::exception e)
	{
		std::cout << "ERROR: no se ha podido abrir el archivo que contiene la ruta de los assets\n";
	}
}

VernierEngine* VernierEngine::setupInstance(const std::string& appName, const std::string& sceneFile, const std::string& scene)
{
	if (_instance == nullptr)
	{
		_instance = new VernierEngine(appName, sceneFile, scene);

	}
	return _instance;
}

void VernierEngine::startScene(const std::string& sceneFile, const std::string& scene)
{
	_gSM->initScene(sceneFile, scene);
}
