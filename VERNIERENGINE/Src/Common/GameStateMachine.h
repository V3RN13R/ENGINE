#pragma once
#include <string>
#include <memory>
#include <stack>
class Scene;

class GameStateMachine {

private:
    GameStateMachine();
    ~GameStateMachine();
    static GameStateMachine* _instance;
    std::stack<Scene*> _sceneStack;
    bool _load, _pop, _push;
    std::string _file, _name;
    // bool keyPressed();
public:
    static GameStateMachine* getInstance();
    static bool setUpInstance();
    static void deleteInstance();
    void clearScenes();
    void initScene(const std::string& sceneFile, const std::string& scene);
    void changeScene(std::string file, std::string name, bool push = true); //false para borrar todas las escenas existentes en la pila
    void popScene();
    void fixedUpdate();
    void update();
    void lateUpdate();
    bool lastUpdate();
    Scene* getScene();

};