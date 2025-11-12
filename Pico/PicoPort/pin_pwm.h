#include "pin.h"
#include <hardware/pwm.h>
struct PinPWM : Pin {
private:
	uint8_t _s,_c;
public:
	void SetResolution(uint8_t r) {
		pwm_set_wrap(_s, r-1);
	}
	void Set(uint8_t d) {
		pwm_set_chan_level(_s,_c,d);
	}
	PinPWM(uint8_t p, uint8_t d = 0) : Pin(p) {
		gpio_set_function(_p,GPIO_FUNC_PWM);
		_s = pwm_gpio_to_slice_num(_p);
		_c = pwm_gpio_to_channel(_p);
		Set(d);
		pwm_set_enabled(_s, true);
	}
};
