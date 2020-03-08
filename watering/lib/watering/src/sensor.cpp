#include "sensor.hpp"

Sensor::Sensor(SensorReader* reader_)
    : reader(reader_)
{}

bool Sensor::isDry()
{
    return reader->currentValue() >= 400;
}

