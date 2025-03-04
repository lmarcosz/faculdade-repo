#include <Wire.h>

const int slaveAdress = 8;
const int buttonpin = 2;

char a;
int b = 0;
int cont = 0;
int LedState;
int Led_int_State = LOW;
float temperatura = 0.0;
int last_state = LOW;
int state;
int reading;

unsigned long last_time = 0;
unsigned long time = 200;

void setup() {
  Serial.begin(9600);
  Wire.begin(slaveAdress);
  pinMode(buttonpin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonpin), Write_button, FALLING);
}

void loop() {
  menu();
  if (reading == 1) {
    Wire.beginTransmission(slaveAdress);
    Wire.write(2);
    Wire.write(1);
    Serial.println("Botão pressionado!");
    Wire.endTransmission();
    reading = 0;
    cont = 0;
  }
}

void menu() {
  if (cont == 0) {
    Serial.println();
    Serial.println("Menu de opções:");
    Serial.println("1) Ligar LED");
    Serial.println("2) Desligar LED");
    Serial.println("3) Ligar Buzzer");
    Serial.println("4) Desligar Buzzer");
    Serial.println("5) Temperatura");
    cont = 1;
  }

  if (Serial.available()) {
    a = Serial.read();
    if (a >= '1' && a <= '5') {
      b = (a - '1') + 1;
    } else {
      b = 0;
    }
    Serial.println(a);
  }

  switch (b) {
    case 1:
      Wire.beginTransmission(slaveAdress);
      Wire.write(1);
      Wire.write(1);
      Wire.endTransmission();
      Serial.println("Status: LED ON");
      cont = 0;
      break;

    case 2:
      Wire.beginTransmission(slaveAdress);
      Wire.write(1);
      Wire.write(0);
      Wire.endTransmission();
      Serial.println("Status: LED OFF");
      cont = 0;
      break;

    case 3:
      Wire.beginTransmission(slaveAdress);
      Wire.write(0);
      Wire.write(1);
      Wire.endTransmission();
      Serial.println("Status: Buzzer ON");
      cont = 0;
      break;

    case 4:
      Wire.beginTransmission(slaveAdress);
      Wire.write(0);
      Wire.write(0);
      Wire.endTransmission();
      Serial.println("Status: Buzzer OFF");
      cont = 0;
      break;

    case 5:
      Wire.requestFrom(slaveAdress, 2);  // Solicita 2 bytes do escravo
      if (Wire.available() >= 2) {
        int tempHigh = Wire.read(); 
        int tempLow = Wire.read();  
        temperatura = (tempHigh << 8 | tempLow) / 100.0;  // Reconstrói o valor da temperatura
      }
      Serial.println("Status: Temperatura");
      Serial.print("Temperatura: ");
      Serial.println(temperatura);
      cont = 0;
      break;

    default:
      break;
  }
}

void Write_button() {
  reading = 1;
  Serial.println(reading);
}