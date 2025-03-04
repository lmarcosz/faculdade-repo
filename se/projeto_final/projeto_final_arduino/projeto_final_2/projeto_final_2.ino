#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

//Sensor de umidade do solo
const int moisturePin = A0;

//LEDs nível de umidade
const int ledPin_0 = 5;
const int ledPin_1 = 6;
const int ledPin_2 = 9;
const int ledPin_3 = 10;
int ledState_0 = LOW;
int ledState_1 = LOW;
int ledState_2 = LOW;
int ledState_3 = LOW;
int pwmLed0 = 0;
int pwmLed1 = 0;
int pwmLed2 = 0;
int pwmLed3 = 0;
int pwmLeds = 0;

//Pot
const int potPin = A1;
int valorPot;

//Buzzer
const int buzzerPin = 2;
int buzzerState = LOW;
long buzzerIntervalMillis = 100;
bool flagBuzzer = true;
int flagCooler = 0;

//Variáveis de medição
int moisture = 0;
int percentMoisture = 0;
float temp = 0;
float preassureAux = 0;
float preassure = 0;
float altitude = 0;

float limitanteTemp = 0;


long lastMillis = 0;
long interval = 1000;
int ledInterval = 10;
long millisLedInterval;

void setup() {
  Serial.begin(9600);
  while (Serial.available() > 0) Serial.read();  // Limpa o buffer de recepção
  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    while (1) delay(10);
  }
  pinMode(ledPin_0, OUTPUT);
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(moisturePin, INPUT);
}

void loop() {
  char op = NULL;
  char opAux;
  lastMillis = millis();
  millisLedInterval = lastMillis;
  int contAux = 0;

  showMenu();

  while(op == NULL){
    //Entrada do Monitor Serial
    if(Serial.available()){
      opAux = Serial.read();
      if(opAux != '\n') op = opAux;
    }

    //Leitura de umidade do solo
    moisture = analogRead(moisturePin);
    percentMoisture = map(moisture, 0, 1023, 100, 0);

    //Leitura de temperatura
    temp = bmp.readTemperature();

    //Leitura de pressão atmosférica
    preassureAux = bmp.readPressure();
    preassure = preassureAux/100;

    //Leitura de altitude
    altitude = bmp.readAltitude(1013.25);

    //Leitura limitante de temp
    valorPot = analogRead(potPin); 
    limitanteTemp = map(valorPot, 0, 1023, 0, 30);

    //Leds proporcionais ao nível de umidade de solo
    if(millis() - millisLedInterval >= ledInterval){
      millisLedInterval = millis();
      if(moisture >= 0 && moisture <= 255){
        pwmLed0 = moisture;
        pwmLed1 = 0;
        pwmLed2 = 0;
        pwmLed3 = 0;
      } 
      else if(moisture >= 256 && moisture <= 510){
        pwmLed0 = 255;
        pwmLed1 = moisture-255;
        pwmLed2 = 0;
        pwmLed3 = 0;
      } else if(moisture >= 511 && moisture <= 765){
        pwmLed0 = 255;
        pwmLed1 = 255;
        pwmLed2 = moisture-510;
        pwmLed3 = 0;
      } else if(moisture >= 766 && moisture <= 1023){
        pwmLed0 = 255;
        pwmLed1 = 255;
        pwmLed2 = 255;
        pwmLed3 = moisture-765;
        if(pwmLed3 >= 255) pwmLed3 = 255;
      }
      analogWrite(ledPin_0, pwmLed0);
      analogWrite(ledPin_1, pwmLed1);
      analogWrite(ledPin_2, pwmLed2);
      analogWrite(ledPin_3, pwmLed3);
    }

    //Entrada do Monitor Serial (opções do menu)
    if(Serial.available()){
      opAux = Serial.read();
      if(opAux != '\n'){
        op = opAux;
        if(op == 'a'){
          Serial.print("Temperatura = ");
          Serial.print(temp);
          Serial.println(" *C");
          Serial.print("Pressão Atmosférica = ");
          Serial.print(preassure);
          Serial.println(" hPa");
          Serial.print("Altitude = ");
          Serial.print(altitude);
          Serial.println(" m");
          Serial.print("Umidade do Solo = ");
          Serial.print(percentMoisture);
          Serial.println("%");
          Serial.println();
        }
        else if(op == 'b'){
          Serial.print("Limitante atual: ");
          Serial.print(limitanteTemp);
          Serial.println("*C");
        }
        //Opção inválida
        else{
          Serial.println("Opção inválida!");
        }
      }
    }

    if(temp > limitanteTemp){
      flagCooler = 1;
      if(flagBuzzer){
        toneBuzzer(); //Toca buzzer
        flagBuzzer = false;
      }
    } else {
      flagCooler = 0;
      flagBuzzer = true;
    } 

        //A cada 100ms...
    if(millis() - lastMillis >= 100){
      Serial.write(flagCooler);   
      lastMillis = millis();
    }

    //Voltar para o menu
    if(op != 'm') op = NULL;
  }
}

void showMenu(){
  Serial.println("\n(a) Mostrar medições em tempo real;");
  Serial.println("(b) Mostrar o limitante de temperatura");
}

void toneBuzzer(){
  unsigned long previousMillis = millis();
  buzzerState = HIGH;

  while(buzzerState!=LOW){
    if(millis() - previousMillis >= buzzerIntervalMillis){
      buzzerState = !buzzerState;
    }
    digitalWrite(buzzerPin, buzzerState);
  }
}
