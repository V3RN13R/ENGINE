#include "MovementPlayer.h"
#include "PhysicsManager.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

void MovementPlayer::mover() {

	_mono->applyCentralImpulse(_vel);
	_mono->setLinearVelocity(_vel);
}

char leeInput() {
}