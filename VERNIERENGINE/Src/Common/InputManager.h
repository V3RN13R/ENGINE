#include "SDL.h"

class InputManager {
private:
	SDL_Event _evt;

public:
	InputManager(){}
	~InputManager(){}

	char leeInput(SDL_Event _evt);
	void update();
};