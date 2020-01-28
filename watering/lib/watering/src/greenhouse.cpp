#include "greenhouse.hpp"

Greenhouse::Greenhouse(Clock* clock_, Sensor* sensor_, Valve* valve_)
    : clock(clock_), sensor(sensor_), valve(valve_)
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
