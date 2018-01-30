#include "rgbled.h"

void RGBLED::init() const
{
	pinMode(mRPin, OUTPUT);
	pinMode(mGPin, OUTPUT);
	pinMode(mBPin, OUTPUT);
}
