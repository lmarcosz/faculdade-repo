const int buzzerPin = 2;
const int tempPin = 0;
const int potPin = A1;
const int ldrPin = A2;
const int ledPin_1 = 5;
const int ledPin_2 = 6;
const int ledPin_3 = 10;
const int ledPin_4 = 11;

int ledState_1 = LOW;
int ledState_2 = LOW;
int ledState_3 = LOW;
int ledState_4 = LOW;

int pwmLed1 = 0;
int pwmLed2 = 0;
int pwmLed3 = 0;
int pwmLed4 = 0;

int cont = 0;
float vetTemp[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
float mediaTemp = 0;
int quo = 1;

const int LM35 = 0;
float temp = 0;
int ADCread = 0;
int limitanteTemp = 0;
int valorPot;
int lastValorPot = valorPot;
int valorLDR = 0;
int ledInterval = 10;

long lastMillis;
long millisLedInterval;

void setup() {
  analogReference(INTERNAL1V1); //TENSÃO DE REF 1,1V
   //analogReference(DEFAULT); //TENSÃO DE REF 5V
  Serial.begin(9600);
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);
  pinMode(ledPin_4, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  runWeatherStation();
}

void showMenu(){
  Serial.println("\n(a) Mostrar o valor de temperatura;");
  Serial.println("(b) Mostrar o valor da luminosidade; ");
  Serial.println("(c) Mostrar o valor do potenciômetro.\n");
}

int runWeatherStation(){
  char op = NULL;
  char opAux;
  lastMillis = millis();
  millisLedInterval = lastMillis;
  int contAux = 0;

  //Imprime as opções do menu
  showMenu();

  while(op == NULL){
    //Entrada do Monitor Serial
    if(Serial.available()){
      opAux = Serial.read();
      if(opAux != '\n') op = opAux;
    }

    //Leitura para os componentes do potenciômetro
    valorPot = analogRead(potPin); 
    pwmLed1 = map(valorPot, 0, 1023, 0, 255);
    limitanteTemp = map(valorPot, 0, 1023, 0, 30);

    //Leitura do sensor de temperatura
    ADCread = analogRead(tempPin);
    temp = 0.1075268817*ADCread;
    //temp = 0.48875855327*ADCread;

    //Leitura LDR
    valorLDR = analogRead(ldrPin);

    //A cada 100ms...
    if(millis() - lastMillis >= 100){
      //Obtendo a temperatura atual
      vetTemp[cont] = temp;

      //Média das temperaturas
      float somaTemp = 0;
      for(int i=0; i<quo; i++) somaTemp += vetTemp[i];
      mediaTemp = somaTemp/quo;

      //Valor do potenciometro
      /*
      if(lastValorPot != valorPot && contAux>0){
        Serial.print("Novo limitante de temperatura: ");
        Serial.print(limitanteTemp);
        Serial.println("C");
        Serial.println(ADCread);
      }
      */
      lastValorPot = valorPot;
      contAux = 1;
      
      //Aritmética para obter a média entre temperaturas
      cont++;
      if(cont==20) cont = 0;
      if(quo<20) quo++;

      lastMillis = millis();
    }

    //Led 1 proporcional ao potenciômetro
    analogWrite(ledPin_1, pwmLed1);

    //Condição para acionar o alarme limitante de temperatura
    if(temp > limitanteTemp){
      digitalWrite(buzzerPin, HIGH);
    } else{
      digitalWrite(buzzerPin, LOW);
    }

    // Luminosidade Baixa => Acende os leds gradativamente
    if(valorLDR > 900){ 
      if(millis() - millisLedInterval >= ledInterval){
        millisLedInterval = millis();
        analogWrite(ledPin_2, pwmLed2);
        pwmLed2++;
        if(pwmLed2 >= 255){
          analogWrite(ledPin_3, pwmLed3);
          pwmLed3++;
          if(pwmLed3 >= 255){
            analogWrite(ledPin_4, pwmLed4);
            pwmLed4++;
          }
        }
      }
    }
    // Luminosidade Alta => Apaga os leds gradativamente 
    else{ 
      if(millis() - millisLedInterval >= ledInterval){
        millisLedInterval = millis();
        analogWrite(ledPin_4, pwmLed4);
        pwmLed4--;
        if(pwmLed4 <= 0){
          analogWrite(ledPin_3, pwmLed3);
          pwmLed3--;
          if(pwmLed3 <= 0){
            analogWrite(ledPin_2, pwmLed2);
            pwmLed2--;
          }
        }
      }
    }

    //Mantém a faixa de valor do pwm entre 0 e 255
    if(pwmLed2 > 255) pwmLed2 = 255;
    if(pwmLed3 > 255) pwmLed3 = 255;
    if(pwmLed4 > 255) pwmLed4 = 255;
    if(pwmLed2 < 0) pwmLed2 = 0;
    if(pwmLed3 < 0) pwmLed3 = 0;
    if(pwmLed4 < 0) pwmLed4 = 0;

    //Entrada do Monitor Serial
    if(Serial.available()){
      opAux = Serial.read();
      if(opAux != '\n'){
        op = opAux;
        //Mostrar a média das últimas 20 temperaturas
        if(op == 'a'){
          Serial.print("Média das últimas 20 temperaturas: ");
          Serial.print(mediaTemp);
          Serial.println("C");
        }
        //Mostrar o valor de luminosidade
        else if(op == 'b'){
          Serial.print("Valor de luminosidade: ");
          Serial.println(valorLDR);
        }
        //Mostrar o valor do potenciômetro
        else if(op == 'c'){
          Serial.print("Valor do potenciômetro: ");
          Serial.println(valorPot);
        }
        //Opção inválida
        else{
          Serial.println("Opção inválida!");
        }
      }
    }

    //Voltar para o menu
    if(op != 'm') op = NULL;
  }
  
  return 0;
}
