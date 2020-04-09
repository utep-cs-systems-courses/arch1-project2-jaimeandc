#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "song.h"
static int state = 1;

char song()
{
  switch(state){
  case 1:
    buzzer_set_period(2093); //low C7
    ++state;
    break;
  case 2:
    buzzer_set_period(2093); //low C7
    ++state;
    break;
  case 3:
    buzzer_set_period(1396); //G7
    ++state;
    break;
  case 4:
    buzzer_set_period(1396); //G7
    ++state;
    break;
  case 5:
    buzzer_set_period(1318); //A7
    ++state;
    break;
  case 6:
    buzzer_set_period(1318); //A7
    state++;
    break;
  case 7:
    buzzer_set_period(1396); //G7
    ++state;
    break;
  case 8:
    buzzer_set_period(1567); //F7
    ++state;
    break;
  case 9:
    buzzer_set_period(1567); //F7
    ++state;
    break;
  case 10:
    buzzer_set_period(1760); //E7
    ++state;
    break;
  case 11:
    buzzer_set_period(1760); //E7
    ++state;
    break;
  case 12:
    buzzer_set_period(1975); //D7
    ++state;
    break;
  case 13:
    buzzer_set_period(1975); //D7
    ++state;
    break;
  case 14:
    buzzer_set_period(2093); //low C7
    state = 1;
    break;

  }
}
