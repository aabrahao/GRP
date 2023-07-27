#include "M3USDigitalEncoder.h"
#include "Arduino.h"

M3USDigitalEncoder::M3USDigitalEncoder(Pin pwm)
    : m_pwm(pwm), m_timeout(20000) {
    setup();
}

void M3USDigitalEncoder::setup() {
    pinMode(m_pwm, INPUT);
}

unsigned long M3USDigitalEncoder::pulse() {
    return pulseIn(m_pwm, HIGH, m_timeout);
}

float M3USDigitalEncoder::angle(){
    return map(pulse(), 0, 4096, 0, 360);
}