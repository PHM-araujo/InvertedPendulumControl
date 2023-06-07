#include "MotorDrive.h"
#include <Arduino.h>


void MotorDrive::init(){
    pinMode(26, OUTPUT);
    pinMode(25, OUTPUT);
}


void MotorDrive::setSpeed(int pwm){
    if(pwm >= 0){
        analogWrite(AIN2, pwm);
        analogWrite(AIN1, LOW);
    }else{
        pwm = -1*pwm;
        analogWrite(AIN1, pwm);
        analogWrite(AIN2, LOW);
    }
}

void MotorDrive::stop(){
    Serial.println("Parada total");

	analogWrite(AIN2, 0); 
	analogWrite(AIN1, 0); 

}

void MotorDrive::testeDrive(){
    Serial.println("Motor girando para direita");
    analogWrite(AIN2, 255);
    analogWrite(AIN1, 0);
    delay(1000);

    Serial.println("Motor girando para esquerda");
    analogWrite(AIN1, 255);
    analogWrite(AIN2, 0);
    delay(1000);

    stop();
    delay(5000);
}
