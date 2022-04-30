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
	static UIManager* setUpInstance();
	static UIManager* getInstance();
	bool init();
	void createPanel();
	void initOverlaySystem();
};