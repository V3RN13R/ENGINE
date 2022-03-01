#include "Component.h"


Component::Component(std::string tag) {
	_tag = tag;
}

Component::~Component() {
	// EventManager::getInstance()->UnregisterListenerForAll(this);
}

void Component::setEntity(Entity* e) { _e = e; }
Entity* Component::getEntity() { return _e; }

void Component::start() { }

void Component::preUpdate() { }

void Component::update() { }

void Component::render() { }

void Component::setEnabled(bool enabled) {
	if (/*startWasCalled_ &&*/ enabled == _enabled)
		return;
	
	_enabled = enabled;

	if (_activeOnHierarchy) {
		if (_enabled) {
			/*if (!startWasCalled_)*/
			start();
			/*startWasCalled_ = true;*/
		}
	}
}