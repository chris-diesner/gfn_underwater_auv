#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

void setup()
{
    Serial.begin(9600);
    Wire.begin();

    byte status = mpu.begin();
    while (status != 0)
    {
        Serial.print("MPU6050 Error: ");
        Serial.println(status);
        delay(1000);
    }

    mpu.calcOffsets(); // Gyro & Accel kalibrieren
    Serial.println("MPU6050 ready.");
}

void loop()
{
    mpu.update();

    Serial.print("AngleX: ");
    Serial.print(mpu.getAngleX());
    Serial.print("  AngleY: ");
    Serial.print(mpu.getAngleY());
    Serial.print("  AngleZ: ");
    Serial.println(mpu.getAngleZ());

    delay(20);
}
