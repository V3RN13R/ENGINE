#pragma once

#include "Component.h"
#include <string>
#include <map>

class SoundComponent : public Component
{
private: 
	std::map<std::string, std::pair<std::string, int>> _sounds;
public:
	SoundComponent(std::map<std::string, std::string> args, Entity* ent);
	void playMusic(std::string s, float volume = 1.0f);
	void playsound(std::string s, float volume = 1.0f);
	void stopSound(std::string sound);
	void stopAllSounds();
};