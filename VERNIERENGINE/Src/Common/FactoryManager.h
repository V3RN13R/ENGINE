#pragma once
#include <map>
#include <string>
#include "Component.h"
#include "Factory.h"

class FactoryManager {
public:
	~FactoryManager();

	static FactoryManager* getInstance();
	static bool setUpInstance();

	//static void clean();  ?¿?¿

	Component* findAndCreate(const std::string& name);  //pasarle argumentos¿

	void addFactory(const std::string& name, Factory* factory);

private:
	static FactoryManager* _instance;
	std::map<std::string, Factory*> _map;

};