#include <unity.h>

#include <sensor.hpp>
#include <sensorreader.hpp>
#include <valve.hpp>
#include <clock.hpp>
#include <greenhouse.hpp>

class FakeSensorReader: public SensorReader
{
public:
    FakeSensorReader()
        : SensorReader(), value(0)
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

class FakeClock: public Clock
{
    virtual time_t currentTime()
    {
        return time;
    }

    time_t time;
};

void test_water_if_dry()
{
    FakeSensorReader reader;
    Sensor sensor(&reader);
    reader.setNextValue(0);
    Valve v;
    FakeClock c;
    Greenhouse gh(&c, &sensor, &v);
    gh.control();
    TEST_ASSERT_TRUE(v.isWatering());
}


void runTests()
{
    UNITY_BEGIN();
    RUN_TEST(test_water_if_dry);
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
