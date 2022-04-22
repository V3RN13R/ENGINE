#include "GameStateMachine.h"
#include "Scene.h"
#include "SDL.h"

void GameStateMachine::changeScene(std::unique_ptr<Scene> _scene, std::string file, std::string name) {
	_scene.reset(new Scene(file, name));
	_scene->start();
}

//bool GameStateMachine::keyPressed() {
	//SDL_Event event;
	//while (SDL_PollEvent(&event)) {
	//	if (event.type == SDL_QUIT) {
	//		return false;
	//	}

	//	if (event.type == SDL_KEYDOWN) {
	//		//se mira qué tecla se ha preisonado
	//		if (event.key.keysym.sym == SDLK_ESCAPE) {
	//			return false;
	//		}

	//		MessageType tecla = MessageType::DEFAULT;
	//		if (event.key.keysym.sym == SDLK_1) {
	//			tecla = MessageType::ESCENA1;
	//		}
	//		else if (event.key.keysym.sym == SDLK_2) {
	//			tecla = MessageType::ESCENA2;
	//		}

	//		std::pair<Sint32, Sint32> mousePos_;
	//		if (event.type == SDL_MOUSEMOTION) {
	//			mousePos_.first = event.motion.x;
	//			mousePos_.second = event.motion.y;
	//			std::cout << mousePos_.first << " " << mousePos_.second << std::endl;
	//		}

	//		//si es una tecla válida se envia el mensaje correspondiente
	//		if (tecla != MessageType::DEFAULT) {
	//			for (Entity* e : Entity::_listeners) {
	//				e->receiveEvent(tecla, e);
	//			}
	//		}
	//	}
	//}
	//return true;
//}