#include "sensor.hpp"

#include "Arduino.h"

Sensor::Sensor(int pin_)
    : pin(pin_)
{
    pinMode(pin, INPUT);
}

bool Sensor::isDry()
{
    return false;
}

