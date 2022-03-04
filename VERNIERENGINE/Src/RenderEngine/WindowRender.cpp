#include "WindowRender.h"
//#include "OgreShaderGenerator.h"
#include <Ogre.h>
#include <SDL.h>
#include <SDL_syswm.h>
#include <assert.h>
#include <iostream>

std::unique_ptr<WindowRender>  WindowRender::_instance;

WindowRender::WindowRender(std::string name) :_wName(name)
{
	setUpOgreRoot();
}

void WindowRender::setUpOgreRoot()
{
	SDL_Init(SDL_INIT_EVERYTHING);
#ifdef _DEBUG
	_root = new Ogre::Root(/*"plugins_d.cfg"*/);
#else
	_root = new Ogre::Root();

#endif // _DEBUG
	if (_root->showConfigDialog(nullptr) || _root->restoreConfig())
		return;
	_root->initialise(false);
	setUpWindow();
	_mSceneManager = _root->createSceneManager();
		
	_mSceneManager->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

	
	/*if (Ogre::RTShader::ShaderGenerator::initialize())
	{
		Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
		shadergen->addSceneManager(_mSceneManager);
	}*/

	_mSceneManager->setAmbientLight(Ogre::ColourValue(.3, .3, .3));
}

void WindowRender::setUpWindow()
{
	//En caso de que no se hubiese iniciado el video nos aseguramos de ello
	if (!SDL_WasInit(SDL_INIT_VIDEO))
		SDL_InitSubSystem(SDL_INIT_VIDEO);

	Uint32 flags = SDL_WINDOW_ALLOW_HIGHDPI;

	_sDLWindow = SDL_CreateWindow(_wName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width_, screen_height_, flags);

	SDL_SysWMinfo wmInfo;
	SDL_VERSION(&wmInfo.version);
	if (SDL_GetWindowWMInfo(_sDLWindow, &wmInfo) == SDL_FALSE) {
		OGRE_EXCEPT(Ogre::Exception::ERR_INTERNAL_ERROR,
			"No se ha podido obtener la informacion de la ventana de SDL",
			"BaseApplication::setup");
	}

	Ogre::NameValuePairList params;
	params["FSAA"] = true;
	params["vsync"] = true;
	params["gamma"] = true;
	params["externalWindowHandle"] = Ogre::StringConverter::toString(size_t(wmInfo.info.win.window));

	_rWindow = _root->createRenderWindow(_wName.c_str(), screen_width_, screen_height_, false, &params);

	SDL_SetWindowGrab(_sDLWindow, SDL_bool(false));
	//SDL_ShowCursor(false);//De momento que se vea si se quiere ocultar desmutear esta linea
}

bool WindowRender::setUpInstance(std::string name)
{
	assert(_instance.get() == nullptr);
	_instance.reset(new WindowRender(name));
	return _instance.get();
}

WindowRender* WindowRender::getInstance()
{
	assert(_instance.get() != nullptr);
		return _instance.get();
}

void WindowRender::closeWindow()
{
}

WindowRender::~WindowRender()
{
	_root->destroySceneManager(_mSceneManager);
	delete _root;
}