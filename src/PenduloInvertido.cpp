# include "PenduloInvertido.h"


PenduloInvertido::PenduloInvertido(){
}

void PenduloInvertido::init(){

	sensor_rotacao.init();
    motor.init();
    sensor_ultrasonico.init();

    pos = sensor_ultrasonico.readDistance();

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
    pos = sensor_ultrasonico.readDistance();

    int home_inicial = pos_home - pos_home*0.01;
    int home_final = pos_home + pos_home*0.01;

    Serial.println("Voltando home ...");
    while(!(pos >= home_inicial and pos <= home_final)){

        if(pos > pos_home){
            motor.setSpeed(200);
        }if(pos < pos_home){
            motor.setSpeed(-200);
        }

        delay(5);
        pos = sensor_ultrasonico.readDistance();
        Serial.println(pos);
    }
    Serial.println("Voltei home");
    motor.stop();
}

void PenduloInvertido::controle(){

    if (!execTime) execTime = millis();     
	else if(millis() - execTime >= samplingTime){
		execTime = 0;

        pos = sensor_ultrasonico.readDistance();

        leitura = sensor_rotacao.readAngle();
                
        float erro = ref - leitura;

		atuation = controlador.PID(erro);           // Força no piloto 
        printInformation();

        motor.setSpeed(atuation);
	}
    

}

void PenduloInvertido::behavior(String msg){
    
    switch (msg[0])
    {
    case 'I':
        start();
        //teste_Acomodacao();
        //teste_LeituraAng();
        //teste_PWM();
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

//! Tem que ser otimizado
void PenduloInvertido::changeDirection(){

    if(pos <= dist_min_cd){
        motor.setSpeed(255);
        Serial.println("Mudei de direção");
        // Inicia o timer que vai desabilita a mudança de direção
        en_dir = millis();
        delay(35);
    }else if(pos >= dist_max_cd){
        motor.setSpeed(-255);
        Serial.println("Mudei de direção");
        // Inicia o timer que vai desabilita a mudança de direção
        en_dir = millis();
        delay(35);
    }

}

bool PenduloInvertido::enableChangeDir(){
    if(millis() - en_dir >= 100) return true;

    return false;
}

void PenduloInvertido::teste_Acomodacao(){

    // Piloto na posiçao inicial - 273

    int pos = sensor_ultrasonico.readDistance();
    Serial.println(pos);
    testeTimer = millis();

    while(pos > 40){
        motor.setSpeed(255);
        pos = sensor_ultrasonico.readDistance();
        Serial.println(pos);
        delay(5);
    }

    motor.stop();

    Serial.print("Tempo de acomodação: ");
    Serial.println(millis() - testeTimer);
}

void PenduloInvertido::teste_LeituraAng(){

    // Piloto na posiçao inicial - 273

    float angulos_media[13];

    for(int i = 0; i <= 12; i++){
        Serial.print("Medindo angulo ");
        Serial.println(-30 + i*5);
        delay(5000);
        for(int j = 0; j < 5; j++){
            angulos_media[i] += sensor_rotacao.readAngle()/5;
            delay(50);
        }
    }

    Serial.print("Média de leitura para cada angulo");
    for(int i = 0; i < 13; i++){
        Serial.print("Angulo ");
        Serial.print(-30 + i*5);
        Serial.print(" : ");
        Serial.println(angulos_media[i]);
    }
}

void PenduloInvertido::teste_PWM(){
    float aceleracoes[34];

    // Rotina para gerar a curva de PWM 
    for(int i = 0; i <= 33; i++){
        Serial.print("PWM: ");
        Serial.println(90 + i*5);
        while(pos < 270){
            motor.setSpeed(-200);
            pos = sensor_ultrasonico.readDistance();
            delay(5);
        }

        testeTimer = millis();
        while(pos > 40){
            motor.setSpeed(90+i*5);
            pos = sensor_ultrasonico.readDistance();
            delay(5);
        }

        float time_seg = (millis() - testeTimer);
        // Calcula a aceleraçao em mm/ms
        aceleracoes[i] = 230/time_seg;

    }

    motor.stop();

    // Imprimi as acelerações do piloto
    Serial.println("Acelerações para cada valor de PWM");
    for(int i = 0; i <= 33; i++){
        Serial.print("PWM ");
        Serial.print(90 + i*5);
        Serial.print(": ");
        Serial.println(aceleracoes[i],5);
    }
}

void PenduloInvertido::printInformation(){
    
    // Informação mostrada na serial
    // Serial.print(atuation);
    // Serial.print("    ");
    // Serial.print(sensor_rotacao.readAngle());
    // Serial.print("    ");
    // Serial.println(pos);

    // Informação mostrada no plotter
    Serial.print("Ref:");
	Serial.println(0);
	Serial.print(",");
	Serial.print("Angle:");
	Serial.println(leitura);
}

