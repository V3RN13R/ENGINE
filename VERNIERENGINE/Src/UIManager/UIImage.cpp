#include "UIImage.h"
#include "OgreOverlay.h"
#include "OgreOverlayManager.h"
#include "OgreOverlayContainer.h"

UIImage::UIImage(std::string name, int order, std::string image) {
	_overlayCont = static_cast<Ogre::OverlayContainer*>(_overlayMng->createOverlayElement("Panel", " PanelName" + std::to_string(order)));
	_overlayCont->setMetricsMode(Ogre::GMM_PIXELS);
	_overlayCont->setDimensions(500, 500);
	_overlayCont->setPosition(-100, -100);
	_overlayCont->setMaterialName(image);

	_overlay = _overlayMng->create(name + std::to_string(order));
	_overlay->add2D(_overlayCont);
	_overlayCont->show();
}

void UIImage::show() { 
	_overlayCont->show();
}

void UIImage::hide() {
	_overlayCont->hide();
}