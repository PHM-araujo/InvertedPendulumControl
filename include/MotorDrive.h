#ifndef _MOTORDRIVE_
#define _MOTORDRIVE_

#include <Arduino.h>
#include <Wire.h>


/*
ESP32           Driver
12V     -       B+
GND     -       B-
Motor   -       M+
Motor   -       M-
3.3V    -      REN  
3.3V    -      LEN
3.3V    -      VCC
GND     -      GND
RX2     -      RPWM
TX2     -      LPWM
*/


class MotorDrive{
    private:
    
    unsigned char Rpwm = 16;
    unsigned char Lpwm = 17;

    public: 

        MotorDrive();

        void setSpeed(int pwm);

        void stop();

        void testeDrive();
};

#endif