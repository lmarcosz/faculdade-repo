const int buttonPin_1 = 2;
const int buttonPin_2 = 3;
const int buttonPin_3 = 4;
const int buzzerPin = 5;
const int ledPin_1 = 11;
const int ledPin_2 = 12;
const int ledPin_3 = 13;

int buttonState_1 = 0;
int buttonState_2 = 0;
int buttonState_3 = 0;
int ledState_1 = LOW;
int ledState_2= LOW;
int ledState_3 = LOW;
int buzzerState = LOW;

int lastButtonState_1 = LOW;
int lastButtonState_2 = LOW;
int lastButtonState_3 = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 100;

char realPassword[3] = {'1', '2', '3'};
char passwordInserted[3];
char op;
int contOpC = LOW;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);
  pinMode(buttonPin_1, INPUT);
  pinMode(buttonPin_2, INPUT);
  pinMode(buttonPin_3, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop(){
  if(insertPassword()){
    while(showMenu());
  }
}

char pushButton(){
  int reading_1 = digitalRead(buttonPin_1);
  int reading_2 = digitalRead(buttonPin_2);
  int reading_3 = digitalRead(buttonPin_3);
  char ret = '0';

  if(reading_1 != lastButtonState_1 || reading_2 != lastButtonState_2 || reading_3 != lastButtonState_3){
    lastDebounceTime = millis();
  }

  if(millis() - lastDebounceTime >= debounceDelay) {
    if(reading_1 != buttonState_1){
      buttonState_1 = reading_1;
      if(reading_1) {
        Serial.println("Botão 1 apertado!");
        blinkOneLed(200, ledPin_1, ledState_1);
        ret = '1';
      }
    }
    if(reading_2 != buttonState_2){
      buttonState_2 = reading_2;
      if(reading_2) {
        Serial.println("Botão 2 apertado!");
        blinkOneLed(200, ledPin_2, ledState_2);
        ret = '2';
      }
    }
    if(reading_3 != buttonState_3){
      buttonState_3 = reading_3;
      if(reading_3){
        Serial.println("Botão 3 apertado!");
        blinkOneLed(200, ledPin_3, ledState_3);
        ret = '3';
      }
    }
  }

  lastButtonState_1 = reading_1;
  lastButtonState_2 = reading_2;
  lastButtonState_3 = reading_3;

  return ret;
}

int insertPassword(){
  int cont=0;
  char buttonPushed = '0';
  contOpC = LOW;

  Serial.println("\nAperte a sequência correta de botões para continuar...");

  while(cont<3){
    buttonPushed = pushButton();
    if(buttonPushed != '0'){
      passwordInserted[cont] = buttonPushed;
      cont++;
    }
  }

  int check = 0;
  for(int i=0; i<3; i++){
    if(realPassword[i]!=passwordInserted[i]){
      check++;
    }
  }

  if(check==0){
    Serial.println("\nSenha correta, bem vindo!\n");
    return 1;
  }

  incorrectPassword();
  return 0;
}

void incorrectPassword(){
  int cont = 0;
  int blinkTimes = 4;
  unsigned long ledIntervalMillis = 250;
  unsigned long previousMillis = millis();

  Serial.println("\nSenha incorreta!\n");
  buzzerState = !buzzerState;

  while(cont < blinkTimes*2){
    if(millis() - previousMillis >= ledIntervalMillis){
      previousMillis = millis();
      ledState_1 = !ledState_1;
      ledState_2 = !ledState_2;
      ledState_3 = !ledState_3;
      cont++;
    }
    digitalWrite(ledPin_1, ledState_1);
    digitalWrite(ledPin_2, ledState_2);
    digitalWrite(ledPin_3, ledState_3);
    digitalWrite(buzzerPin, buzzerState);
  }

  buzzerState = !buzzerState;
  digitalWrite(buzzerPin, buzzerState);
}

int showMenu() {
  Serial.println("Digite (a) para alterar a senha.");
  Serial.println("Digite (b) para visualizar a senha atual.");
  Serial.println("Digite (c) para ligar/desligar o buzzer");
  Serial.println("Digite (d) para logout\n");

  char op = insertMenuOption();

  switch(op){
    case 'a':
      changePassword();
      break;
    case 'b':
      showPassword();
      break;
    case 'c':
      switchBuzzer();
      break;
    case 'd':
      return 0;
      break;
    default:
      Serial.println("Digite uma opção válida!\n");
  }
  return 1;
}

char insertMenuOption(){
  char op = NULL;
  char opAux;
  while(op == NULL){
    if(Serial.available()){
      opAux = Serial.read();
      if(opAux != '\n'){
        op = opAux;
      }
    }
  }
  return op;
}

void showPassword(){
  Serial.print("Senha atual: botão ");
  Serial.print(realPassword[0]);
  Serial.print(", botão ");
  Serial.print(realPassword[1]);
  Serial.print(", botão ");
  Serial.print(realPassword[2]);
  Serial.print(".\n\n");
}

void changePassword(){
  int cont=0;
  char buttonPushed = '0';

  for(int i=0; i<3; i++){
    cont=0;
  
    if(i==0){
      Serial.println("Pressione o primeiro digito da senha: ");
    } else if(i==1){
      Serial.println("Pressione o segundo digito da senha: ");
    } else {
      Serial.println("Pressione o terceiro digito da senha: ");
    }

    while(cont<1){
      buttonPushed = pushButton();
      if(buttonPushed != '0'){
        realPassword[i] = buttonPushed;
        cont++;
      }
    }
  }

  Serial.println("\nSenha alterada com sucesso!\n");
}

void switchBuzzer(){
  contOpC = !contOpC;
  if(contOpC == HIGH){
    Serial.println("Buzzer ligado!");
    digitalWrite(buzzerPin, HIGH);
  } else{
    Serial.println("Buzzer desligado!\n");
    digitalWrite(buzzerPin, LOW);
  }
}

void blinkOneLed(unsigned long ledIntervalMillis, int ledPin, int ledState){
  unsigned long previousMillis = millis();
  ledState = HIGH;

  while(ledState!=LOW){
    if(millis() - previousMillis >= ledIntervalMillis){
      ledState = !ledState;
    }
    digitalWrite(ledPin, ledState);
  }
}

