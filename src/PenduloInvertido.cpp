# include "PenduloInvertido.h"
# include "math.h"

PenduloInvertido::PenduloInvertido()
{
}

void PenduloInvertido::init(){

    // Inicializa pinos
    pinMode(pwmA, OUTPUT);
    pinMode(in1A, OUTPUT);
    pinMode(in2A, OUTPUT);
	pinMode(2, OUTPUT);
    
    // Incializa o contador de tempo passado
    countTime = millis();

    // Inicializa giroscopio
    giroscopio.init();

    // Inicializa o bluetooth 
    initBluetooth();

    SerialBT.println("Pêndulo iniciado");
    digitalWrite(2, HIGH);
}

void PenduloInvertido::initBluetooth(){
    SerialBT.begin("Pendulo"); 
  	Serial.println("O dispositivo já pode ser pareado!");
}

void PenduloInvertido::setMotorForward(){
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);
}

void PenduloInvertido::setMotorBackward(){
    // Set Motor A backward
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, HIGH);

}

void PenduloInvertido::setSpeed(int pwm){
    //Serial.print("PWM nos motores: ");
    //Serial.println(pwm);
    analogWrite(pwmA, pwm);
}

void PenduloInvertido::stop(){
    Serial.println("Parado");

	digitalWrite(in1A, LOW); 
	digitalWrite(in2A, LOW); 

    start_condition = false;
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
		stop();
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

void PenduloInvertido::testeMotores(){
    setMotorForward();
    setSpeed(255);

    delay(10000);
}

