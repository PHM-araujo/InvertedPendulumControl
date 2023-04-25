#include "PenduloInvertido.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


PenduloInvertido penduloInvertido = PenduloInvertido();


void setup() {
	Serial.begin(115200);
	penduloInvertido.init();
   
}
 
void loop(){

	//penduloInvertido.testeMotores();
	//penduloInvertido.testeGiro();

	penduloInvertido.comunicaSerial();
	penduloInvertido.sendGiroData();

	
	if(penduloInvertido.isStarted()) penduloInvertido.controle();

	
	
}