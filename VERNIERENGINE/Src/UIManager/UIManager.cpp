#include "UIManager.h"
#include "RenderMain.h"
//#include <DefaultResourceProvider.h>
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>
#include <OgreRenderSystem.h>
#include <OgreRenderWindow.h>
#include <CEGUI/GUIContext.h>
#include <SDL.h>

std::unique_ptr<UIManager>  UIManager::_instance;

bool UIManager::init() {
	assert(_instance == nullptr);
	_instance.reset(new UIManager());
	return _instance.get();
}

UIManager* UIManager::instance() {
	assert(_instance != nullptr);
	return _instance.get();
}

void UIManager::setup(Ogre::RenderWindow* renderWindow) {
	_ogreRenderer = &CEGUI::OgreRenderer::bootstrapSystem(*renderWindow);
	m_renderer = RenderMain::getInstance()->getRenderWindow();
	//loadScheme()
	CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme");
	CEGUI::SchemeManager::getSingleton().createFromFile("WindowsLook.scheme");

	//CEGUI::System::getSingleton().getDefaultGUIContext().setDefaultFont("DejaVuSans-10");
	CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");

	_windowRoot = CEGUI::WindowManager::getSingleton().createWindow("DefaultWindow", "_MasterRoot");
	_windowRoot->setUsingAutoRenderingSurface(true);
	CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(_windowRoot);

	setUpResources();
}

void UIManager::destroy()
{
	//CEGUI::System::getSingleton().destroyGUIContext(*_context);
}

void UIManager::setUpResources()
{
	//CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");
	//CEGUI::Scheme::setDefaultResourceGroup("schemes");
	//CEGUI::Font::setDefaultResourceGroup("fonts");
	//CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeel");
	//CEGUI::WindowManager::setDefaultResourceGroup("layouts");
}

void UIManager::loadScheme(std::string filename)
{
	//CEGUI::SchemeManager::getSingleton().createFromFile(filename);
}

void UIManager::setFont(std::string filename)
{
	//CEGUI::System::getSingleton().getDefaultGUIContext().setDefaultFont(filename);
}

CEGUI::Window* UIManager::createWidget(std::string type, std::string name, std::pair<float, float> pos, std::pair<float, float> size)
{
	//CEGUI::Window* myImageWindow = CEGUI::WindowManager::getSingleton().createWindow(type, name);
	//myImageWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(pos.first, 0.0), CEGUI::UDim(pos.second, 0.0)));
	//myImageWindow->setSize(CEGUI::USize(CEGUI::UDim(0.0, size.first), CEGUI::UDim(0.0, size.second)));
	////myImageWindow->setProperty("Image", "TaharezLook/full_image");
	//CEGUI::System::getSingleton().getDefaultGUIContext().getRootWindow()->addChild(myImageWindow);

	return nullptr;//myImageWindow;
}

void UIManager::addWidget(CEGUI::Window* window)
{
	//CEGUI::System::getSingleton().getDefaultGUIContext().getRootWindow()->addChild(window);
}

void UIManager::removeWidget(CEGUI::Window* window)
{
	//_windowRoot->removeChild(window);
}

void UIManager::destroyWidget(CEGUI::Window* window)
{
	//removeWidget(window);
	//CEGUI::WindowManager::getSingleton().destroyWindow(window);
}

void UIManager::setMouseVisibility(bool visible)
{
	//if (visible) CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().show();
	//else CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().hide();
}

void UIManager::resizeWindow(int width, int height)
{
	//CEGUI::Sizef size = CEGUI::Sizef(width, height);
	//CEGUI::System::getSingleton().notifyDisplaySizeChanged(size);
}

bool UIManager::render(double deltaTime)
{
	return false;
}