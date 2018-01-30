#include "joystick.h"

void Joystick::update()
{
    int x = analogRead(mXPin) - 511;
    int y = analogRead(mYPin) - 511;
    mState.angle = atan2(y, x) + PI;
    mState.magnitude = sqrt(static_cast<long>(x) * x + static_cast<long>(y) * y);
    mState.magnitude = min(mState.magnitude, 512.0) / 512.0;
    if (mState.magnitude < mDeadzone)
    {
        mState.magnitude = 0.0;
        mState.angle = 0.0;
    }
    int buttonState = digitalRead(mButtonPin);
    if (buttonState != (mState.pressed ? LOW : HIGH))
    {
        mState.pressed = (buttonState == LOW);
        if (mOnClick && mState.pressed) mOnClick(mState);
    }
    if (mOnUpdate) mOnUpdate(mState);
}

void Joystick::setOnClick(void(*function)(const State &))
{
    mOnClick = function;
}

void Joystick::setOnUpdate(void(*function)(const State &))
{
    mOnUpdate = function;
}

void Joystick::removeOnClick()
{
    mOnClick = nullptr;
}

void Joystick::removeOnUpdate()
{
    mOnUpdate = nullptr;
}

void Joystick::init() const
{   
    pinMode(mXPin, INPUT);
    pinMode(mYPin, INPUT);
    pinMode(mButtonPin, INPUT_PULLUP);
}
