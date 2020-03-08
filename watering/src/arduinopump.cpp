#include "arduinopump.hpp"

#include <Arduino.h>

ArduinoPump::ArduinoPump(int pin_)
    : pin(pin_)
{
    pinMode(pin_, OUTPUT);
}

void ArduinoPump::enableWater()
{
    digitalWrite(pin, HIGH);
    Pump::enableWater();
}

void ArduinoPump::disableWater()
{
    digitalWrite(pin, LOW);
    Pump::disableWater();
}
