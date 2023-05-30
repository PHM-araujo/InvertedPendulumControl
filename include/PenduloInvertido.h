#ifndef _PENDULOINVERTIDO_
#define _PENDULOINVERTIDO_

#include "BluetoothSerial.h"
#include <Arduino.h>
#include <Wire.h>
#include "Display.h"
#include "MotorDrive.h"
#include "RotationSensor.h"

class PenduloInvertido
{

    private:
        // App
        BluetoothSerial SerialBT;
        String command = "";
        MotorDrive motor;
        Display display;
        RotationSensor sensor;

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

        // Métodos 
        PenduloInvertido();

        void init();

        void initBluetooth();
        void msgHandler();
        void comunicaSerial();
        void start();

        bool isStarted();

        void controle();

        void teste();



};





#endif