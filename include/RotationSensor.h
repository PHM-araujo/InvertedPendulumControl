#ifndef _ROTATIONSENSOR_
#define _ROTATIONSENSOR_

#include <Arduino.h>
#include <Wire.h>

/*
ESP32           SENSOR
VIN     -       VCC
GND     -       GND
D23     -       DIR 
D21     -       SDA
D22     -       SCL 
*/



class RotationSensor{
    private:
    

    public: 

        RotationSensor();

        void init();

        float readAngle();

        void testRotSensor();

        void testDisplay();
};

#endif
 