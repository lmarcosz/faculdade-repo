const buttonPin = 7;
const g1LedPin = 2;
const r1LedPin = 3;
const r2LedPin = 13;
const y2LedPin = 12;
const g2LedPin = 11;

short delayTime = 10000;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(r1LedPin, OUTPUT);
  pinMode(g1LedPin, OUTPUT);
  pinMode(r2LedPin, OUTPUT);
  pinMode(y2LedPin, OUTPUT);
  pinMode(g2LedPin, OUTPUT);
}

void loop() {
  digitalWrite(g1LedPin, HIGH);
  digitalWrite(r1LedPin, LOW);
  delay(delayTime);
  
  digitalWrite(g1LedPin, LOW);
  digitalWrite(r1LedPin, HIGH);
  delay(delayTime);

}
