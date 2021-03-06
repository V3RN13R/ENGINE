// ENGINE.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include "OgreRoot.h"
#include <iostream>
#include <cstdlib>


#include "ENGINE.h"
#include "RenderMain.h"
#include "PhysicsManager.h"
#include "PruebaBullet.h"
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

#include "SoundManager.h"
#include "UIManager.h"
#include "UIImage.h"

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
	_ogre = RenderMain::getInstance();
	_ogre->init(appName);

	FactoryManager::setUpInstance();
	setupFactories();

	////Resources
	readAssetsPath();
	ResourceManager::init(_assetsPath);
	ResourceManager::getInstance()->setUp(); //Carga de recursos


	UIManager::setUpInstance();
	UIManager::getInstance()->initOverlaySystem();

	//UIImage* image = new UIImage("imagen", "imagenp", "altavoz");

	//Physics
	if (!PhysicsManager::setUpInstance()) {
		throw std::exception("ERROR: Couldn't load PhysicsManager\n");
	}
	_physics = PhysicsManager::getInstance();

	PruebaBullet::mainPhys();

	//SoundManager
	//inicializa la intancia y llama al init() de Soundmanager
	SoundManager::setUpInstance();
	_soundManager = SoundManager::getInstance();
	//_soundManager->playSound("main theme.mp3", 1.0f);

}

bool VernierEngine::processFrame()
{
	//std::cout << "updating...\n";
	if (/*_ogre->pollEvents()*/  InputManager::instance()->pollEvents()) {
		//InputManager::getInstance()->Update();
		//PhysicsManager::getInstance()->Update();

		_physics->stepPhysics();
		_soundManager->update();
		GameStateMachine::instance()->fixedUpdate();
		GameStateMachine::instance()->update();
		GameStateMachine::instance()->lateUpdate();
		GameStateMachine::instance()->lastUpdate();
		//UIManager::getInstance()->start();

		//tr->setPosition(Vector3D(tr->getPos().getX(), tr->getPos().getY() - 0.0001, tr->getPos().getZ()));
		//tr2->rotate(0.01, 2);
		_ogre->updateWindow();
		// LoadImages::instance()->renderTexturas();
	}
	else return false;

}


VernierEngine::~VernierEngine()
{


	/*delete (*_gsm)->getScene();
	_gsm.release();*/

	PhysicsManager::deleteInstance();
	_physics = nullptr;
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

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	lua_State* L;

	// initialize Lua interpreter
	L = luaL_newstate();

	// load Lua base libraries (print / math / etc)
	luaL_openlibs(L);
	luaL_dofile(L, "Data.lua");
	lua_getglobal(L, "DLLName");
	lua_call(L, 0, 1);
	std::string dllName = lua_tostring(L, -1);
	dllName += ".dll";
	std::wstring dllNameW = std::wstring(dllName.begin(), dllName.end());
	HINSTANCE hDLL = LoadLibrary(dllNameW.c_str());
	lua_pop(L, 1);
	if (hDLL == NULL)
		std::cout << "Failed Load DLL\n";
	else {
		std::cout << "LoadDll\n";
		lua_getglobal(L, "WindowName");
		lua_call(L, 0, 1);
		const std::string appName = lua_tostring(L, -1);
		lua_pop(L, 1);
		lua_getglobal(L, "SceneFile");
		lua_call(L, 0, 1);
		const std::string sceneFile = lua_tostring(L, -1);
		lua_pop(L, 1);
		lua_getglobal(L, "SceneName");
		lua_call(L, 0, 1);
		const std::string scene = lua_tostring(L, -1);
		lua_pop(L, 1);
		VernierEngine::setupInstance(appName, sceneFile, scene);
		typedef int (*funcFirstTry) ();
		lua_getglobal(L, "FunctionName");
		lua_call(L, 0, 1);
		funcFirstTry ftry = (funcFirstTry)GetProcAddress(hDLL, lua_tostring(L, -1));
		lua_pop(L, 1);
		lua_close(L);
		if (!ftry) {
			std::cout << "ERROR\n";
		}
		else
			ftry();
	VernierEngine::getInstance()->startScene(sceneFile,scene);
		FreeLibrary(hDLL);
	}
	bool stay = true;
	do {
		stay = VernierEngine::getInstance()->processFrame();
	} while (stay);

	delete VernierEngine::getInstance();
	//se acaba el programa
	std::cout << "Hola\n";
	return 0;
}

bool VernierEngine::setupInstance(const std::string& appName, const std::string& sceneFile, const std::string& scene)
{
	if (_instance == nullptr)
	{
		_instance = new VernierEngine(appName, sceneFile, scene);
		return true;
	}
	return false;
}

void VernierEngine::startScene(const std::string& sceneFile, const std::string& scene)
{
	GameStateMachine::instance()->initScene(sceneFile, scene);
}
