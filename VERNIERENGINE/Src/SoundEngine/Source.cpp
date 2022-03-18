//#include <SDL.h>
#include "SoundManager.h"

int main(int argv, char** args) 
{
	/* Initialize only SDL Audio on default device */
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		return 1;
	}
	
	SoundManager* _sm = new SoundManager();
	/* Init Simple-SDL2-Audio */
	_sm->initAudio();

	/* Play music and a sound */
	_sm->playMusic("highlands.wav", SDL_MIX_MAXVOLUME);
	_sm->playSound("sounds_door1.wav", SDL_MIX_MAXVOLUME / 2);

	/* While using delay for showcase, don't actually do this in your project */
	SDL_Delay(1000);

	/* Override music, play another sound */
	_sm->playMusic("road.wav", SDL_MIX_MAXVOLUME);
	SDL_Delay(1000);

	/* Pause audio test */
	_sm->pauseAudio();
	SDL_Delay(1000);
	_sm->unpauseAudio();

	_sm->playSound("sounds_door2.wav", SDL_MIX_MAXVOLUME / 2);
	SDL_Delay(2000);

	/* Caching sound example, create, play from Memory, clear */

	auto* sound = _sm->createAudio("sounds_door1.wav", 0, SDL_MIX_MAXVOLUME / 2);
	_sm->playSoundFromMemory(sound, SDL_MIX_MAXVOLUME);
	SDL_Delay(2000);

	auto* music = _sm->createAudio("highlands.wav", 1, SDL_MIX_MAXVOLUME);
	_sm->playMusicFromMemory(music, SDL_MIX_MAXVOLUME);
	SDL_Delay(2000);

	/* End Simple-SDL2-Audio */
	_sm->endAudio();

	/* Important to free audio after ending Simple-SDL2-Audio because they might be referenced still */
	_sm->freeAudio(sound);
	_sm->freeAudio(music);

	SDL_Quit();

	return 0;
}