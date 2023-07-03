#ifndef _PENDULOINVERTIDO_
#define _PENDULOINVERTIDO_

#include <Arduino.h>
#include "RotationSensor.h"
#include "MotorDrive.h"
#include "UltrasonicSensor.h"
#include "Controlador.h"
#include "SimpleKalmanFilter.h"

class PenduloInvertido
{

    private:
        RotationSensor sensor_rotacao;
        MotorDrive motor;
        UltrasonicSensor sensor_ultrasonico;
        Controlador controlador = Controlador(67,11, 12.5);
        SimpleKalmanFilter angleKalmanFilter = SimpleKalmanFilter(1, 1, 0.01);

        // Variaveis do controle
        bool start_condition = false;
        float ref = 0;
        int atuation = 0;
        float leitura = 0;

        // Variaveis de posição
        int pos = 150;
        int dist_max = 273;
        int dist_min = 30;
        int pos_home = 150;
        int dist_min_cd = 50;
        int dist_max_cd = 250;

        // Timers 
        unsigned long en_dir = 0;
        unsigned long samplingTime = 5;
        unsigned long execTime = 0;

        // Metodos auxiliares
        void readGanhos(String msg);
        void printInformation();
        void start();

    public:

        PenduloInvertido();

        void controle();
        void init();
        bool isStarted();
        void teste();
        bool outOfRange();
        void stop();
        void returnHome();
        void behavior(String msg);
        void changeDirection();
        bool enableChangeDir();

};





#endif