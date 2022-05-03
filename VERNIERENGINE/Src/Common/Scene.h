#pragma once

#include <string>
#include <vector>
#include "EngineDll.h"
#include "Entity.h"
#include "Utils.h"

namespace luabridge {
	class LuaRef;
	//class lua_State;

}
typedef struct lua_State lua_State;

class FactoryManager;
class InputManager;
class GameStateMachine;

class V3RN13R_API Scene {
private:
	std::vector<Entity*> _entities;
	std::vector<Entity*> _listeners;

	GameStateMachine* _GSM;

	InputManager* IM = nullptr;

	FactoryManager* _fmanager;

	Entity* createEntity(const std::string& fileName, luabridge::LuaRef entInfo);


	bool sceneStarted = false;
	std::string _name;
	lua_State* _state = nullptr;
	lua_State* _stateAux = nullptr;
public:
	Scene(const std::string& file, const std::string& name, GameStateMachine* gsm);
	~Scene();

	void addEntity(Entity* e);
	void addListener(Entity* e);
	GameStateMachine* getGSM();

	Entity* createEntityByPrefab(const std::string& file, const std::string& nameInFile, const std::string& nameInGame);

	void start();

	void onEnable();

	void onDisable();	

	void fixedUpdate();

	void lateUpdate();

	void update();

	void clearEntities();

	std::string getName() { return _name; }

	const std::vector<Entity*>* getListeners() { return &_listeners; }

	void refresh();


	/// <summary>
	/// Busca y devuelve el primer objeto en la escena con ese nombre
	/// </summary>
	/// <param name="name">Nombre del objeto a buscar</param>
	/// <returns>Primer objeto en la escena con ese nombre</returns>
	Entity* getObjectWithName(std::string name);

	/// <summary>
	/// Busca y devuelve una lista con los objetos con el nombre indicado
	/// </summary>
	/// <param name="name">Nombre de los objetos a buscar</param>
	/// <returns>Lista de objetos con ese nombre en la escena</returns>
	std::vector<Entity*> getAllObjectsWithName(std::string name);


	void setSceneActive(bool set);
};