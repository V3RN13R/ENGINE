#include "Scene.h"
#include "LuaManager.h"
#include "FactoryManager.h"
#include "InputManager.h"
#include <algorithm>
#include <SDL.h>
#include "UIElement.h"
//#include "checkML.h"

Scene::Scene(const std::string& file, const std::string& name, GameStateMachine* gsm) {

	_GSM = gsm;
	_name = name;

	if (_state)lua_close(_state);

	try {
		_state = readFileLua(file);
		std::cout << "Archivo " << file << " abierto con �xito\n";
	}
	catch (std::string& error) {
		std::cout << "ERROR al leer el archivo " << file << "\n";
		std::cout << error << '\n';
		return;
	}
	if (_state == nullptr) {
		std::cout << "ERROR al leer el archivo " << file << "\n";
		return;
	}

	LuaRef _refScene = NULL;
	try {
		_refScene = readElementFromFile(_state, name);
	}
	catch (...) {
		std::cout << "ERROR al cargar la escena del archivo " << file << "\n";
		return;
	}

	//sacamos el vector de entidades y las creamos
	enableExceptions(_refScene);

	LuaRef _entidades = NULL;
	try {
		//leemos el vector que contiene las entidades
		_entidades = _refScene.rawget("entities");
	}
	catch (...) {
		std::cout << "ERROR al cargar la lista de entidades de la escena " << file << "\n";
		return;
	}

	for (int i = 1; i <= _entidades.length(); i++)
	{
		std::string _ent = _entidades[i];

		//crea las entidades con sus componentes
		//con el nombre ent, se busca el .lua y se cree lo que pone alli
		LuaRef _entInfo = readElementFromFile(_state, _ent);

		if (!createEntity(_ent, _entInfo)) 
			std::cout << "ERROR: no se ha podido cargar la entidad: " << _ent;
		std::cout << "\n";
	}
	std::cout << "Listo.\n\n-------------------------\n\n";

}

Entity* Scene::createEntity(const std::string& entityName, LuaRef entInfo)
{
	Entity* _entity = new Entity(entityName, this);

	std::cout << "-------------------------------- Creando entidad " << entityName << " --------------------------------\n";

	if (entInfo == NULL || entInfo.isNil()) { 
		std::cout << "ERROR: No se encontro la informacion de la entidad\n";
		return nullptr;
	}

	//leemos el array de componentes
	LuaRef components = entInfo.rawget("Components");
	//comprobacion de errores
	if (components.isNil()) { std::cout << "ERROR: No se ha podido leer el Array 'Components' \n"; return nullptr; }

	for (int i = 1; i <= components.length(); i++)
	{
		//carga los componentes
		enableExceptions(components[i]);

		_entity->addComponent(components[i], _fmanager->getInstance()->findAndCreate(components[i], entInfo.rawget(components[i]),_entity));
	}


	std::cout << "\n	Fin de la lectura de componentes\n";
	bool active = true;
	bool correct = readVariable<bool>(entInfo, "Active", &active);
	if (correct) _entity->setActive(active);

	addEntity(_entity);

	bool isListener = true;
	bool correct2 = readVariable<bool>(entInfo, "Listener", &isListener);
	if (correct2 && isListener) {
		addListener(_entity);
	}

	std::cout << "\n-------------------------------- Fin de la lectura de la entidad " << entityName << " --------------------------------\n";
	return _entity;
}


Entity* Scene::createEntityByPrefab(const std::string& file, const std::string& nameInFile, const std::string& nameInGame)
{
	std::cout << "\n\n";
	if (_stateAux)
		lua_close(_stateAux);
	try {
		_stateAux = readFileLua(file);
		std::cout << "Archivo " << file << " abierto con �xito\n";
	}
	catch (std::string& error) {
		std::cout << "ERROR al leer el archivo " << file << "\n";
		std::cout << error << '\n';
		return nullptr;
	}
	if (_stateAux == nullptr) {
		std::cout << "ERROR al leer el archivo " << file << "\n";
		return nullptr;
	}

	LuaRef refEntity = NULL;
	try {
		refEntity = readElementFromFile(_stateAux, nameInFile);
	}
	catch (...) {
		std::cout << "ERROR al cargar la entidad del archivo " << file << "\n";
		return nullptr;
	}
	std::cout << "Cargando " << nameInFile << "\n";

	Entity* entity;
	enableExceptions(refEntity);

	entity = createEntity(nameInGame, refEntity);
	if (!entity)
		std::cout << "ERROR al cargar la entidad: " << nameInFile;

	std::cout << "\n\n";
	return entity;
}

Scene::~Scene()
{
	for (Entity* qEnt : _entities) {
		delete qEnt;
		qEnt = nullptr;
	}
	//delete _state;

	//hay que borrar el estado de lua
	if (_state)lua_close(_state);
	if(_stateAux)lua_close(_stateAux);

}

void Scene::addEntity(Entity* e)
{
	if (e) {
		_entities.push_back(e);
	}
}
void Scene::addListener(Entity* e)
{
	if (e) {
		_listeners.push_back(e);
	}
}

GameStateMachine* Scene::getGSM()
{
	return _GSM;;
}

void Scene::hideUI() {
	for (int i = 0; i < _uielements.size(); i++) {
		_uielements[i]->hide();
	}
}

void Scene::showUI() {
	for (int i = 0; i < _uielements.size(); i++) {
		_uielements[i]->show();
	}
}

void Scene::start() {
	sceneStarted = true;
	size_t n = _entities.size();
	for (int i = 0; i < n; i++) {
		if (!_entities[i]->getDestroy() && _entities[i]->isActive())
			_entities[i]->start();
	}
}

void Scene::onEnable() {
	size_t n = _entities.size();
	for (int i = 0; i < n; i++) {
		if (!_entities[i]->getDestroy())
			_entities[i]->onEnable();
	}
}

void Scene::onDisable() {
	size_t n = _entities.size();
	for (int i = 0; i < n; i++) {
		if (!_entities[i]->getDestroy())
			_entities[i]->onDisable();
	}
}

//Ver si hace falta el render()

void Scene::firstUpdate()
{
	size_t n = _entities.size();
	for (int i = 0; i < n; i++) {
		if (!_entities[i]->getDestroy() && _entities[i]->isActive())
			_entities[i]->firstUpdate();
	}
}


void Scene::update()
{
	size_t n = _entities.size();
	for (int i = 0; i < n; i++) {
		if (!_entities[i]->getDestroy() && _entities[i]->isActive())
			_entities[i]->update();
	}
}


void Scene::lateUpdate()
{
	size_t n = _entities.size();
	for (int i = 0; i < n; i++) {
		if (!_entities[i]->getDestroy() && _entities[i]->isActive())
			_entities[i]->lateUpdate();
	}
}

void Scene::clearEntities()
{
	for (auto it = _entities.begin(); it != _entities.end();) {
		if ((*it)->getDestroy()) {
			(*it)->onDisable();
			Entity* e = (*it);
			delete e;
			it = _entities.erase(it);
			e = nullptr;
		}
		else
			it++;
	}
}

Entity* Scene::getObjectWithName(std::string name)
{
	for (Entity* e : _entities) {
		if (e->getName() == name)
			return e;
	}
	return nullptr;
}

std::vector<Entity*> Scene::getAllObjectsWithName(std::string name)
{
	std::vector<Entity*> eS = std::vector<Entity*>();

	for (Entity* e : _entities) {
		if (e->getName() == name)
			eS.push_back(e);
	}

	return eS;
}

void Scene::setSceneActive(bool set)
{
	for (Entity* qEnt : _entities)
		qEnt->setActive(set);
}


void Scene::refresh()
{	// remove dead entities from the list of entities
	_entities.erase( //
	std::remove_if( //
		_entities.begin(), //
		_entities.end(), //
		[](const Entity* e) { //
			if (e->isActive()) {
				return false;
			}
			else {
				delete e;
				return true;
			}
		}), //
	_entities.end());
}