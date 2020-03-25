#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed, switch1_down, switch2_down, switch3_down;

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void
switch_init()
{
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_down = (p2val & SW0) ? 0 : 1;
  switch1_down = (p2val & SW1) ? 0 : 1;
  switch2_down = (p2val & SW2) ? 0 : 1;
  switch3_down = (p2val & SW3) ? 0 : 1;
  
  switch_state_changed = 1;
  led_update();
}
