#include <Arduino.h>
#include <IMU.h>
#include <Wire.h>

IMU_hermes::IMU_hermes(uint8_t address) : i2cAddress(address), previousTime(0) {}

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
    Serial.print(quatI, 2);
    Serial.print(F(","));
    Serial.print(quatJ, 2);
    Serial.print(F(","));
    Serial.print(quatK, 2);
    Serial.print(F(","));
    Serial.print(quatReal, 2);
    Serial.print(F(","));
    Serial.print(quatRadianAccuracy, 2);
    Serial.print(F(","));
    Serial.println();
  } else 
  {
    Serial.println("No data available");
  }
}