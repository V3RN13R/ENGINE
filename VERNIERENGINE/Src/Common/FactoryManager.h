#pragma once
#include <map>
#include <string>
#include "Component.h"
#include <memory>

class FactoryManager {
public:
	~FactoryManager();

	static FactoryManager* getInstance();
	static bool setUpInstance();

	//static void clean(); 

	Component* findAndCreate(const std::string& name);  //pasarle argumentos�

	template<typename T>
	void addFactory(const std::string& name);

	void initEngineFactories();

private:
	template<typename T>
	Component* createComponent() { return new T(); };
	
	static std::unique_ptr<FactoryManager> _instance;
	std::map<std::string, Component*> _map;

};