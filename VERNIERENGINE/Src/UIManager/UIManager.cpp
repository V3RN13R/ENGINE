#include "UIManager.h"
#include "OgreOverlay.h"
#include "OgreOverlayPrerequisites.h"
#include "OgreTextAreaOverlayElement.h"
#include "OgreFontManager.h"
#include "OgreOverlayContainer.h"
#include "OgreOverlayElement.h"
#include "OgreOverlayManager.h"
#include "OgreSceneManager.h"
#include "OgreOverlaySystem.h"
#include "../RenderEngine/WindowRender.h"

UIManager* UIManager::_instance = nullptr;

UIManager::UIManager() {
}

UIManager* UIManager::setUpInstance()
{
    assert(_instance == nullptr);
    _instance = new UIManager();
    return _instance;
}

UIManager* UIManager::getInstance()
{
    assert(_instance != nullptr);
    return _instance;
}


void UIManager::createPanel() {
    // Create a panel

    Ogre::OverlayContainer* panel = static_cast<Ogre::OverlayContainer*>(_overlayMng->createOverlayElement("Panel", "PanelName"));
    panel->setMetricsMode(Ogre::GMM_PIXELS);
    panel->setPosition(10, 10);
    panel->setDimensions(100, 100);
    // panel->setMaterialName("Material/blanco"); // Optional background material

    panel->setMaterialName("BaseWhite");

     // Create an overlay, and add the panel
    _instance->_overlay->add2D(panel);

    // Show the overlay
    _instance->_overlay->show();
}

bool UIManager::init() {
    return true;
}

void UIManager::initOverlaySystem() {
    _instance->_overlaySys = new Ogre::OverlaySystem();
    _instance->_overlayMng = Ogre::OverlayManager::getSingletonPtr();
    _instance->_overlay = _overlayMng->create("OverlayName");

    WindowRender::getInstance()->getSceneManager()->addRenderQueueListener(_instance->_overlaySys);
}