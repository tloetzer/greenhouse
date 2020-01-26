#include "valve.hpp"

#include "Arduino.h"

Valve::Valve(int pin_)
    : pin(pin_)
{
    pinMode(pin_, OUTPUT);
}

void Valve::enableWater()
{
    digitalWrite(pin, HIGH);
    watering = true;
}

void Valve::disableWater()
{
    digitalWrite(pin, LOW);
    watering = false;
}
