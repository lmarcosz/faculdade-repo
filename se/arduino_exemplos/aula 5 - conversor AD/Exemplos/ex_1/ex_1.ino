const int LM35 = 0;
float temp = 0;
int ADCread = 0;


void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL1V1);
}

void loop() {
  ADCread = analogRead(LM35);
  temp = ADCread * 0.1075268817;

  Serial.print("Temperatura = ");
  Serial.print(temp);
  Serial.print("ºC\n");
  delay(1000);
}
