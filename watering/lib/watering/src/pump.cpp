#include "pump.hpp"

Pump::Pump()
{
}

void Pump::enableWater()
{
    watering = true;
}

void Pump::disableWater()
{
    watering = false;
}
