#ifndef _DISPLAY_
#define _DISPLAY_

#include <Arduino.h>
#include <LiquidCrystal.h>

/* LCD 1602
ESP32           Display
3.3V    -       VDD(1)
GND     -       VSS(2)
3.3V    -       VO(3)
13      -       RS(4)
GND     -       RW(5)
14      -       E(6)
33      -       D4(11)
25      -       D5(12)
26      -       D6(13)
27      -       D7(14)
*/

class Display{
    private:

    public: 

        Display();

        void testDisplay();

        void print(String msg);
};

#endif