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
		MessageType tecla = MessageType::DEFAULT;
		if (event.type == SDL_KEYDOWN) {
			//se mira qué tecla se ha preisonado
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				return false;
			}
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
		}
		// Clicks del ratón.
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			tecla = onMouseButtonChange(event, true);
		}
		// Movimiento del ratón.
		if (event.type == SDL_MOUSEMOTION) {
			_mousePos.first = event.motion.x;
			_mousePos.second = event.motion.y;
			std::cout << _mousePos.first << " " << _mousePos.second << std::endl;
		}

		//si es una tecla válida se envia el mensaje correspondiente
		if (tecla != MessageType::DEFAULT) {
			for (Entity* e : *_listenersScene) {
				e->receiveEvent(tecla, e);
			}
		}
	}
	return true;
}

MessageType InputManager::onMouseButtonChange(const SDL_Event& event, bool isDown) {
	switch (event.button.button) {
	case SDL_BUTTON_LEFT:
		std::cout << "\nIZQ" << std::endl;
		return MessageType::CLICKIZ;
		break;
	case SDL_BUTTON_RIGHT:
		std::cout << "\nDER" << std::endl;
		return MessageType::CLICKDE;
		break;
	default:
		break;
	}
}