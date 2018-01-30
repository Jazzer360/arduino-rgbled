#include "color.h"

Color Color::blend(const Color & c1, const Color & c2, double ratio)
{
    byte r = c1.red * (1 - ratio) + c2.red * ratio;
    byte g = c1.green * (1 - ratio) + c2.green * ratio;
    byte b = c1.blue * (1 - ratio) + c2.blue * ratio;
    return Color(r, g, b);
}

Color Color::fromAngle(double angle)
{
    const byte segment = angle / (PI / 3);
    const double ratio = fmod(angle, (PI / 3)) / (PI / 3);
    switch (segment)
    {
    case 0:
	case 6:
        return Color::blend(Color(RED), Color(ORANGE), ratio);
    case 1:
        return Color::blend(Color(ORANGE), Color(YELLOW), ratio);
    case 2:
        return Color::blend(Color(YELLOW), Color(GREEN), ratio);
    case 3:
        return Color::blend(Color(GREEN), Color(BLUE), ratio);
    case 4:
        return Color::blend(Color(BLUE), Color(PURPLE), ratio);
    case 5:
        return Color::blend(Color(PURPLE), Color(RED), ratio);
    default:
        return Color(OFF);
    }
}
