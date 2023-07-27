#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "Arduino.h"

template<typename T>
void print(const T &value) {
  Serial.print(value);
}

template<typename T>
void println(const T &value) {
  Serial.println(value);
}

String clean(String message);
String token(String message, int index);
String command(const String &message);
float argument(const String &message, int index, float default_value = 0);
String argumentString(const String &message, int index, float default_value = 0);

#endif