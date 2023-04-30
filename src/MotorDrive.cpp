#include "MotorDrive.h"

MotorDrive::MotorDrive(){
    pinMode(Rpwm, OUTPUT);
    pinMode(Lpwm, OUTPUT);
}

void MotorDrive::setSpeed(int pwm){
    if(pwm >= 0){
        analogWrite(Rpwm, pwm);
        analogWrite(Lpwm, LOW);
    }else{
        pwm = -1*pwm;
        analogWrite(Lpwm, pwm);
        analogWrite(Rpwm, LOW);
    }
}

void MotorDrive::stop(){
    Serial.println("Parada total");

	digitalWrite(Rpwm, HIGH); 
	digitalWrite(Lpwm, HIGH); 

}

void MotorDrive::testeDrive(){
    Serial.println("Motor girando para direita");
    analogWrite(Rpwm, 100);
    analogWrite(Lpwm, LOW);
    delay(500);

    Serial.println("Motor girando para esquerda");
    analogWrite(Lpwm, 100);
    analogWrite(Rpwm, LOW);
    delay(500);
}
