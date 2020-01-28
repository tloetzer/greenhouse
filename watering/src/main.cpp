#ifdef ARDUINI
#include <Arduino.h>
#endif

#include <stddef.h>
#include "sensor.hpp"
#include "valve.hpp"
#include "greenhouse.hpp"

static const size_t GREENHOUSE_COUNT = 4;

Greenhouse* greenhouses[GREENHOUSE_COUNT];

#ifdef ARDUINO
void setup()
{
    greenhouses[0] = new Greenhouse(new Sensor(A0), new Valve(10));
    greenhouses[1] = new Greenhouse(new Sensor(A1), new Valve(11));
    greenhouses[2] = new Greenhouse(new Sensor(A2), new Valve(12));
    greenhouses[3] = new Greenhouse(new Sensor(A3), new Valve(13));
}

void loop()
{
    for(size_t i=0; i < GREENHOUSE_COUNT; ++i)
    {
        greenhouses[i]->control();
    }
}

#endif
