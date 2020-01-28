#ifndef SENSORREADER_HPP
#define SENSORREADER_HPP

class SensorReader
{
public:
    SensorReader();

    virtual int currentValue() = 0;
};

#endif
