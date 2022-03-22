#pragma once
#include <map>
#include <string>
#include "Component.h"
#include <memory>
class Factory;

class FactoryManager {
public:
	~FactoryManager();

	static FactoryManager* getInstance();
	static bool setUpInstance();

	//static void clean(); 

	Component* findAndCreate(const std::string& name, std::map<std::string, std::string> args);  //pasarle argumentos

	void addFactory(const std::string& name, Factory* fact);

private:	
	static std::unique_ptr<FactoryManager> _instance;
	std::map<std::string, Factory*> _map;

};