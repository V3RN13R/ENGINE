#pragma once
#include "Component.h"
#include <map>
#include <string>




class Entity;
class Vector3D;
class Pickable :
    public Component
{
public:
    Pickable(std::map<std::string, std::string> args) : value(stof(args["Value"])) {};
private:
    int value;
    void onTriggerEnter(Entity* other, Vector3D point);
};

