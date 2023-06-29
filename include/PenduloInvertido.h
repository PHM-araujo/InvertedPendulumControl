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
        Controlador controlador = Controlador(15, 0, 0);


        bool start_condition = false;
        int dist_max = 273;
        int dist_min = 40;
        int pos_home = 150;
        unsigned long samplingTime = 100;
        unsigned long execTime = 0;
        float ref = 0;

    public:

        PenduloInvertido();


        void init();
        void start();
        bool isStarted();

        void teste();
        bool outOfRange();
        void stop();

        void controle();

        void returnHome();

        void behavior(String msg);

        void readGanhos(String msg);
};





#endif