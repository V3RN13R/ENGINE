#include "Player.h"
#include <iostream>
//#include "checkML.h"

Player::Player(std::map<std::string, std::string> args)
{
	bananas = 0;
}

void Player::addBananas(int nBananas)
{
	bananas += nBananas;
	std::cout << bananas << "\n";
}
