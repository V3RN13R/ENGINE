#pragma once
#ifndef _RENDERENGINE_RENDERENGINE_H
#define _RENDERENGINE_RENDERENGINE_H

#include <memory>
#include <string>
#include "Ogre.h"
#include "Vector3D.h"

namespace Ogre {
	class Root;
	class SceneManager;
	class SceneNode;
	class RenderWindow;
}
class WindowRender;
class RenderMain {

public:
	RenderMain(const std::string& appName) { _appName = appName; }
	~RenderMain();

	static RenderMain* setUpInstance(const std::string& appName);
	static RenderMain* getInstance();
	static void deleteInstance();

	bool init(const std::string& name);
	WindowRender* GetWindowRender();
	Ogre::Root* getRoot();
	Ogre::SceneManager* getSceneManager();
	Ogre::RenderWindow* getRenderWindow();
	void updateWindow();
	Ogre::SceneNode* addSceneNode(std::string name, Ogre::SceneNode* parent = nullptr);
	Ogre::SceneNode* getSceneNodeByName(std::string name);
	bool pollEvents();
	static Ogre::Vector3 toOgre(Vector3D v) {
		return Ogre::Vector3(v.getX(), v.getY(), v.getZ());
	}
private:
	std::string _appName;
	Ogre::Root* _root = nullptr;
	Ogre::SceneManager* _mSceneManager = nullptr;
	static RenderMain* _instance;
	WindowRender* _windowRender;
};
#endif