#ifndef ARDUINOVALVE_HPP
#define ARDUINOVALVE_HPP

#include <valve.hpp>

class ArduinoValve: public Valve
{
public:
    ArduinoValve(int pin);

    void enableWater();
    void disableWater();
private:
    int pin;
};

#endif
