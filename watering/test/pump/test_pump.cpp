#include <unity.h>

#include <pump.hpp>

void test_watering_status_enabled()
{
    Pump p;
    p.enableWater();
    TEST_ASSERT_TRUE(v.isWatering());
}

void test_watering_status_disabled()
{
    Pump p;
    p.disableWater();
    TEST_ASSERT_FALSE(v.isWatering());
}

void runTests()
{
    UNITY_BEGIN();
    RUN_TEST(test_watering_status_enabled);
    RUN_TEST(test_watering_status_disabled);
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
