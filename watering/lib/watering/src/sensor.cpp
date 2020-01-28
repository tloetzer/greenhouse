#include "sensor.hpp"

Sensor::Sensor(SensorReader* reader_)
    : reader(reader_)
{}

bool Sensor::isDry()
{
    //TODO: read value and decide if its dry
    return reader->currentValue() == 0;
}

