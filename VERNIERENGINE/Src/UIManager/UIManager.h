#pragma once
#include "UIElement.h"
#include <vector>
#include <string>

class UIImage;
class UIText;

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
	~UIManager();
	static UIManager* setUpInstance();
	static UIManager* getInstance();
	static void deleteInstance();
	void clearOverlay();

	void initOverlaySystem();
	void start();
	int getNum();
	UIImage* addImage(std::string overlayName, std::string image);
	UIText* addText(std::string overlayName, std::string fontName, int fontSize, int order, std::string text, int r, int g, int b, int x, int y);
	// UIImage* getImage(std::string imageName);
};