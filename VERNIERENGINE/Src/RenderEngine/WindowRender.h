#pragma once
#include <memory>
#include <string>
#include "../Common/Singleton.h"

class SDL_Renderer;

namespace Ogre {
	class Root;
	class SceneManager;
	class SceneNode;
	class RenderWindow;
	class FileSystemLayer;
	class Light;
	enum LightTypes;
}
class InputManager;
class SDL_Window;
class WindowRender : public Singleton<WindowRender>
{
	friend Singleton<WindowRender>;
private:

	Ogre::Root* _root = nullptr;
	Ogre::SceneManager* _mSceneManager = nullptr;
	Ogre::RenderWindow* _rWindow = nullptr;
	SDL_Window* _sDLWindow = nullptr;
	InputManager* _iM = nullptr;
	int screen_width_ = 840;
	int screen_height_ = 600;
	void setUpWindow(const std::string& name);
	SDL_Renderer* _renderer;
	std::string _name;

protected:
public:
	WindowRender() {}
	~WindowRender();
	void closeWindow();
	bool setUpInstance(std::string name);
	bool ExitWindow();
	Ogre::Light* createLight(Ogre::LightTypes type = (Ogre::LightTypes)0);
	void setAmbientLight(float x, float y, float z);
#pragma region Getters
	Ogre::Root* getRoot() { return _root; }
	Ogre::SceneManager* getSceneManager() { return _mSceneManager; }
	Ogre::RenderWindow* getRenderWindow() { return _rWindow; }
	SDL_Window* getSDLWindow() { return _sDLWindow; }
	int getScreenWidth() { return screen_width_; };
	int getScreenHeight() { return screen_height_; };
	static WindowRender* getInstance();
	void updateWindow();
	void setUpOgreRoot(const std::string& name);
#pragma endregion

};