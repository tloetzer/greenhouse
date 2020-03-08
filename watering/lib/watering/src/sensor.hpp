#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "sensorreader.hpp"

class Sensor
{
public:
    Sensor(SensorReader* reader);

    bool isDry();
private:
    SensorReader* reader;
};

#endif
