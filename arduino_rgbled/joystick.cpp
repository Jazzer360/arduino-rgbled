#include "joystick.h"

Joystick::State Joystick::getState() const
{
    int x = analogRead(mXPin) - 511;
    int y = analogRead(mYPin) - 511;
    double angle = atan2(y, x) + PI;
    double magnitude = sqrt(static_cast<long>(x) * x + static_cast<long>(y) * y);
    magnitude = min(magnitude, 512.0) / 512.0;
    bool pressed = digitalRead(mButtonPin) == HIGH;
    if (magnitude < mDeadzone)
    {
        magnitude = 0.0;
        angle = 0.0;
    }
    return Joystick::State{ angle, magnitude, pressed };
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

void Joystick::init() const
{   
    pinMode(mXPin, INPUT_PULLUP);
    pinMode(mYPin, INPUT_PULLUP);
    pinMode(mButtonPin, INPUT_PULLUP);
}
