#include <unity.h>

#include <sensor.hpp>
#include <sensorreader.hpp>

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

void test_dry_if_moisture_low()
{
    FakeSensorReader reader;
    Sensor sensor(&reader);
    reader.setNextValue(400);
    TEST_ASSERT_TRUE(sensor.isDry());
}

void test_not_dry_if_moisture_high()
{
    FakeSensorReader reader;
    Sensor sensor(&reader);
    reader.setNextValue(399);
    TEST_ASSERT_FALSE(sensor.isDry());
}

void runTests()
{
    UNITY_BEGIN();
    RUN_TEST(test_dry_if_moisture_low);
    RUN_TEST(test_not_dry_if_moisture_high);
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
