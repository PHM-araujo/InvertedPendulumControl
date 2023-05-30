# include "PenduloInvertido.h"

PenduloInvertido::PenduloInvertido()
{
}

void PenduloInvertido::init(){

    // Inicializa o bluetooth 
    initBluetooth();

    SerialBT.println("Pêndulo iniciado");
    digitalWrite(2, HIGH);

	pinMode(16, OUTPUT);
    pinMode(17, OUTPUT);

}

void PenduloInvertido::initBluetooth(){
    SerialBT.begin("Pendulo"); 
  	Serial.println("O dispositivo já pode ser pareado!");
}

void PenduloInvertido::start(){
    Serial.println("Iniciado");
    start_condition = true;
}

bool PenduloInvertido::isStarted(){
    return start_condition;
}

void PenduloInvertido::msgHandler(){
	switch(command[0])
	{
	case 'I':
		start();
		break;
	case 'S':
		motor.stop();
        start_condition = false;
		break;
    }
}

void PenduloInvertido::comunicaSerial(){  
    command = (char)SerialBT.read();

	if (SerialBT.available())
	{
		Serial.println(command[0]);
		msgHandler();
		command = "";
	}
}

void PenduloInvertido::controle(){

}

void PenduloInvertido::teste(){
	motor.testeDrive();
	//sensor.testRotSensor();
	//display.testDisplay();
	//delay(1000);
}