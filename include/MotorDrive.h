#ifndef _MOTORDRIVE_
#define _MOTORDRIVE_

#include <Arduino.h>
#include <Wire.h>


/* DRV8833
ESP32           Driver
Motor   -      A01
Motor   -      A02
12V     -      VM
3.3V    -      VCC
GND     -      GND
D4      -      PWMA
RX2     -      AIN2
TX2     -      AIN1
STBY    -      3.3v
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