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
//#include "checkML.h"
//LUA
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <SDL_render.h>
#include "checkML.h"
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
		VernierEngine::setupInstance(appName, sceneFile, scene);//lamar desde la dll
		typedef int (*funcFirstTry) ();
		lua_getglobal(L, "FunctionName");
		lua_call(L, 0, 1);
		funcFirstTry ftry = (funcFirstTry)GetProcAddress(hDLL, lua_tostring(L, -1));
		if (ftry == nullptr)
		{
			std::cout << "No se ha abierto la DLL correctamente\n";
			return 0;
		}
		std::cout << "Se ha leido la DLL\n";
		lua_pop(L, 1);
		lua_close(L);
		VernierEngine::setupInstance("WILDLESS", sceneFile, scene);
		/*if (!ftry) {
			std::cout << "ERROR\n";
		}
		else
			ftry();*/
		VernierEngine::getInstance()->startScene(sceneFile, scene);
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