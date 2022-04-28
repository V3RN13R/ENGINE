#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <vector>
#include <iostream>
#include "Component.h"
#include "ecs.h"
#include <unordered_map>
class Vector3D;
//class Manager;
enum class MessageType;
namespace Ogre {
	class SceneNode;
}

class Scene;

class Entity {
	//friend Manager;

public:

	Entity(std::string entityName, Scene* scene = nullptr);

	virtual ~Entity();

	void start();
	void onEnable();
	void onDisable();

	/*template<typename T, typename ...Ts>
	T* addComponent(Ts &&... args) {
		T* c = new T(std::forward<Ts>(args)...);
		c->setEntity(this);
		c->init();
		constexpr auto id = ecs::cmpIdx<T>;

		if (_cmpArray[id] != nullptr) {
			removeComponent<T>();
		}

		_cmpArray[id] = c;
		_components.emplace_back(c);

		return c;
	}*/


	void onCollisionEnter(Entity* e, Vector3D point, Vector3D normal) {
		for (Component* c : _components) {
			if (c->isEnable()) {
				c->onCollisionEnter(e, point, normal);
			}
		}
	};
	virtual void onCollisionStay(Entity* e, Vector3D point) {
		for (Component* c : _components) {
			if (c->isEnable()) {
				c->onCollisionStay(e, point);
			}
		}
	};


	void addComponent(std::string s, Component* c){
		_cmps.insert({ s, c });
		_components.emplace_back(c);
	}

	Component* getComponent(std::string s) {
		auto it = _cmps.find(s);
		if (it != _cmps.end())
			return _cmps[s];
		return nullptr;
	}

	template<typename T>
	void removeComponent() {
		auto id = ecs::cmpIdx<T>;
		if (_cmpArray[id] != nullptr) {
			Component* old_cmp = _cmpArray[id];
			_cmpArray[id] = nullptr;
			_components.erase( //
				std::find_if( //
					_components.begin(), //
					_components.end(), //
					[old_cmp](const Component* c) { //
						return c == old_cmp;
					}));
			delete old_cmp;
		}
	}

	template<typename T>
	inline T* getComponent() {
		auto id = ecs::cmpIdx<T>;
		return static_cast<T*>(_cmpArray[id]);
	}

	template<typename T>
	inline bool hasComponent() {
		auto id = ecs::cmpIdx<T>;
		return _cmpArray[id] != nullptr;
	}

	//inline void setMngr(Manager* mngr) {
	//	_mngr = mngr;
	//}

	//inline Manager* getMngr() {
	//	return _mngr;
	//}

	inline bool isActive() const {
		return _active;
	}

	inline void setActive(bool state) {
		_active = state;
	}

	template<typename T>
	inline bool hasGroup() {
		return _groups[ecs::grpIdx<T>];
	}

	template<typename T>
	inline void setGroup(bool state) {
		_groups[ecs::grpIdx<T>] = state;
	}

	inline void resetGroups() {
		_groups.reset();
	}


	virtual void update() {
		std::size_t n = _components.size();
		for (auto i = 0u; i < n; i++) {
			if(_components[i]->getEnable())
				_components[i]->update();
		}
	}

	void fixedUpdate() {
		std::size_t n = _components.size();
		for (auto i = 0u; i < n; i++) {
			if (_components[i]->getEnable())
				_components[i]->fixedUpdate();
		}
	}

	void render() {
		std::size_t n = _components.size();
		for (auto i = 0u; i < n; i++) {
			_components[i]->render();
		}
	}

	std::string getName()
	{
		return _entityName;
	}

	Ogre::SceneNode* getNode()
	{
		return _oNode;
	}


	void receiveEvent(MessageType msg, Entity* e) {
		for (Component* c : _components) {
			c->receiveEvent(msg, e);
		}
	};

	static std::vector<Entity*> _listeners;

	//static void addListener(Entity* entity) { _listeners.emplace_back(entity); }

	void destroy() { _destroy = true; }

	bool getDestroy() { return _destroy; }

	Scene* getScene() { return _scene; }


	/*static Entity* getEntity(std::string name) {
		for (int i = 0; i < _entities.size(); i++) {
			if (_entities[i]->getName() == name) return _entities[i];
		}
	}*/

protected:
	Ogre::SceneNode* _oNode;
	//static std::vector<Entity*> _entities; //(Entity.h)

private:

	Scene* _scene;
	bool _active;
	bool _destroy = false;
	//Manager* _mngr;
	std::unordered_map<std::string, Component*> _cmps;
	std::vector<Component*> _components;
	std::array<Component*, ecs::maxComponent> _cmpArray;
	std::bitset<ecs::maxGroup> _groups;
	std::string _entityName;
};