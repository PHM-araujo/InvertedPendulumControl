#include "Display.h"


Display::Display(){
    lcd.begin(8,2);
}

void Display::testDisplay(){
    lcd.print("hello, world!");
}
