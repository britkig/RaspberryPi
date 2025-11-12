# PicoPort
This repository contains a set of libraries to simplify access to GPIO pins on the Raspberry Pi® Pico® series of microcontrollers by representing them as objects.

## How it Works
These libraries use `struct` constructors to initialise pins before the `main` code block runs.

[Basic Example](example.cpp)
## Input Pin
To define an input (replacing `PIN_NUMBER` with the GPIO pin number):
```c
#include "pin_input.h"

PinInput MyInput(PIN_NUMBER);
```
And the pin's state can be read without blocking by calling `Read`:
```c
MyInput.Read();
```
You can also block execution until the pin has reached a desired state by calling `WaitForState`:
```c
MyInput.WaitForState(false|true);
```
## Output Pin
To define an input (replacing `PIN_NUMBER` with the GPIO pin number):
```c
#include "pin_output.h"

PinOutput MyOutput(PIN_NUMBER [,false|true]);
```
The initial output state can also be set by providing as second, though optional, parameter of boolean (false = off, true = on); if omitted, defaults to false.

And the output can be turned on or off by calling `Set`:
```c
MyOutput.Set(false|true);
```
## PWM Pin
To define a PWM pin (replacing `PIN_NUMBER` with the GPIO pin number):
```c
#include "pin_pwm.h"

PinPWM MyPWM(PIN_NUMBER [,0 ... 255]);
```
The initial duty time can also be set by providing as second, though optional, parameter of an integer between 0 and 255; if omitted, defaults to zero (full off).

The output duty time can be adjusted `Set`:
```c
MyPWM.Set(0 ... 255);
```
The time resolution can be adjusted by calling `SetResolution`:
```c
MyPWM.SetResolution(0 ... 255);
```

**Notes:**
- For maximum compatibility, only values between 0 and 255 (`uint8_t`) are accepted.
- Additionally, you should call `SetResolution` at least once in your code to ensure proper operation, as there is a quirk with the microcontroller's PWM registeres that doesn't result in 100% duty time when both duty and resolution values are the same. As a workaround, you should set the resolution value to be one-less than the maximum duty time used.

## Design Notes
For predictable behaviour, all pin declarations made using these libraries should be declared outside of any and all function blocks.
## Tricks
You can declare multiple pins of the same type by declaring an array instead of one per line, followed by the pin numbers, comma-separated, in curly-brackets:
```c
PinOutPut MyOutputs[8]={0,1,2,3,4,5,6,7};
```
The advantage of this approach is that you can iterate through them with loops.
