#include "FactoryManager.h"
#include "Factory.h"

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

Component* FactoryManager::findAndCreate(const std::string& name)
{
	std::map<std::string, Factory*>::iterator it = _map.find(name);
	if (it != _map.end())
		return (*it).second->createComponent();	//aquí se pasarian los argumentos
	return nullptr;
}

void FactoryManager::addFactory(const std::string& name, Factory* factory)
{
	_map[name] = factory;
}
