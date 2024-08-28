#include <Arduino.h>
#include <IMU.h>

IMU_hermes::IMU_hermes()
    :quatI(0), quatJ(0), quatK(0), quatReal(0) {}

void IMU_hermes::begin() 
{
  // Init Serial Monitor
  Serial.begin(115200);
    Wire.begin();
  if (myIMU.begin(0x4A) == false)
  {
    Serial.println("BNO080 not detected at default I2C address. Check your jumpers and the hookup guide. Freezing...");
    while (1);
  }
  Wire.setClock(400000);
  myIMU.enableRotationVector(20);
}

void IMU_hermes::updateData() 
{
  if (myIMU.dataAvailable() == true) 
  {
    float quatI = myIMU.getQuatI();
    float quatJ = myIMU.getQuatJ();
    float quatK = myIMU.getQuatK();
    float quatReal = myIMU.getQuatReal();
  } 
  else 
  {
    Serial.println("No data available");
  }
}