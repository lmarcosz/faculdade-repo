// Projeto Iluminação Automatizada
const int LDR = 0; // pino do LDR
const int Led = 6; // pino do LED
int ValorLido = 0;
int pwm = 0; // Valor referente ao duty cycle
long lastMillis = millis();
int interval = 10;

void setup() {
  pinMode(Led, OUTPUT);
}

void loop() {
  ValorLido = analogRead(LDR); // Lê tensão de entrada

  if (ValorLido < 100){ // Altera a condição de operação do sistema de iluminação
    if(millis() - lastMillis >= interval){
      lastMillis = millis();
      analogWrite(Led, pwm);
      pwm++;
    }
  } else{
    digitalWrite(Led, LOW);
    pwm = 0;
  }

  if (pwm > 255){ // Define o valor limite para o duty cycle
    pwm=255;
  }
}

