#include "RotationSensor.h"

RotationSensor::RotationSensor(){}

void RotationSensor::init(){
    Wire.begin();
    as5600.begin(23);
    as5600.setDirection(AS5600_CLOCK_WISE);
    int b = as5600.isConnected();
    Serial.print("Connect: ");
    Serial.println(b);

    delay(1000);

    Serial.println("Sensor iniciado");
}


float RotationSensor::readAngle(){
    Serial.print("\tω = ");
    Serial.println(as5600.getAngularSpeed(AS5600_MODE_RPM));
    delay(100);
}

void RotationSensor::testRotSensor(){
    readAngle();
}