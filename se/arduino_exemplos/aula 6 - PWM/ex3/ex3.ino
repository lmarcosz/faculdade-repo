// Projeto Dimmer
const int PotPin = A1; // pino do Potenciômetro
const int LedPin = 11; // pino do LED
int ValorPot = 0;
int pwm = 0; // valor referente ao duty cycle

void setup() {
  pinMode(LedPin, OUTPUT);
}
void loop() {
  ValorPot = analogRead(PotPin);
  pwm = map(ValorPot, 0, 1023, 0, 255); // Os valores da variável pwm irão variar de 0 a 255,
  // conforme o potenciômetro varia de 0 a 1023.
  analogWrite(LedPin, pwm); // Ativa LedPin como uma saída PWM.
  // O sinal é definido pelo valor de duty cycle com período fixo.
}