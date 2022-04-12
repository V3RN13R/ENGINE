#include "Camera.h"
#include "Entity.h"
#include "RenderMain.h"
#include <Ogre.h>
#include "Transform.h"
#include "OgreMath.h"
#include <iostream>

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



void Camera::setMonkePos(Vector3D* monPos) {
	_monkePos = monPos;
}


void Camera::update() {
	Transform* camTr = entity_->getComponent<Transform>();
	if (camTr != nullptr) {
		Vector3D nuevaPos = Vector3D(_monkePos->getX() + _monkeRadio * std::cos(_monkeAngle), _monkePos->getY() + 10 , _monkePos->getZ() + _monkeRadio * std::sin(_monkeAngle));
		camTr->setPosition(nuevaPos);
		setLooking(*_monkePos);
	}
};


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



void Camera::receiveEvent(MessageType msg) {
	std::cout << "Recive msg";
	switch (msg) {
	case MessageType::PULSA_Q:

		_monkeAngle = (_monkeAngle + 1) % 360;
		std::cout << "AnguloCam mono: " << _monkeAngle << "\n";
		break;
	case MessageType::PULSA_E:
		_monkeAngle = (_monkeAngle + 1) % 360;
		std::cout << "AnguloCam mono: " << _monkeAngle << "\n";

		break;
	}
}