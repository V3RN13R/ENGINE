#include "Entity.h"
#include "RenderMain.h"
#include <Ogre.h>
#include <SDL.h>
//#include "Manager.h"

std::vector<Entity*> Entity::_listeners = std::vector<Entity*>(0, nullptr);


Entity::Entity(std::string entityName) : _active(true), //
	//_mngr(mngr), //
	_cmpArray(), //
	_groups(), //
_entityName(entityName)
{
	_oNode = RenderMain::getInstance()->addSceneNode(entityName);
}

Entity::~Entity() {
	for (auto c : _components) {

		delete c;
	}
	//RenderMain::getInstance()->getSceneManager()->destroyAllMovableObjects(_oNode);
	_oNode->removeAndDestroyAllChildren();
	RenderMain::getInstance()->getSceneManager()->destroySceneNode(_oNode);
}

void Entity::start()
{
	if (_active && !_destroy)
		for (Component* c : _components)
			if (c->isEnable())
				c->start();
};