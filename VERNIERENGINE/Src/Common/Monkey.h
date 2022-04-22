#include "Entity.h"
#include "Utils.h"

class Monkey : public Entity {
private:
	float vel = 10;
	Transform* transformCamara = nullptr;//Es necesario para saber la orientaci�n de la c�mara, para que si se le da a la w avance en esa direcci�n
public:
	void setCamTrOnMonkey(Transform* trCam) { transformCamara = trCam; };
	Monkey(std::string entityName) : Entity(entityName) {}
	~Monkey(){}
	virtual void receiveEvent(MessageType msg, Entity* e);
};