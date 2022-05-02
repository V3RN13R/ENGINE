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
class FactoryManager;
class UIManager;

class GameStateMachine;

class VernierEngine {
public:
	void startGame(int (*a)());
	static VernierEngine* getInstance() { return _instance; }
	//static bool setupInstance(const std::string& appName, const std::string& sceneFile, const std::string& scene);
	static VernierEngine* setupInstance(const std::string& appName, const std::string& sceneFile, const std::string& scene);
	void startScene(const std::string& sceneFile, const std::string& scene);
	VernierEngine(const std::string& appName, const std::string& sceneFile, const std::string& value);
	RenderMain* getRenderMain();
	FactoryManager* getFactoryMng();
	SoundManager* getSoundMng();
	ResourceManager* getResourceMng();
	InputManager* getInputMng();
	PhysicsManager* getPhysicsMng();
	UIManager* getUIMng();
	GameStateMachine* getGSM();
	bool processFrame();

	//bool CheckLua(lua_State* L, int r);
	//int initialiseDLLs();

	~VernierEngine();
private:
	void readAssetsPath();
	static VernierEngine* _instance;
	std::string _appName;


	RenderMain* _ogre = nullptr;
	PhysicsManager* _physics = nullptr;
	SoundManager* _soundManager = nullptr;
	GameStateMachine* _gSM = nullptr;
	InputManager* _input = nullptr;
	Transform* tr = nullptr;
	Transform* tr2 = nullptr;

	//SDL_Renderer* _renderer = nullptr;
	std::string _assetsPath = "";

	//HMODULE game;
	//Scene* _scene;
};