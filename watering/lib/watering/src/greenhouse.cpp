#include "greenhouse.hpp"

Greenhouse::Greenhouse(Clock* clock_, Sensor* sensor_, Pump* pump_, double wateringDuration_, double wateringCooldown_)
    : clock(clock_), sensor(sensor_), pump(pump_), startOfCurrentWatering(0),
        wateringDuration(wateringDuration_), wateringCooldown(wateringCooldown_)
{
}

double Greenhouse::currentWateringDurationSeconds() {
    return difftime(clock->currentTime(), startOfCurrentWatering);
}

double Greenhouse::secondsSinceLastWatering() {
    return difftime(clock->currentTime(), startOfCurrentWatering) - wateringDuration;
}

void Greenhouse::control()
{
    if(pump->isWatering() && (currentWateringDurationSeconds() > wateringDuration))
    {
        pump->disableWater();
    }
    if(sensor->isDry() && (secondsSinceLastWatering() > wateringCooldown))
    {
        pump->enableWater();
        startOfCurrentWatering = clock->currentTime();
    }
}

