#include "MotorDrive.h"

MotorDrive::MotorDrive(){
}

void MotorDrive::init(){
}

void MotorDrive::setSpeed(int pwm){
    analogWrite(pwmA, pwm);
}

void MotorDrive::stop(){
    Serial.println("Parado");

	digitalWrite(in1A, LOW); 
	digitalWrite(in2A, LOW); 

}

void MotorDrive::testeDrive(){


}
