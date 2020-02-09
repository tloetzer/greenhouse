#include "greenhouse.hpp"

Greenhouse::Greenhouse(Clock* clock_, Sensor* sensor_, Pump* pump_, double wateringDuration_, double wateringCooldown_)
    : clock(clock_), sensor(sensor_), pump(pump_), startOfCurrentWatering(0),
        wateringDuration(wateringDuration_), wateringCooldown(wateringCooldown_)
{
}

double Greenhouse::currentWateringDurationMinutes() {
    return difftime(clock->currentTime(), startOfCurrentWatering) / 60;
}

double Greenhouse::minutesSinceLastWatering() {
    return (difftime(clock->currentTime(), startOfCurrentWatering) - (wateringDuration * 60)) / 60;
}

void Greenhouse::control()
{
    if(pump->isWatering() && (currentWateringDurationMinutes() > wateringDuration))
    {
        pump->disableWater();
    }
    if(sensor->isDry() && (minutesSinceLastWatering() > wateringCooldown))
    {
        pump->enableWater();
        startOfCurrentWatering = clock->currentTime();
    }
}

