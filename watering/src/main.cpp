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

Greenhouse* newGreenhouse(int sensorPin, int pumpPin)
{
    Sensor* sensor = new Sensor(new ArduinoSensorReader(sensorPin));
    Pump* pump = new ArduinoPunp(pumpPin);
    double wateringDuration = 5;
    double wateringCooldown = 30;
    double wateringCooldownAfterMoist = 60*60*8; //8 hours
    return new Greenhouse(null /* TODO: clock */, sensor, pump, wateringDuration, wateringCooldown, WateringCooldownAfterMoist);

#ifdef ARDUINO
void setup()
{
    greenhouses[0] = newGreenhouse(A0, 10);
    greenhouses[1] = newGreenhouse(A1, 11);
    greenhouses[2] = newGreenhouse(A2, 12);
    greenhouses[3] = newGreenhouse(A3, 13);
}

void loop()
{
    for(size_t i=0; i < GREENHOUSE_COUNT; ++i)
    {
        greenhouses[i]->control();
    }
}

#endif
