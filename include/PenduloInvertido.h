#ifndef _PENDULOINVERTIDO_
#define _PENDULOINVERTIDO_

#include "BluetoothSerial.h"
#include <Arduino.h>
#include <Wire.h>
#include "Giroscopio.h"

class PenduloInvertido
{

    private:
        // App
        BluetoothSerial SerialBT;
        String command = "";

        // Pinos 
        // Motor A
        int pwmA = 13;
        int in1A = 32;
        int in2A = 33;

        // Motor B
        int pwmB = 14;
        int in1B = 26;
        int in2B = 27;

        int kp = 15;

        // Direção
        // 0 -> Frente
        // 1 -> Tras
        bool dir = 1;


        bool start_condition = false;

        unsigned long countTime;

        unsigned long timeToSend = 1500;

    public:
        // Atributos públicos
        Giroscopio giroscopio = Giroscopio();

        // Métodos 
        PenduloInvertido();

        void init();

        void initBluetooth();
        void msgHandler();
        void comunicaSerial();
        void sendGiroData();

        void setMotorForward();
        void setMotorBackward();
        void setSpeed(int pwm);

        void stop();
        void start();

        bool isStarted();

        void controle();

        void testeGiro();
        void testeMotores(); 


};





#endif