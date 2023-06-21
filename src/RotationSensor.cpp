#include "RotationSensor.h"
#include <Arduino.h>


void RotationSensor::init(){
    // Inicia comunicação I2C
    Wire.begin();

    // Configura direção 
    as5600.begin(23);
    as5600.setDirection(AS5600_CLOCK_WISE);

    // Checa se o sensor está conectado 
    int b = as5600.isConnected();
    Serial.print("Connect: ");
    Serial.println(b);

    delay(1000);

    Serial.println("Sensor iniciado");

    // Posição inicial
    as5600.resetCumulativePosition(0);
}


float RotationSensor::readAngle(){
    return as5600.getCumulativePosition() / angle_max;
}
