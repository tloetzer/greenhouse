#ifndef SENSORREADER_HPP
#define SENSORREADER_HPP

class SensorReader
{
public:
    SensorReader(int pin);

    virtual int currentValue();
private:
    const int pin;
};

#endif
