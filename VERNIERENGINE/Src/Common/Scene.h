#pragma once

#include <string>
#include <vector>
#include "Entity.h"
#include "FactoryManager.h"
#include "InputManager.h"
#include "Utils.h"

namespace luabridge {
	class LuaRef;
}



class Scene {
private:
	std::vector<Entity*> _entities;
	std::vector<Entity*> _listeners;

	InputManager* IM = nullptr;

	FactoryManager* _fmanager;

	Entity* createEntity(const std::string& fileName, luabridge::LuaRef entInfo);

	void clearEntities();

	bool sceneStarted = false;

public:
	Scene(const std::string& file, const std::string& name);
	~Scene();

	void addEntity(Entity* e);
	void addListener(Entity* e);

	Entity* createEntityByPrefab(const std::string& file, const std::string& nameInFile, const std::string& nameInGame);

	void start();

	void onEnable();	

	void fixedUpdate();

	void update();


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