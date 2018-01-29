#ifndef _JOYSTICK_h
#define _JOYSTICK_h

#include "Arduino.h"

class Joystick
{
public:
    struct State {
        const double angle;
        const double magnitude;
        const bool pressed;
    };
    Joystick(byte xPin, byte yPin, byte buttonPin)
        : Joystick(xPin, yPin, buttonPin, 0)
    { init(); }
    Joystick(byte xPin, byte yPin, byte buttonPin, double deadzone)
        : mXPin{ xPin }, mYPin{ yPin }, mButtonPin{ buttonPin },
          mDeadzone{ deadzone }, mOnClick{ nullptr }
    { init(); }
    const State getState();
    void setOnClick(void(*)());
    void removeOnClick();
private:
    const byte mXPin;
    const byte mYPin;
    const byte mButtonPin;
    const double mDeadzone;
    void (*mOnClick)();
    const void init();
};

#endif

