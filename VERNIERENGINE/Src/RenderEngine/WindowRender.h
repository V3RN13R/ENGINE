#pragma once
#include <memory>
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
	static std::unique_ptr<WindowRender> _instance;

	Ogre::Root* _root = nullptr;
	Ogre::SceneManager* _mSceneManager = nullptr;
	Ogre::RenderWindow* _rWindow = nullptr;
	SDL_Window* _sDLWindow = nullptr;
	std::string _wName = "motorcito";
	int screen_width_ = 840;
	int screen_height_ = 600;
	void setUpOgreRoot();
	void setUpWindow();
protected:
public:
	WindowRender(std::string name);
	~WindowRender();
	void BORRAR();
	void closeWindow();
	bool setUpInstance(std::string name);

#pragma region Getters
	Ogre::Root* getRoot() { return _root; }
	Ogre::SceneManager* getSceneManager() { return _mSceneManager; }
	Ogre::RenderWindow* getRenderWindow() { return _rWindow; }
	SDL_Window* getSDLWindow() { return _sDLWindow; }
	int getScreenWidth() { return screen_width_; };
	int getScreenHeight() { return screen_height_; };
	static WindowRender* getInstance();
#pragma endregion

};