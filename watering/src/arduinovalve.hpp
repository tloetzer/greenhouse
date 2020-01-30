#ifndef ARDUINOPUMP_HPP
#define ARDUINOPUMP_HPP

#include <pump.hpp>

class ArduinoPump: public Pump
{
public:
    ArduinoPump(int pin);

    void enableWater();
    void disableWater();
private:
    int pin;
};

#endif
