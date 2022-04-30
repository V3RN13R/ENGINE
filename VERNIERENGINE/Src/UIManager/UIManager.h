#pragma once

namespace Ogre {
	class OverlayManager;
	class OverlaySystem;
	class Overlay;
}

class UIManager {
private:
	Ogre::OverlayManager* _overlayMng;
	Ogre::OverlaySystem* _overlaySys;
	Ogre::Overlay* _overlay;
	static UIManager* _instance;
public:
	UIManager();
	~UIManager() {}
	void initOverlaySystem();
	static UIManager* setUpInstance();
	static UIManager* getInstance();
};