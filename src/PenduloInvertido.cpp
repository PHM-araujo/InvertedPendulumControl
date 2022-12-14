# include "PenduloInvertido.h"
# include "math.h"

PenduloInvertido::PenduloInvertido()
{
}

void PenduloInvertido::init(){

    // Inicializa pinos
    pinMode(pwmA, OUTPUT);
    pinMode(pwmB, OUTPUT);
    pinMode(in1A, OUTPUT);
    pinMode(in2A, OUTPUT);
    pinMode(in1B, OUTPUT);
    pinMode(in2B, OUTPUT);// Para mostrar que terminou de inicializar
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

    // Set Motor B forward
    digitalWrite(in1B, HIGH);
    digitalWrite(in2B, LOW);
}

void PenduloInvertido::setMotorBackward(){
    // Set Motor A backward
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, HIGH);

    // Set Motor B backward
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, HIGH);
}

void PenduloInvertido::setSpeed(int pwm){
    Serial.print("PWM nos motores: ");
    Serial.println(pwm);
    analogWrite(pwmA, pwm);
    analogWrite(pwmB, pwm);
}

void PenduloInvertido::stop(){
    Serial.println("Parado");

	digitalWrite(in1A, LOW); 
	digitalWrite(in2A, LOW); 

	digitalWrite(in1B, LOW); // direcional
	digitalWrite(in2B, LOW); // direcional

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
    int speed;

    float angle = giroscopio.readAngle();
    Serial.print("Valor de angulo: ");
    Serial.println(angle);

    if(angle >= 0){
        Serial.print("Tras");
        setMotorBackward();
    } else{
        Serial.print("Frente");
        setMotorForward();
    }

    speed = abs(angle)*kp;

    Serial.print("Velocidade ");
    Serial.println(speed);

    if (speed > 255) speed = 255;

    setSpeed(speed);
}

void PenduloInvertido::sendGiroData(){
    if(millis() - countTime > timeToSend){
        countTime = millis();
        SerialBT.println(giroscopio.readAngle());
    }
}

void PenduloInvertido::testeGiro(){
    Serial.println(giroscopio.readAngle());
    delay(2000);
}

void PenduloInvertido::testeMotores(){
    setMotorForward();
    setSpeed(255);

    delay(10000);
}

