# include "PenduloInvertido.h"

PenduloInvertido::PenduloInvertido(){
}

void PenduloInvertido::init(){

	sensor_rotacao.init();
    motor.init();

}

void PenduloInvertido::start(){
    Serial.println("Iniciado");
    start_condition = true;
}

bool PenduloInvertido::isStarted(){
    return start_condition;
}

void PenduloInvertido::controle(){

}

void PenduloInvertido::teste(){
	//sensor_rotacao.readAngle();
    motor.testeDrive();
	//delay(1000);
}