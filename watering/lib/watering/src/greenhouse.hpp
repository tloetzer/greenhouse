#ifndef GREENHOUSE_HPP
#define GREENHOUSE_HPP
#include "sensor.hpp"
#include "pump.hpp"
#include "clock.hpp"

class Greenhouse
{
public:
    Greenhouse(Clock* clock, Sensor* sensor, Pump* pump, double wateringDuration);
    void control();
private:
    Clock* clock;
    Sensor* sensor;
    Pump* pump;
    time_t startOfCurrentWatering;
    double wateringDuration;
};

#endif
