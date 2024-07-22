#pragma once
#include <SparkFun_BNO080_Arduino_Library.h>
#include <Wire.h>

class IMU_hermes
{
public:
    IMU_hermes(uint8_t address = 0x4A);
    BNO080 hermes;
    void begin();
    void update(int interval);
    float quatI, quatJ, quatK, quatReal, quatRadianAccuracy;

private:
    unsigned long previousTime;
    uint8_t i2cAddress;
    void getUpdate();
};