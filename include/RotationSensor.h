#ifndef _ROTATIONSENSOR_
#define _ROTATIONSENSOR_

#include <Wire.h>
#include "AS5600.h"

/* As5600
ESP32           SENSOR
VIN(5V) -       VCC
GND     -       GND
D23     -       DIR 
D21     -       SDA
D22     -       SCL 
*/



class RotationSensor{
    private:
    AS5600 as5600;

    float angle_max = 67.38;

    public: 

        void init();
        float readAngle();
        void calibSensor();
};

#endif
 