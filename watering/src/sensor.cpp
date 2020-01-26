#include "sensor.hpp"

Sensor::Sensor(int pin)
{
    reader = new SensorReader(pin);
}

Sensor::Sensor(SensorReader* reader_)
    : reader(reader_)
{}

bool Sensor::isDry()
{
    //TODO: read value and decide if its dry
    return false;
}

