#ifndef _PENDULOINVERTIDO_
#define _PENDULOINVERTIDO_

#include <Arduino.h>
#include "RotationSensor.h"
#include "MotorDrive.h"

class PenduloInvertido
{

    private:
        RotationSensor sensor_rotacao;
        MotorDrive motor;

        int kp = 15;

        // Direção
        // 0 -> Frente
        // 1 -> Tras
        bool dir = 1;


        bool start_condition = false;
        unsigned long countTime;

    public:
        // Atributos públicos

        // Métodos 
        PenduloInvertido();

        void init();

        void start();

        bool isStarted();

        void controle();

        void teste();



};





#endif