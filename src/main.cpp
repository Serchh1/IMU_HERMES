#include <Arduino.h>
#include <IMU.h>
#include <Wire.h>

IMU_hermes::IMU_hermes(uint8_t address) : i2cAddress(address),
  previousTime(0), quatI(0), quatJ(0), quatK(0), quatReal(0), quatRadianAccuracy(0) {}

void IMU_hermes::begin() 
{
  // Init Serial Monitor
  Serial.begin(115200);
  Wire.begin();
  hermes.begin(i2cAddress);
  Wire.setClock(400000);
  hermes.enableRotationVector(10);
}

void IMU_hermes::update(int interval) 
{
  if ((millis() - previousTime) > interval) 
  {
    getUpdate();
    previousTime = millis();
  }
}

void IMU_hermes::getUpdate() 
{
  if (hermes.dataAvailable() == true) 
  {
    float quatI = hermes.getQuatI();
    float quatJ = hermes.getQuatJ();
    float quatK = hermes.getQuatK();
    float quatReal = hermes.getQuatReal();
    float quatRadianAccuracy = hermes.getQuatRadianAccuracy();
  } else 
  {
    Serial.println("No data available");
  }
}