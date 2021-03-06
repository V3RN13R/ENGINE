#pragma once

#include <string>
#include <memory>
#define SDL_MAIN_HANDLED
#include "EngineDll.h"

class RenderMain;
class PhysicsManager;
class WindowRender;
class SDL_Window;
class Manager;
class Transform;
class ResourceManager;
class InputManager;
class SoundManager;
class FactoryManager;
class UIManager;
class VernierTime;
class Callbacks;
class GameStateMachine;

class V3RN13R_API VernierEngine {
public:
    void startGame(int (*a)());
    static VernierEngine* getInstance() { return _instance; }
    static VernierEngine* setupInstance(const std::string& appName, const std::string& sceneFile, const std::string& scene);
    void startScene(const std::string& sceneFile, const std::string& scene);
    VernierEngine(const std::string& appName, const std::string& sceneFile, const std::string& value);
    RenderMain* getRenderMain();
    FactoryManager* getFactoryMng();
    SoundManager* getSoundMng();
    ResourceManager* getResourceMng();
    InputManager* getInputMng();
    PhysicsManager* getPhysicsMng();
    UIManager* getUIMng();
    GameStateMachine* getGSM();
    VernierTime* getTime();
    Callbacks* getCbs();
    bool processFrame(double dt);
    bool getPlay() { return play; }
    void closeGame() { play = false; }
    bool update();
    double getDeltaTime() { return deltaTime; };
    
    ~VernierEngine();
private:
    void readAssetsPath();
    static VernierEngine* _instance;
    std::string _appName;

    VernierTime* _vernierTime;
    RenderMain* _ogre = nullptr;
    PhysicsManager* _physics = nullptr;
    SoundManager* _soundManager = nullptr;
    GameStateMachine* _gSM = nullptr;
    InputManager* _input = nullptr;
    bool play = true;
    std::string _assetsPath = "";
    double deltaTime = 0;
    double lastFrameTime = 0;
};