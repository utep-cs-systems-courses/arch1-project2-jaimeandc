#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
static int counter = 0;
static int sound = 3000;
static char state = 0;
void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
    char ledFlags = 0; /* by default, no LEDs on */
    if(switch_state_changed){
      ledFlags |= switch_state_down ? song(): stay_green();//toggle red with button
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;// set bits for on leds
     }
  switch_state_changed = 0;
}


char stay_red(){
  
  // buzzer_set_period(3000);
  if(counter == 3){
    buzzer_set_period(5000);
    counter = 0;
  }
  return LED_RED;
}

char toggle_red()
{
  switch(state){
  case 0:
    counter++;
    state = 1;
    buzzer_set_period(3000);
    return LED_RED;
    break;
  case 1:
    counter++;
    state =0;
    sound = 1500;
    buzzer_set_period(sound);
    return 0;
    break;
  }
}
char stay_green(){
   buzzer_set_period(10);
 return  LED_GREEN;
}

char song(){
  switch(state){
  case 0:
    buzzer_set_period(1000);
    state++;
    return LED_RED;
    break;
  case 1:
    buzzer_set_period(1500);
    state++;
    return LED_GREEN;
    break;
  case 2:
    buzzer_set_period(2000);
    state++;
    return LED_RED;
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


  

