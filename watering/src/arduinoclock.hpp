#ifndef ARDUINOCLOCK_HPP
#define ARDUINOCLOCK_HPP

#include <clock.hpp>

class ArduinoClock: public Clock
{
public:
    virtual time_t currentTime();
};

#endif
