#include "Entity.h"
#include "RenderMain.h"
#include <Ogre.h>
#include <SDL.h>
#include "Manager.h"


Entity::Entity(Manager* mngr, std::string entityName) : _active(true), //
_mngr(mngr), //
_cmpArray(), //
_groups(), //
_entityName(entityName)
{
	_oNode = RenderMain::getInstance()->addSceneNode(entityName);
}


Entity::~Entity() {
	for (auto c : _components) {

		delete c;
	}
	//RenderMain::getInstance()->getSceneManager()->destroyAllMovableObjects(_oNode);
	_oNode->removeAndDestroyAllChildren();
	RenderMain::getInstance()->getSceneManager()->destroySceneNode(_oNode);
};


void Entity::keyPressed() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {

		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_w)
				if (!_listeners.empty()) {
					for (Entity* e : _listeners) {
						e->receiveEvent(MessageType::W);
					}
				}
			break;
		}
	}
}
