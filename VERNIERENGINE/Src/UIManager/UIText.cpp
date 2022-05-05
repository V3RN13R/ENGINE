#include "UIText.h"

#include <OgreOverlayContainer.h>
#include <OgreOverlayManager.h>
#include <OgreTextAreaOverlayElement.h>
#include <OgreOverlay.h>
#include <OgreFont.h>
#include <OgreFontManager.h>
#include <OgreResourceManager.h>
#include "LuaManager.h"
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <SDL_render.h>
#include "checkML.h"
}

UIText::UIText(std::string overlayName, std::string fontName, int fontSize, int order, std::string text, int rT, int gT, int bT, int rD, int gD, int bD, int x, int y) : UIElement()
{
	//Initialization of everything that ogre needs to show something
	Ogre::OverlayContainer* panel = static_cast<Ogre::OverlayContainer*>(_overlayMng->createOverlayElement("Panel", "PanelName" + std::to_string(order)));
	panel->setMetricsMode(Ogre::GMM_PIXELS);
	panel->setPosition(x, y);
	panel->setDimensions(10000000, 10000000);

	_txt = static_cast<Ogre::TextAreaOverlayElement*>(_overlayMng->createOverlayElement("TextArea", fontName + std::to_string(order)));
	_txt->setMetricsMode(Ogre::GMM_PIXELS);
	_txt->setPosition(0, 0);
	_txt->setDimensions(10000000, 10000000);
#pragma region CARGA_FUENTE
	//Ogre::FontManager* fontMgr = Ogre::FontManager::getSingletonPtr();
	//// create a font resource
	Ogre::ResourcePtr font = Ogre::FontManager::getSingletonPtr()->getByName(fontName, "Fonts");
	if (!font) {
		lua_State* state = readFileLua("Fonts.lua");
		LuaRef refFont = readElementFromFile(state, fontName);
		std::string type;
		readVariable<std::string>(refFont, "type", &type);
		std::string source;
		readVariable<std::string>(refFont, "source", &source);
		std::string size;
		readVariable<std::string>(refFont, "size", &size);
		std::string res;
		readVariable<std::string>(refFont, "resolution", &res);
		font = Ogre::FontManager::getSingletonPtr()->create(fontName, "Fonts");
		// set as truetype
		font->setParameter("type", type);
		// set the .ttf file name
		font->setParameter("source", source);
		// set the size
		font->setParameter("size", size);
		// set the dpi
		font->setParameter("resolution", res);
		// load the ttf
		font->load();
	}
#pragma endregion
	_txt->setMetricsMode(Ogre::GMM_PIXELS);
	_txt->setCaption(text);
	_txt->setCharHeight(fontSize);
	_txt->setColourBottom(Ogre::ColourValue(rT, gT, bT, 1));
	_txt->setColourTop(Ogre::ColourValue(rD, gD, bD, 1));
	setFont(fontName);
	panel->addChild(_txt);
	// Create an overlay, and add the panel
	_overlay = _overlayMng->create(overlayName + std::to_string(order));
	_overlay->add2D(panel);

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

