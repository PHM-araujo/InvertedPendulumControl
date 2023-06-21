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

	analogWrite(AIN2, 0); 
	analogWrite(AIN1, 0); 

}

void MotorDrive::testeDrive(){
    Serial.println("Motor girando para direita");
    analogWrite(AIN2, 200);
    analogWrite(AIN1, 0);
    delay(100);

    Serial.println("Motor girando para esquerda");
    analogWrite(AIN1, 200);
    analogWrite(AIN2, 0);
    delay(100);

    stop();
    delay(100);
}
