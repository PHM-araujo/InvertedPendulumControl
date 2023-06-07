#ifndef _MOTORDRIVE_
#define _MOTORDRIVE_


/* DRV8833
ESP32           Driver
Motor   -      A01
Motor   -      A02
12V     -      VM
3.3V    -      STBY
GND     -      GND
26     -      AIN2
25     -      AIN1
*/


class MotorDrive{
    private:
    
    unsigned char AIN2 = 26;
    unsigned char AIN1 = 25;

    public: 

        void init();

        void setSpeed(int pwm);

        void stop();

        void testeDrive();
};

#endif