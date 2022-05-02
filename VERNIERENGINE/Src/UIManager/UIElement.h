#pragma once
#include <string>

namespace Ogre {
	class OverlayContainer;
	class OverlayManager;
	class OverlaySystem;
	class Overlay;
}

enum MetricsMode {
	GMM_RELATIVE, GMM_PIXELS, GMM_RELATIVE_ASPECT_ADJUSTED
};

class UIElement {
private:
	int _x, _y;
	int _w, _h;
	std::string _material;

protected:
	Ogre::OverlayManager* _overlayMng;
	Ogre::OverlaySystem* _overlaySys;
	Ogre::OverlayContainer* _overlayCont;
	Ogre::Overlay* _overlay;

public:
	// CONSTRUCTORA / DESTRUCTORA
	UIElement();
	~UIElement(){}

	// MUESTRA EN PANTALLA EL OVERLAY
	void show();

	// SETTERS
	void setMetricsMode(MetricsMode mmode);
	void setPosition(int x, int y);
	void setDimensions(int dx, int dy);
	void setSize(int w, int h);
	void setMaterial(std::string material);
	void setRenderOrder(int z);

	// GETTERS
	std::pair<int, int> getPosition() { return { _x, _y }; }
	std::pair<int, int> getSize()     { return { _w, _h }; }
	std::string getMaterial()		  { return  _material; }
};