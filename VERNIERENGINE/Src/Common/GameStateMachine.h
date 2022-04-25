#pragma once
#include <string>
#include <memory>
#include "Singleton.h"
#include <stack>
class Scene;

class GameStateMachine : public Singleton<GameStateMachine> {

	friend class Singleton<GameStateMachine>;

private:
	GameStateMachine() {}
	std::stack<Scene*> _sceneStack;
	bool _load, _pop, _push;
	std::string _file, _name;
	// bool keyPressed();
public:
	~GameStateMachine() { }

	void clearScenes();
	void initScene(const std::string& sceneFile, const std::string& scene);
	void changeScene(std::string file, std::string name, bool push = true); //false para borrar todas las escenas existentes en la pila
	void popScene();
	void fixedUpdate();
	void update();
	bool lastUpdate();
	Scene* getScene();
	GameStateMachine& ih() {
		return *GameStateMachine::instance();
	}
};

