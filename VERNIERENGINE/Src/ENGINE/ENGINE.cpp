// ENGINE.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include "OgreRoot.h"
#include <iostream>
#include <cstdlib>

#include "ENGINE.h"
#include "RenderMain.h"
#include "PhysicsManager.h"
#include "PruebaBullet.h"
#include "FactoryManager.h"
#include "../../Src/Common/Transform.h"
#include "../../Src/Common/Manager.h"
#include "../../Src/Common/MeshRenderer.h"
//#include <SDL.h>

VernierEngine* VernierEngine::_instance = nullptr;

VernierEngine::VernierEngine(const std::string& appName) : _appName(appName) {
	// Render Manager
	if (!RenderMain::setUpInstance(_appName)) {
		throw std::exception("ERROR: Couldn't load RenderMain\n");
	}
	_ogre = RenderMain::getInstance();
	_ogre->init();

	_mngr.reset(new Manager());

	FactoryManager::setUpInstance();
	 //Physics
	if (!PhysicsManager::setUpInstance()) {
		throw std::exception("ERROR: Couldn't load PhysicsManager\n");
	}
	_physics = PhysicsManager::getInstance();

	PruebaBullet::mainPhys();

	Entity* ent = _mngr->addEntity("Prueba");
	MeshRenderer* mr = ent->addComponent<MeshRenderer>(ent);
	mr->start("Sphere");
	mr->onEnable();
	tr = ent->addComponent<Transform>();
	tr->setPosition(Vector3D(0,1,0));

	Entity* ent2 = _mngr->addEntity("Prueba2");
	MeshRenderer* mr2 = ent2->addComponent<MeshRenderer>(ent2);
	mr2->start("Plane");
	mr2->onEnable();
	tr2 = ent2->addComponent<Transform>();
	tr2->setPosition(Vector3D(0, -2, 0));
	tr2->rotate(-90, 0);
}

bool VernierEngine::processFrame()
{
	std::cout <<  "updating...\n";
	if (_ogre->pollEvents()) {
		//InputManager::getInstance()->Update();
		//PhysicsManager::getInstance()->Update();
		_mngr->update();
		tr->setPosition(Vector3D(tr->getPos().getX(), tr->getPos().getY() - 0.0001, tr->getPos().getZ()));
		tr2->rotate(0.01, 2);
		_ogre->updateWindow();
	}
	else return false;

}




VernierEngine::~VernierEngine()
{
	//_ogre->clean();
	//_physics->clean();
}


int main()
{
	bool stay = true;
	VernierEngine::setupInstance("WildLess");
	do {
		stay = VernierEngine::getInstance()->processFrame();
	} while (stay);
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