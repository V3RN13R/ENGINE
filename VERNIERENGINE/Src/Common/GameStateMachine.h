#pragma once
#include <string>
#include <memory>

class Scene;

// SIN IMPLEMENTAR

class GameStateMachine {
private:
	void changeScene(std::unique_ptr<Scene> _scene, std::string file, std::string name);
	// bool keyPressed();
public:
	GameStateMachine() {}
	~GameStateMachine() { }

};

