#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "sensorreader.hpp"

class Sensor
{
public:
    Sensor(int pin);
    Sensor(SensorReader* reader);

    bool isDry();
private:
    SensorReader* reader;
};

#endif
