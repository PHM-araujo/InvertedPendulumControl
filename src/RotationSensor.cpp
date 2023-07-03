#include "RotationSensor.h"
#include <Arduino.h>

void RotationSensor::init(){
    // Inicia comunicação I2C
    Wire.begin();

    // Configura direção 
    as5600.begin(23);
    as5600.setDirection(AS5600_COUNTERCLOCK_WISE);

    // Checa se o sensor está conectado 
    int b = as5600.isConnected();
    Serial.print("Connect: ");
    Serial.println(b);

    delay(1000);
}

float RotationSensor::readAngle(){

    float angle = as5600.getCumulativePosition() / angle_max;   

    // Checa se é um valor de angulo válido
    while(abs(angle) > 35) angle = as5600.getCumulativePosition() / angle_max;

    return angle;
}

void RotationSensor::calibSensor(){
    Serial.println("Configurando angulo inicial ...");

    // Posição inicial
    unsigned long timer = millis();
    while(millis() - timer <= 10){
        as5600.resetCumulativePosition(0);
    }

    Serial.println("Angulo inicial configurado");
}
