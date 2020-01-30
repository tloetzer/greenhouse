#ifndef PUMP_HPP
#define PUMP_HPP

class Pump
{
public:
    Pump();

    bool isWatering()
    {
        return watering;
    }

    void enableWater();
    void disableWater();

private:
    bool watering;
};

#endif
