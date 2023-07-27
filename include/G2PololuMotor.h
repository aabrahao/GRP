#ifndef __G2_POLOLU_MOTOR_H__
#define __G2_POLOLU_MOTOR_H__

#include "Types.h"

class G2PololuMotor {
public:
    G2PololuMotor(Pin pwm, Pin dir); 
    void speed(float s); // -1.0 to +1.0
private:
    Pin m_pwm;
    Pin m_dir;
};

#endif