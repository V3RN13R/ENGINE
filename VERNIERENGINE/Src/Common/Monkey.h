#include "Entity.h"
#include "Utils.h"

class Monkey : public Entity {
private:
	float vel = 10;
	Transform* transformCamara = nullptr;//Es necesario para saber la orientación de la cámara, para que si se le da a la w avance en esa dirección
public:
	void setCamTrOnMonkey(Transform* trCam) { transformCamara = trCam; };
	Monkey(std::string entityName) : Entity(entityName) {}
	~Monkey(){}
	virtual void receiveEvent(MessageType msg, Entity* e);
};