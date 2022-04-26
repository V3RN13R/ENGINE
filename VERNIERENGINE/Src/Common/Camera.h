#pragma once

#include "Component.h"
#include <string>
#include "Vector3D.h"
#include <map>
#include "Utils.h"
#include <string>
class Component;
class Transform;

//
//
//const float _PI = 3.1416;
//const float toRadians = _PI / 180.0;
//const float toAngles = 180.0 / _PI;

namespace Ogre {
	class Root;
	class SceneManager;
	class SceneNode;
	class Entity;
	class Mesh;
	class Camera;
	class Viewport;
	
}
class Camera : public Component {
private:
	Ogre::Camera* _camera=nullptr;
	Ogre::SceneNode* mNodeCamera;
	float _nearClipDist = 1;
	float _farClipDist = 100000;
	Vector3D _looking = { 0, 0, 0 };
	float _aspectRatio = 1;
	Vector3D _bckgColor = { 0, 0, 0 }; //color por defecto
	Ogre::Viewport* _vp;
	Entity* mono;
	std::string entidadBuscar;

	int _monkeAngle = 0;
	float _monkeRadio = 500;
	Vector3D* _monkePos = nullptr;
	Vector3D _posRel;;

	Transform* _camTr;
	std::string _camName;
public:
	Camera(std::map<std::string, std::string> args, Entity* ent);
	virtual ~Camera();
	virtual void update();
	void setNearClipDist(float n) { _nearClipDist = n; }
	void setFarClipDist(float n) { _farClipDist = n; }
	void setAspectRatio(float n) { _aspectRatio = n; }
	void setLooking(Vector3D look) { _looking = look; }
	void setBckgColor(Vector3D color);
	void setMonkePos(Vector3D* pos);
	void start();
	//virtual void sendEvent(MessageType msg){}
	void receiveEvent(MessageType msg, Entity* e);

};