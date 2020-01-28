#include <unity.h>

#include <sensor.hpp>
#include <sensorreader.hpp>

class FakeSensorReader: public SensorReader
{
public:
    FakeSensorReader()
        : SensorReader(0), value(0)
    {}

    virtual int currentValue()
    {
        return value;
    }

    void setNextValue(int value_)
    {
        value = value_;
    }

private:
    int value;
};

void test_dry_if_moisture_low()
{
    FakeSensorReader reader;
    Sensor sensor(&reader);
    reader.setNextValue(0);
    TEST_ASSERT(sensor.isDry());
}

void runTests()
{
    UNITY_BEGIN();
    test_dry_if_moisture_low();
    UNITY_END();
}

#ifdef ARDUINO

#include <Arduino.h>

void setup() {
    delay(2000);
    runTests();
}

void loop()
{
}

#else

int main(int argc, char **argv)
{
    runTests();
}

#endif
