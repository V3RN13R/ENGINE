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
#include "Manager.h"
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
#include "InitFactories.cpp"



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

	
	//Physics
	if (!PhysicsManager::setUpInstance()) {
		throw std::exception("ERROR: Couldn't load PhysicsManager\n");
	}
	_physics = PhysicsManager::getInstance();

	PruebaBullet::mainPhys();

	_scene.reset(new Scene(sceneFile, scene));
	_scene->start();
	
	_scene->onEnable();


	_IM = new InputManager();
	_IM->setEntities(_scene->getEntities());
	//Entity* light = _mngr->addEntity("Light");
	//Light* l = light->addComponent<Light>();
	//Transform* tLight = light->addComponent<Transform>();
	//l->setDiffuseColor(Vector3D(1, 0, 0));
	////l->start();
	//tLight->setPosition({ 0, 500, 10 });

	Camera* camera = new Camera("Camera");
	//Transform* trCam = camera->addComponent<Transform>();
	camera->start();
	//t->setPosition({ 0, 500, 10 });
	camera->setBckgColor({ 1,0,0 });
	_scene->addEntity(camera);
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
	if (/*_ogre->pollEvents()*/  _IM->keyPressed()) {
		//InputManager::getInstance()->Update();
		//PhysicsManager::getInstance()->Update();

		_physics->stepPhysics();
		_scene->fixedUpdate();
		_scene->update();
		//tr->setPosition(Vector3D(tr->getPos().getX(), tr->getPos().getY() - 0.0001, tr->getPos().getZ()));
		//tr2->rotate(0.01, 2);
		_ogre->updateWindow();
	}
	else return false;

}


VernierEngine::~VernierEngine()
{


	delete _scene.get();
	_scene.release();

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

//bool VernierEngine::CheckLua(lua_State* L, int r)
//{
//	if (r != LUA_OK)
//	{
//		std::string errormsg = lua_tostring(L, -1);
//		std::cout << errormsg << std::endl;
//		return false;
//	}
//	return true;
//}

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//struct Player
	//{
	//	std::string title;
	//	std::string name;
	//	std::string family;
	//	int level;
	//} player;

	//lua_State* L = luaL_newstate();
	//luaL_openlibs(L);

	//luaL_dofile(L, "Prueba.lua");

	//// Stage 1: Just read simple variables
	//std::cout << "[CPP] Stage 1 - Read Simple Variables" << std::endl;
	//lua_getglobal(L, "a");
	//if (lua_isnumber(L, -1)) std::cout << "[CPP S1] a = " << (int)lua_tointeger(L, -1) << std::endl;
	//lua_getglobal(L, "b");
	//if (lua_isnumber(L, -1)) std::cout << "[CPP S1] b = " << (int)lua_tointeger(L, -1) << std::endl;
	//lua_getglobal(L, "c");
	//if (lua_isnumber(L, -1)) std::cout << "[CPP S1] c = " << (int)lua_tointeger(L, -1) << std::endl;
	//lua_getglobal(L, "d");
	//if (lua_isstring(L, -1)) std::cout << "[CPP S1] d = " << lua_tostring(L, -1) << std::endl << std::endl;

	//// Stage 2: Read Table Object
	//std::cout << "[CPP] Stage 2 - Read Table (Key/Value pairs)" << std::endl;
	//lua_getglobal(L, "player");
	//if (lua_istable(L, -1))
	//{
	//	lua_pushstring(L, "Name");
	//	lua_gettable(L, -2);
	//	player.name = lua_tostring(L, -1);
	//	lua_pop(L, 1);

	//	lua_pushstring(L, "Family");
	//	lua_gettable(L, -2);
	//	player.family = lua_tostring(L, -1);
	//	lua_pop(L, 1);

	//	lua_pushstring(L, "Title");
	//	lua_gettable(L, -2);
	//	player.title = lua_tostring(L, -1);
	//	lua_pop(L, 1);

	//	lua_pushstring(L, "Level");
	//	lua_gettable(L, -2);
	//	player.level = (int)lua_tointeger(L, -1);
	//	lua_pop(L, 1);
	//}
	//std::cout << "[CPP S2] " << player.title << " " << player.name << " of " << player.family << " [Lvl: " << player.level << "]" << std::endl << std::endl;

	//// Stage 3: Call Lua Function
	//std::cout << "[CPP] Stage 3 - Call Lua Function" << std::endl;
	//lua_getglobal(L, "CalledFromCPP1");
	//if (lua_isfunction(L, -1))
	//{
	//	lua_pushnumber(L, 5.0f);
	//	lua_pushnumber(L, 6.0f);
	//	lua_pushstring(L, "Bwa ha ha!");
	//	std::cout << "[CPP S3] Calling 'CalledFromCPP1' in lua script" << std::endl;
	//}

	//// Stage 4: Call Lua Function, which calls C++ Function
	//std::cout << "[CPP] Stage 4 - Call Lua Function, whcih in turn calls C++ Function" << std::endl;
	//lua_getglobal(L, "CalledFromCPP2");
	//if (lua_isfunction(L, -1))
	//{
	//	lua_pushnumber(L, 5.0f);
	//	lua_pushnumber(L, 6.0f);
	//	std::cout << "[CPP S4] Calling 'CalledFromCPP2' in lua script" << std::endl;
	//}

	//lua_getglobal(L, "CreatePlane");

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