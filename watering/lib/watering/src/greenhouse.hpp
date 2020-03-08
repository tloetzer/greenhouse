#ifndef GREENHOUSE_HPP
#define GREENHOUSE_HPP
#include "sensor.hpp"
#include "pump.hpp"
#include "clock.hpp"

class Greenhouse
{
public:
    Greenhouse(Clock* clock, Sensor* sensor, Pump* pump, double wateringDuration, double wateringCooldown, double wateringCooldownAfterMoist);
    void control();
private:
    Clock* clock;
    Sensor* sensor;
    Pump* pump;
    time_t startOfCurrentWatering;
    double wateringDuration;
    double wateringCooldown;
    double wateringCooldownAfterMoist;
    double currentWateringDurationSeconds();
    double secondsSinceLastWatering();
    bool wateringBlocked;
};

#endif
