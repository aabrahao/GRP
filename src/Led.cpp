#include "Led.h"
#include <Arduino.h>

Led::Led(Pin pin) 
  : m_pin(pin) {
    setup();
}

void Led::setup() {
  pinMode(m_pin, OUTPUT); 
}

void Led::on() {
  digitalWrite(m_pin, HIGH); 
}

void Led::off() {
  digitalWrite(m_pin, LOW); 
}