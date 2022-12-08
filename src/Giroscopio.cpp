#include "Giroscopio.h"

Giroscopio::Giroscopio(){

}

void Giroscopio::init(){
    Wire.begin();
    mpu6050.begin();
    mpu6050.calcGyroOffsets(true);
}


float Giroscopio::readAngle(){
    mpu6050.update();
    return mpu6050.getAccAngleX();
}