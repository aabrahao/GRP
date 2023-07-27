#ifndef __RADIO_CONTROLLER_H__
#define __RADIO_CONTROLLER_H__

#include "Types.h"

///////////////////////////////////////////////////
// Receiver

class RadioController {
public:
    RadioController();
    void setup(Pin pin);        
    float channel(Pin pin);
private:
    float m_min;
    float m_max;
    float m_timeout;
};

///////////////////////////////////////////////////
// Channel

class RadioControllerChannel {
public:
    RadioControllerChannel(RadioController &receiver, Pin pin);
    float channel();
private:
    RadioController &m_receiver;
    Pin m_pin;
};

///////////////////////////////////////////////////
// Knob, stick

class RadioControllerKnob : public RadioControllerChannel {
public:
    RadioControllerKnob(RadioController &receiver, Pin pin) : RadioControllerChannel(receiver, pin) { }
    float value() { return channel(); }
};

///////////////////////////////////////////////////
// Stick

class RadioControllerStick : public RadioControllerKnob {
public:
    RadioControllerStick(RadioController &receiver, Pin pin) : RadioControllerKnob(receiver, pin) { }
};

///////////////////////////////////////////////////
// 2-Way Switch

class RadioControllerTwoWaySwitch : public RadioControllerChannel {
public:
    RadioControllerTwoWaySwitch(RadioController &receiver, Pin pin) : RadioControllerChannel(receiver, pin) { }
    int value();
    bool on() { return value() == 1; }
    bool off() { return value() == 0; }
};

///////////////////////////////////////////////////
// 3-Way Switch

class RadioControllerThreeWaySwitch : public RadioControllerChannel {
public:
    RadioControllerThreeWaySwitch(RadioController &receiver, Pin pin) : RadioControllerChannel(receiver, pin) { }
    int value();
    bool down() { return value() == -1; }
    bool center() { return value() == 0; }
    bool up() { return value() == 1; }
};

#endif
