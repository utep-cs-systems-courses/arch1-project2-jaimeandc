#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
//static int state = 1;
static int count = 0;
void led_init()
{
  P1DIR |= LEDS;
  switch_state_changed = 1;
  led_update();
}

void led_update()
{
  char ledFlags = 0;
  if(switch_state_changed){
    ledFlags |= switch_state_down ? song(): 0;
    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  switch_state_changed = 0;
}

