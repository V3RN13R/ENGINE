#pragma once

#include <string>
#include <map>

#include "fmod.hpp"
#include "fmod_errors.h"

class Vector3D;

class SoundManager {
public:
	static SoundManager* getInstance();
	static bool setUpInstance();
	static void deleteInstance();
	/**
	*	Si el sonido está en el map, no hace nada, si no, lo crea
	**/ 
	void createSound(const std::string sound, bool b3d = true, bool bLooping = false, bool bStream = false);
	int  playSound(const std::string& strSoundName, float fVolumedB = 0.0f);
	void update();

	void stopChannel(int id);
	void stopAllChannels();
	void setChannelvolume(int nChannelId, float volumedB);

	typedef std::map<std::string, FMOD::Sound*> SoundMap;
	typedef std::map<int, FMOD::Channel*> ChannelMap;
private:
	SoundManager() {};
	virtual ~SoundManager();
	static SoundManager* _instance;
	void init();

	SoundMap _SoundMap;
	ChannelMap _ChannelMap;

	FMOD::System* _System;
	int _NextChannelId = 0;

	float dbToVolume(float db);
	static int errorCheck(FMOD_RESULT result);

	//getters
	SoundMap& getSoundMap() { return _SoundMap; };
	ChannelMap& getSoundChannels() { return _ChannelMap; };
	int& getNextChannelId() { return _NextChannelId; };

};