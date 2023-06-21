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
	//Serial.println(sensor_rotacao.readAngle());
    //motor.testeDrive();
    //Serial.println(sensor_ultrasonico.readDistance());
	//delay(100);
}

bool PenduloInvertido::outOfRange(){
    int pos = sensor_ultrasonico.readDistance();
    Serial.println(pos);

    if (pos < dist_min or pos > dist_max){
        return true;
    } 
    
    return false;
}


void PenduloInvertido::stop(){
    Serial.println("Parado");
    motor.stop();
    start_condition = false;
}