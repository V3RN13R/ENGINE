//#include "Scene.h"
//#include "LuaManager.h"
//
//
//Scene::Scene(const std::string& file, const std::string& name) {
//	std::cout << "Cargando escena " << name << "\n";
//
//}
//
//Entity* Scene::createEntity(const std::string& entityName, LuaRef entInfo)
//{
//	Entity* _entity = new Entity(entityName);
//
//	std::cout << "-------------------------------- Creando entidad " << entityName << " --------------------------------\n";
//
//	if (entInfo == NULL || entInfo.isNil() || entInfo.isRefNil()) {
//		std::cout << "ERROR: No se encontro la informacion de la entidad\n";
//		return nullptr;
//	}
//
//	//leemos el array de componentes
//	LuaRef components = entInfo.rawget("Components");
//	//comprobacion de errores
//	if (components.isNil()) { std::cout << "ERROR: No se ha podido leer el Array 'Components' \n"; return nullptr; }
//
//	for (int i = 1; i <= components.length(); i++)
//	{
//		//carga los componentes
//		enableExceptions(components[i]);
//		entity->addComponent(components[i], entInfo.rawget(components[i]));
//	}
//
//	LuaRef children = entInfo.rawget("Children");
//	LuaRef list = children.rawget("entities");
//
//
//	if (!list.isNil()) {
//		for (int i = 1; i <= list.length(); i++) {
//			enableExceptions(list[i]);
//			createEntity(list[i], children.rawget(list[i]))->transform()->setParent(entity->transform());
//		}
//	}
//
//	std::cout << "\n	Fin de la lectura de componentes\n";
//	bool active = true;
//	bool correct = readVariable<bool>(entInfo, "Active", &active);
//	if (correct) entity->setActive(active);
//
//	std::string tag = "Default";
//	correct = readVariable<std::string>(entInfo, "Tag", &tag);
//	if (correct)
//		entity->setTag(tag);
//
//	addEntity(entity);
//
//	std::cout << "\n-------------------------------- Fin de la lectura de la entidad " << entityName << " --------------------------------\n";
//	return entity;
//}
//
//Scene::~Scene()
//{
//	for (Entity* qEnt : _entities) {
//		delete qEnt;
//		qEnt = nullptr;
//	}
//}
//
//void Scene::addEntity(Entity* e)
//{
//	if (e) {
//		_entities.push_back(e);		
//	}
//}
//
//void Scene::start() {
//	
//}
//
////Ver si hace falta el render()
//
//void Scene::fixedUpdate()
//{
//	size_t n = _entities.size();
//	for (int i = 0; i < n; i++) {
//		if (!_entities[i]->getDestroy())
//			_entities[i]->fixedUpdate();
//	}
//}
//
//void Scene::update()
//{
//	size_t n = _entities.size();
//	for (int i = 0; i < n; i++) {
//		if (!_entities[i]->getDestroy())
//			_entities[i]->update();
//	}
//}
//
//
//void Scene::clearEntities()
//{
//	for (auto it = _entities.begin(); it != _entities.end();) {
//		if ((*it)->getDestroy()) {
//			Entity* e = (*it);
//			it = _entities.erase(it);
//			delete e;
//			e = nullptr;
//		}
//		else
//			it++;
//	}
//}
//
//Entity* Scene::getObjectWithName(std::string name)
//{
//	for (Entity* e : _entities) {
//		if (e->getName() == name)
//			return e;
//	}
//	return nullptr;
//}
//
//std::vector<Entity*> Scene::getAllObjectsWithName(std::string name)
//{
//	std::vector<Entity*> eS = std::vector<Entity*>();
//
//	for (Entity* e : _entities) {
//		if (e->getName() == name)
//			eS.push_back(e);
//	}
//
//	return eS;
//}
//
//void Scene::setSceneActive(bool set)
//{
//	for (Entity* qEnt : _entities)
//		qEnt->setActive(set);
//}