#include "FactoryManager.h"
#include "Transform.h"
#include "RigidBody.h"


FactoryManager*  FactoryManager::_instance;

FactoryManager::~FactoryManager()
{
	for (std::pair<std::string, Factory*> i : _map) {
		delete i.second;
	}
	_map.clear();
}

FactoryManager* FactoryManager::getInstance()
{
	return _instance;
}

bool FactoryManager::setUpInstance()
{
	if (_instance == nullptr) {
		_instance = new FactoryManager();
		return true;
	}
	return false;
}

void FactoryManager::deleteInstance()
{
	delete _instance;
}

Component* FactoryManager::findAndCreate(const std::string& name)
{
	std::map<std::string, Factory*>::iterator it = _map.find(name);
	if (it != _map.end())
		return (*it).second->createComponent(args);

	throw "ERROR: NO SE HA PODIDO LEER EL COMPONENTE: " + name + "\n";

}

void FactoryManager::addFactory(const std::string& name, Factory* fact)
{
	_map[name] = fact;
}