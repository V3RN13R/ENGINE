#include "Entity.h"
#include "RenderMain.h"
#include <Ogre.h>
#include <SDL.h>
#include "Vector3D.h"
#include <ENGINE.h>

//std::vector<Entity*> Entity::_listeners = std::vector<Entity*>(0, nullptr);


Entity::Entity(std::string entityName, Scene* scene) : _active(true), //
_cmpArray(), //
_groups(), //
_entityName(entityName), //
_scene(scene)
{
	//_entities.emplace_back(this);
	_oNode = VernierEngine::getInstance()->getRenderMain()->addSceneNode(entityName);
}

Entity::~Entity() {
	/*for (auto c : _components) {

		delete c;
	}*/
	for (int i = 1; i < _components.size(); i++) {
		delete _components[i];
		_components[i] = nullptr;
	}
	delete _components[0];
	_components.clear();
	_cmps.clear();


	//RenderMain::getInstance()->getSceneManager()->destroyAllMovableObjects(_oNode);
	_oNode->removeAndDestroyAllChildren();
	VernierEngine::getInstance()->getRenderMain()->getSceneManager()->destroySceneNode(_oNode);
}

void Entity::start()
{
	if (_active && !_destroy)
		for (Component* c : _components)
			if (c->isEnable()) {
				c->setEntity(this);
				c->start();
			}
};

void Entity::onEnable()
{
	if (_active && !_destroy)
		for (Component* c : _components)
			c->onEnable();
};

void Entity::onDisable()
{
	if (_active && !_destroy)
		for (Component* c : _components)
			c->onDisable();
};