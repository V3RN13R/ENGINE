#include "SoundComponent.h"
#include "ENGINE.h"
#include "SoundManager.h"

SoundComponent::SoundComponent(std::map<std::string, std::string> args, Entity* ent) : Component(ent)
{
    auto iter = args.begin();
    while (iter != args.end()) {
        _sounds[iter->first] = { iter->second, -1 };
        ++iter;
    }
}

void SoundComponent::playMusic(std::string s, float volume)
{
    VernierEngine::getInstance()->getSoundMng()->createSound(_sounds[s].first, false, true, false);
    playsound(s, volume);
}

void SoundComponent::playsound(std::string s, float volume)
{
	_sounds[s].second = VernierEngine::getInstance()->getSoundMng()->playSound(_sounds[s].first, volume);
}

void SoundComponent::stopSound(std::string sound)
{
    VernierEngine::getInstance()->getSoundMng()->stopChannel(_sounds[sound].second);
}

void SoundComponent::stopAllSounds()
{
    auto iter = _sounds.begin();
    while (iter != _sounds.end()) {
        stopSound(iter->first);
        ++iter;
    }
}

