#include "RadioController.h"
#include <Arduino.h>

float myMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

///////////////////////////////////////////////////
// Receiver

RadioController::RadioController()    
    : m_min(1000), m_max(2000), m_timeout(30000) {

}

void RadioController::setup(Pin pin) {
    pinMode(pin, INPUT);
}

float RadioController::channel(Pin pin) {
    float msec = pulseIn(pin, HIGH, m_timeout);
    msec = constrain(msec, m_min, m_max);
    return map(msec, m_min, m_max,-1.0, 1.0);
} 

///////////////////////////////////////////////////
// Channel

RadioControllerChannel::RadioControllerChannel(RadioController &receiver, Pin pin)
    : m_receiver(receiver), m_pin(pin) {
    m_receiver.setup(m_pin);
}

float RadioControllerChannel::channel() {
    return m_receiver.channel(m_pin);
}

///////////////////////////////////////////////////
// 2-Way Switch

int RadioControllerTwoWaySwitch::value() {
    return channel() > 0 ? 1 : 0;
}

///////////////////////////////////////////////////
// 3-Way Switch

int RadioControllerThreeWaySwitch::value() {
    float c = channel();
    int s = 0;
    if (c < -0.333333333333333)  
        s = -1;
    else if(c > 0.333333333333333) 
        s = 1;
    return s;
}
