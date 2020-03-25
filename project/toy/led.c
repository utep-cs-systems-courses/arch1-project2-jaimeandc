#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"

static int state = 0;
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
    ledFlags |= switch_state_down ? song(): mute();
    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  switch_state_changed = 0;
}



char stay_green(){
  return LED_GREEN;
}


char song()
{
  switch(state){
  case 0:
    buzzer_set_period(2093); //low C7
    ++state;
    return LED_RED;
    break;
  case 1:
    buzzer_set_period(2093); //low C7
    ++state;
    return LED_RED;
    break;
  case 2:
    buzzer_set_period(1396); //G7
    ++state;
    return LED_GREEN;
    break;
  case 3:
    buzzer_set_period(1396); //G7 
    ++state;
    return LED_GREEN;
    break;
  case 4:
    buzzer_set_period(1318);//A7
    ++state;
    return LED_RED;
    break;
  case 5:
    buzzer_set_period(1318);//A7
    ++state;
    return LED_RED;
    break;
  case 6:
    buzzer_set_period(1396);//G7
    ++state;
      return LED_GREEN;
    break;
  case 7:
    buzzer_set_period(1567);//F7
    ++state;
    return LED_RED;
    break;
  case 8:
    buzzer_set_period(1567);//F7
    ++state;
    return LED_RED;
    break;
  case 9:
    buzzer_set_period(1760);//E7
    ++state;
    return LED_GREEN;
    break;
  case 10:
    buzzer_set_period(1760);//E7
    ++state;
    return LED_RED;
    break;
  case 11:
    buzzer_set_period(1975);//D7
    ++state;
    return LED_GREEN;
    break;
  case 12:
    buzzer_set_period(1975);//D7
    ++state;
    return LED_GREEN;
    break;
  case 13:
    buzzer_set_period(2093);//low C7
    state = 0;
    return LED_RED;
    break;
  }
}

char mute(){
  buzzer_set_period(0);
  return 0;
}
