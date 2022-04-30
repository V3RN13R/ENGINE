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
#include "Monkey.h"
#include <Windows.h>
#include "UIManager.h"
#include "InputManager.h"
#include "Scene.h"
#include "GameStateMachine.h"
#include "InitFactories.h"
#include "LoadImages.h"
#include "SoundManager.h"
#include "UIManager.h"

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
	_ogre->init();

	FactoryManager::setUpInstance();
	setupFactories();

	////Resources
	readAssetsPath();
	ResourceManager::init(_assetsPath);
	ResourceManager::getInstance()->setUp(); //Carga de recursos


	UIManager::setUpInstance();
	UIManager::getInstance()->initOverlaySystem();
	UIManager::getInstance()->createPanel();

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
	_soundManager->playSound("main theme.mp3", 1.0f);

	GameStateMachine::instance()->initScene(sceneFile, scene);
	
	LoadImages::instance()->init();
	
	//Entity* light = _mngr->addEntity("Light");
	//Light* l = light->addComponent<Light>();
	//Transform* tLight = light->addComponent<Transform>();
	//l->setDiffuseColor(Vector3D(1, 0, 0));
	////l->start();
	//tLight->setPosition({ 0, 500, 10 });

	//Camera* camera = new Camera("Camera");
	//Transform* trCam = camera->addComponent<Transform>();
	//camera->start();
	//t->setPosition({ 0, 500, 10 });
	//camera->setBckgColor({ 0,0.5f,0.5f });
	//GameStateMachine::instance()->getScene()->addEntity(camera);
	//camera->addListener(camera);
	
	// Accedemos a la ventana y creamos el renderer.
	// SDL_Window* _sdlw = WindowRender::getSDLWindow();
	//_renderer = SDL_CreateRenderer(_sdlw, -1,
	//	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//assert(_renderer != nullptr);

	//Entity* ent = _mngr->addEntity("Prueba");
	//MeshRenderer* mr = ent->addComponent<MeshRenderer>(ent);
	//Rigidbody* rb = ent->addComponent<Rigidbody>(ent);
	//tr = ent->addComponent<Transform>();
	//tr->setPosition(Vector3D(0, 400, 10));
	//rb->addSphereRigidbody(1, 50, { 0,400,10 });//falta obtener radio mediante la mesh
	//mr->start("Sphere");
	//mr->onEnable();

	//Monkey* mnk = new Monkey("MONKEY");
	////MeshRenderer* mrMnk = mnk->addComponent<MeshRenderer>(mnk);
	//Rigidbody* rbMnk = mnk->addComponent<Rigidbody>(mnk);
	//Transform* trMnk = mnk->addComponent<Transform>();
	//trMnk->setPosition(Vector3D(0, 300, 10));
	//trMnk->setScale(Vector3D(100, 100, 100));
	//rbMnk->addSphereRigidbody(1, 50, { 0,300,10 });//falta obtener radio mediante la mesh
	////mrMnk->start("Sphere");
	////mrMnk->onEnable();
	//_mngr->addEntity(mnk);
	//mnk->addListener(mnk);
	//mnk->setCamTrOnMonkey(trCam);
	
	//tr1->setRotation(Vector3D(270, 0, 0));


	//Entity* ent2 = _mngr->addEntity("Prueba2");
	//MeshRenderer* mr2 = ent2->addComponent<MeshRenderer>(ent2);
	//tr2 = ent2->addComponent<Transform>();
	////Rigidbody* rb2 = ent2->addComponent<Rigidbody>(ent2);
	//tr2->setPosition(Vector3D(0, -2, 0));
	//rb2->addBoxRigidbody(0, { 0,-2,0 }, { 1000,10,1000 });//falta obtener size mediante la mesh
	//mr2->start("plano","Plane");
	//mr2->onEnable();
	//tr2->rotate(-90, 0);

	//Entity* eprueba = _mngr->addEntity("Cubop");
	//Transform* tprueba = ent2->addComponent<transo>();
	//MeshRenderer* mprueba = ent2->addComponent<MeshRenderer>();

	//MeshRenderer* mr1 = mnk->addComponent<MeshRenderer>();
	//mr1->start("mono", "piedra.mesh");
	//mr1->setMaterial("Material/piedra");
	//mr1->onEnable();

	////Hay qeu decirle ala cámar la posición de monke para que le siga
	//camera->setMonkePos(&trMnk->getPos());

	//UIManager::init();
	//UIManager::instance()->setup(RenderMain::getInstance()->getRenderWindow());
}

bool VernierEngine::processFrame()
{
	//std::cout << "updating...\n";
	if (/*_ogre->pollEvents()*/  InputManager::instance()->keyPressed()) {
		//InputManager::getInstance()->Update();
		//PhysicsManager::getInstance()->Update();

		_physics->stepPhysics();
		_soundManager->update();
		GameStateMachine::instance()->fixedUpdate();
		GameStateMachine::instance()->update();
		GameStateMachine::instance()->lateUpdate();
		GameStateMachine::instance()->lastUpdate();

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
		typedef int (*funcFirstTry) ();
		lua_getglobal(L, "FunctionName");
		lua_call(L, 0, 1);
		funcFirstTry ftry = (funcFirstTry)GetProcAddress(hDLL, lua_tostring(L, -1));
		lua_pop(L, 1);
		if (!ftry) {
			std::cout << "ERROR\n";
		}
		else
			ftry();
		FreeLibrary(hDLL);
	}
	lua_getglobal(L, "WindowName");
	lua_call(L, 0, 1);
	bool stay = true;
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
	VernierEngine::setupInstance(appName,sceneFile,scene);
	lua_close(L);
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
		_instance = new VernierEngine(appName,sceneFile,scene);
		return true;
	}
	return false;
}