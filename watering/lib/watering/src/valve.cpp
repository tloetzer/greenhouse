#include "valve.hpp"

Valve::Valve()
{
}

void Valve::enableWater()
{
    watering = true;
}

void Valve::disableWater()
{
    watering = false;
}
