#pragma once
#include <string>
#include <map>
#include <vector>
#include "Component.h"
#include <memory>

class Scene;
class Transform;

class Entity
{
public:
// Constructora de las entidades.
	Entity(Scene* scene, const std::string& name, const bool enabled = true);
// Destructora de las entidades.
	virtual ~Entity();
// Update de las entidades.
	void update();

	// void onCollision();
	// void preUpdate();
	// void physicsUpdate();

// M�todo que devuelve el componente "tag" de una entidad.
	template <typename T>
	T* getComponent(const std::string& tag) {
		if (!hasComponent(tag))
			return nullptr;
	};

// M�todo que devuelve si la entidad tiene un componente "tag".
	bool hasComponent(const std::string& tag);
// M�todo que activa/desactiva una entidad.
	void setEnabled(bool active);

// M�todo que devuelve si la entidad est� activa.
	const bool isActive() { return (_enabled && _activeOnHierarchy); }
// M�todo que devuelve si la entidad est� activa.
	const bool isEnabled() { return _enabled; }
// M�todo que devuelve si la entidad est� activa.
	const bool isActiveOnHierarchy() { return _activeOnHierarchy; }
// M�todo que devuelve la escena a la que pertenece la entidad.
	const Scene* getScene() { return _scene; }

	// M�todo que devuelve el Transform de las entidades.
		// const Transform* getTransform() { return getComponent<Transform>("Transform"); }


private:
	std::string _name;
	Scene* _scene;
	bool _enabled = true, _activeOnHierarchy = true;
	
	std::vector<std::unique_ptr<Component>> _components;
	std::map<std::string, Component*> map_;
};

