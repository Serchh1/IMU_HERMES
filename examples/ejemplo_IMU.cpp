#include <Arduino.h>
#include <IMU.h>

IMU_hermes imu;

void setup()
{
    imu.begin();
}

void loop()
{
    imu.update(10);
}