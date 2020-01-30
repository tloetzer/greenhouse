#include "greenhouse.hpp"

Greenhouse::Greenhouse(Clock* clock_, Sensor* sensor_, Pump* pump_)
    : clock(clock_), sensor(sensor_), pump(pump_)
{
}

void Greenhouse::control()
{
    if(sensor->isDry())
    {
        pump->enableWater();
    }
    else
    {
        pump->disableWater();
    }
}
