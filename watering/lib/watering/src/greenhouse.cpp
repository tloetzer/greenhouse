#include "greenhouse.hpp"

Greenhouse::Greenhouse(Clock* clock_, Sensor* sensor_, Pump* pump_, double wateringDuration_)
    : clock(clock_), sensor(sensor_), pump(pump_), startOfCurrentWatering(0), wateringDuration(wateringDuration_)
{
}

void Greenhouse::control()
{
    if(pump->isWatering() && difftime(clock->currentTime(), startOfCurrentWatering) > wateringDuration)
    {
        pump->disableWater();
        //wait at least one cycle before re-enabling watering
        return;
    }
    if(sensor->isDry())
    {
        pump->enableWater();
        startOfCurrentWatering = clock->currentTime();
    }
}
