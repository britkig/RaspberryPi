
//  EXAMPLE PROJECT
//  Flashes on-module Pi Pico LED at 1Hz intervals

#include "pin_output.h"

PinOutput BuiltInLED(LED_BUILTIN);

void main(){

	while(true){

		BuiltInLED.Set(!BuiltInLED.Get());

		sleep_ms(1000);

  }

}
