#ifndef _CONTROLADOR_
#define _CONTROLADOR_

#include <Arduino.h>
#include <Wire.h>


class Controlador{
    private:
    
    //! Ajeitar pinos dos motores 
    // Pinos Motor
    int pwmA = 13;
    int in1A = 32;
    int in2A = 33;

    public: 

        Controlador();

        void PID();
};

#endif