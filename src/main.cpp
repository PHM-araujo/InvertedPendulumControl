#include "PenduloInvertido.h"

PenduloInvertido penduloInvertido = PenduloInvertido();


void setup() {
	Serial.begin(115200);
	penduloInvertido.init();
}
 
void loop(){

	//penduloInvertido.teste();

	if(Serial.available() > 0){
		String msg = Serial.readStringUntil(';');
		Serial.println(msg);

		penduloInvertido.behavior(msg);
	}

	if(penduloInvertido.isStarted()){
		penduloInvertido.controle();

		// Checa se é necessário mudar a direção do pêndulo
		// if(penduloInvertido.enableChangeDir()){
		// 	penduloInvertido.changeDirection();
		// }

		// Checa se o piloto está na área permitida
		if (penduloInvertido.outOfRange()){
			penduloInvertido.stop();
		}

	}
}
	