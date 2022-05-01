#include "Pickable.h"
#include "Entity.h"
#include "Vector3D.h"
#include "Rigidbody.h"
#include "Player.h"
#include <iostream>

void Pickable::onTriggerEnter(Entity* other, Vector3D point)
{
	
	if (entity_->isActive() && other->getComponent("MovementPlayer")) {
		std::cout << "triggerEntra\n";
		entity_->setActive(false);
		Player* playerInfo = static_cast<Player*>(other->getComponent("Player"));
		if (playerInfo) {
			playerInfo->addBananas(value);
		}
	}
}
