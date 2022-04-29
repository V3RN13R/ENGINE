#include "InputManager.h"
#include "Entity.h"
#include "Scene.h"
#include <iostream>


bool InputManager::keyPressed() {
	
	
	const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
	SDL_Event event;
	SDL_PollEvent(&event);

	if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
	{

		if (keyboard_state_array[SDL_SCANCODE_ESCAPE]) {
			return false;
		}


		if (keyboard_state_array[SDL_SCANCODE_W] && !(keyboard_state_array[SDL_SCANCODE_S]) && !keyboard_state_array[SDL_SCANCODE_SPACE])
		{

			for (Entity* e : *_listenersScene) {
				e->receiveEvent(MessageType::W, e);
			}
		}
		else if (!keyboard_state_array[SDL_SCANCODE_W] && keyboard_state_array[SDL_SCANCODE_S] && !keyboard_state_array[SDL_SCANCODE_SPACE])
		{
			for (Entity* e : *_listenersScene) {
				e->receiveEvent(MessageType::S, e);
			}
		}

		if (keyboard_state_array[SDL_SCANCODE_D] && !keyboard_state_array[SDL_SCANCODE_A] && !keyboard_state_array[SDL_SCANCODE_SPACE])
		{
			for (Entity* e : *_listenersScene) {
				e->receiveEvent(MessageType::D, e);
			}
		}
		else if (!keyboard_state_array[SDL_SCANCODE_D] && keyboard_state_array[SDL_SCANCODE_A] && !keyboard_state_array[SDL_SCANCODE_SPACE])
		{
			for (Entity* e : *_listenersScene) {
				e->receiveEvent(MessageType::A, e);
			}
		}

		if (keyboard_state_array[SDL_SCANCODE_SPACE] && !keyboard_state_array[SDL_SCANCODE_D] && !keyboard_state_array[SDL_SCANCODE_A] && !keyboard_state_array[SDL_SCANCODE_S] && !keyboard_state_array[SDL_SCANCODE_W])
		{
			for (Entity* e : *_listenersScene) {
				e->receiveEvent(MessageType::ESPACIO, e);
			}
		}

		if (keyboard_state_array[SDL_SCANCODE_Q] && !keyboard_state_array[SDL_SCANCODE_E])
		{
			for (Entity* e : *_listenersScene) {
				e->receiveEvent(MessageType::PULSA_Q, e);
			}
		}
		else if (!keyboard_state_array[SDL_SCANCODE_Q] && keyboard_state_array[SDL_SCANCODE_E])
		{
			for (Entity* e : *_listenersScene) {
				e->receiveEvent(MessageType::PULSA_E, e);
			}
		}

		if (keyboard_state_array[SDL_SCANCODE_R] && !keyboard_state_array[SDL_SCANCODE_T])
		{
			for (Entity* e : *_listenersScene) {
				e->receiveEvent(MessageType::R, e);
			}
		}

		if (keyboard_state_array[SDL_SCANCODE_T]&&!keyboard_state_array[SDL_SCANCODE_R])
		{
			for (Entity* e : *_listenersScene) {
				e->receiveEvent(MessageType::T, e);
			}
		}


	}


	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
		MessageType tecla = MessageType::DEFAULT;
		

		// Clicks del ratón.
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			_isMouseButtonEvent = true;
			tecla = onMouseButtonChange(event, true);
		}
		// Movimiento del ratón.
		if (event.type == SDL_MOUSEMOTION) {
			_isMouseMotionEvent = true;
			_mousePos.first = event.motion.x;
			_mousePos.second = event.motion.y;
			//std::cout << _mousePos.first << " " << _mousePos.second << std::endl;
		}
		// Levantar click.
		if (event.type == SDL_MOUSEBUTTONUP) {
			_isMouseButtonEvent = false;
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

InputManager::InputManager()
{
	clearState();
}

MessageType InputManager::onMouseButtonChange(const SDL_Event& event, bool isDown) {
	switch (event.button.button) {
	case SDL_BUTTON_LEFT:
		//std::cout << "\nIZQ" << std::endl;
		return MessageType::CLICKIZ;
		break;
	case SDL_BUTTON_RIGHT:
		//std::cout << "\nDER" << std::endl;
		return MessageType::CLICKDE;
		break;
	default:
		break;
	}
}