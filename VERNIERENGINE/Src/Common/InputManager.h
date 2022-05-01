#pragma once 
#include "SDL.h"
#include "Utils.h"
#include <vector>
#include "Singleton.h"
#include <SDL_scancode.h>
class Entity;

class InputManager : public Singleton<InputManager> {
	friend Singleton<InputManager>;

private:
	InputManager();

	int onMouseButtonChange(const SDL_Event& event);

	const std::vector<Entity*>* _listenersScene = nullptr;
	std::pair<Sint32, Sint32> _mousePos;

	bool _isKeyDownEvent, _isKeyUpEvent, _isMouseButtonEvent, _isMouseMotionEvent;

	struct KeyState {
		bool _down=false;
		bool _up=false;
		bool _pressed=false;
	};
	KeyState _keys[SDL_NUM_SCANCODES];
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

	void manageInput(SDL_Event evt);
	bool pollEvents();
	bool getKey(SDL_Scancode code);

	bool getKeyDown(SDL_Scancode code);

	bool getKeyUp(SDL_Scancode code);
	void setListenersVector(const std::vector<Entity*>* listeners) { _listenersScene = listeners; };
	bool getMouseDown() { return _isMouseButtonEvent; }

	//inline int getMouseButtonState(MOUSEBUTTON b) {
	//	return _mbState[b];
	//}


	const std::pair<Sint32, Sint32>& getMousePos() {
		return _mousePos;
	}
	InputManager& ih() {
		return *InputManager::instance();
	}
};