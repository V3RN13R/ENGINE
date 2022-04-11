#include "SoundManager.h"
#include "Vector3D.h"
#include <iostream>
#include <vector>
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
			_instance->init();
		}
		catch (...) {
			return false;
		}
	}

	return true;
}
void SoundManager::init()
{
	_instance->_System = NULL;
	errorCheck(FMOD::System_Create(&_instance->_System));
	errorCheck(_instance->_System->init(512, FMOD_INIT_NORMAL, nullptr));
}

void SoundManager::deleteInstance()
{
	delete _instance;
}

SoundManager::~SoundManager()
{
}

void SoundManager::update() {
	std::vector<ChannelMap::iterator> pStoppedChannels;
	for (auto it = _instance->getSoundChannels().begin(), itEnd = _instance->getSoundChannels().end(); it != itEnd; ++it)
	{
		bool bIsPlaying = false;
		it->second->isPlaying(&bIsPlaying);
		if (!bIsPlaying)
		{
			pStoppedChannels.push_back(it);
		}
	}
	for (auto& it : pStoppedChannels)
	{
		_instance->getSoundChannels().erase(it);
	}
	errorCheck(_instance->_System->update());
}
void SoundManager::createSound(const std::string sound, bool b3d, bool bLooping, bool bStream)
{
	auto found = _instance->getSoundMap().find(sound);
	if (found != _instance->getSoundMap().end())
		return;

	FMOD::Sound* fSonido;

	//flags
	FMOD_MODE eMode = FMOD_DEFAULT;
	eMode |= b3d ? FMOD_3D : FMOD_2D;
	eMode |= bLooping ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
	eMode |= bStream ? FMOD_CREATESTREAM : FMOD_CREATECOMPRESSEDSAMPLE;

	_instance->errorCheck(_System->createSound(sound.c_str(), eMode, 0, &fSonido));
	
	if (fSonido) {
		_instance->getSoundMap()[sound] = fSonido;
	}
}

int SoundManager::playSound(const std::string& strSoundName, Vector3D& vPos, float volumedB)
{
	int nChannelId = _instance->getNextChannelId()++;
	auto found = _instance->getSoundMap().find(strSoundName);
	if (found == _instance->getSoundMap().end())
	{
		createSound(strSoundName);
		found = _instance->getSoundMap().find(strSoundName);
		if (found == _instance->getSoundMap().end())
		{
			return nChannelId;
		}
	}
	FMOD::Channel* pChannel = nullptr;
	errorCheck(_System->playSound(found->second, NULL, false, &pChannel));
	if (pChannel)
	{
		FMOD_MODE currMode;
		found->second->getMode(&currMode);
		if (currMode & FMOD_3D) {
			FMOD_VECTOR position = { vPos.getX(), vPos.getX(), vPos.getX() };
			errorCheck(pChannel->set3DAttributes(&position, nullptr));
		}
		errorCheck(pChannel->setVolume(dbToVolume(volumedB)));
		_instance->getSoundChannels()[nChannelId] = pChannel;
	}
	return nChannelId;
}

void SoundManager::stopChannel(int channelId)
{
	auto found = _instance->getSoundChannels().find(channelId);
	if (found == _instance->getSoundChannels().end())
		return;
	errorCheck(found->second->stop());
}

void SoundManager::stopAllChannels()
{
	for (auto x : _instance->getSoundChannels())
		errorCheck(x.second->stop());
}
void SoundManager::setChannelvolume(int channelId, float volumedB)
{
	auto found = _instance->getSoundChannels().find(channelId);
	if (found == _instance->getSoundChannels().end())
		return;

	errorCheck(found->second->setVolume(dbToVolume(volumedB)));
}

float SoundManager::dbToVolume(float db)
{
	return powf(10.0f, 0.05f * db);
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
