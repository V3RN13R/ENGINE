#pragma once

#include <string>
#include <memory>
#define SDL_MAIN_HANDLED


//class SDL_Renderer;
class RenderMain;
class PhysicsManager;
class WindowRender;
class SDL_Window;
class Manager;
class Transform;
class ResourceManager;
class InputManager;


class Scene;

class VernierEngine {
public:

	static VernierEngine* getInstance() { return _instance; }
	static bool setupInstance(const std::string& appName);

	VernierEngine(const std::string& appName);

	bool processFrame();
	//bool CheckLua(lua_State* L, int r);
	
	~VernierEngine();
private:
	void readAssetsPath();
	static VernierEngine* _instance;
	std::string _appName;

	InputManager* _IM = nullptr;

	RenderMain* _ogre = nullptr;
	PhysicsManager* _physics = nullptr;
	std::unique_ptr<Scene> _scene;
	Transform* tr = nullptr;
	Transform* tr2 = nullptr;

	//SDL_Renderer* _renderer = nullptr;
	std::string _assetsPath = "";

	//Scene* _scene;
};