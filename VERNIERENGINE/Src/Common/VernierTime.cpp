
#include "VernierTime.h"
#include <OgreTimer.h>


VernierTime::VernierTime() : deltaTime_(0), time_(0), nextFixedTime_(0), fixedDeltaTime_(1.0 / NFrames)
{
    lastFrameTime_ = std::chrono::high_resolution_clock::now();
}


VernierTime::~VernierTime()
{
}

double VernierTime::deltaTime() {
    return deltaTime_;
}

double VernierTime::fixedDeltaTime()
{
    return fixedDeltaTime_;
}

double VernierTime::Time()
{
    return time_;
}

bool VernierTime::frameStarted()
{
    std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - lastFrameTime_;

    deltaTime_ = elapsed.count();

    time_ += deltaTime_;

    lastFrameTime_ = std::chrono::high_resolution_clock::now();

    if (time_ >= nextFixedTime_) {
        nextFixedTime_ = time_ + fixedDeltaTime_;
        return true;
    }
    return false;
}