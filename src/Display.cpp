#include "Display.h"


LiquidCrystal lcd(13, 14, 33, 25, 26, 27);

Display::Display(){
    lcd.begin(8,2);
}

void Display::print(String msg){
    lcd.print(msg);
}

void Display::testDisplay(){
    // Turn off the cursor:
    lcd.noCursor();
    delay(500);
    // Turn on the cursor:
    lcd.cursor();
    delay(500);
}
