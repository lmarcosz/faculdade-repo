const int ledPin = LED_BUILTIN;
const int buzzerPin = 2;
int ledState = LOW;
int buzzerState = LOW;
int State = 0;
unsigned long previousMillis = 0;
int interval = 1000;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println(State);
}

void loop() {
  if (millis() - previousMillis >= interval) {
    previousMillis = millis();
    State++;
    State = State % 3;
    Serial.println(State);
    switch (State) {
      case 0: 
        buzzerState = LOW;
        ledState = LOW;
        interval = 1000;
        break;
      case 1:
        buzzerState = LOW;
        ledState = HIGH;
        interval = 500;
        break;
      case 2:
        buzzerState = HIGH;
        ledState = HIGH;
        interval = 300;
        break; 
      default:
        break;
    }
    digitalWrite(buzzerPin,buzzerState);
    digitalWrite(ledPin,ledState);
  }
}

