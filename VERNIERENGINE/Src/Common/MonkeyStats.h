#include "Component.h"
#include <string>
#include <map>

class MonkeyStats : public Component
{
public:
	MonkeyStats(std::map<std::string, std::string> args);
	virtual ~MonkeyStats() {};

	float getLives() { return _lives; };
	float getSpeed() { return _speed; };
	float getJump() { return _jump; };

	void loseLives();
	bool isDead();
private:
	float _lives, _speed, _jump;
};