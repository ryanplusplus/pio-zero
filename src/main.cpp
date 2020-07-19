#include <Arduino.h>
#include <tiny/TimerGroup.h>
#include "TimeSource.h"
#include "DigitalOutput.h"

using namespace tiny;

enum {
  blink_period = 500
};

static TimeSource time_source;
static TimerGroup timer_group(&time_source);
static Timer heartbeat_timer;

static DigitalOutput<LED_BUILTIN> led;

static void blink(void* context, TimerGroup* timer_group) {
  static bool state;
  led.write(state = !state);
  timer_group->start(&heartbeat_timer, blink_period, (void*)nullptr, blink);
}

void setup() {
  blink(nullptr, &timer_group);
}

void loop() {
  timer_group.run();
}
