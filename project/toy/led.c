#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
static int counter = 0;
static int sound;
static int state = 0;

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


char stay_red(){}

char toggle_red(){}

char stay_green(){
  return LED_GREEN;
}
char song()
{
  switch(state){
  case 0:
    buzzer_set_period(1000);
    state++;
    return LED_RED;
    break;
  case 1:
    buzzer_set_period(1500);
    state++;
    return LED_RED;
    break;
  case 2:
    buzzer_set_period(2000);
    state++;
    return LED_GREEN;
    break;
  case 3:
    buzzer_set_period(2500);
    state++;
    return LED_GREEN;
    break;
  case 4:
    buzzer_set_period(3000);
    state++;
    return LED_RED;
    break;
  case 5:
    buzzer_set_period(3500);
    state++;
    return LED_GREEN;
    break;
  case 6:
    buzzer_set_period(4000);
      state = 0;
    return LED_GREEN;
    break;
  }
}