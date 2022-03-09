#pragma once

#include "Component.h"
#include "Vector3D.h"
class Component;
class Transform : public Component {
public:
	Transform() :
		pos_(), vel_(), width_(), height_(), rotation_() {
	}

	Transform(Vector3D pos, Vector3D vel, float width, float height, float rotation);

	virtual ~Transform() {
	}

	Vector3D& getPos() {
		return pos_;
	}

	Vector3D& getVel() {
		return vel_;
	}

	float getH() const {
		return height_;
	}

	void setH(float height) {
		height_ = height;
	}

	float getW() const {
		return width_;
	}

	void setW(float width) {
		width_ = width;
	}

	float getRot() const {
		return rotation_;
	}

	void setRot(float rot) {
		rotation_ = rot;
	}

	void update() override {
		pos_ = pos_ + vel_;
	}

private:
	Vector3D pos_;
	Vector3D vel_;
	float width_;
	float height_;
	float rotation_;
};