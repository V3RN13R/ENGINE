#include "UIElement.h"
#include "OgreOverlay.h"
#include "OgreOverlayManager.h"
#include "OgreOverlayElement.h"
#include "OgreOverlayContainer.h"

UIElement::UIElement() {
	_overlayMng = Ogre::OverlayManager::getSingletonPtr();
}


void UIElement::show() {
	_overlay->show();
}

void UIElement::setMetricsMode(MetricsMode mmode) {
	switch (mmode) {
	case GMM_PIXELS:
		_overlayCont->setMetricsMode(Ogre::GMM_PIXELS);
		break;
	case GMM_RELATIVE:
		_overlayCont->setMetricsMode(Ogre::GMM_RELATIVE);
		break;
	case GMM_RELATIVE_ASPECT_ADJUSTED:
		_overlayCont->setMetricsMode(Ogre::GMM_RELATIVE_ASPECT_ADJUSTED);
	}
}

void UIElement::setPosition(int x, int y) {
	_overlayCont->setPosition(x, y);

	_x = x;
	_y = y;
}

void UIElement::setDimensions(int dx, int dy) {
	_overlayCont->setDimensions(dx, dy);
}

void UIElement::setSize(int w, int h) {
	_overlayCont->setWidth(w);
	_overlayCont->setHeight(h);

	_w = w;
	_h = h;
}

void UIElement::setMaterial(std::string material) {
	_overlayCont->setMaterialName(material);

	_material = material;
}

void UIElement::setRenderOrder(int z) {
	_overlay->setZOrder(z);
}