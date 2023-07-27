#ifndef __SERIAL_PORT_H__
#define __SERIAL_PORT_H__

#include "Command.h"

class SerialPort {
public:
  using ReceivedEvent = void (*)(const String &);
  SerialPort(long baud, ReceivedEvent callback);
  void setup();
  void update();
  void send(const String &message);
private:
  long m_baud;
  ReceivedEvent m_received;
  String m_buffer;
};

#endif