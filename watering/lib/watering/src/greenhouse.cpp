#include "greenhouse.hpp"

Greenhouse::Greenhouse(Sensor* sensor_, Valve* valve_)
    : sensor(sensor_), valve(valve_)
{
}

void Greenhouse::control()
{
    if(sensor->isDry())
    {
        valve->enableWater();
    }
    else
    {
        valve->disableWater();
    }
}
