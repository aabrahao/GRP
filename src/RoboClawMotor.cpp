#include "RoboClawMotor.h"
#include <cmath>
#include <Arduino.h>

const Pin g_address = 0x80; 
const float g_zero_threshold = 0.01;
const unsigned g_speed_max = 88000;

/////////////////////////////////
// channel

RoboClawMotor::RoboClawMotor(RoboClaw &roboclaw, Pin channel) 
    : m_roboclaw(roboclaw), m_channel(channel) {

}

void RoboClawMotor::speed(float s) {
    if (s > -g_zero_threshold && s < g_zero_threshold )
        s = 0;
    int32_t u = map(std::fabs(s), 0, 1.0, 0, g_speed_max);
    if (s < 0)
        u = -u;
    if (m_channel == 1)
        m_roboclaw.SpeedM1(g_address, u);
    else if (m_channel == 2)
        m_roboclaw.SpeedM2(g_address, u);
}
