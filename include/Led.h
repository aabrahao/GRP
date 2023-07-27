#ifndef __LED_H__
#define __LED_H__

#include "Types.h"

class Led {
public:
  Led(Pin pin);
  void setup();
  void on();
  void off();
private:
  Pin m_pin;
};

#endif