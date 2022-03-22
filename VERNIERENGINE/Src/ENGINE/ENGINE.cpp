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

//LUA
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

//#ifdef _WIN32
#pragma comment(lib, "liblua53.a")
//#endif

//#include <SDL.h>

VernierEngine* VernierEngine::_instance = nullptr;

VernierEngine::VernierEngine(const std::string& appName) : _appName(appName) {
	// Render Manager
	if (!RenderMain::setUpInstance(_appName)) {
		throw std::exception("ERROR: Couldn't load RenderMain\n");
	}
	_ogre = RenderMain::getInstance();
	_ogre->init();

	_mngr.reset(new Manager());

	FactoryManager::setUpInstance();
	//Physics
	if (!PhysicsManager::setUpInstance()) {
		throw std::exception("ERROR: Couldn't load PhysicsManager\n");
	}
	_physics = PhysicsManager::getInstance();

	PruebaBullet::mainPhys();
	Entity* camera = _mngr->addEntity("Camera");
	Camera* c = camera->addComponent<Camera>();
	Transform* t = camera->addComponent<Transform>();
	c->start();
	t->setPosition({ 0, 500, 10 });
	c->setBckgColor({ 1,0,0 });
	Entity* ent = _mngr->addEntity("Prueba");
	MeshRenderer* mr = ent->addComponent<MeshRenderer>(ent);
	Rigidbody* rb = ent->addComponent<Rigidbody>(ent);
	tr = ent->addComponent<Transform>();
	tr->setPosition(Vector3D(0, 400, 10));
	rb->addSphereRigidbody(1, 50, { 0,400,10 });//falta obtener radio mediante la mesh
	mr->start("Sphere");
	mr->onEnable();

	Entity* ent2 = _mngr->addEntity("Prueba2");
	MeshRenderer* mr2 = ent2->addComponent<MeshRenderer>(ent2);
	tr2 = ent2->addComponent<Transform>();
	Rigidbody* rb2 = ent2->addComponent<Rigidbody>(ent2);
	tr2->setPosition(Vector3D(0, -2, 0));
	rb2->addBoxRigidbody(0, { 0,-2,0 }, { 1000,10,1000 });//falta obtener size mediante la mesh
	mr2->start("Plane");
	mr2->onEnable();
	tr2->rotate(-90, 0);




}

bool VernierEngine::processFrame()
{
	std::cout << "updating...\n";
	if (_ogre->pollEvents()) {
		//InputManager::getInstance()->Update();
		//PhysicsManager::getInstance()->Update();
		_physics->stepPhysics();
		_mngr->fixedUpdate();
		_mngr->update();
		//tr->setPosition(Vector3D(tr->getPos().getX(), tr->getPos().getY() - 0.0001, tr->getPos().getZ()));
		tr2->rotate(0.01, 2);
		_ogre->updateWindow();
	}
	else return false;

}




VernierEngine::~VernierEngine()
{
	_ogre->clean();//borra el RenderMain
	_physics->clean();
	delete _instance;
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

	struct Player
	{
		std::string title;
		std::string name;
		std::string family;
		int level;
	} player;

	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	luaL_dofile(L, "Prueba.lua");

	// Stage 1: Just read simple variables
	std::cout << "[CPP] Stage 1 - Read Simple Variables" << std::endl;
	lua_getglobal(L, "a");
	if (lua_isnumber(L, -1)) std::cout << "[CPP S1] a = " << (int)lua_tointeger(L, -1) << std::endl;
	lua_getglobal(L, "b");
	if (lua_isnumber(L, -1)) std::cout << "[CPP S1] b = " << (int)lua_tointeger(L, -1) << std::endl;
	lua_getglobal(L, "c");
	if (lua_isnumber(L, -1)) std::cout << "[CPP S1] c = " << (int)lua_tointeger(L, -1) << std::endl;
	lua_getglobal(L, "d");
	if (lua_isstring(L, -1)) std::cout << "[CPP S1] d = " << lua_tostring(L, -1) << std::endl << std::endl;

	// Stage 2: Read Table Object
	std::cout << "[CPP] Stage 2 - Read Table (Key/Value pairs)" << std::endl;
	lua_getglobal(L, "player");
	if (lua_istable(L, -1))
	{
		lua_pushstring(L, "Name");
		lua_gettable(L, -2);
		player.name = lua_tostring(L, -1);
		lua_pop(L, 1);

		lua_pushstring(L, "Family");
		lua_gettable(L, -2);
		player.family = lua_tostring(L, -1);
		lua_pop(L, 1);

		lua_pushstring(L, "Title");
		lua_gettable(L, -2);
		player.title = lua_tostring(L, -1);
		lua_pop(L, 1);

		lua_pushstring(L, "Level");
		lua_gettable(L, -2);
		player.level = (int)lua_tointeger(L, -1);
		lua_pop(L, 1);
	}
	std::cout << "[CPP S2] " << player.title << " " << player.name << " of " << player.family << " [Lvl: " << player.level << "]" << std::endl << std::endl;

	// Stage 3: Call Lua Function
	std::cout << "[CPP] Stage 3 - Call Lua Function" << std::endl;
	lua_getglobal(L, "CalledFromCPP1");
	if (lua_isfunction(L, -1))
	{
		lua_pushnumber(L, 5.0f);
		lua_pushnumber(L, 6.0f);
		lua_pushstring(L, "Bwa ha ha!");
		std::cout << "[CPP S3] Calling 'CalledFromCPP1' in lua script" << std::endl;
	}

	// Stage 4: Call Lua Function, which calls C++ Function
	std::cout << "[CPP] Stage 4 - Call Lua Function, whcih in turn calls C++ Function" << std::endl;
	lua_getglobal(L, "CalledFromCPP2");
	if (lua_isfunction(L, -1))
	{
		lua_pushnumber(L, 5.0f);
		lua_pushnumber(L, 6.0f);
		std::cout << "[CPP S4] Calling 'CalledFromCPP2' in lua script" << std::endl;
	}

	lua_getglobal(L, "CreatePlane");

	bool stay = true;
	VernierEngine::setupInstance("WildLess");
	do {
		stay = VernierEngine::getInstance()->processFrame();
	} while (stay);


	//se acaba el programa
	std::cout << "Hola\n";
	return 0;
}

bool VernierEngine::setupInstance(const std::string& appName)
{
	if (_instance == nullptr)
	{
		_instance = new VernierEngine(appName);
		return true;
	}
	return false;
}