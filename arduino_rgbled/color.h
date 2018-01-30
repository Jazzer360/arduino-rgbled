#ifndef _COLOR_h
#define _COLOR_h

#include "Arduino.h"

#define RED 0x00FF0000
#define ORANGE 0x00BF1F00
#define YELLOW 0x00FF7F00
#define GREEN 0x00007F00
#define BLUE 0X000000FF
#define PURPLE 0x007F002F
#define OFF 0x00000000

class Color {
public:
    const byte red;
    const byte green;
    const byte blue;
    Color(long c) : Color(c >> 16, c >> 8, c) {}
    Color(byte r, byte g, byte b) : red{ r }, green{ g }, blue{ b } {}
    static Color blend(const Color &c1, const Color &c2, double ratio);
};

#endif
