#pragma once

#include <chrono>
#include "EngineDll.h"

const int NFrames = 50;

class V3RN13R_API VernierTime {
private:
    double deltaTime_;
    double fixedDeltaTime_;
    double time_;
    double nextFixedTime_;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastFrameTime_;
    //static VernierTime* _instance;


public:   
    /*static VernierTime* getInstance();
    static bool setUpInstance();
    static void deleteInstance();*/
    VernierTime();
    virtual ~VernierTime();


    bool frameStarted();

    double deltaTime();

    double fixedDeltaTime();

    double Time();
};

