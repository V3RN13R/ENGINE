#pragma once

#include "Component.h"
#include "Vector3D.h"
#include <map>
class Component;

class Transform : public Component {
	enum Axis :uint8_t { x, y, z };
public:
	Transform() :
		_position(), _scale(), _rotation(0,0,0) {
	}

	Transform(Vector3D position, Vector3D scale, Vector3D rotation);
	
	Transform(std::map<std::string, std::string> args);

	virtual bool init();

	virtual ~Transform() {
	}

	Vector3D& getPos() {
		return _position;
	}

	void setPosition(Vector3D position)
	{
		_position = position;
	}

	float getH() const {
		return _scale.getY();
	}

	void setH(float height) {
		_scale.setY(height);
	}

	float getW() const {
		return _scale.getX();
	}

	void setW(float width) {
		_scale.setX(width);
	}

	Vector3D getRot() const {
		return _rotation;
	}

	void rotate(Vector3D rotation);
	void rotate(float degree, uint8_t axis);

	void setRotation(Vector3D rotation);

	void setScale(Vector3D scale);

	Vector3D getScale()
	{
		return _scale;
	}

	Ogre::Matrix3 fromEulerAngleToRotationMatrix(Vector3D vec);


	void update() override;
	void fixedUpdate() override;
	//virtual void sendEvent(MessageType msg) {}
	//virtual void receiveEvent(MessageType msg) {}
private:
	Vector3D _position;
	Vector3D _glbposition;
	Vector3D _scale;
	Vector3D _rotation;
	Vector3D _glrotation;
};