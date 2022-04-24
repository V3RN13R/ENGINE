#pragma once 
#include "SDL.h"
#include "Utils.h"
#include <vector>
#include "Singleton.h"

class Entity;

class InputManager : public Singleton<InputManager> {
	friend Singleton<InputManager>;

private:
	InputManager() {
		clearState();
	}

	MessageType onMouseButtonChange(const SDL_Event& event, bool isDown);

	const std::vector<Entity*>* _listenersScene = nullptr;
	std::pair<Sint32, Sint32> _mousePos;

	bool _isKeyDownEvent, _isKeyUpEvent, _isMouseButtonEvent, _isMouseMotionEvent;

	//std::array<bool, 3> _mbState;

public:
	enum MOUSEBUTTON : uint8_t {
		LEFT = 0, MIDDLE = 1, RIGHT = 2
	};
	
	void clearState() {
		_isKeyDownEvent = false;
		_isKeyUpEvent = false;
		_isMouseButtonEvent = false;
		_isMouseMotionEvent = false;
		//for (auto i = 0u; i < 3; i++) {
			//_mbState[i] = false;
		//}
	}

	virtual ~InputManager() {}

	bool keyPressed();

	void setListenersVector(const std::vector<Entity*>* listeners) { _listenersScene = listeners; };
	bool getMouseDown() { return _isMouseButtonEvent; }

	//inline int getMouseButtonState(MOUSEBUTTON b) {
	//	return _mbState[b];
	//}

	void setEntities(const std::vector<Entity*>* entidades) { _entidadesScene = entidades; };

	const std::pair<Sint32, Sint32>& getMousePos() {
		return _mousePos;
	}
	InputManager& ih() {
		return *InputManager::instance();
	}
};