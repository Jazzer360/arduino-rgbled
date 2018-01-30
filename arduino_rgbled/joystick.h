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
        : mXPin{ xPin }, mYPin{ yPin }, mButtonPin{ buttonPin }, mDeadzone{ deadzone }
    { init(); }
    void update();
    void setOnClick(void(*function)(const State &));
    void setOnUpdate(void(*function)(const State &));
    void removeOnClick();
    void removeOnUpdate();
private:
    const byte mXPin;
    const byte mYPin;
    const byte mButtonPin;
    const double mDeadzone;
	State mState{ 0.0, 0.0, false };
	void(*mOnClick)(const State &) { nullptr };
    void(*mOnUpdate)(const State &) { nullptr };
    void init() const;
};

#endif
