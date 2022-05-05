﻿#include "Camera.h"
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
	entidadBuscar = args["Entity"];
}

Camera::~Camera() {
	
	RenderMain::getInstance()->getSceneManager()->destroyCamera(_camera);
}

void Camera::setBckgColor(Vector3D color)
{
	_bckgColor = color;
	_vp->setBackgroundColour(Ogre::ColourValue(_bckgColor.getX(), _bckgColor.getY(), _bckgColor.getZ()));
	SoundComponent* _sc = (SoundComponent*)entity_->getComponent("SoundComponent");
}



void Camera::setMonkePos(Vector3D* monPos) {
	_monkePos = monPos;
}


void Camera::update() {
	if (mono) {
		_monkePos = &(static_cast<Transform*>(mono->getComponent("Transform")))->getPos();
		if (_camTr != nullptr) {
			//camtTr para mover al nodo padre y mNodeCamera para mover la posición del nodo hijo que es donde se encuentra la cámara
			_camTr->setPosition(Vector3D(_monkePos->getX(), _monkePos->getY(), _monkePos->getZ()));
			mNodeCamera->lookAt(Ogre::Vector3(_monkePos->getX(), _monkePos->getY(), _monkePos->getZ()), Ogre::Node::TS_WORLD, Ogre::Vector3::NEGATIVE_UNIT_Z);
		}
	}	


	MousePositionRelative mousePosRel = InputManager::getInstance()->getMousePosRel();
	if (InputManager::getInstance()->getMouseButtons().leftDown) {
		float rotar = _sensibilidad * mousePosRel.x;
		Transform* camTr = static_cast<Transform*>(entity_->getComponent("Transform"));
		camTr->rotate(Vector3D(0, rotar, 0));
		mNodeCamera->yaw(Ogre::Degree(-rotar));
		_monkeAngle = fmod((_monkeAngle + rotar), 360.f);//modulo entre dos floats
	}
	
	
}

void Camera::start() {
	mono = entity_->getScene()->getObjectWithName(entidadBuscar);

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
	 _sc = (SoundComponent*)entity_->getComponent("SoundComponent");
	if(_sc)
		_sc->playMusic("Music", 0.1f);
}

void Camera::onDisable()
{
	Component::onDisable();
	if (_sc)
		_sc->stopAllSounds();
}

void Camera::onEnable()
{
	Component::onEnable();
	if (_sc)
		_sc->resumeAllSounds();
}



void Camera::receiveEvent(int msg, Entity* e) {
	if (msg == MessageType::UNO)
		if (VernierEngine::getInstance()->getGSM()->getScene()->getName() == "jugar1" ||
		VernierEngine::getInstance()->getGSM()->getScene()->getName() == "jugar2" ||
		VernierEngine::getInstance()->getGSM()->getScene()->getName() == "jugar3")
			entity_->getScene()->getGSM()->changeScene("menupausa.lua", "menupausa", true);

	Transform* camTr = static_cast<Transform*>(entity_->getComponent("Transform"));
	if (camTr) {

		switch (msg) {
		case MessageType::PULSA_Q:
			camTr->rotate(Vector3D(0, _sensibilidad, 0));
			mNodeCamera->yaw(Ogre::Degree(-_sensibilidad));
			_monkeAngle = fmod((_monkeAngle + _sensibilidad), 360.f);//modulo entre dos floats
			break;
		case MessageType::PULSA_E:
			camTr->rotate(Vector3D(0, -_sensibilidad, 0));
			mNodeCamera->yaw(Ogre::Degree(_sensibilidad));
			_monkeAngle = fmod((_monkeAngle - _sensibilidad), 360.f);
			break;
		}
	}
}
