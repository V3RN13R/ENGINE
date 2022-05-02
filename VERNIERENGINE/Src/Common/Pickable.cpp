#include "Pickable.h"
#include "Entity.h"
#include "Vector3D.h"
#include "Rigidbody.h"
#include "MeshRenderer.h"
#include "Player.h"
#include <iostream>
#include "ENGINE.h"
#include "VernierTime.h"


void Pickable::onTriggerEnter(Entity* other, Vector3D point) {
	if (entity_->isActive() && other->getComponent("MovementPlayer")) {
		std::cout << "triggerEntra\n";
		gotcha = true;
		_mesh = static_cast<MeshRenderer*>(entity_->getComponent("MeshRenderer"));
		_rb = static_cast<Rigidbody*>(entity_->getComponent("Rigidbody"));
		_mesh->setVisible(false);
		_rb->setEnable(false);
		Player* playerInfo = static_cast<Player*>(other->getComponent("Player"));
		if (playerInfo) {
			playerInfo->addBananas(_value);
		}
		_lastTime = VernierEngine::getInstance()->getTime()->Time();
	}
}

void Pickable::update()
{
	if (gotcha) {
		float currentTime = VernierEngine::getInstance()->getTime()->Time();
		if (_lastTime + _generationTime < currentTime) {
			_mesh->setVisible(true);
			_rb->setEnable(true);
			gotcha = false;
		}
	}
}
