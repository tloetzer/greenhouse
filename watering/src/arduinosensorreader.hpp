#ifndef ARDUINOSENSORREADER_HPP
#define ARDUINOSENSORREADER_HPP
#include <sensorreader.hpp>

class ArduinoSensorReader: public SensorReader
{
public:
    ArduinoSensorReader(int pin);

    virtual int currentValue();
private:
    const int pin;

};
#endif