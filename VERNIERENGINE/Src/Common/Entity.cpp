#include "Entity.h"
#include "RenderMain.h"
#include <Ogre.h>
#include <SDL.h>
#include "Vector3D.h"
#include <ENGINE.h>


Entity::Entity(std::string entityName, Scene* scene) : _active(true), _entityName(entityName), _scene(scene)
{
	_oNode = VernierEngine::getInstance()->getRenderMain()->addSceneNode(entityName);
}

Entity::~Entity() {
	for (int i = 1; i < _components.size(); i++) {
		delete _components[i];
		_components[i] = nullptr;
	}
	delete _components[0];
	_components.clear();
	_cmps.clear();

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
}

void Entity::onCollisionEnter(Entity* e, Vector3D point, Vector3D normal)
{
	for (Component* c : _components) {
		if (c->isEnable()) {
			c->onCollisionEnter(e, point, normal);
		}
	}
}

void Entity::onCollisionStay(Entity* e, Vector3D point)
{
	for (Component* c : _components) {
		if (c->isEnable()) {
			c->onCollisionStay(e, point);
		}
	}
}

void Entity::onCollisionExit(Entity* e, Vector3D point)
{
	for (Component* c : _components) {
		if (c->isEnable()) {
			c->onCollisionExit(e, point);
		}
	}
}

void Entity::onTriggerEnter(Entity* e, Vector3D point)
{
	for (Component* c : _components) {
		if (c->isEnable()) {
			c->onTriggerEnter(e, point);
		}
	}
}

void Entity::onTriggerStay(Entity* e, Vector3D point)
{
	for (Component* c : _components) {
		if (c->isEnable()) {
			c->onTriggerStay(e, point);
		}
	}
}

void Entity::onTriggerExit(Entity* e, Vector3D point)
{
	for (Component* c : _components) {
		if (c->isEnable()) {
			c->onTriggerExit(e, point);
		}
	}
}

void Entity::addComponent(std::string s, Component* c)
{
	_cmps.insert({ s, c });
	_components.emplace_back(c);
}

Component* Entity::getComponent(std::string s)
{
	auto it = _cmps.find(s);
	if (it != _cmps.end())
		return _cmps[s];
	return nullptr;
}

void Entity::setActive(bool state)
{
	if (state == _active)
		return;


	_active = state;

	std::size_t n = _components.size();
	for (auto i = 0u; i < n; i++) {
		_components[i]->setEnable(state);
	}
}

void Entity::update()
{
	std::size_t n = _components.size();
	for (auto i = 0u; i < n; i++) {
		if (_components[i]->getEnable())
			_components[i]->update();
	}
}

void Entity::lateUpdate()
{
	std::size_t n = _components.size();
	for (auto i = 0u; i < n; i++) {
		if (_components[i]->getEnable())
			_components[i]->lateUpdate();
	}
}

void Entity::firstUpdate()
{
	std::size_t n = _components.size();
	for (auto i = 0u; i < n; i++) {
		if (_components[i]->getEnable())
			_components[i]->firstUpdate();
	}
}

void Entity::receiveEvent(int msg, Entity* e)
{
	for (Component* c : _components) {
		c->receiveEvent(msg, e);
	}
}