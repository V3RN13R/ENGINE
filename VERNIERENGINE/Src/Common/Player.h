#pragma once
#include "Component.h"
#include <map>
#include <string>


class Player :
    public Component
{
public:

    Player(std::map<std::string, std::string> args);
    void addBananas(int nbananas);
private:
    int bananas;

};

