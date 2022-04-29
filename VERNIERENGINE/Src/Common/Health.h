#include "Component.h"
#include <string>
#include <map>

class Health : public Component
{
public:
	Health(std::map<std::string, std::string> args);
	virtual ~Health() {};

	float getLives() { return _lives; };

	void loseLives();

	bool isDead();

private:
	float _lives;
};