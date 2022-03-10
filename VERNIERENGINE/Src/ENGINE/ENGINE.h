#pragma once

#include <string>

class RenderMain;
class PhysicsManager;
class WindowRender;
class SDL_Window;

class VernierEngine {
public:
	static VernierEngine* getInstance() { return _instance; }
	static bool setupInstance(const std::string& appName);

	VernierEngine(const std::string& appName);

	void processFrame();
	bool updateWindow();
	
	~VernierEngine();
private:
	static VernierEngine* _instance;
	std::string _appName;

	RenderMain* _ogre;
	PhysicsManager* _physics;
	WindowRender* _windowRender;
	SDL_Window* _sDLWindow;
};