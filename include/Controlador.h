#ifndef _CONTROLADOR_
#define _CONTROLADOR_

#include <Arduino.h>
#include <Wire.h>


class Controlador{
    private:
    
    float kp, kd, ki;

    float erro_k1, erro_k2, atuation_k1;

    public: 

        Controlador(float KP, float KD, float KI);
        int PID(float erro);
        void setGanhos(float Kp, float Kd, float Ki);
        void resetConditions();
};

#endif