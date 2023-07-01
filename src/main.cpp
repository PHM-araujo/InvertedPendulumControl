#include "PenduloInvertido.h"

PenduloInvertido penduloInvertido = PenduloInvertido();


void setup() {
	Serial.begin(115200);
	penduloInvertido.init();
}
 
void loop(){

	// penduloInvertido.teste();

	if(Serial.available() > 0){
		String msg = Serial.readStringUntil(';');
		Serial.println(msg);

		penduloInvertido.behavior(msg);
	}

	if(penduloInvertido.isStarted()){
		penduloInvertido.controle();

		// Checa se é necessário dar um teco
		if(!penduloInvertido.getTeco()){
			penduloInvertido.teco();
		}else{
			// Checa se pode habilitar o teco
			penduloInvertido.enableTeco();
		}

		// Checa se o piloto está na área permitida
		if (penduloInvertido.outOfRange()){
			penduloInvertido.stop();
		}
	}
    
    // Atraso minimo necessário para o sensor ultrasônico funcionar
	delay(3);
}
	