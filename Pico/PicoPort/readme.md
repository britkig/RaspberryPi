# PicoPort
This repository contains a set of libraries to simplify access to GPIO pins on the Raspberry Pi® Pico® series of microcontrollers by representing them as objects.

## How it Works
These libraries use `struct` constructors to initialise pins before the `main` code block runs.

[Basic Example](example.cpp)
## Input Pin
To define an input (replacing `PIN_NUMBER` with the GPIO pin number):
```c
#include "pin_input.h"

PinInput MyInput(PIN_NUMBER [, false|true]);
```
An optional second parameter can be provided to enable or disable interrupt handling; this is required for some calls listed below. Defaults to `true`.

The pin's state can be read without blocking by calling `Read`:
```c
MyInput.Read();
```
You can also block execution until the pin has reached a desired state by calling `WaitForState`:
```c
MyInput.WaitForState(false|true);
```
**Note:**
- Interrupt registering is required for this function to work, this is enabled by default unless explicitly disable in the pin's code declaration.
- There may be a delay of detection of input state change through `WaitForState` while the CPU is a deep-sleep wait-for-interrupt state.

## Output Pin
To define an input (replacing `PIN_NUMBER` with the GPIO pin number):
```c
#include "pin_output.h"

PinOutput MyOutput(PIN_NUMBER [,false|true]);
```
The initial output state can also be set by providing as second, though optional, parameter of boolean (false = off, true = on). Defaults to false.

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
The initial duty time can also be set by providing as second, though optional, parameter of an integer between 0 and 255. Defaults to zero (0% duty).

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
- Additionally, you should call `SetResolution` at least once in your code prior to any `Set` calls to ensure proper operation, as there is a quirk with the microcontroller's PWM registers that doesn't result in 100% duty time when both duty and resolution values are equal. As a workaround, you should set the resolution value to be one-less than the maximum duty time being used in your code.
- Setting a duty time higher than the resolution value will result in the output being always on.
- If using multiple PWM outputs, some pins share the same PWM resolution register, and calling `SetResolution` will affect all pins that share that register.

## Design Notes
For predictable behaviour, all pin declarations made using these libraries should be declared outside of any and all function blocks.
## Tricks
You can declare multiple pins of the same type by declaring an array instead of one per line, followed by the pin numbers, comma-separated, in curly-brackets:
```c
PinOutPut MyOutputs[8]={0,1,2,3,4,5,6,7};
```
The advantage of this approach is that you can iterate through them with loops.
