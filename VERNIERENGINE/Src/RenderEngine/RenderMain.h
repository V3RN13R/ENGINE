#pragma once
#ifndef _RENDERENGINE_RENDERENGINE_H
#define _RENDERENGINE_RENDERENGINE_H

#include <memory>
#include <string>
namespace Ogre {
	class Root;
	class SceneManager;
}
class WindowRender;
class RenderMain {

public:
	RenderMain(const std::string& appName) { _appName = appName; }
	static RenderMain* setUpInstance(const std::string& appName);
	static RenderMain* getInstance();
	bool init();
	WindowRender* GetWindowRender();
	Ogre::Root* getRoot();
	Ogre::SceneManager* getSceneManager();
	bool updateWindow();
private:
	std::string _appName;
	Ogre::Root* _root = nullptr;
	Ogre::SceneManager* _mSceneManager = nullptr;
	static std::unique_ptr<RenderMain> _instance;
	WindowRender* _windowRender;
};
#endif