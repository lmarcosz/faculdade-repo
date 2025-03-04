const int LM35 = 0;
const int buzzerPin = 12;
float temp = 0;
int ADCread = 0;

unsigned long lastMillis = 0;
unsigned long interval = 1000;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL1V1);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  ADCread = analogRead(LM35);
  temp = ADCread * 0.1075268817204301;

  if(temp > 27){
    digitalWrite(buzzerPin, HIGH);
  } else{
    digitalWrite(buzzerPin, LOW);
  }

  if(millis() - lastMillis >= interval){
    lastMillis = millis();
    Serial.print("Temperatura = ");
    Serial.print(temp);
    Serial.print("ºC\n");
  }
}
