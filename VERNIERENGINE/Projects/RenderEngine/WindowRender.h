#pragma once
#include <string>
namespace Ogre {
	class Root;
	class SceneManager;
	class SceneNode;
	class RenderWindow;
	class FileSystemLayer;
	class Light;
	enum LightTypes;
}
class SDL_Window;
class WindowRender
{

private:
	Ogre::Root* _root = nullptr;
	Ogre::SceneManager* _mSceneManager = nullptr;
	Ogre::RenderWindow* _rWindow = nullptr;
	SDL_Window* _sDLWindow = nullptr;
	std::string _wName = "motorcito";
	int screen_width_ = 1920;
	int screen_height_ = 1080;
	void setUpOgreRoot();
	void setUpWindow();
protected:
public:
	WindowRender(std::string name);
	~WindowRender();
	void closeWindow();
	void setUpInstance(std::string name);

#pragma region Getters
	Ogre::Root* getRoot() { return _root; }
	Ogre::SceneManager* getSceneManager() { return _mSceneManager; }
	Ogre::RenderWindow* getRenderWindow() { return _rWindow; }
	SDL_Window* getSDLWindow() { return _sDLWindow; }
	//getInstance
#pragma endregion

};

