#pragma once

#include "Component.h"
#include "EngineDll.h"
#include <string>
#include <map>

class V3RN13R_API SoundComponent : public Component
{
private: 
	std::string _route;
	std::map<std::string, std::pair<std::string, int>> _sounds;
public:
	SoundComponent(std::map<std::string, std::string> args, Entity* ent);
	void playMusic(std::string s, float volume = 1.0f);
	void playsound(std::string s, float volume = 1.0f);
	void stopSound(std::string sound);
	void resumeSound(std::string sound);
	void stopAllSounds();
	void resumeAllSounds();
};