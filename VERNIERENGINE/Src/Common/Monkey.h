#include "Entity.h"
#include "Manager.h"

class Monkey : public Entity {
public:
	Monkey(std::string entityName) : Entity(entityName) {}
	~Monkey(){}
	virtual void receiveEvent(MessageType msg, Entity* e);
};