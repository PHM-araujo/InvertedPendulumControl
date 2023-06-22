#include "MotorDrive.h"
#include <Arduino.h>


void MotorDrive::init(){
    pinMode(26, OUTPUT);
    pinMode(25, OUTPUT);
}


void MotorDrive::setSpeed(int pwm){
    if(pwm >= 0){
        // Direita
        analogWrite(AIN2, pwm);
        analogWrite(AIN1, LOW);
    }else{
        //Esquerda
        pwm = -1*pwm;
        analogWrite(AIN1, pwm);
        analogWrite(AIN2, LOW);
    }
}

void MotorDrive::stop(){

	analogWrite(AIN2, 0); 
	analogWrite(AIN1, 0); 

}

void MotorDrive::testeDrive(){
    Serial.println("Motor girando para direita");
    setSpeed(255);
    delay(500);

    Serial.println("Motor girando para esquerda");
    setSpeed(-255);
    delay(500);

    stop();
    delay(5000);
}
