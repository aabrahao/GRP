#include "L298NMotor.h"
#include <Arduino.h>

L298NMotor::L298NMotor(Pin enA, Pin in1, Pin in2) 
    : m_enA(enA), m_in1(in1), m_in2(in2) {
    pinMode(m_enA, OUTPUT);
    pinMode(m_in1, OUTPUT);
    pinMode(m_in2, OUTPUT);
    analogWrite(m_enA, 0); 
}

void L298NMotor::speed(float s) {
    u_int8_t u = map(std::fabs(s), 0.0, 1.0, 0, 255);
    if (s > 0) {
        digitalWrite(m_in1, LOW);
        digitalWrite(m_in2, HIGH);   
    }
    else {
        digitalWrite(m_in1, HIGH);
        digitalWrite(m_in2, LOW);
    }
    analogWrite(m_enA, u);
}