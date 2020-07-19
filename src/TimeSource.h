/*!
 * @file
 * @brief
 */

#ifndef TIMESOURCE_H
#define TIMESOURCE_H

#include <Arduino.h>
#include <tiny/ITimeSource.h>

class TimeSource : public tiny::ITimeSource {
 public:
  auto ticks() -> TickCount {
    return (TickCount)millis();
  }
};

#endif
