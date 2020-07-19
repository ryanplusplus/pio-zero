/*!
 * @file
 * @brief
 */

#ifndef DIGITALOUTPUT_H
#define DIGITALOUTPUT_H

#include <Arduino.h>
#include <cstdint>
#include <tiny/hal/IDigitalOutput.h>

template<uint8_t pin>
class DigitalOutput : public tiny::IDigitalOutput {
 public:
  DigitalOutput() {
    pinMode(pin, OUTPUT);
  }

  auto write(bool state) -> void {
    digitalWrite(pin, state);
  };
};

#endif
