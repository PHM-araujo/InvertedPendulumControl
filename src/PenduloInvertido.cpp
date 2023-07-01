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

    // Zerar condições iniciais
    controlador.resetConditions();
}

bool PenduloInvertido::isStarted(){
    return start_condition;
}

bool PenduloInvertido::outOfRange(){
    int pos = sensor_ultrasonico.readDistance();

    if (pos < dist_min or pos > dist_max){
        Serial.println("Out");
        return true;
    } 

    if(pos < 0){
        Serial.println("Valor inválido");
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
    int pos = sensor_ultrasonico.readDistance();
    int home_inicial = pos_home - pos_home*0.02;
    int home_final = pos_home + pos_home*0.02;;

    Serial.println("Voltando home ...");
    while(!(pos >= home_inicial and pos <= home_final)){

        if(pos > pos_home){
            motor.setSpeed(200);
        }if(pos < pos_home){
            motor.setSpeed(-200);
        }

        pos = sensor_ultrasonico.readDistance();
        Serial.println(pos);
        delay(2);
    }
    Serial.println("Voltei home");
    motor.stop();
}

void PenduloInvertido::controle(){

    if (!execTime) execTime = millis();
	else if(millis() - execTime >= samplingTime){
		execTime = 0;

        float leitura = sensor_rotacao.readAngle();

        // Checa se é uma leitura válida
        if (leitura > 50) stop();
                
        float erro = ref - leitura;

		int atuation = controlador.PID(erro);
        Serial.print(atuation);
        Serial.print("    ");
        Serial.println(sensor_rotacao.readAngle());


        motor.setSpeed(atuation);
	}
    

}

void PenduloInvertido::behavior(String msg){
    
    switch (msg[0])
    {
    case 'I':
        start();
        break;
    case 'P':
        stop();
        break;
    case 'S':
        readGanhos(msg);
        break;
    case 'R':
        returnHome();
        break;
    case 'C':
        sensor_rotacao.calibSensor();
        break;
    default:
        break;
    }

}

void PenduloInvertido::readGanhos(String msg){
    String Kp_str = "", Kd_str = "", Ki_str = "";

    int pos = msg.indexOf(',', 2);
    for(int i = 4; i < pos; i++) Kp_str += msg[i];

    int pos2 = msg.indexOf(',', pos + 1);
    for(int i = pos + 3; i < pos2; i++) Kd_str += msg[i];

    int pos3 = msg.indexOf(',', pos2 + 1);
    for(int i = pos2 + 3; i < pos3; i++) Ki_str += msg[i];

    float Kp = Kp_str.toFloat();
    float Kd = Kd_str.toFloat();
    float Ki = Ki_str.toFloat();

    controlador.setGanhos(Kp, Kd, Ki);
}

void PenduloInvertido::changeDirection(){
    int pos = sensor_ultrasonico.readDistance();

    // Inicia o timer que vai desabilita a mudança de direção
    en_dir = millis();

    if(pos <= 40){
        motor.setSpeed(-200);
    }else if(pos >= 260){
        motor.setSpeed(200);
    }

    delay(10);
}

bool PenduloInvertido:: enableChangeDir(){
    if(millis() - en_dir >= 1000) return true;

    return false;
}


void PenduloInvertido::teste(){

    // Serial.print("Angle:");
	// Serial.print(sensor_rotacao.readAngle());
    // Serial.print(",");
    // Serial.print("Kalman_filter:");
	// Serial.println(angleKalmanFilter.updateEstimate(sensor_rotacao.readAngle()));


    //motor.testeDrive();
    //Serial.println(sensor_ultrasonico.readDistance());
	delay(5);
}

