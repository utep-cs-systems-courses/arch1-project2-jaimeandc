#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "song.h"
static int direction = 0;
static int count = 0;
static int i = 0;
char unsigned red_on = 0, green_on = 0, led_changed = 0;
/*Scale notes are in order: lowC7, D, E, F, G, A, B, highC7 */
int scale[] = {2093,1975,1760,1567,1396,1318,1174,1046};
char toggle_red()
{
  static char state = 0;

  switch (state){
  case 0:
    red_on = 1;
    state = 1;
    count++;
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
    count = 0;
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
      led_update(); // Twinkle Twinkle
      break;
    case 2://scale in selected direction.
      switch(direction){
      case 0:
      if(i != 6){
	buzzer_set_period(scale[i]);
	i++;
      };
      break;
      case 1:
	if(i != 0){
	  buzzer_set_period(scale[i]);
	  i--;
	};
	break;
      }
      break;
    case 3:
      song();y // Jazzy Twinkle Twinkle
      break;
    case 4:// sets the direction of scale for button 2 and mutes tones.
      switch(direction){
      case 0:
	buzzer_set_period(2000);
	direction = 1;
	break;
      case 1:
	buzzer_set_period(4000);
	direction = 0;
	break;
      }
      buzzer_set_period(0);
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
