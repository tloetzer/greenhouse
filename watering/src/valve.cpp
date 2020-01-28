#include "valve.hpp"

#ifdef ARDUINO
#include "Arduino.h"
#endif

Valve::Valve(int pin_)
    : pin(pin_)
{
#ifdef ARDUINO
    pinMode(pin_, OUTPUT);
#endif
}

void Valve::enableWater()
{
#ifdef ARDUINO
    digitalWrite(pin, HIGH);
#endif
    watering = true;
}

void Valve::disableWater()
{
#ifdef ARDUINO
    digitalWrite(pin, LOW);
#endif
    watering = false;
}
