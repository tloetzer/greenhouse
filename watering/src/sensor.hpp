#ifndef SENSOR_HPP
#define SENSOR_HPP

class Sensor
{
public:
    Sensor(int pin);
    bool isDry();
private:
    int pin;
};

#endif
