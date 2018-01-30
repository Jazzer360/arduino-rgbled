#include "rgbled.h"

void RGBLED::setColor(const Color &color, double brightness)
{
    analogWrite(mRPin, color.red * brightness);
    analogWrite(mGPin, color.green * brightness);
    analogWrite(mBPin, color.blue * brightness);
}

void RGBLED::init() const
{
	pinMode(mRPin, OUTPUT);
	pinMode(mGPin, OUTPUT);
	pinMode(mBPin, OUTPUT);
}
