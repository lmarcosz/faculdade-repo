// Projeto Efeito Fade
//Acendendo e apagando o LED de forma gradual

const int LEDpin = 6; // pino do LED
int pwm = 0; // Valor referente ao duty cycle
long currentMillis = 0;
unsigned long interval = 5;

void setup(){
  pinMode(LEDpin, OUTPUT);
}
void loop(){
  for (pwm = 0; pwm <= 255; pwm++){
    currentMillis = millis();
    while(millis() - currentMillis < interval){
      analogWrite(LEDpin,pwm);
    }
  }
  for (pwm = 255; pwm >= 0; pwm--){
    currentMillis = millis();
    while(millis() - currentMillis < interval){
      analogWrite(LEDpin,pwm);
    }
  }
}
