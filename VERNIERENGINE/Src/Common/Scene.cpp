#include "Scene.h"
#include "LuaManager.h"
#include "LoadImages.h"
#include <algorithm>
#include <SDL.h>


Scene::Scene(const std::string& file, const std::string& name, GameStateMachine* gsm) {
	//_fmanager->setUpInstance(); se puede quitar en el main se debe de instanciar

	_GSM = gsm;
	lua_State* _state = nullptr;

	// Cargamos todas las imagenes desde un archivo .lua
	LoadImages::instance()->cargaImagen("imagenes.lua", "imagenes");

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

	//LoadImage::instance()->cargaImagen("prueba2.lua", "prueba2");
}

Entity* Scene::createEntity(const std::string& entityName, LuaRef entInfo)
{
	Entity* _entity = new Entity(entityName, this);

	std::cout << "-------------------------------- Creando entidad " << entityName << " --------------------------------\n";

	if (entInfo == NULL || entInfo.isNil()) { //|| entInfo.isRefNil()
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

	//LuaRef children = entInfo.rawget("Children");
	//LuaRef list = children.rawget("entities");
	//if (!list.isNil()) {
	//	for (int i = 1; i <= list.length(); i++) {
	//		enableExceptions(list[i]);
	//		createEntity(list[i], children.rawget(list[i]))->transform()->setParent(_entity->transform());
	//	}
	//}

	std::cout << "\n	Fin de la lectura de componentes\n";
	bool active = true;
	bool correct = readVariable<bool>(entInfo, "Active", &active);
	if (correct) _entity->setActive(active);

	/*std::string tag = "Default";
	correct = readVariable<std::string>(entInfo, "Tag", &tag);
	if (correct)
		_entity->setTag(tag);*/

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

	lua_State* state = nullptr;
	try {
		state = readFileLua(file);
		std::cout << "Archivo " << file << " abierto con �xito\n";
	}
	catch (std::string& error) {
		std::cout << "ERROR al leer el archivo " << file << "\n";
		std::cout << error << '\n';
		return nullptr;
	}
	if (state == nullptr) {
		std::cout << "ERROR al leer el archivo " << file << "\n";
		return nullptr;
	}

	LuaRef refEntity = NULL;
	try {
		refEntity = readElementFromFile(state, nameInFile);
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

void Scene::fixedUpdate()
{
	size_t n = _entities.size();
	for (int i = 0; i < n; i++) {
		if (!_entities[i]->getDestroy() && _entities[i]->isActive())
			_entities[i]->fixedUpdate();
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
			Entity* e = (*it);
			it = _entities.erase(it);
			delete e;
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