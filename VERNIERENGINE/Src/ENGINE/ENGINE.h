#pragma once

#include <string>
#include <memory>

class RenderMain;
class PhysicsManager;
class WindowRender;
class SDL_Window;
class Manager;
class Transform;

class VernierEngine {
public:
	static VernierEngine* getInstance() { return _instance; }
	static bool setupInstance(const std::string& appName);

	VernierEngine(const std::string& appName);

	bool processFrame();
	//bool CheckLua(lua_State* L, int r);
	
	~VernierEngine();
private:
	static VernierEngine* _instance;
	std::string _appName;

	RenderMain* _ogre;
	PhysicsManager* _physics;
	std::unique_ptr<Manager> _mngr;
	Transform* tr = nullptr;
	Transform* tr2 = nullptr;
};