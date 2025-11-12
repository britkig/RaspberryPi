#pragma once	// FOR PI PICO ONLY
#include "pin_input.h"
struct PinReset : PinInput{
	PinReset(uint8_t p):PinInput(p,false){
		WaitForState(false);
		gpio_set_irq_enabled_with_callback(_p, GPIO_IRQ_EDGE_RISE|GPIO_IRQ_EDGE_FALL, true, &_trigger);
	}
private:
	static void _trigger(uint gpio, uint32_t events){
		if(!Read()) return;
		watchdog_enable(0,1);
		while(true);
	}
};
