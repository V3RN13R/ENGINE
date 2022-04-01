#include "Camera.h"
#include "Entity.h"
#include "RenderMain.h"
#include <Ogre.h>


Camera::~Camera() {
	
	RenderMain::getInstance()->getSceneManager()->destroyCamera(_camera);
	//RenderMain::getInstance()->getSceneManager()->destroySceneNode(mNodeCamera);
	//delete _camera;
}

void Camera::setBckgColor(Vector3D color)
{
	_bckgColor = color;
	_vp->setBackgroundColour(Ogre::ColourValue(_bckgColor.getX(), _bckgColor.getY(), _bckgColor.getZ()));
}

void Camera::start() {
	_camera = RenderMain::getInstance()->getSceneManager()->createCamera("MainCam");

	_camera->setNearClipDistance(_nearClipDist);
	_camera->setFarClipDistance(_farClipDist);
	_camera->setAutoAspectRatio(true);
	mNodeCamera = entity_->getNode()->createChildSceneNode();
	mNodeCamera->attachObject(_camera);

	mNodeCamera->setPosition(0, 500, 1000);
	mNodeCamera->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);

	 _vp= RenderMain::getInstance()->getRenderWindow()->addViewport(_camera);

	_vp->setBackgroundColour(Ogre::ColourValue(_bckgColor.getX(), _bckgColor.getY(), _bckgColor.getZ()));
	_aspectRatio = Ogre::Real(_vp->getActualWidth()) / Ogre::Real(_vp->getActualHeight());
	_camera->setAspectRatio(_aspectRatio);
}