#include "rgbled.h"
#include "color.h"
#include "joystick.h"

const byte pinX{ A0 };
const byte pinY{ A1 };
const byte pinJoybtn{ 3 };
const double deadzone{ 0.05 };

Joystick joystick{ pinX, pinY, pinJoybtn, deadzone };

volatile bool paused{ false };
long lastClick{};

void onClick()
{
    if (millis() - lastClick > 10)
    {
        Serial.println("CLICKED");
        paused = !paused;
        lastClick = millis();
    }
}

void setup()
{
    Serial.begin(9600);
    joystick.setOnClick(onClick);
}

void loop()
{
    const Joystick::State &joy = joystick.getState();
    Serial.print("Angle: ");
    Serial.println(joy.angle);
    Serial.print("Mag: ");
    Serial.println(joy.magnitude);
    Serial.print("Clicked: ");
    Serial.println(joy.pressed);
	Serial.println("\n");
    delay(100);
}
