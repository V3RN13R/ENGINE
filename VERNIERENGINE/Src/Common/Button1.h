#pragma once
#include "Component.h"
#include <map>
#include <functional>

class Image;
class GameStateMachine;

class Button1 : public Component {
private:
    Entity* _ent;
    Image* _img;
    std::string _callbackName;

public:
    Button1(std::map<std::string, std::string> args, Entity* ent);
    ~Button1() {}
    void start() override;
    void update() override;
    void setCallBackFunction(std::string callBackName);
    std::function<void()> callback;
    void setCallback();
    void setCallBackFunction(std::function<void()> callBack);
};