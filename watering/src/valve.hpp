#ifndef VALVE_HPP
#define VALVE_HPP

class Valve
{
public:
    Valve(int pin);

    bool isWatering()
    {
        return watering;
    }

    void enableWater();
    void disableWater();
private:
    bool watering;
    int pin;
};

#endif
