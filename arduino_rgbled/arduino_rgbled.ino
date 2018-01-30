#include "rgbled.h"
#include "color.h"
#include "joystick.h"

const byte pinX{ A0 };
const byte pinY{ A1 };
const byte pinJoybtn{ 3 };
const double deadzone{ 0.05 };

const byte pinR{ 9 };
const byte pinG{ 10 };
const byte pinB{ 11 };

Joystick joystick{ pinX, pinY, pinJoybtn, deadzone };
RGBLED led{ pinR, pinG, pinB };

volatile bool paused{ false };

void onClick(const Joystick::State &state)
{
    paused = !paused;
}

void onUpdate(const Joystick::State &state)
{
    if (!paused)
    {
        Color color = Color::fromAngle(state.angle);
        led.setColor(color, state.magnitude);
    }
}

void setup()
{
    joystick.setOnClick(onClick);
    joystick.setOnUpdate(onUpdate);
}

void loop()
{
    joystick.update();
}
