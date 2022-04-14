#include "Camera.h"
#include "Entity.h"
#include "RenderMain.h"
#include <Ogre.h>
#include "Transform.h"
#include "OgreMath.h"
#include <iostream>
#include <math.h>


const float M_PI = 3.1416;
const float toRadians = M_PI / 180.0;
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
	Entity::update();
	Transform* camTr = getComponent<Transform>();
	if (camTr != nullptr) {
		/*Vector3D nuevaPos = Vector3D(_monkePos->getX() + _monkeRadio * std::cos( _monkeAngle*toRadians), _monkePos->getY() + 0 , _monkePos->getZ() + _monkeRadio * std::sin(_monkeAngle*toRadians));
		camTr->setPosition(nuevaPos)*/;
		//camtTr para mover al nodo padre y mNodeCamera para mover la posición del nodo hijo que es donde se encuentra la cámara
		camTr->setPosition(Vector3D(_monkePos->getX(), _monkePos->getY() + 500, _monkePos->getZ()));
		mNodeCamera->lookAt(Ogre::Vector3(_monkePos->getX(), _monkePos->getY(), _monkePos->getZ()), Ogre::Node::TS_WORLD, Ogre::Vector3::NEGATIVE_UNIT_Z);
	}
};


void Camera::start() {
	_camera = RenderMain::getInstance()->getSceneManager()->createCamera("MainCam");

	_camera->setNearClipDistance(_nearClipDist);
	_camera->setFarClipDistance(_farClipDist);
	_camera->setAutoAspectRatio(true);
	mNodeCamera = _oNode->createChildSceneNode();
	mNodeCamera->attachObject(_camera);
	//mNodeCamera->yaw(Ogre::Degree(90));

	mNodeCamera->setPosition(0, 500, _monkeRadio);
	mNodeCamera->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);

	 _vp= RenderMain::getInstance()->getRenderWindow()->addViewport(_camera);

	_vp->setBackgroundColour(Ogre::ColourValue(_bckgColor.getX(), _bckgColor.getY(), _bckgColor.getZ()));
	_aspectRatio = Ogre::Real(_vp->getActualWidth()) / Ogre::Real(_vp->getActualHeight());
	_camera->setAspectRatio(_aspectRatio);
}



void Camera::receiveEvent(MessageType msg, Entity* e) {
	std::cout << "Recive msg";
	Transform* camTr = getComponent<Transform>();
	switch (msg) {
		case MessageType::PULSA_Q:
			camTr->rotate(Vector3D(0, -5, 0));
			//_oNode->yaw(Ogre::Degree(-5));
			mNodeCamera->yaw(Ogre::Degree(5));
			_monkeAngle = (_monkeAngle - 5) % 360;
			//camTr->setRotation()
			std::cout << "AnguloCam mono: " << _monkeAngle << "\n";
			break;
		case MessageType::PULSA_E:
			camTr->rotate(Vector3D(0, 5, 0));
			//_oNode->yaw(Ogre::Degree(5));
			mNodeCamera->yaw(Ogre::Degree(-5));
			_monkeAngle = (_monkeAngle + 5) % 360;
			std::cout << "AnguloCam mono: " << _monkeAngle << "\n";
			break;
	}
}