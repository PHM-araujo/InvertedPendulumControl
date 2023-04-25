#ifndef _MOTORDRIVE_
#define _MOTORDRIVE_

#include <Arduino.h>
#include <Wire.h>


class MotorDrive{
    private:
    
    //! Ajeitar pinos dos motores 
    // Pinos Motor
    int pwmA = 13;
    int in1A = 32;
    int in2A = 33;

    public: 

        MotorDrive();

        void init();

        void setSpeed(int pwm);

        void stop();

        void testeDrive();
};

#endif