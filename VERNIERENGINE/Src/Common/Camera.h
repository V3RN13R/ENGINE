#pragma once

#include "Component.h"
#include "Utils.h"
#include "EngineDll.h"
#include <map>
#include <string>

class Transform;
class SoundComponent;

namespace Ogre {
	class Root;
	class SceneManager;
	class SceneNode;
	class Entity;
	class Mesh;
	class Camera;
	class Viewport;
	
}
class V3RN13R_API Camera : public Component {
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
	float _sensibilidad;
	Vector3D _posRel;;

	Transform* _camTr;
	std::string _camName;
public:
	Camera(std::map<std::string, std::string> args, Entity* ent);
	virtual ~Camera();

	void setNearClipDist(float n) { _nearClipDist = n; }
	void setFarClipDist(float n) { _farClipDist = n; }
	void setAspectRatio(float n) { _aspectRatio = n; }
	void setLooking(Vector3D look) { _looking = look; }
	void setBckgColor(Vector3D color);
	void start();
	void lookAt(Vector3D v);
	void yaw(float d);
	void pitch(float d);
	void roll(float d);
};