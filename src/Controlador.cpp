# include "Controlador.h"


Controlador::Controlador(float KP, float KD, float KI){
    // Ganhos default
    setGanhos(KP, KD, KI);

    // Considera que o pendulo comeca na vertical 
    erro_k1 = 0;
    erro_k2 = 0;
    atuation_k1 = 0;
    atuation_k2 = 0;
}

int Controlador::PID(float erro){
    float temp = atuation_k1 + (kp + ki + kd)*erro + (ki - kp - 2*kd)*erro_k1 + kd*erro_k2;
    
    // Salva a atuação para ser usada no próximo loop
    atuation_k1 = temp;

    erro_k2 = erro_k1;
    erro_k1 = erro;

    return temp;
}

int Controlador::PD(float erro){
    float temp = kp*(1301*erro_k2 - 3038*erro_k1 + 2061*erro) - 2*atuation_k1 - atuation_k2;
    
    // Salva a atuação para ser usada no próximo loop
    atuation_k2 = atuation_k1;
    atuation_k1 = temp;

    erro_k2 = erro_k1;
    erro_k1 = erro;

    return temp;
}

void Controlador::setGanhos(float KP, float KD, float KI){
    kp = KP;
    kd = KD;
    ki = KI;

    Serial.print("Valores de ganho configurados:");
    Serial.print(" Kp = ");
    Serial.print(kp);
    Serial.print(" Kd = ");
    Serial.print(kd);
    Serial.print(" Ki = ");
    Serial.println(ki);
}

void Controlador::resetConditions(){
    erro_k1 = 0;
    erro_k2 = 0;
    atuation_k1 = 0;
    atuation_k2 = 0;
}