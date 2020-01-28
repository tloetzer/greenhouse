#include "arduinovalve.hpp"

#include <Arduino.h>

ArduinoValve::ArduinoValve(int pin_)
    : pin(pin_)
{
    pinMode(pin_, OUTPUT);
}

void ArduinoValve::enableWater()
{
    digitalWrite(pin, HIGH);
    Valve::enableWater();
}

void ArduinoValve::disableWater()
{
    digitalWrite(pin, LOW);
    Valve::disableWater();
}
