#include "rgbled.h"
#include "color.h"
#include "joystick.h"

const byte pinX{ PIN_A0 };
const byte pinY{ PIN_A1 };
const byte pinJoybtn{ 3 };
const double deadzone{ 0.05 };

Joystick joystick{ pinX, pinY, pinJoybtn, deadzone };

void onClick()
{
    Serial.println("CLICKED");
}

void setup()
{
    Serial.begin(9600);
    joystick.setOnClick(onClick);
}

void loop()
{

}
