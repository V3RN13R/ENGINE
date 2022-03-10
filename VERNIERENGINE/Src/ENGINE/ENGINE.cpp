// ENGINE.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include "OgreRoot.h"
#include <iostream>
#include <cstdlib>

#include "ENGINE.h"
#include "RenderMain.h"
#include "PhysicsManager.h"
#include "PruebaBullet.h"
#include "FactoryManager.h"
//#include <SDL.h>

VernierEngine* VernierEngine::_instance = nullptr;

VernierEngine::VernierEngine(const std::string& appName) : _appName(appName) {
	// Render Manager
	if (!RenderMain::setUpInstance(_appName)) {
		throw std::exception("ERROR: Couldn't load RenderMain\n");
	}
	_ogre = RenderMain::getInstance();
	_ogre->init();

	FactoryManager::setUpInstance();

	//windowRender = _ogre->GetWindowRender();
	//_sDLWindow = windowRender->getSdlWindow();
	
	// Physics
	//if (!PhysicsManager::setUpInstance()) {
	//	throw std::exception("ERROR: Couldn't load PhysicsManager\n");
	//}
	//_physics = PhysicsManager::getInstance();

	PruebaBullet::mainPhys();
}

void VernierEngine::processFrame()
{
	std::cout <<  "updating...\n";

	//Bucle incipal del motor
	/*RenderMain::getInstance().update();
	PhysicsManager::getInstance().update();*/
}

bool VernierEngine::updateWindow()
{
	return _ogre->updateWindow();
}



VernierEngine::~VernierEngine()
{
	/*RenderMain::clean();
	PhysicsManager::clean();*/
}


int main()
{
	
	VernierEngine::setupInstance("WildLess");
	do {
	
	}while(VernierEngine::getInstance()->updateWindow());
    return 0;
}

bool VernierEngine::setupInstance(const std::string& appName)
{
	if (_instance == nullptr)
	{
		_instance = new VernierEngine(appName);
		return true;
	}
	return false;
}