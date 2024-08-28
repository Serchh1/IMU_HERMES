#include <Arduino.h>
#include <IMU.h>

IMU_hermes myIMU;

void setup()
{
    myIMU.begin();
}

void loop()
{   
    Serial.print(myIMU.quatI, 2);
    Serial.print(F(","));
    Serial.print(myIMU.quatJ, 2);
    Serial.print(F(","));
    Serial.print(myIMU.quatK, 2);
    Serial.print(F(","));
    Serial.print(myIMU.quatReal, 2);
    Serial.println();
    delay(500);
}