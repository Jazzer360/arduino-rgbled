#ifndef _RGBLED_h
#define _RGBLED_h

#include "Arduino.h"
#include "color.h"

class RGBLED {
public:
	RGBLED(byte rPin, byte gPin, byte bPin)
        : mRPin{ rPin }, mGPin{ gPin }, mBPin{ bPin }
	{ init(); }
	void setColor(const Color &color, double brightness=1.0);
private:
	const byte mRPin;
	const byte mGPin;
	const byte mBPin;
	void init() const;
};

#endif
