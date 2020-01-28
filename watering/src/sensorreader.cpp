#include "sensorreader.hpp"
#ifdef ARDUINO
#include <Arduino.h>
#endif

SensorReader::SensorReader(int pin_)
    : pin(pin_)
{
#ifdef ARDUINO
    pinMode(pin, INPUT);
#endif
}

int SensorReader::currentValue()
{
#ifdef ARDUINO
    return analogRead(pin);
#endif
}
