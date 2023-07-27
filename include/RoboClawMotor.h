#ifndef __ROBOCLAW_channel_H__
#define __ROBOCLAW_channel_H__

#include <RoboClaw.h>
#include "Types.h"

/////////////////////////////////
// channel

class RoboClawMotor {
public:
    RoboClawMotor(RoboClaw &roboclaw, Pin channel); 
    void speed(float s); // -1.0 to +1.0
private:
    RoboClaw &m_roboclaw;
    Pin m_channel;
};

#endif