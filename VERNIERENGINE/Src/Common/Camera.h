#pragma once

#include "Component.h"
#include <string>
#include "Vector3D.h"
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
	float _nearClipDist = 1;
	float _farClipDist = 100000;
	Vector3D _looking = new Vector3D(0, 0, 0);
	float _aspectRatio=1;
	Vector3D _bckgColor = new Vector3D(0, 0, 1);
	Ogre::Viewport* _vp;
public:
	Camera() {};
	virtual ~Camera() {};
	void setNearClipDist(float n) { _nearClipDist = n; }
	void setFarClipDist(float n) { _farClipDist = n; }
	void setAspectRatio(float n) { _aspectRatio = n; }
	void setLooking(Vector3D look) { _looking = look; }
	void setBckgColor(Vector3D color);
	void start();
};