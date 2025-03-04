/* Este código implementa um contador que conta o número de vezes que
um botão (push-button) mudou de estado. Essa quantidade é impressa no
Monitor Serial a cada segundo. Adicionalmente, ao pressionar o botão, um
LED é aceso.
Obs.: Não é feito o tratamento do efeito bouncing. */
const int buttonPin = 2; // número do pino do botão (pino 2)
const int ledPin = 13; // número do pino do LED (pino 13)
bool last; // Guarda o último estado do botão;
unsigned long print_timer = 0; // Timer para a impressão na porta
 // serial UART0;
uint8_t counter = 0; // Contador: conta o número de mudança de
 // estados no botão;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); // define o pino do botão como entrada
  pinMode(ledPin, OUTPUT); // define o pino do LED como saída
  last = digitalRead(buttonPin);
}

void loop() {
  bool now = digitalRead(buttonPin); // Lê o estado atual do botão;

  if (now != last) { // Checa se houve uma mudança de estado;
    ++counter;
    last = now; // Atualiza o ultimo estado;
    if (now == true) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }

  if (millis() - print_timer > 1000) { // Imprime a quantidade de mudanças // a cada segundo;
    Serial.println(counter);
    print_timer = millis();
  }
}


