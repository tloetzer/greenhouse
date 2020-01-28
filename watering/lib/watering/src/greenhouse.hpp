#ifndef GREENHOUSE_HPP
#define GREENHOUSE_HPP
#include "sensor.hpp"
#include "valve.hpp"
#include "clock.hpp"

class Greenhouse
{
public:
    Greenhouse(Clock* clock, Sensor* sensor, Valve* valve);
    void control();
private:
    Clock* clock;
    Sensor* sensor;
    Valve* valve;
};

#endif
