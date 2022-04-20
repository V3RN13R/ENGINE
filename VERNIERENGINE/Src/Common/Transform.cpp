#include "Transform.h"
#include <Ogre.h>
#include "Entity.h"
#include "RigidBody.h"
//#include "RenderMain.h"
const float toRad = 3.1416 / 180;

Transform::Transform(Vector3D position, Vector3D scale, Vector3D rotation) : _position(position), _scale(scale), _rotation(rotation)
{
}

Transform::Transform(std::map<std::string, std::string> args) : _position(args["position"]), _scale(args["scale"]), _rotation(args["rotation"])
{
}

void Transform::rotate(Vector3D rotation)
{
	entity_->getNode()->pitch(Ogre::Degree(rotation.getX()));
	entity_->getNode()->yaw(Ogre::Degree(rotation.getY()));
	entity_->getNode()->roll(Ogre::Degree(rotation.getZ()));
	_rotation = Vector3D(static_cast<int>((_rotation.getX() + rotation.getX())) % 360, static_cast<int>((_rotation.getY() + rotation.getY())) % 360, static_cast<int>((_rotation.getZ() + rotation.getZ())) % 360);
}

void Transform::rotate(float degree, uint8_t axis)
{
		Rigidbody* rb = entity_->getComponent<Rigidbody>();
	switch (axis)
	{
	case 0:
		_rotation.setX(_rotation.getX() + degree);
		entity_->getNode()->pitch(Ogre::Degree(degree));
		break;
	case 1:
		_rotation.setY(_rotation.getY() + degree);
		entity_->getNode()->yaw(Ogre::Degree(degree));
		break;
	case 2:
		_rotation.setZ(_rotation.getZ() + degree);
		entity_->getNode()->roll(Ogre::Degree(degree));
		break;
	default:
		break;
	}

	if (rb) {
		Ogre::Vector3(_rotation.getX() * toRad, _rotation.getY() * toRad, _rotation.getZ() * toRad);
		Ogre::Quaternion qa;
		qa.FromRotationMatrix(fromEulerAngleToRotationMatrix({ _rotation.getX() * toRad, _rotation.getY() * toRad, _rotation.getZ() * toRad }));
		rb->recalculateAxis(_position, qa.x, qa.y, qa.z, qa.w);
	}
}

void Transform::setRotation(Vector3D rotation)
{
	entity_->getNode()->pitch(Ogre::Degree(-_rotation.getX()));
	entity_->getNode()->yaw(Ogre::Degree(-_rotation.getY()));
	entity_->getNode()->roll(Ogre::Degree(-_rotation.getZ()));

	entity_->getNode()->pitch(Ogre::Degree(rotation.getX()));
	entity_->getNode()->yaw(Ogre::Degree(rotation.getY()));
	entity_->getNode()->roll(Ogre::Degree(rotation.getZ()));

	_rotation = rotation;
}

Ogre::Matrix3 Transform::fromEulerAngleToRotationMatrix(Vector3D vec)
{
	Ogre::Matrix3 r_x = { 1,0,0,
						  0,cos(vec.getX()),-sin(vec.getX()),
						  0,sin(vec.getX()),cos(vec.getX()) };
	Ogre::Matrix3 r_y = { cos(vec.getY()),0,sin(vec.getY()),
					  0,1,0,
					  -sin(vec.getY()), 0, cos(vec.getY()) };
	Ogre::Matrix3 r_z = { cos(vec.getZ()), -sin(vec.getZ()), 0,
				  sin(vec.getZ()),cos(vec.getZ()),0,
				 0, 0, 1 };
	return (r_x * r_y * r_z);
}

void Transform::update() //Falta bullet
{
	entity_->getNode()->setPosition(Ogre::Vector3(_position.getX(), _position.getY() , _position.getZ()));
}

void Transform::setScale(Vector3D vec) {
	_scale = vec;
	entity_->getNode()->setScale(_scale.getX(), _scale.getY(), _scale.getZ());
}

void Transform::fixedUpdate()
{

	if (entity_->hasComponent<Rigidbody>()) {
		setPosition(entity_->getComponent<Rigidbody>()->getPosition());
}
}
