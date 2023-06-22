# include "PenduloInvertido.h"

PenduloInvertido::PenduloInvertido(){
}

void PenduloInvertido::init(){

	sensor_rotacao.init();
    motor.init();
    sensor_ultrasonico.init();

    start_condition = true;

    // Posição inicial - lixo
    pos = sensor_ultrasonico.readDistance();

    returnHome();

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
    pos = sensor_ultrasonico.readDistance();

    if (pos < dist_min or pos > dist_max){
        Serial.println("Out");
        return true;
    } 
    
    return false;
}


void PenduloInvertido::stop(){
    Serial.println("Parado");
    motor.stop();
    start_condition = false;
}


void PenduloInvertido::returnHome(){
    int pos_aux = sensor_ultrasonico.readDistance();
    int home_inicial = pos_home - pos_home*0.02;
    int home_final = pos_home + pos_home*0.02;;

    Serial.println("Voltando home ...");
    while(!(pos_aux >= home_inicial and pos_aux <= home_final)){

        if(pos_aux > pos_home){
            motor.setSpeed(200);
        }if(pos_aux < pos_home){
            motor.setSpeed(-200);
        }

        pos_aux = sensor_ultrasonico.readDistance();
        Serial.println(pos_aux);
        delay(2);
    }
    Serial.println("Voltei home");
    motor.stop();
}

