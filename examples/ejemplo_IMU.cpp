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
    
    Serial.print(imu.quatI, 2);
    Serial.print(F(","));
    Serial.print(imu.quatJ, 2);
    Serial.print(F(","));
    Serial.print(imu.quatK, 2);
    Serial.print(F(","));
    Serial.print(imu.quatReal, 2);
    Serial.print(F(","));
    Serial.print(imu.quatRadianAccuracy, 2);
    Serial.print(F(","));
    Serial.println();
}