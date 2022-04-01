#include "SoundManager.h"
#include <iostream>
SoundManager* SoundManager::_instance = nullptr;
SoundManager* SoundManager::getInstance()
{
	return _instance;
}

bool SoundManager::setUpInstance()
{
	if (_instance == nullptr) {
		try {
			_instance = new SoundManager();
			//_instance->init(...);
		}
		catch (...) {
			return false;
		}
	}

	return true;
}

void SoundManager::deleteInstance()
{
	delete _instance;
}

SoundManager::~SoundManager()
{
}
void SoundManager::createSound(std::string sound, bool b3d, bool bLooping, bool bStream)
{
	auto found = _instance->getSoundMap().find(sound);
	if (found != _instance->getSoundMap().end())
		return;

	FMOD::Sound* fSonido;

	FMOD_MODE eMode = FMOD_DEFAULT;
	eMode |= b3d ? FMOD_3D : FMOD_2D;
	eMode |= bLooping ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
	eMode |= bStream ? FMOD_CREATESTREAM : FMOD_CREATECOMPRESSEDSAMPLE;

	_instance->errorCheck(_System->createSound(sound.c_str(), eMode, 0, &fSonido));
	
	if (fSonido) {
		_instance->getSoundMap()[sound] = fSonido;
	}
}

//Comprueba si hay un error en la ejecucion de un método de Fmod
int SoundManager::errorCheck(FMOD_RESULT result)
{
	if (result != FMOD_OK) {
		std::cout << "FMOD ERROR " << result << std::endl;
		return 1;
	}
	return 0;
}
