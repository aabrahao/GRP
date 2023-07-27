#include "G2PololuMotor.h"
#include <Arduino.h>

const float g_zero_threshold = 0.01;

G2PololuMotor::G2PololuMotor(Pin pwm, Pin dir) 
    : m_pwm(pwm), m_dir(dir) {
    pinMode(m_pwm, OUTPUT);
    pinMode(m_dir, OUTPUT);
    analogWrite(m_pwm, 0); 
}

void G2PololuMotor::speed(float s) {
    if (s > -g_zero_threshold && s < g_zero_threshold )
        s = 0;
    u_int8_t u = map(std::fabs(s), 0.0, 1.0, 0, 255);
    if (s > 0)
        digitalWrite(m_dir, LOW);
    else
        digitalWrite(m_dir, HIGH);
    analogWrite(m_pwm, u);
}