#include "Health.h"

Health::Health(std::map<std::string, std::string> args) : _lives(stof(args["Lives"]))
{	
}

void Health::loseLives()
{
	_lives--;
}

bool Health::isDead()
{
	return _lives < 1;
}
