#include "PenduloInvertido.h"

PenduloInvertido penduloInvertido = PenduloInvertido();


void setup() {
	Serial.begin(115200);
	penduloInvertido.init();
   
}
 
void loop(){
	penduloInvertido.teste();
}