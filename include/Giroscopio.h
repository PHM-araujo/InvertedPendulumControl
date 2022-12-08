#ifndef _GIROSCOPIO_
#define _GIROSCOPIO_

#include <Arduino.h>
#include <Wire.h>
#include "MPU6050_tockn.h"

/*
    Esp32       MPU6050
      22          SCL
      21          SDA
      GND         GND
      VCC         VCC

*/


class Giroscopio{
    private:

        MPU6050 mpu6050 = MPU6050(Wire);
    

    public: 

        Giroscopio();

        void init();

        float readAngle();
};

#endif
 