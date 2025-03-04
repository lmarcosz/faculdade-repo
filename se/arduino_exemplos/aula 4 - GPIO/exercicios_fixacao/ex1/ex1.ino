const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;
int op;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin);

  if(Serial.available()){
    char op = Serial.read();
  }

  if (op == 1) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}