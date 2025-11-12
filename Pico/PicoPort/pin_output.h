#pragma once	// FOR PI PICO ONLY
#include "pin.h"
struct PinOutput : Pin{
private:
	bool _i;
public:
	bool Get(){
		return gpio_get(_p)!=_i;
	}
	bool Set(bool v){
		if (Get()==v) return false;
		gpio_put(_p,v!=_i);
		return true;
	}
	PinOutput(uint8_t p, bool i=false):Pin(p){
		gpio_set_dir(_p,OUTPUT);
		Set(_i=i);
	}
};
