#include "Entity.h"
#include "Manager.h"

class Monkey : public Entity {
public:
	Monkey(Manager* mngr, std::string entityName) : Entity(mngr, entityName) {}
	~Monkey(){}
	virtual void receiveEvent(MessageType msg, Entity* e);
};