#pragma once	// FOR PI PICO ONLY
#include "pin.h"
struct PinInput : Pin{
	void subscribe_irq(bool e){
		gpio_set_irq_enabled(_p,GPIO_IRQ_EDGE_RISE|GPIO_IRQ_EDGE_FALL,e);
	}
	PinInput(uint8_t p,bool irq=true):Pin(p){
		gpio_set_dir(_p,GPIO_IN);
		gpio_pull_up(_p);
		if(irq) subscribe_irq(irq);
	}
	bool Read(){
		return !gpio_get(_p);
	}
	void WaitForState(bool s=true){
		while(Read()!=s) __wfi();
	}
	void WaitForPress(bool s=true){
		WaitForState(!s);
		WaitForState(s);
	}
};
