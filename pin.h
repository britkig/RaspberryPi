#pragma once  // FOR PI PICO ONLY
#include <hardware/gpio.h>
struct Pin{
protected:
	uint8_t _p;
	Pin(uint8_t p){
		gpio_init(_p=p);
	}
};
#define PICOPORT_A {0,1,2,3}
#define PICOPORT_AB {0,1,2,3,4,5,6,7}
#define PICOPORT_B {4,5,6,7}
#define PICOPORT_BC {4,5,6,7,8,9,10,11}
#define PICOPORT_C {8,9,10,11}
#define PICOPORT_CD {8,9,10,11,12,13,14,15}
#define PICOPORT_D {12,13,14,15}
#define PICOPORT_DE {12,13,14,15,16,17,18,19}
//	WARNING: Ports D and E do not share same side of Pico module.
#define PICOPORT_E {16,17,18,19}
#define PICOPORT_EF {16,17,18,19,20,21,22,26}
#define PICOPORT_F {20,21,22,26}
#define PICOPORT_G {27,28}
//	WARNING: Ports F and G have a one-pin gap between them
