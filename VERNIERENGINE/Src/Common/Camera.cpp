#include "Camera.h"
#include "Entity.h"
#include "RenderMain.h"
#include "Scene.h"
#include <Ogre.h>
#include "Transform.h"
#include "Component.h"
#include "OgreMath.h"
#include "Transform.h"
#include <iostream>
#include <math.h>


const float toRadians = M_PI / 180.0;
const float toAngles = 180.0 / M_PI;

Camera::Camera(std::map<std::string, std::string> args, Entity* ent) : Component(ent),
	_bckgColor(args["BackgroundColor"]), _camName(args["CameraName"]), _looking(args["Looking"]) {
	_nearClipDist = std::stof(args["NearClipDistance"]);
	_farClipDist = std::stof(args["FarClipDistance"]);
	_aspectRatio = std::stof(args["AspectRatio"]);
	mono = entity_->getScene()->getObjectWithName(args["Entity"]);
}

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
	_monkePos = &(static_cast<Transform*>(mono->getComponent("Transform")))->getPos();
	std::cout << "Pos camera: " << _monkePos->getY() << "\n";
	if (_camTr != nullptr) {
		/*Vector3D nuevaPos = Vector3D(_monkePos->getX() + _monkeRadio * std::cos( _monkeAngle*toRadians), _monkePos->getY() + 0 , _monkePos->getZ() + _monkeRadio * std::sin(_monkeAngle*toRadians));
		camTr->setPosition(nuevaPos)*/;
		//camtTr para mover al nodo padre y mNodeCamera para mover la posición del nodo hijo que es donde se encuentra la cámara
		_camTr->setPosition(Vector3D(_monkePos->getX(), _monkePos->getY(), _monkePos->getZ()));
		/*mNodeCamera->lookAt(Ogre::Vector3(_monkePos->getX(), _monkePos->getY(), _monkePos->getZ()), Ogre::Node::TS_WORLD, Ogre::Vector3::NEGATIVE_UNIT_Z);*/
	}
};


void Camera::start() {
	_camera = RenderMain::getInstance()->getSceneManager()->createCamera(_camName);

	_camera->setNearClipDistance(_nearClipDist);
	_camera->setFarClipDistance(_farClipDist);
	_camera->setAutoAspectRatio(true);
	mNodeCamera = entity_->getNode()->createChildSceneNode();
	mNodeCamera->attachObject(_camera);
	//mNodeCamera->yaw(Ogre::Degree(90));

	mNodeCamera->setPosition(0, 0/*500*/, _monkeRadio);
	mNodeCamera->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);

	 _vp= RenderMain::getInstance()->getRenderWindow()->addViewport(_camera);

	_vp->setBackgroundColour(Ogre::ColourValue(_bckgColor.getX(), _bckgColor.getY(), _bckgColor.getZ()));
	_aspectRatio = Ogre::Real(_vp->getActualWidth()) / Ogre::Real(_vp->getActualHeight());
	_camera->setAspectRatio(_aspectRatio);

	_camTr = (Transform*)entity_->getComponent("Transform");
}



//void Camera::receiveEvent(MessageType msg, Entity* e) {
//	std::cout << "Recibe msg";
//	Transform* camTr = getComponent<Transform>();
//	switch (msg) {
//		case MessageType::PULSA_Q:
//			camTr->rotate(Vector3D(0, 5, 0));
//			//_oNode->yaw(Ogre::Degree(-5));
//			mNodeCamera->yaw(Ogre::Degree(-5));
//			_monkeAngle = (_monkeAngle + 5) % 360;
//			//camTr->setRotation()
//			//_oNode->getOrientation(). * toAngles;
//			//std::cout << "AnguloCam mono: " << //camTr->setRotation()
//			//	_oNode->getOrientation() * toAngles << "\n";
//			break;
//		case MessageType::PULSA_E:
//			camTr->rotate(Vector3D(0, -5, 0));
//			//_oNode->yaw(Ogre::Degree(5));
//			mNodeCamera->yaw(Ogre::Degree(5));
//			_monkeAngle = (_monkeAngle - 5) % 360;
//			//std::cout << "AnguloCam mono: " << _monkeAngle << "\n";
//			break;
//	}
//}
