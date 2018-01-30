#include "joystick.h"

const Joystick::State& Joystick::getState()
{
    int x = analogRead(mXPin) - 511;
    int y = analogRead(mYPin) - 511;
    mState.angle = atan2(y, x) + PI;
    mState.magnitude = sqrt(static_cast<long>(x) * x + static_cast<long>(y) * y);
    mState.magnitude = min(mState.magnitude, 512.0) / 512.0;
    mState.pressed = digitalRead(mButtonPin) == LOW;
    if (mState.magnitude < mDeadzone)
    {
        mState.magnitude = 0.0;
        mState.angle = 0.0;
    }
    return mState;
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
    pinMode(mXPin, INPUT);
    pinMode(mYPin, INPUT);
    pinMode(mButtonPin, INPUT_PULLUP);
}
