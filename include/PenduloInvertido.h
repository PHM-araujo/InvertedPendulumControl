#ifndef _PENDULOINVERTIDO_
#define _PENDULOINVERTIDO_

#include <Arduino.h>
#include "RotationSensor.h"
#include "MotorDrive.h"
#include "UltrasonicSensor.h"
#include "Controlador.h"

class PenduloInvertido
{

    private:
        RotationSensor sensor_rotacao;
        MotorDrive motor;
        UltrasonicSensor sensor_ultrasonico;
        Controlador controlador = Controlador(67,11, 12.5);


        bool start_condition = false;
        float ref = 0;

        // Variaveis de posição
        int dist_max = 273;
        int dist_min = 30;
        int pos_home = 150;

        // Timers 
        unsigned long samplingTime = 5;
        unsigned long execTime = 0;

        // Metodos auxiliares
        void readGanhos(String msg);

    public:

        PenduloInvertido();

        void controle();
        void init();
        void start();
        bool isStarted();
        void teste();
        bool outOfRange();
        void stop();
        void returnHome();
        void behavior(String msg);

};





#endif