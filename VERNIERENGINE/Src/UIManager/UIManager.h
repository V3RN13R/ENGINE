#pragma once
#include "UIElement.h"
#include <vector>
#include <string>

class UIImage;

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
	std::vector<UIElement*> _overlayElements;
	int _num;
	static UIManager* _instance;

public:
	UIManager();
	~UIManager() {}
	void initOverlaySystem();
	void start();
	static UIManager* setUpInstance();
	static UIManager* getInstance();
	UIImage* addImage(std::string overlayName, std::string image);
	// UIImage* getImage(std::string imageName);
};