#include "WindowRender.h"
//#include "OgreShaderGenerator.h"
#include <Ogre.h>
#include <SDL.h>
#include <SDL_syswm.h>
#include <assert.h>
#include <iostream>
#include "RenderMain.h"
#include <SDL_render.h>
//std::unique_ptr<WindowRender>  WindowRender::_instance;


#include "OgreDefaultDebugDrawer.h"
#include "../Common/Light.h"
#include "../Common/ENGINE.h"
#include "checkML.h"

void WindowRender::setUpOgreRoot(const std::string& name)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	_root = VernierEngine::getInstance()->getRenderMain()->getRoot();
	//_root->showConfigDialog(NULL);
	if (!_root->showConfigDialog(NULL))
		return;


	_root->initialise(false);
	setUpWindow(name);
	_mSceneManager = VernierEngine::getInstance()->getRenderMain()->getSceneManager();

	//_mSceneManager->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

	/*if (Ogre::RTShader::ShaderGenerator::initialize())
	{
		Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
		shadergen->addSceneManager(_mSceneManager);
	}*/

	//_mSceneManager->setAmbientLight(Ogre::ColourValue(.5, .5, .5)); //Color base (gris)
}

void WindowRender::setUpWindow(const std::string& name)
{
	//En caso de que no se hubiese iniciado el video nos aseguramos de ello
	if (!SDL_WasInit(SDL_INIT_VIDEO))
		SDL_InitSubSystem(SDL_INIT_VIDEO);

	Uint32 flags = SDL_WINDOW_ALLOW_HIGHDPI;
	_name = name;
	_sDLWindow = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1900, 1060, flags);

	//S_sdlwindow2 = SDL_CreateWindow("Interfaz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, flags);
	//Create the renderer

	SDL_SysWMinfo wmInfo;
	SDL_VERSION(&wmInfo.version);
	if (SDL_GetWindowWMInfo(_sDLWindow, &wmInfo) == SDL_FALSE) {
		OGRE_EXCEPT(Ogre::Exception::ERR_INTERNAL_ERROR,
			"No se ha podido obtener la informacion de la ventana de SDL",
			"BaseApplication::setup");
	}

	Ogre::NameValuePairList params;
	//params["FSAA"] = true;
	params["vsync"] = true;
	//params["gamma"] = true;
	params["externalWindowHandle"] = Ogre::StringConverter::toString(size_t(wmInfo.info.win.window));

	_rWindow = _root->createRenderWindow(_name, screen_width_, screen_height_, false, &params);
	//_rWindow->setActive(true);
	//_rWindow->setVisible(true);
	SDL_SetWindowGrab(_sDLWindow, SDL_bool(false));
	//SDL_ShowCursor(false);//De momento que se vea si se quiere ocultar desmutear esta linea
}


bool WindowRender::setUpInstance(std::string name)
{
	//assert(_instance.get() == nullptr);
	//_instance.reset(new WindowRender(name));
	//return _instance.get();
	return false;
}

WindowRender* WindowRender::getInstance()
{
	assert(instance() != nullptr);
	return instance();
}

void WindowRender::updateWindow()
{
	_root->renderOneFrame();
}

void WindowRender::closeWindow()
{

}

// FALTA EL INPUT
bool WindowRender::ExitWindow() {
	bool continueRender = true;
	if (_sDLWindow == nullptr) {
		return false;  // SDL events not initialized

	}
	return continueRender;
}

Ogre::Light* WindowRender::createLight(Ogre::LightTypes type)
{
	Ogre::Light* light = _mSceneManager->createLight();
	light->setType((Ogre::Light::LightTypes)type);

	return light;
}

void WindowRender::setAmbientLight(float x, float y, float z)
{
	_mSceneManager->setAmbientLight(Ogre::ColourValue(x, y, z));
}



WindowRender::~WindowRender()
{
	_root->getRenderSystem()->destroyRenderWindow(_name);//esto borra la _rWindow
	delete _renderer;
	_root->destroySceneManager(_mSceneManager);
	SDL_DestroyWindow(_sDLWindow);
	SDL_Quit();
	_root->shutdown();
	delete _root;
}