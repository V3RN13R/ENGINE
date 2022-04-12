#pragma once

#include <CEGUI.h>
#include <OgreRenderSystem.h>
#include <RendererModules/Ogre/Renderer.h>
#include <OgreRenderWindow.h>
#include <glm/glm.hpp>
#include <Window.h>
#include <GUIContext.h>
#include <SDL.h>

class UIManager {
public:
	void init(const std::string& resourceDirectory);
	void destroy();

	void draw();

	void loadScheme(const std::string& schemeFile);
	void setFont(const std::string& fontFile);
	//SDL_Window* createWidget(const std::string& type, const glm::vec4& destRectPerc, const glm::vec4& destRectPix, const std::string& name = "");
	//static void setWidgetDestRect(SDL_Window* widget, const glm::vec4& destRectPerc, const glm::vec4& destRectPix);

	// Getters
    Ogre::RenderWindow* getRenderer() { return m_renderer; }
	const CEGUI::GUIContext* getContext() { return m_context; }
private:
	Ogre::Root* _root = nullptr;
    Ogre::RenderWindow* m_renderer;
	CEGUI::GUIContext* m_context = nullptr;
	SDL_Window* m_root = nullptr;
};
// ceguibase_d
// ogreguirenderer_d