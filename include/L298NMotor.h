#ifndef __L298N_MOTOR_H__
#define __L298N_MOTOR_H__

#include "Types.h"

class L298NMotor {
public:
    L298NMotor(Pin enA, Pin in1, Pin in2); 
    void speed(float s); // -1.0 to +1.0
private:
    Pin m_enA;
    Pin m_in1;
    Pin m_in2;
};

#endif