#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "Component.h"
#include "EngineDll.h"

class Vector3D;
namespace Ogre {
	class SceneNode;
}

class Scene;

class V3RN13R_API Entity {

public:

	Entity(std::string entityName, Scene* scene = nullptr);

	virtual ~Entity();

	void start();
	void onEnable();
	void onDisable();

	void onCollisionEnter(Entity* e, Vector3D point, Vector3D normal);
	void onCollisionStay(Entity* e, Vector3D point);
	void onCollisionExit(Entity* e, Vector3D point);

	void onTriggerEnter(Entity* e, Vector3D point);
	void onTriggerStay(Entity* e, Vector3D point);
	void onTriggerExit(Entity* e, Vector3D point);

	void addComponent(std::string s, Component* c);

	Component* getComponent(std::string s);

	std::vector<Component*> getComponents() { return _components; };

	bool isActive() const { return _active; }

	void setActive(bool state);

	void update();

	void lateUpdate();

	void firstUpdate();

	std::string getName() {return _entityName;}

	Ogre::SceneNode* getNode() {return _oNode;}

	void receiveEvent(int msg, Entity* e);

	static std::vector<Entity*> _listeners;

	void destroy() { _destroy = true; }

	bool getDestroy() { return _destroy; }

	Scene* getScene() { return _scene; }

protected:
	Ogre::SceneNode* _oNode;

private:
	Scene* _scene;
	bool _active;
	bool _destroy = false;
	std::unordered_map<std::string, Component*> _cmps;
	std::vector<Component*> _components;
	std::string _entityName;
};