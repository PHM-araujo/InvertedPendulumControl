#ifndef _PENDULOINVERTIDO_
#define _PENDULOINVERTIDO_

#include <Arduino.h>
#include "RotationSensor.h"
#include "MotorDrive.h"
#include "UltrasonicSensor.h"

class PenduloInvertido
{

    private:
        RotationSensor sensor_rotacao;
        MotorDrive motor;
        UltrasonicSensor sensor_ultrasonico;

        int kp = 15;
        bool dir = 1;
        bool start_condition = false;
        unsigned long countTime;
        int dist_max = 273;
        int dist_min = 40;

    public:

        PenduloInvertido();
        void init();
        void start();
        bool isStarted();
        void controle();
        void teste();
        bool outOfRange();
        void stop();
};





#endif