#include "UIManager.h"
#include "UIImage.h"
#include "UIText.h"
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
#include "checkML.h"
#include "OgreFont.h"
#include "OgreResourceManager.h"
#include "../Common/GameStateMachine.h"
#include "../Common/Scene.h"

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

void UIManager::deleteInstance() {
    delete _instance;
}

void UIManager::clearOverlay() {
    if (!_overlayElements.empty()) {
        for (UIElement* elem : _overlayElements) {
            elem->hide();
            delete elem;
            elem = nullptr;
        }
        _overlayElements.clear();
    }
}

UIManager::~UIManager() {


    clearOverlay();
    _overlayMng->destroyAll();
    _overlay = nullptr;
    delete _overlaySys;

    //delete _overlayMng;


}


void UIManager::initOverlaySystem() {
    _instance->_overlaySys = new Ogre::OverlaySystem();
    _instance->_overlayMng = Ogre::OverlayManager::getSingletonPtr();
    _instance->_overlay = _overlayMng->create("OverlayName");
    _instance->_num = 0;
   Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
    WindowRender::getInstance()->getSceneManager()->addRenderQueueListener(_instance->_overlaySys);
}

void UIManager::start() {
}

UIImage* UIManager::addImage(std::string overlayname, std::string image){
    auto imagen = new UIImage(overlayname, _num, image);
    _instance->_overlayElements.push_back(imagen);
    GameStateMachine::getInstance()->getScene()->addUIElem(imagen);
    _num++;
    return imagen;
}
void UIManager::addText(UIText* txt) {
    GameStateMachine::getInstance()->getScene()->addUIElem(txt);
}
UIText* UIManager::addText(std::string overlayName, std::string fontName, int fontSize, int order, std::string text, int rT, int gT, int bT, int rD, int gD, int bD, int x, int y) {
    //Ogre::FontManager::getSingleton().getByName("DejaVu/SerifCondensedItalic");
    auto texto = new UIText(overlayName, fontName, fontSize, _num, text, rT, gT, bT, rD, gD, bD, x, y);
    _instance->_overlayElements.push_back(texto);
    _num++;
    GameStateMachine::getInstance()->getScene()->addUIElem(texto);
    return texto;
}
UIText* UIManager::createText(std::string overlayName, std::string fontName, int fontSize, int order, std::string text, int rT, int gT, int bT, int rD, int gD, int bD, int x, int y) {
    //Ogre::FontManager::getSingleton().getByName("DejaVu/SerifCondensedItalic");
    auto texto = new UIText(overlayName, fontName, fontSize, _num, text, rT, gT, bT, rD, gD, bD, x, y);
    _instance->_overlayElements.push_back(texto);
    _num++;
    return texto;
}
int UIManager::getNum() {
    return _num;
}

//UIImage* UIManager::getImage(std::string image) {
//    auto it = _overlayElements.begin();
//    for (it; it != _overlayElements.end(); it++) {
//        if (static_cast<UIImage*>(*it)->getName() == image) 
//            return static_cast<UIImage*>(*it);
//    }
//    if (it == _overlayElements.end() || _overlayElements.size() == 0) 
//        return nullptr;
//}

//void UIManager::createPanel() {
//    // Create a panel
//
//    Ogre::OverlayContainer* panel = static_cast<Ogre::OverlayContainer*>(_overlayMng->createOverlayElement("Panel", "PanelName"));
//    panel->setMetricsMode(Ogre::GMM_PIXELS);
//    panel->setPosition(10, 10);
//    panel->setDimensions(100, 100);
//    // panel->setMaterialName("Material/blanco"); // Optional background material
//
//    panel->setMaterialName("BaseWhite");
//
//     // Create an overlay, and add the panel
//    _instance->_overlay->add2D(panel);
//
//    // Show the overlay
//    _instance->_overlay->show();
//}