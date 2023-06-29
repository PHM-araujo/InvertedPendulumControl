#ifndef _ULTRASONICSENSOR_
#define _ULTRASONICSENSOR_

/* HCR04
ESP32           SENSOR
VIN(5V) -       VCC
GND     -       GND
Tx2     -       Trig
Rx2     -       Echo
*/



class UltrasonicSensor{
    private:
        unsigned char TRIGGER_PIN = 17;
        unsigned char ECHO_PIN = 16;
    public: 

        void init();

        int readDistance();

        float readAceleration();

        float readVelocity();
};

#endif
 