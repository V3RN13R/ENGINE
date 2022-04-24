#pragma once 
#include "SDL.h"
#include "Utils.h"
#include <vector>
//#include "Singleton.h"

class Entity;

class InputManager {/*public Singleton<InputManager> { friend Singleton<InputManager>;*/
private:
	//inline InputManager& im() {
	//	return *InputManager::instance();
	//}
	const std::vector<Entity*>* _entidadesScene = nullptr;

public:
	InputManager() { }
	~InputManager(){}
   bool keyPressed(); 
   void setEntities(const std::vector<Entity*>* entidades)  { _entidadesScene = entidades; };
};