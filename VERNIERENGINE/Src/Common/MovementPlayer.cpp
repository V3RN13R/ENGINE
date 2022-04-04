#include "MovementPlayer.h"
#include "PhysicsManager.h"
#include <btBulletCollisionCommon.h>
#include "btBulletDynamicsCommon.h"

//void MovementPlayer::mover() {
//
//	const btVector3 push = btVector3(10, 10, 10);
//	_mono->applyCentralImpulse(push);
//	_mono->setLinearVelocity(push);
//}


//void MovementPlayer::receiveEvent(MessageType msg) {
//	switch (msg) {
//	case MessageType::MOVERW:
//		const btVector3 adelante = btVector3(0, 10, 0);
//		_mono->applyCentralImpulse(adelante);
//		break;
//	case MessageType::MOVERA:
//		const btVector3 izq = btVector3(-10, 0, 0);
//		_mono->applyCentralImpulse(izq);
//		break;
//	case MessageType::MOVERS:
//		const btVector3 atras = btVector3(0, -10, 0);
//		_mono->applyCentralImpulse(atras);
//		break;
//	case MessageType::MOVERD:
//		const btVector3 der = btVector3(10, 0, 0);
//		_mono->applyCentralImpulse(der);
//		break;
//
//	}
//}