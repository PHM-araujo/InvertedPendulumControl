#include "UltrasonicSensor.h"
#include <HCSR04.h>

void UltrasonicSensor::init(){
    HCSR04.begin(TRIGGER_PIN, ECHO_PIN);
}


int UltrasonicSensor::readDistance(){
    double* distances = HCSR04.measureDistanceMm();
	return distances[0];
}

// float UltrasonicSensor::readVelocity(){
    
// }

// float UltrasonicSensor::readAceleration(){

// }