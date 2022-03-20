#include "FactoryManager.h"
#include "Transform.h"
#include "RigidBody.h"
std::unique_ptr<FactoryManager>  FactoryManager::_instance;

FactoryManager::~FactoryManager()
{
	for (std::pair<std::string, Component*> i : _map) {
		delete i.second;
	}
	_map.clear();
}

FactoryManager* FactoryManager::getInstance()
{
	return _instance.get();
}

bool FactoryManager::setUpInstance()
{
	if (_instance == nullptr) {
		_instance.reset(new FactoryManager());
		return true;
	}
	return false;
}

Component* FactoryManager::findAndCreate(const std::string& name)
{
	std::map<std::string, Component*>::iterator it = _map.find(name);
	if (it != _map.end())
		return _map[name];	//aqu� se pasarian los argumentos
	throw "ERROR: NO SE HA PODIDO LEER EL COMPONENTE: " + name + "\n";
}

template<typename T>
void FactoryManager::addFactory(const std::string& name)
{
	//_map[(name == "") ? "paco" : name] = FactoryManager::createComponent<T>;
	_map[name] = FactoryManager::getInstance()->createComponent<T>();
}

void FactoryManager::initEngineFactories()
{
	FactoryManager::getInstance()->addFactory<Transform>("Transform");
}
