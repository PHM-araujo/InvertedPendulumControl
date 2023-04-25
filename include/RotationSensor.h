#ifndef _ROTATIONSENSOR_
#define _ROTATIONSENSOR_

#include <Arduino.h>
#include <Wire.h>


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
 