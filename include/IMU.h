#pragma once
#include <Arduino.h>
#include <SparkFun_BNO080_Arduino_Library.h>
#include <Wire.h>

class IMU_hermes
{
public:
    IMU_hermes();
    void updateData();
    void begin();
    float quatI, quatJ, quatK, quatReal;

private:
    BNO080 myIMU;
};