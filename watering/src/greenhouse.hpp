#ifndef GREENHOUSE_HPP
#define GREENHOUSE_HPP
#include "sensor.hpp"
#include "valve.hpp"

class Greenhouse
{
public:
    Greenhouse(Sensor* sensor, Valve* valve);
    void control();
private:
    Sensor* sensor;
    Valve* valve;
};

#endif
