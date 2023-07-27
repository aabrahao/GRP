
#include "SerialPort.h"

const char g_delimeter = '\n';

SerialPort::SerialPort(long baud, ReceivedEvent callback)
  : m_baud(baud), m_received(callback) {
}

void SerialPort::setup() {
  Serial.begin(m_baud);
}

void SerialPort::update() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == g_delimeter) {
      m_received(clean(m_buffer));
      m_buffer = String();
    }
    else
      m_buffer += c;
  }
}

void SerialPort::send(const String &message) {
  Serial.print(message + g_delimeter);
  Serial.flush();
}
