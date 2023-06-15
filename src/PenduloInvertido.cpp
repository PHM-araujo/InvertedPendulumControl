# include "PenduloInvertido.h"

PenduloInvertido::PenduloInvertido(){
}

void PenduloInvertido::init(){

	sensor_rotacao.init();
    motor.init();
    sensor_ultrasonico.init();

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
    //! Testar 
    motor.testeDrive();
    //Serial.println(sensor_ultrasonico.readDistance());
	//delay(100);
}