#include "rgbled.h"
#include "color.h"
#include "joystick.h"

const byte pinX{ A0 };
const byte pinY{ A1 };
const byte pinJoybtn{ 3 };
const double deadzone{ 0.05 };

Joystick joystick{ pinX, pinY, pinJoybtn, deadzone };

const byte pinR{ 9 };
const byte pinG{ 10 };
const byte pinB{ 11 };

RGBLED led{ pinR, pinG, pinB };

volatile bool paused{ false };
long lastClick{};

void onClick()
{
    if (millis() - lastClick > 10)
    {
        paused = !paused;
        lastClick = millis();
    }
}

Color angleToColor(double angle) {
    const byte segment = angle / (PI / 3);
    const double ratio = fmod(angle, (PI / 3)) / (PI / 3);
    switch (segment)
    {
    case 0:
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

void setup()
{
    joystick.setOnClick(onClick);
}

void loop()
{
    if (!paused)
    {
        const Joystick::State &joy = joystick.getState();
        Color color = angleToColor(joy.angle);
        led.setColor(color, joy.magnitude);
    }
}
