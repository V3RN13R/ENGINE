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

void WindowRender::setUpOgreRoot()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	_root = RenderMain::getInstance()->getRoot();
	//_root->showConfigDialog(NULL);
	if (!_root->showConfigDialog(NULL))
		return;


	_root->initialise(false);
	setUpWindow();
	_mSceneManager = RenderMain::getInstance()->getSceneManager();

	//_mSceneManager->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

	/*if (Ogre::RTShader::ShaderGenerator::initialize())
	{
		Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
		shadergen->addSceneManager(_mSceneManager);
	}*/
	BORRAR();
	//_mSceneManager->setAmbientLight(Ogre::ColourValue(.3, .3, .3));
}

void WindowRender::setUpWindow()
{
	//En caso de que no se hubiese iniciado el video nos aseguramos de ello
	if (!SDL_WasInit(SDL_INIT_VIDEO))
		SDL_InitSubSystem(SDL_INIT_VIDEO);

	Uint32 flags = SDL_WINDOW_ALLOW_HIGHDPI;

	_sDLWindow = SDL_CreateWindow("Motor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width_, screen_height_, flags);

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

	_rWindow = _root->createRenderWindow("Motor", screen_width_, screen_height_, false, &params);
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
	_root->getRenderSystem()->destroyRenderWindow("Motor");//esto borra la _rWindow
	_root->destroySceneManager(_mSceneManager);
	SDL_DestroyWindow(_sDLWindow);
	SDL_Quit();
	delete _root;
}


void WindowRender::BORRAR() {
	//Ogre::Camera* mCamera;

	//mCamera = _mSceneManager->createCamera("MainCam");

	//mCamera->setNearClipDistance(1);
	//mCamera->setFarClipDistance(100000);
	//mCamera->setAutoAspectRatio(true);
	//Ogre::SceneNode* mNodeCamera = _mSceneManager->getRootSceneNode()->createChildSceneNode();
	//mNodeCamera->attachObject(mCamera);

	//mNodeCamera->setPosition(0, 500, 1000);
	//mNodeCamera->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);

	//Ogre::Viewport* vp = _rWindow->addViewport(mCamera);

	//vp->setBackgroundColour(Ogre::ColourValue(0, 0, 1));

	//mCamera->setAspectRatio(
	//	Ogre::Real(vp->getActualWidth()) /
	//	Ogre::Real(vp->getActualHeight()));
	_mSceneManager->setAmbientLight(Ogre::ColourValue(.5, .5, .5));
	Ogre::Light* luz = _mSceneManager->createLight("LuzAmbiente");
	luz->setType(Ogre::Light::LT_DIRECTIONAL);
	luz->setDiffuseColour(1, 1, 1);

	Ogre::SceneNode* mLightNode = _mSceneManager->getRootSceneNode()->createChildSceneNode("nLuz");

	mLightNode->attachObject(luz);

	mLightNode->setDirection(Ogre::Vector3(1, -1, -1));  //vec3.normalise();
	//Ogre::Entity* e = _mSceneManager->createEntity(Ogre::SceneManager::PrefabType::PT_SPHERE);

	//Ogre::SceneNode* node = _mSceneManager->getRootSceneNode()->createChildSceneNode();

	//node->attachObject(e);

	//node->setPosition(0, 100, 0);

	/*Ogre::Entity* e2 = _mSceneManager->createEntity(Ogre::SceneManager::PrefabType::PT_PLANE);
	Ogre::SceneNode* node2 = _mSceneManager->getRootSceneNode()->createChildSceneNode();
	node2->attachObject(e2);
	node2->setPosition(0, -100, 0);*/

}