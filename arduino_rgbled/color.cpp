#include "color.h"

Color Color::blend(const Color & c1, const Color & c2, double ratio)
{
    byte r = c1.red * (1 - ratio) + c2.red * ratio;
    byte g = c1.green * (1 - ratio) + c2.green * ratio;
    byte b = c1.blue * (1 - ratio) + c2.blue * ratio;
    return Color(r, g, b);
}
