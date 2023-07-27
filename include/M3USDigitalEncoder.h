#ifndef __M3_USDIGITAL_ENCODER_H__
#define __M3_USDIGITAL_ENCODER_H__

#include "Types.h"

class M3USDigitalEncoder {
public:
    M3USDigitalEncoder(Pin pwm);
    void setup();
    unsigned long pulse();
    float angle(); 
private:
    Pin m_pwm;
};

#endif