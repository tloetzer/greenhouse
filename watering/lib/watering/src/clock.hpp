#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <time.h>

class Clock
{
public:
    Clock() {}

    virtual time_t currentTime() = 0;
};

#endif
