#include <unity.h>

#include <sensor.hpp>
#include <sensorreader.hpp>
#include <pump.hpp>
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
public:
    FakeClock()
    {
        time.tm_sec = 0;
        time.tm_min = 0;
        time.tm_hour = 0;
        time.tm_mday = 1;
        time.tm_mon = 0;
        time.tm_year = 2020;
        time.tm_isdst = 0;
    }

    virtual time_t currentTime()
    {
        return mktime(&time);
    }

    tm time;
};

const int drySensorValue = 0;
const int moistSensorValue = 1023;
const int wateringDuration = 2;

void test_water_if_dry()
{
    FakeSensorReader reader;
    Sensor sensor(&reader);
    reader.setNextValue(drySensorValue);
    Pump p;
    FakeClock c;
    Greenhouse gh(&c, &sensor, &p, wateringDuration);
    gh.control();
    TEST_ASSERT_TRUE(p.isWatering());
}

void test_no_water_if_moist()
{
    FakeSensorReader reader;
    Sensor sensor(&reader);
    reader.setNextValue(moistSensorValue);
    Pump p;
    FakeClock c;
    Greenhouse gh(&c, &sensor, &p, wateringDuration);
    gh.control();
    TEST_ASSERT_FALSE(p.isWatering());
}

void test_watering_stops_after_time()
{
    FakeSensorReader reader;
    Sensor sensor(&reader);
    reader.setNextValue(drySensorValue);
    Pump p;
    FakeClock c;
    Greenhouse gh(&c, &sensor, &p, wateringDuration);
    gh.control();
    TEST_ASSERT_TRUE(p.isWatering());
    c.time.tm_min = c.time.tm_min + wateringDuration + 1;
    gh.control();
    TEST_ASSERT_FALSE(p.isWatering());
}

void runTests()
{
    UNITY_BEGIN();
    RUN_TEST(test_water_if_dry);
    RUN_TEST(test_no_water_if_moist);
    RUN_TEST(test_watering_stops_after_time);
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
