#include "Transform.h"
#include <Ogre.h>
#include "Entity.h"
#include "RigidBody.h"
//#include "RenderMain.h"

Transform::Transform(Vector3D position, Vector3D scale, Vector3D rotation) : _position(position), _scale(scale), _rotation(rotation)
{
}

void Transform::rotate(Vector3D rotation)
{
	entity_->getNode()->pitch(Ogre::Degree(rotation.getX()));
	entity_->getNode()->yaw(Ogre::Degree(rotation.getY()));
	entity_->getNode()->roll(Ogre::Degree(rotation.getZ()));
	_rotation += rotation;
}

void Transform::rotate(float degree, uint8_t axis)
{
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

void Transform::update() //Falta bullet
{
	entity_->getNode()->setPosition(Ogre::Vector3(_position.getX(), _position.getY() , _position.getZ()));
}

void Transform::fixedUpdate()
{

	if (entity_->hasComponent<Rigidbody>()) {
		setPosition(entity_->getComponent<Rigidbody>()->getPosition());
}
}
