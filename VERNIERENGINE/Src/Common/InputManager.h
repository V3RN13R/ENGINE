#pragma once 
#include "SDL.h"
#include "Utils.h"
#include <vector>
#include "Singleton.h"

class Entity;

class InputManager : public Singleton<InputManager> {
	friend Singleton<InputManager>;

private:
	InputManager() { }
	MessageType onMouseButtonChange(const SDL_Event& event, bool isDown);

	const std::vector<Entity*>* _entidadesScene = nullptr;
	std::pair<Sint32, Sint32> _mousePos;

public:

	virtual ~InputManager() {}

	bool keyPressed();

	void setEntities(const std::vector<Entity*>* entidades) { _entidadesScene = entidades; };

	const std::pair<Sint32, Sint32>& getMousePos() {
		return _mousePos;
	}
	InputManager& ih() {
		return *InputManager::instance();
	}
};