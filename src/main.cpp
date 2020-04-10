#include <Arduino.h>

extern "C" {
#include <stddef.h>
#include <tiny_digital_output.h>
#include <tiny_timer.h>
#include <tiny_time_source.h>
}

enum {
  blink_period = 1000
};

static tiny_digital_output_t led;
static tiny_timer_group_t timer_group;
static tiny_timer_t blink_timer;

static void blink(tiny_timer_group_t* timer_group, void* context) {
  static bool state;
  state = !state;
  tiny_digital_output_write(&led.interface, state);
  tiny_timer_start(timer_group, &blink_timer, blink_period / 2, blink, NULL);
}

void setup() {
  tiny_digital_output_init(&led, 13);
  tiny_timer_group_init(&timer_group, tiny_time_source_init());

  blink(&timer_group, NULL);
}

void loop() {
  tiny_timer_group_run(&timer_group);
}
