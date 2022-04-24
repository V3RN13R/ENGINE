#pragma once
#include "Component.h"
#include "Texture.h"

class GameStateMachine;
class Button1 : public Component {
private:
	Texture* _tx;
public:
	Button1(Texture* tx){}
	~Button1(){}
	void update() override;
};