#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

char unsigned red_on = 0, green_on = 0, led_changed = 0;
char toggle_red()
{
  static char state = 0;

  switch (state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;
}
char toggle_green()
{
  char changed = 0;
  if(red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

void state_advance()
{
  char changed = 0;
  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }
  led_changed = changed;
  led_update();
  int button = 0;
  switch(buttonSelect(button))
    {
    case 1:
      led_update();
      break;
    case 2:
      buzzer_set_period(4000);
      break;
    case 3:
      song();
      break;
    case 4:
      mute();
      break;
    }
}

int buttonSelect(button)
{
  if(switch_state_down){
    button = 1;
  }
  else if(switch1_down){
    button = 2;
  }
  else if(switch2_down){
    button = 3;
  }
  else if(switch3_down){
    button = 4;
  }
  return button;
}
