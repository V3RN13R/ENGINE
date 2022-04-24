#pragma once

#include "Component.h"
#include <string>
#include "Vector3D.h"

#include "Utils.h"
#include "Entity.h"
namespace Ogre {
	class Root;
	class SceneManager;
	class SceneNode;
	class Entity;
	class Mesh;
	class Camera;
	class Viewport;
	
}
class Camera : public Entity {
private:
	Ogre::Camera* _camera=nullptr;
	Ogre::SceneNode* mNodeCamera;
	float _nearClipDist = 1;
	float _farClipDist = 100000;
	Vector3D _looking = new Vector3D(0, 0, 0);
	float _aspectRatio=1;
	Vector3D _bckgColor = new Vector3D(0, 0, 1);
	Ogre::Viewport* _vp;

	int _monkeAngle = 0;
	float _monkeRadio = 500;
	Vector3D* _monkePos = nullptr;
	
	
public:
	Camera(std::string entityName);
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
	//virtual void receiveEvent(MessageType msg, Entity* e);

};