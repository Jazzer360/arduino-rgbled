#ifndef _JOYSTICK_h
#define _JOYSTICK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Joystick {
public:
    Joystick(byte xPin, byte yPin, byte buttonPin) :
        mXPin{ xPin }, mYPin{ yPin }, mButtonPin{ buttonPin } {}
private:
    byte mXPin;
    byte mYPin;
    byte mButtonPin;
    int deadzone;
};

#endif

