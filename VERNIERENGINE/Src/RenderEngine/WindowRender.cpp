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
	//_root->showConfigDialog(NULL);
	if (!_root->showConfigDialog(NULL))
		return;


	_root->initialise(false);
	setUpWindow();
	_mSceneManager = _root->createSceneManager();
		
	//_mSceneManager->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

	/*if (Ogre::RTShader::ShaderGenerator::initialize())
	{
		Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
		shadergen->addSceneManager(_mSceneManager);
	}*/
	BORRAR();
	//_mSceneManager->setAmbientLight(Ogre::ColourValue(.3, .3, .3));
	//--------------------------------BORRAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR----------------------------------
	_root->startRendering();
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
	//params["FSAA"] = true;
	params["vsync"] = true;
	//params["gamma"] = true;
	params["externalWindowHandle"] = Ogre::StringConverter::toString(size_t(wmInfo.info.win.window));

	_rWindow = _root->createRenderWindow(_wName.c_str(), screen_width_, screen_height_, false, &params);
	//_rWindow->setActive(true);
	//_rWindow->setVisible(true);
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
void WindowRender::BORRAR() {
	Ogre::Camera* mCamera;

	mCamera = _mSceneManager->createCamera("MainCam");

	mCamera->setNearClipDistance(1);
	mCamera->setFarClipDistance(100000);
	mCamera->setAutoAspectRatio(true);
	Ogre::SceneNode* mNodeCamera = _mSceneManager->getRootSceneNode()->createChildSceneNode();
	mNodeCamera->attachObject(mCamera);

	mNodeCamera->setPosition(0, 500, 1000);
	mNodeCamera->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);

	Ogre::Viewport* vp = _rWindow->addViewport(mCamera);

	vp->setBackgroundColour(Ogre::ColourValue(0, 0, 1));

	mCamera->setAspectRatio(
		Ogre::Real(vp->getActualWidth()) /
		Ogre::Real(vp->getActualHeight()));
	_mSceneManager->setAmbientLight(Ogre::ColourValue(.5, .5, .5));
	Ogre::Light* luz = _mSceneManager->createLight("Luz");
	luz->setType(Ogre::Light::LT_DIRECTIONAL);
	luz->setDiffuseColour(1, 1, 1);

	Ogre::SceneNode* mLightNode = _mSceneManager->getRootSceneNode()->createChildSceneNode("nLuz");

	mLightNode->attachObject(luz);

	mLightNode->setDirection(Ogre::Vector3(1, -1, -1));  //vec3.normalise();
	Ogre::Entity* e = _mSceneManager->createEntity(Ogre::SceneManager::PrefabType::PT_SPHERE);

	Ogre::SceneNode* node = _mSceneManager->getRootSceneNode()->createChildSceneNode();

	node->attachObject(e);

	node->setPosition(0, 100, 0);

	Ogre::Entity* e2 = _mSceneManager->createEntity(Ogre::SceneManager::PrefabType::PT_PLANE);

	Ogre::SceneNode* node2 = _mSceneManager->getRootSceneNode()->createChildSceneNode();

	node2->attachObject(e2);

	node2->setPosition(0, -100, 0);
}