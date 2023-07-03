#include "MotorDrive.h"
#include <Arduino.h>


void MotorDrive::init(){
    pinMode(26, OUTPUT);
    pinMode(25, OUTPUT);
}


void MotorDrive::setSpeed(int pwm){



    if(pwm >= 0){
        // Direita
        pwm = pwm + offset;
        if(pwm > 255) pwm = 255;

        analogWrite(AIN2, pwm);
        analogWrite(AIN1, LOW);
    }else{
        //Esquerda
        pwm = -1*pwm;
        pwm = pwm + offset;
        if(pwm > 255) pwm = 255;

        analogWrite(AIN1, pwm);
        analogWrite(AIN2, LOW);
    }
}

void MotorDrive::stop(){

	analogWrite(AIN2, 0); 
	analogWrite(AIN1, 0); 

}

void MotorDrive::testeDrive(){
    setSpeed(-255);
}
