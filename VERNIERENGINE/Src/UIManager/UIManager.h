#pragma once

#include <functional>
#include <string>
#include <memory>

namespace Ogre {
	class RenderWindow;
	class RenderTarget;
	class Root;
}

namespace CEGUI
{
	class OgreRenderer;
	class System;
	class Window;
	class GUIContext;
	class WindowManager;
	class SchemeManager;
	class FontManager;
	class EventArgs;
}

class UIManager {

public:
	static UIManager* instance();
	static bool init();

	UIManager(){}
	~UIManager(){}

	void setup(Ogre::RenderWindow* renderWindow);

	//void setup(Ogre::RenderWindow* renderWindow);
	void destroy();

	bool render(double d);
	void loadScheme(std::string filename);
	void setFont(std::string filename);

	CEGUI::Window* createWidget(std::string type, std::string name, std::pair<float, float> pos = { 0,0 }, std::pair<float, float> size = { 100,100 });

	void addWidget(CEGUI::Window* window);
	void removeWidget(CEGUI::Window* window);
	void destroyWidget(CEGUI::Window* window);
	void setMouseVisibility(bool visible);
	void resizeWindow(int width, int height);
	
	//// Getters
    //Ogre::RenderWindow* getRenderer() { return m_renderer; }
	//const CEGUI::GUIContext* getContext() { return _context; }
private:
	static std::unique_ptr<UIManager> _instance;

	CEGUI::System* _system = nullptr;
	CEGUI::WindowManager* _windowMngr = nullptr;
	CEGUI::SchemeManager* _schemeMngr = nullptr;
	CEGUI::FontManager* _fontMngr = nullptr;
	CEGUI::OgreRenderer* _ogreRenderer = nullptr;

    Ogre::RenderWindow* m_renderer=nullptr;

	CEGUI::Window* _windowRoot = nullptr;
	CEGUI::GUIContext* _context = nullptr;


	void setUpResources();
};
// ceguibase_d
// ogreguirenderer_d