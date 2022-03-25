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

	void createSound(std::string sound, bool b3d, bool bLooping, bool bStream);
	int  playSound(const std::string& strSoundName, const Vector3D& vPos, float fVolumedB = 0.0f);


	typedef std::map<std::string, FMOD::Sound*> SoundMap;
	typedef std::map<int, FMOD::Channel*> ChannelMap;
private:
	SoundManager();
	virtual ~SoundManager();
	static SoundManager* _instance;

	SoundMap _SoundMap;
	ChannelMap _ChannelMap;

	FMOD::System* _System;

	static int errorCheck(FMOD_RESULT result);

	//getters
	SoundMap& getSoundMap() { return _SoundMap; };
	ChannelMap& getSoundChannels() { return _ChannelMap; };
};