#include "InputManager.h"
#include "Entity.h"
#include "Scene.h"
#include <iostream>

InputManager* InputManager::_instance = nullptr;

void InputManager::manageInput(SDL_Event evt)
{

	switch (evt.type) {
	case SDL_MOUSEMOTION:
		mousePositionAbsolute_ = { evt.motion.x , evt.motion.y };
		mousePositionRelative_.x = evt.motion.xrel;
		mousePositionRelative_.y = evt.motion.yrel;
		break;
	case SDL_MOUSEBUTTONDOWN:
		_isMouseButtonEvent = true;
		switch (evt.button.button)
		{
		case SDL_BUTTON_LEFT:
			mouseButtons_.leftDown = evt.button.state;
			break;
		case SDL_BUTTON_MIDDLE:
			mouseButtons_.middleDown = evt.button.state;
			break;
		case SDL_BUTTON_RIGHT:
			mouseButtons_.rightDown = evt.button.state;
			break;
		default:
			break;
		}
		break;
		onMouseButtonChange(evt);
		break;
	case SDL_MOUSEBUTTONUP:
		_isMouseButtonEvent = false;
		switch (evt.button.button)
		{
		case SDL_BUTTON_LEFT:
			mouseButtons_.leftDown = evt.button.state;
			break;
		case SDL_BUTTON_MIDDLE:
			mouseButtons_.middleDown = evt.button.state;
			break;
		case SDL_BUTTON_RIGHT:
			mouseButtons_.rightDown = evt.button.state;
			break;
		default:
			break;
		}
		break;
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
			if (evt.key.keysym.scancode == SDL_SCANCODE_V)
			{
				for (Entity* e : *_listenersScene) {
					e->receiveEvent(MessageType::UNO, e);
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



void InputManager::resetMousePosRel()
{
	mousePositionRelative_.x = 0;
	mousePositionRelative_.y = 0;
}

MousePositionRelative InputManager::getMousePosRel() const
{
	return mousePositionRelative_;
}

MousePositionAbsolute InputManager::getMousePosAbs() const
{
	return mousePositionAbsolute_;
}

MouseButtons InputManager::getMouseButtons() const
{
	return mouseButtons_;
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

int InputManager::onMouseButtonChange(const SDL_Event& event) {

	switch (event.button.button) {
	case SDL_BUTTON_LEFT:
		return MessageType::CLICKIZ;
		break;
	case SDL_BUTTON_RIGHT:
		return MessageType::CLICKDE;
		break;


	default:
		break;
	}
}