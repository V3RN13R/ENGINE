#include "UIText.h"

#include <OgreOverlayContainer.h>
#include <OgreOverlayManager.h>
#include <OgreTextAreaOverlayElement.h>
#include <OgreOverlay.h>
#include <OgreFont.h>
#include <OgreFontManager.h>
#include <OgreResourceManager.h>

UIText::UIText(std::string overlayName, std::string fontName, int fontSize, int order, std::string text, int r, int g, int b, int x, int y) : UIElement()
{
	//Initialization of everything that ogre needs to show something
	_txt = static_cast<Ogre::TextAreaOverlayElement*>(_overlayMng->createOverlayElement("Panel", fontName + std::to_string(order)));
	_txt->setMetricsMode(Ogre::GMM_PIXELS);
	_txt->setPosition(x, y);
	_txt->setDimensions(fontSize, fontSize);

	_txt->setMetricsMode(Ogre::GMM_PIXELS);
	_txt->setCaption(text);
	_txt->setCharHeight(fontSize);
	_txt->setColourBottom(Ogre::ColourValue(0.5, 0.5, 0.5, 1));
	_txt->setColourTop(Ogre::ColourValue(0.5, 0.5, 0.5, 1));

	// Create an overlay, and add the panel
	_overlay = _overlayMng->create(overlayName);
	_overlay->add2D((Ogre::OverlayContainer*)_txt);

}


void UIText::setPosition(int x, int y) {
	_txt->setPosition(x, y);
}

void UIText::setSize(int w, int h) {
	_txt->setDimensions(w, h);
}

void UIText::setFont(std::string fontName) {
	_txt->setFontName(fontName);
}

void UIText::setFontSize(int newSize) {
	_txt->setCharHeight(newSize);
}

void UIText::setText(std::string newText) {
	_txt->setCaption(newText);
}

void UIText::setTextColor(int r, int g, int b) {
	_txt->setColourBottom(Ogre::ColourValue(r, g, b));
	_txt->setColourTop(Ogre::ColourValue(r, g, b));
}

std::pair<int, int> UIText::getSize()
{
	return { _txt->getWidth(), _txt->getHeight() };
}

