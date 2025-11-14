//  EXAMPLE PROJECT
//  Flashes the on-module Pi Pico LED at 1Hz intervals whilst GPIO pin 0 is being pulled to GND.

#include "pin_input.h"
#include "pin_output.h"

PinInput Button0(0);
PinOutput BuiltInLED(LED_BUILTIN);

void main(){
	while(true){
		Button0.WaitForState(true);
		BuiltInLED.Set(!BuiltInLED.Get());
		sleep_ms(1000);
	}
}
