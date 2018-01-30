#ifndef _JOYSTICK_h
#define _JOYSTICK_h

#include "Arduino.h"

class Joystick
{
public:
    struct State {
        double angle;
        double magnitude;
        bool pressed;
    };
    Joystick(byte xPin, byte yPin, byte buttonPin)
        : Joystick(xPin, yPin, buttonPin, 0)
    { init(); }
    Joystick(byte xPin, byte yPin, byte buttonPin, double deadzone)
        : mXPin{ xPin }, mYPin{ yPin }, mButtonPin{ buttonPin },
        mDeadzone{ deadzone }
    { init(); }
    const State& getState();
    void setOnClick(void(*)());
    void removeOnClick();
private:
    const byte mXPin;
    const byte mYPin;
    const byte mButtonPin;
    const double mDeadzone;
	State mState{ 0.0, 0.0, false };
	void (*mOnClick)() { nullptr };
    void init() const;
};

#endif
