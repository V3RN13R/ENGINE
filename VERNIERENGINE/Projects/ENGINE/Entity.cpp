#include "Entity.h"

Entity::Entity(Scene* scene, const std::string& name, const bool enabled = true) : _scene(scene), _name(name), _enabled(enabled){}

bool Entity::hasComponent(const std::string& tag) {
	return (map_.find(tag) != map_.end());
}

void Entity::update() {
	int length = _components.size();
	for (int i = 0; i < length; i++) {
		if (_components[i]->isActive()) _components[i]->update();
	}

}

void Entity::setEnabled(bool enabled) { 
	_enabled = enabled; 
	if (_activeOnHierarchy) {
		for (auto& c : _components)
			c.get()->setActiveOnHierarchy(enabled);
	}
}