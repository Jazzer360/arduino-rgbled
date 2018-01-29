#include "joystick.h"

const Joystick::State Joystick::getState()
{
    int x = analogRead(mXPin) - 511;
    int y = analogRead(mYPin) - 511;
    double angle = atan2(y, x) + PI;
    double mag = sqrt(static_cast<long>(x) * x + static_cast<long>(y) * y);
    mag = min(mag, 512.0) / 512.0;
    bool clicked = digitalRead(mButtonPin) == HIGH;
    if (mag < mDeadzone)
    {
        mag = 0.0;
        angle = 0.0;
    }
    return Joystick::State{ angle, mag, clicked };
}

void Joystick::setOnClick(void(*function)())
{
    mOnClick = function;
    attachInterrupt(digitalPinToInterrupt(mButtonPin), mOnClick, LOW);
}

void Joystick::removeOnClick()
{
    detachInterrupt(digitalPinToInterrupt(mButtonPin));
    mOnClick = nullptr;
}

const void Joystick::init()
{
    pinMode(mXPin, INPUT_PULLUP);
    pinMode(mYPin, INPUT_PULLUP);
    pinMode(mButtonPin, INPUT_PULLUP);
}
