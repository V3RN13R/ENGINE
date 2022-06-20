
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

#include "VernierTime.h"

//LUA
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <SDL_render.h>
#include "checkML.h"
}

#ifdef  _DEBUG
int main(int argc, char* argv[])
#else
#include <Windows.h>
int WINAPI
WinMain(HINSTANCE hinstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
#endif
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	lua_State* L;

	// initialize Lua interpreter
	L = luaL_newstate();

#ifdef _DEBUG
	char* c = new char[1000];
#endif 
	//Como hablamos el dia de la revision, esta linea deja basura sin el metodo (_CrtDumpMemoryLeaks())
	//Por lo que el checkML si dejaba basura y la eliminamos por completo, como hablamos el dia 20 hemos borrado
	//una gran cantidad de basura (13.500 aprox)

	// load Lua base libraries (print / math / etc)
	luaL_openlibs(L);
	luaL_dofile(L, "Data.lua");
	lua_getglobal(L, "DLLName");
	lua_call(L, 0, 1);
	std::string dllName = lua_tostring(L, -1);
#ifdef _DEBUG
	dllName += "_d.dll";
#else
	dllName += ".dll";
#endif // _DEBUG
	std::wstring dllNameW = std::wstring(dllName.begin(), dllName.end());
	HINSTANCE hDLL = LoadLibrary(dllNameW.c_str());
	lua_pop(L, 1);
	if (hDLL == NULL) {
		std::cout << "Failed Load " << dllName << "\n";
		lua_close(L);
	}
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
		typedef int (*funcFirstTry) ();
		lua_getglobal(L, "FunctionName");
		lua_call(L, 0, 1);
		funcFirstTry ftry = (funcFirstTry)GetProcAddress(hDLL, lua_tostring(L, -1));
		if (ftry == nullptr)
		{
			std::cout << "No se ha encontrado la funcion en la dll\n";
			return 0;
		}
		else {
			std::cout << "Cargando la funci�n e iniciando el motor\n";
			lua_pop(L, 1);
			lua_close(L);
			VernierEngine::setupInstance(appName, sceneFile, scene);
			ftry();
			VernierEngine::getInstance()->startScene(sceneFile, scene);
			bool stay = true;	

			do {
				stay = VernierEngine::getInstance()->update();
			} while (stay && VernierEngine::getInstance()->getPlay());

			delete VernierEngine::getInstance();
			FreeLibrary(hDLL);
		}

	}
	//_CrtDumpMemoryLeaks();
	//se acaba el programa
	std::cout << "Hola\n";
	return 0;
}