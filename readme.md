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
MyInput.WaitForState(true|false);
```
## Output Pin
To define an input (replacing `PIN_NUMBER` with the GPIO pin number):
```c
#include "pin_input.h"

PinInput MyOutput(PIN_NUMBER);
```
## Tricks
You can declare multiple pins of the same type by declaring an array instead of one per line, followed by the pin numbers, comma-separated, in curly-brackets:
```c
PinOutPut MyOutputs[8]={0,1,2,3,4,5,6,7};
```
The advantage of this approach is that you can iterate through them with loops.
