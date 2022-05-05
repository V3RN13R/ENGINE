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

public:   
    VernierTime();

    virtual ~VernierTime();

    bool frameStarted();

    double deltaTime();

    double fixedDeltaTime();

    double Time();
};

