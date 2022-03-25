// ENGINE.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include "RenderMain.h"
#include "WindowRender.h"
#include <OgreRoot.h>
std::unique_ptr<RenderMain>  RenderMain::_instance;

RenderMain* RenderMain::setUpInstance(const std::string& appName)
{
	assert(_instance.get() == nullptr);
	_instance.reset(new RenderMain(appName));
	return _instance.get();
}

RenderMain* RenderMain::getInstance()
{
	assert(_instance.get() != nullptr);
	return _instance.get();
}

bool RenderMain::init()
{
	_windowRender = new WindowRender(_appName);
	Ogre::Entity* ogreEnt_ = _windowRender->getSceneManager()->createEntity(Ogre::SceneManager::PrefabType::PT_SPHERE);
	return true;
}

WindowRender* RenderMain::GetWindowRender()
{
	return _windowRender;
}

Ogre::Root* RenderMain::getRoot()
{
	if (_root == nullptr)
	{
#ifdef _DEBUG
		_root = new Ogre::Root(/*"plugins_d.cfg"*/);
#else
		_root = new Ogre::Root();

#endif // _DEBUG
	}
	return _root;
}

Ogre::SceneManager* RenderMain::getSceneManager()
{
	if (_mSceneManager == nullptr) {
		_mSceneManager=_root->createSceneManager();
	}
	return _mSceneManager;
}

Ogre::RenderWindow* RenderMain::getRenderWindow()
{
	return _windowRender->getRenderWindow();
}

void RenderMain::updateWindow()
{
	_windowRender->updateWindow();
}


Ogre::SceneNode* RenderMain::addSceneNode(std::string name, Ogre::SceneNode* parent)
{
	if(!parent)
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
	return _windowRender->ExitWindow();
}





void RenderMain::clean()
{
	delete _instance.get();
	_instance.release();
}
RenderMain::~RenderMain()
{
	//_instance, al ser un unique pointer se borra solo
	//delete _root; //_root lo tiene que borrar WindowRender que es el que lo crea
	//delete _mSceneManager; //Se borra desde WindowRender
	delete _windowRender;
}


