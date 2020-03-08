#include "arduinoclock.hpp"

#include "Arduino.h"

time_t ArduinoClock::currentTime()
{
    return millis();
}
