#include "Entity.h"
#include "RenderMain.h"

Entity::Entity(Manager* mngr, std::string entityName) : _active(true), //
_mngr(mngr), //
_cmpArray(), //
_groups(), //
_entityName(entityName)
{
	_oNode = RenderMain::getInstance()->addSceneNode(entityName);
}
