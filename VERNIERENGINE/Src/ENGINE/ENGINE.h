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
class SoundManager;


class GameStateMachine;

class VernierEngine {
public:

	static VernierEngine* getInstance() { return _instance; }
	static bool setupInstance(const std::string& appName, const std::string& sceneFile, const std::string& scene);

	VernierEngine(const std::string& appName, const std::string& sceneFile, const std::string& value);

	bool processFrame();
	//bool CheckLua(lua_State* L, int r);
	
	~VernierEngine();
private:
	void readAssetsPath();
	static VernierEngine* _instance;
	std::string _appName;


	RenderMain* _ogre = nullptr;
	PhysicsManager* _physics = nullptr;
	SoundManager* _soundManager = nullptr;
	std::unique_ptr<GameStateMachine*> _gsm;
	Transform* tr = nullptr;
	Transform* tr2 = nullptr;

	//SDL_Renderer* _renderer = nullptr;
	std::string _assetsPath = "";

	//Scene* _scene;
};