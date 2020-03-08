#include <Arduino.h>

#include "arduinosensorreader.hpp"

ArduinoSensorReader::ArduinoSensorReader(int pin_)
    : pin(pin_)
{
    pinMode(pin, INPUT);
}

int ArduinoSensorReader::currentValue()
{
    return analogRead(pin);
}