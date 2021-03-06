#pragma once 
#include "SDL.h"
#include "Utils.h"
#include <vector>
#include <SDL_scancode.h>
#include "EngineDll.h"
class Entity;

struct MousePositionAbsolute
{
	int x = 0;
	int y = 0;
};
struct MousePositionRelative
{
	float x = 0;
	float y = 0;
};

struct MouseButtons {
	bool leftDown = false;
	bool middleDown = false;
	bool rightDown = false;
};
class V3RN13R_API InputManager  {
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

	static InputManager* _instance;

	MousePositionAbsolute mousePositionAbsolute_;
	MousePositionRelative mousePositionRelative_;
	MouseButtons mouseButtons_;


public:
	enum MOUSEBUTTON : uint8_t {
		LEFT = 0, MIDDLE = 1, RIGHT = 2
	};
	
	void clearState() {
		_isKeyDownEvent = false;
		_isKeyUpEvent = false;
		_isMouseButtonEvent = false;
		_isMouseMotionEvent = false;
	}

	virtual ~InputManager() {}

	void manageInput(SDL_Event evt);
	bool pollEvents();
	bool getKey(SDL_Scancode code);

	bool getKeyDown(SDL_Scancode code);

	bool getKeyUp(SDL_Scancode code);
	void setListenersVector(const std::vector<Entity*>* listeners) { _listenersScene = listeners; };
	bool getMouseDown() { return _isMouseButtonEvent; }

	void resetMousePosRel();
	MousePositionRelative getMousePosRel() const;
	MousePositionAbsolute getMousePosAbs() const;
	MouseButtons getMouseButtons() const;

	const std::pair<Sint32, Sint32>& getMousePos() {
		return {mousePositionAbsolute_.x, mousePositionAbsolute_.y};
	}

	static InputManager* getInstance();
	static bool setUpInstance();
	static void deleteInstance();
};