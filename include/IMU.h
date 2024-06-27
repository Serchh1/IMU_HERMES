#pragma once
#include <SparkFun_BNO080_Arduino_Library.h>
#include <Wire.h>

class IMU_hermes
{
public:
    IMU_hermes(uint8_t address = 0x4A);
    void begin();
    void update(int interval);

private:
    BNO080 hermes;
    unsigned long previousTime;
    uint8_t i2cAddress;
    void getUpdate();
};