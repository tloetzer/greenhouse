#ifdef ARDUINO
#include <Arduino.h>
#endif

#include <stddef.h>
#include <sensor.hpp>
#include <pump.hpp>
#include <greenhouse.hpp>
#include "arduinosensorreader.hpp"
#include "arduinopump.hpp"

static const size_t GREENHOUSE_COUNT = 4;

Greenhouse* greenhouses[GREENHOUSE_COUNT];

#ifdef ARDUINO
void setup()
{
    greenhouses[0] = new Greenhouse(new Sensor(new ArduinoSensorReader(A0)), new ArduinoPump(10));
    greenhouses[1] = new Greenhouse(new Sensor(new ArduinoSensorReader(A1)), new ArduinoPump(11));
    greenhouses[2] = new Greenhouse(new Sensor(new ArduinoSensorReader(A2)), new ArduinoPump(12));
    greenhouses[3] = new Greenhouse(new Sensor(new ArduinoSensorReader(A3)), new ArduinoPump(13));
}

void loop()
{
    for(size_t i=0; i < GREENHOUSE_COUNT; ++i)
    {
        greenhouses[i]->control();
    }
}

#endif
