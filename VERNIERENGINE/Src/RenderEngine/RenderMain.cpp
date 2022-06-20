// ENGINE.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include "RenderMain.h"
#include "WindowRender.h"
#include <OgreRoot.h>

RenderMain* RenderMain::_instance = nullptr;
RenderMain* RenderMain::setUpInstance(const std::string& appName)
{
	assert(_instance == nullptr);
	_instance = new RenderMain(appName);
	return _instance;
}

RenderMain* RenderMain::getInstance()
{
	assert(_instance != nullptr);
	return _instance;
}

bool RenderMain::init(const std::string& name)
{
	WindowRender::instance()->setUpOgreRoot(name);
	return true;
}

WindowRender* RenderMain::GetWindowRender()
{
	return WindowRender::instance();
}

Ogre::Root* RenderMain::getRoot()
{
	if (_root == nullptr)
	{
#ifdef _DEBUG
		_root = new Ogre::Root();
#else
		_root = new Ogre::Root();

#endif // _DEBUG
	}
	return _root;
}

Ogre::SceneManager* RenderMain::getSceneManager()
{
	if (_mSceneManager == nullptr) {
		_mSceneManager = _root->createSceneManager();
	}
	return _mSceneManager;
}

Ogre::RenderWindow* RenderMain::getRenderWindow()
{
	return WindowRender::instance()->getRenderWindow();
}

void RenderMain::updateWindow()
{
	WindowRender::instance()->updateWindow();
}


Ogre::SceneNode* RenderMain::addSceneNode(std::string name, Ogre::SceneNode* parent)
{
	if (!parent)
		return _mSceneManager->getRootSceneNode()->createChildSceneNode(name);
	else
		return parent->createChildSceneNode(name);
}

Ogre::SceneNode* RenderMain::getSceneNodeByName(std::string name)
{
	return _mSceneManager->getSceneNode(name);
}
//--------------------------------PROVISIONAL-------------------------------
bool RenderMain::pollEvents() {
	return WindowRender::instance()->ExitWindow();
}







void RenderMain::deleteInstance()
{
	delete _instance;
}
RenderMain::~RenderMain()
{
	//_instance, al ser un unique pointer se borra solo
	//delete _root; //_root lo tiene que borrar WindowRender que es el que lo crea
	//delete _mSceneManager; //Se borra desde WindowRender
	_mSceneManager->destroyAllMovableObjects();
	//delete WindowRender::instance();
	WindowRender::instance()->~WindowRender();
	//delete _windowRender;
}
