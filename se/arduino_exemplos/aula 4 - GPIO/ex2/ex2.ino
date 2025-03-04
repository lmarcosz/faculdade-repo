const int buttonPin = 2; // // número do pino do botão (pino 2)
const int ledPin = 13; // número do pino do LED (pino 13)
int buttonState = 0; // variável para leitura do estado do botão
int counter = 0;
int flag = 0; // Variável de controle para a condição em “IF”

void setup() {
  pinMode(ledPin, OUTPUT); // define o pino do LED como saída
  pinMode(buttonPin, INPUT); // define o pino do botão como entrada
  Serial.begin(9600);
}

void loop() {
  delay(100); // delay para debounce
  buttonState = digitalRead(buttonPin); // lê o estado do valor do botão

  if ((buttonState == HIGH)&&(flag==0)) {
    digitalWrite(ledPin, HIGH); // liga o LED
    counter = counter + 1;
    Serial.println(counter);
    flag = 1;
  }

  if ((buttonState == LOW)&&(flag==1)) {
    digitalWrite(ledPin, LOW); // desliga o LED
    counter = counter + 1;
    Serial.println(counter);
    flag = 0;
  }
  
}