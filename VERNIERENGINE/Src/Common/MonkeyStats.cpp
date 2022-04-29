#include "MonkeyStats.h"

MonkeyStats::MonkeyStats(std::map<std::string, std::string> args)
{
	_lives = stof(args["Lives"]);
	_speed = stof(args["Speed"]);
	_jump = stof(args["Jump"]);
}

void MonkeyStats::loseLives()
{
	_lives--;
}

bool MonkeyStats::isDead()
{
	return _lives < 1;
}
