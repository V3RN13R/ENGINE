#include "InputManager.h"
#include "Entity.h"
#include "Scene.h"
#include <iostream>

InputManager* InputManager::_instance = nullptr;

void InputManager::manageInput(SDL_Event evt)
{
	switch (evt.type) {
	case SDL_MOUSEBUTTONDOWN:
	case SDL_MOUSEBUTTONUP:
		onMouseButtonChange(evt);
		break;
	default:
		if (evt.type == SDL_KEYDOWN) {
			SDL_Scancode code = evt.key.keysym.scancode;
			if (!_keys[code]._pressed) {
				_keys[code]._down = true;
				_keys[code]._pressed = true;
				_keys[code]._up = false;
			}
#pragma region BORRAR
			//ESTO EXISTE PARA NO TENER QUE CAMBIAR TODO EL CODIGO DE LAS PRUEBAS PERO HAY QUE BORRARLO
			if (evt.key.keysym.scancode == SDL_SCANCODE_W)
			{
				for (Entity* e : *_listenersScene) {
					e->receiveEvent(MessageType::W, e);
				}
			}
			else if (evt.key.keysym.scancode == SDL_SCANCODE_S)
			{
				for (Entity* e : *_listenersScene) {
					e->receiveEvent(MessageType::S, e);
				}
			}
			if (evt.key.keysym.scancode == SDL_SCANCODE_A)
			{
				for (Entity* e : *_listenersScene) {
					e->receiveEvent(MessageType::A, e);
				}
			}
			else if (evt.key.keysym.scancode == SDL_SCANCODE_D)
			{
				for (Entity* e : *_listenersScene) {
					e->receiveEvent(MessageType::D, e);
				}
			}

			if (evt.key.keysym.scancode == SDL_SCANCODE_SPACE)
			{
				for (Entity* e : *_listenersScene) {
					e->receiveEvent(MessageType::ESPACIO, e);
				}
			}

			if (evt.key.keysym.scancode == SDL_SCANCODE_Q)
			{
				for (Entity* e : *_listenersScene) {
					e->receiveEvent(MessageType::PULSA_Q, e);
				}
			}
			else if (evt.key.keysym.scancode == SDL_SCANCODE_E)
			{
				for (Entity* e : *_listenersScene) {
					e->receiveEvent(MessageType::PULSA_E, e);
				}
			}

			if (evt.key.keysym.scancode == SDL_SCANCODE_R)
			{
				for (Entity* e : *_listenersScene) {
					e->receiveEvent(MessageType::R, e);
				}
			}

			if (evt.key.keysym.scancode == SDL_SCANCODE_T)
			{
				for (Entity* e : *_listenersScene) {
					e->receiveEvent(MessageType::T, e);
				}
			}
			if (evt.key.keysym.scancode == SDL_SCANCODE_F)
			{
				for (Entity* e : *_listenersScene) {
					e->receiveEvent(MessageType::DISPARO, e);
				}
			}
#pragma endregion
			}
			else if (evt.type == SDL_KEYUP)
			{
				SDL_Scancode code = evt.key.keysym.scancode;
				_keys[code]._pressed = false;
				_keys[code]._down = false;
				_keys[code]._up = true;

			}
		}

	}

InputManager* InputManager::getInstance()
{
	return _instance;
}

bool InputManager::setUpInstance()
{
	if (_instance == nullptr) {
		try {
			_instance = new InputManager();
		}
		catch (...) {
			return false;
		}
	}

	return true;
}

void InputManager::deleteInstance()
{
	delete _instance;
}

	bool InputManager::pollEvents() {


#pragma region Antiguo
		//const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
		//SDL_Event event;
		//SDL_PollEvent(&event);


		//if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
		//{

		//	if (keyboard_state_array[SDL_SCANCODE_ESCAPE]) {
		//		return false;
		//	}


		//	if (keyboard_state_array[SDL_SCANCODE_W] && !(keyboard_state_array[SDL_SCANCODE_S]))
		//	{

		//		for (Entity* e : *_listenersScene) {
		//			e->receiveEvent(MessageType::W, e);
		//		}
		//	}
		//	else if (!keyboard_state_array[SDL_SCANCODE_W] && keyboard_state_array[SDL_SCANCODE_S])
		//	{
		//		for (Entity* e : *_listenersScene) {
		//			e->receiveEvent(MessageType::S, e);
		//		}
		//	}

		//	if (keyboard_state_array[SDL_SCANCODE_D] && !keyboard_state_array[SDL_SCANCODE_A])
		//	{
		//		for (Entity* e : *_listenersScene) {
		//			e->receiveEvent(MessageType::D, e);
		//		}
		//	}
		//	else if (!keyboard_state_array[SDL_SCANCODE_D] && keyboard_state_array[SDL_SCANCODE_A])
		//	{
		//		for (Entity* e : *_listenersScene) {
		//			e->receiveEvent(MessageType::A, e);
		//		}
		//	}

		//	if (keyboard_state_array[SDL_SCANCODE_SPACE])
		//	{
		//		for (Entity* e : *_listenersScene) {
		//			e->receiveEvent(MessageType::ESPACIO, e);
		//		}
		//	}

		//	if (keyboard_state_array[SDL_SCANCODE_Q] && !keyboard_state_array[SDL_SCANCODE_E])
		//	{
		//		for (Entity* e : *_listenersScene) {
		//			e->receiveEvent(MessageType::PULSA_Q, e);
		//		}
		//	}
		//	else if (!keyboard_state_array[SDL_SCANCODE_Q] && keyboard_state_array[SDL_SCANCODE_E])
		//	{
		//		for (Entity* e : *_listenersScene) {
		//			e->receiveEvent(MessageType::PULSA_E, e);
		//		}
		//	}

		//	if (keyboard_state_array[SDL_SCANCODE_R] && !keyboard_state_array[SDL_SCANCODE_T])
		//	{
		//		for (Entity* e : *_listenersScene) {
		//			e->receiveEvent(MessageType::R, e);
		//		}
		//	}

		//	if (keyboard_state_array[SDL_SCANCODE_T]&&!keyboard_state_array[SDL_SCANCODE_R])
		//	{
		//		for (Entity* e : *_listenersScene) {
		//			e->receiveEvent(MessageType::T, e);
		//		}
		//	}
		//	if (keyboard_state_array[SDL_SCANCODE_F]) {
		//		for (Entity* e : *_listenersScene) {
		//			e->receiveEvent(MessageType::DISPARO, e);
		//		}
		//	}


		//}
		//while (SDL_PollEvent(&event)) {
		//	if (event.type == SDL_QUIT) {
		//		return false;
		//	}
		//	int tecla = MessageType::DEFAULT;
		//	

		//	// Clicks del ratón.
		//	if (event.type == SDL_MOUSEBUTTONDOWN) {
		//		_isMouseButtonEvent = true;
		//		tecla = onMouseButtonChange(event, true);
		//	}
		//	// Movimiento del ratón.
		//	if (event.type == SDL_MOUSEMOTION) {
		//		_isMouseMotionEvent = true;
		//		_mousePos.first = event.motion.x;
		//		_mousePos.second = event.motion.y;
		//		//std::cout << _mousePos.first << " " << _mousePos.second << std::endl;
		//	}
		//	// Levantar click.
		//	if (event.type == SDL_MOUSEBUTTONUP) {
		//		_isMouseButtonEvent = false;
		//	}

		//	//si es una tecla válida se envia el mensaje correspondiente
		//	if (tecla != MessageType::DEFAULT) {
		//		for (Entity* e : *_listenersScene) {
		//			e->receiveEvent(tecla, e);
		//		}
		//	}
		//}
#pragma endregion

		SDL_Event evt;
		while (SDL_PollEvent(&evt)) {
			switch (evt.type)
			{
			case SDL_QUIT:
				return false;
			default:
				manageInput(evt);
				break;
			}
		}
		return true;
	}

	bool InputManager::getKey(SDL_Scancode code)
	{
		return _keys[code]._pressed;
	}

	bool InputManager::getKeyDown(SDL_Scancode code)
	{
		return _keys[code]._down;
	}

	bool InputManager::getKeyUp(SDL_Scancode code)
	{
		return _keys[code]._up;
	}

	InputManager::InputManager()
	{
		clearState();
	}

	int InputManager::onMouseButtonChange(const SDL_Event & event) {
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