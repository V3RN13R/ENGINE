#include "InputManager.h"
#include "Entity.h"
#include "Scene.h"
#include <iostream>


bool InputManager::keyPressed() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}



		if (event.type == SDL_KEYDOWN) {
			//se mira qué tecla se ha preisonado
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				return false;
			}



			MessageType tecla = MessageType::DEFAULT;
			if (event.key.keysym.sym == SDLK_w) {
				tecla = MessageType::W;
			}
			else if (event.key.keysym.sym == SDLK_a) {
				tecla = MessageType::A;
			}
			else if (event.key.keysym.sym == SDLK_s) {
				tecla = MessageType::S;
			}
			else if (event.key.keysym.sym == SDLK_d) {
				tecla = MessageType::D;
			}
			else if (event.key.keysym.sym == SDLK_q) {
				tecla = MessageType::PULSA_Q;
			}
			else if (event.key.keysym.sym == SDLK_e) {
				tecla = MessageType::PULSA_E;
			}


			//si es una tecla válida se envia el mensaje correspondiente
			if (tecla != MessageType::DEFAULT) {
				for (Entity* e : *_entidadesScene) {
					e->receiveEvent(tecla, e);
				}
			}
		}
		std::pair<Sint32, Sint32> mousePos_;
		if (event.type == SDL_MOUSEMOTION) {
			mousePos_.first = event.motion.x;
			mousePos_.second = event.motion.y;
			std::cout << mousePos_.first << " " << mousePos_.second << std::endl;
		}
	}
	return true;
}