#pragma once
#include <map>
#include <string>
#include "Component.h"
#include <memory>
#include "EngineDll.h"
class Factory;

class V3RN13R_API FactoryManager {
public:
	~FactoryManager();

	static FactoryManager* getInstance();
	static bool setUpInstance();
	static void deleteInstance(); 

	Component* findAndCreate(const std::string& name, std::map<std::string, std::string> args, Entity* ent = nullptr);  //pasarle argumentos

	void addFactory(const std::string& name, Factory* fact);

	void initEngineFactories();

private:
	static FactoryManager* _instance;	
	std::map<std::string, Factory*> _map;
	template<typename T>
	Component* createComponent() { return new T(); };
};