#include "SDL.h"

class InputManager {
private:
	SDL_Event _evt;

public:
	InputManager(){}
	~InputManager(){}

	void leeTecla(SDL_Keycode sdlk);
	//virtual void sendEvent(MessageType msg) = 0;
	//virtual void receiveEvent(MessageType msg) = 0;
};