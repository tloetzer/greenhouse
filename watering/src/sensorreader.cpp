#include "sensorreader.hpp"
#include "Arduino.h"

SensorReader::SensorReader(int pin_)
    : pin(pin_)
{
    pinMode(pin, INPUT);
}

int SensorReader::currentValue()
{
    return analogRead(pin);
}
