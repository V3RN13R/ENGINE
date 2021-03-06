#include "Camera.h"
#include "Entity.h"
#include "Scene.h"
#include "GameStateMachine.h"
#include "RenderMain.h"
#include "Scene.h"
#include "Transform.h"
#include "OgreMath.h"
#include "Transform.h"
#include "SoundComponent.h"
#include "InputManager.h"
#include <iostream>
#include <Ogre.h>
#include <math.h>
#include <ENGINE.h>


Camera::Camera(std::map<std::string, std::string> args, Entity* ent) : Component(ent),
	_bckgColor(args["BackgroundColor"]), _camName(args["CameraName"]), _looking(args["Looking"]), _posRel(args["PosRel"]), _sensibilidad(std::stof(args["Sensibilidad"])) {
	_nearClipDist = std::stof(args["NearClipDistance"]);
	_farClipDist = std::stof(args["FarClipDistance"]);
	_aspectRatio = std::stof(args["AspectRatio"]);
}

Camera::~Camera() {
	
	RenderMain::getInstance()->getSceneManager()->destroyCamera(_camera);
}

void Camera::setBckgColor(Vector3D color)
{
	_bckgColor = color;
	_vp->setBackgroundColour(Ogre::ColourValue(_bckgColor.getX(), _bckgColor.getY(), _bckgColor.getZ()));
}


void Camera::start() {

	_camera = RenderMain::getInstance()->getSceneManager()->createCamera(_camName);

	_camera->setNearClipDistance(_nearClipDist);
	_camera->setFarClipDistance(_farClipDist);
	_camera->setAutoAspectRatio(true);
	mNodeCamera = entity_->getNode()->createChildSceneNode();
	mNodeCamera->attachObject(_camera);

	mNodeCamera->setPosition(_posRel.getX(), _posRel.getY(), _posRel.getZ());
	mNodeCamera->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);

	if (_vp && RenderMain::getInstance()->getRenderWindow()->hasViewportWithZOrder(0))
		RenderMain::getInstance()->getRenderWindow()->removeViewport(0);
	_vp= RenderMain::getInstance()->getRenderWindow()->addViewport(_camera, RenderMain::getInstance()->getRenderWindow()->getNumViewports());

	_vp->setBackgroundColour(Ogre::ColourValue(_bckgColor.getX(), _bckgColor.getY(), _bckgColor.getZ()));
	_aspectRatio = Ogre::Real(_vp->getActualWidth()) / Ogre::Real(_vp->getActualHeight());
	_camera->setAspectRatio(_aspectRatio);

	_camTr = (Transform*)entity_->getComponent("Transform");
}

void Camera::lookAt(Vector3D v) {
	mNodeCamera->lookAt(Ogre::Vector3(v.getX(), v.getY(), v.getZ()), Ogre::Node::TS_WORLD, Ogre::Vector3::NEGATIVE_UNIT_Z);
}
void Camera::yaw(float d){
	mNodeCamera->yaw(Ogre::Degree(d));
}
void Camera::pitch(float d) {
	mNodeCamera->pitch(Ogre::Degree(d));

}
void Camera::roll(float d) {
	mNodeCamera->roll(Ogre::Degree(d));

}