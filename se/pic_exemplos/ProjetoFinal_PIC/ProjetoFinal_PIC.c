#define PIC_ADDRESS 0x0A

// Selecionando pinos utilizados para comunicação com display LCD
sbit LCD_RS at RE2_bit;   // PINO 2 DO PORTD LIGADO AO RS DO DISPLAY
sbit LCD_EN at RE1_bit;   // PINO 3 DO PORTD LIGADO AO EN DO DISPLAY
sbit LCD_D7 at RD7_bit;  // PINO 7 DO PORTD LIGADO AO D7 DO DISPLAY
sbit LCD_D6 at RD6_bit;  // PINO 6 DO PORTD LIGADO AO D6 DO DISPLAY
sbit LCD_D5 at RD5_bit;  // PINO 5 DO PORTD LIGADO AO D5 DO DISPLAY
sbit LCD_D4 at RD4_bit;  // PINO 4 DO PORTD LIGADO AO D4 DO DISPLAY

// Selecionando direção de fluxo de dados dos pinos utilizados para a comunicação com display LCD
sbit LCD_RS_Direction at TRISE2_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 2 DO PORTD
sbit LCD_EN_Direction at TRISE1_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 3 DO PORTD
sbit LCD_D7_Direction at TRISD7_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 7 DO PORTD
sbit LCD_D6_Direction at TRISD6_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 6 DO PORTD
sbit LCD_D5_Direction at TRISD5_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 5 DO PORTD
sbit LCD_D4_Direction at TRISD4_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 4 DO PORTD

int flagCooler = 1;
float valorAltitude = 0;
float valorPressure = 0;
float valorTemp = 0;
int valorUmidade = 0;

void receberDados();
unsigned char I2C_ReceiveByte(unsigned char ack);
int I2C_ReceiveInt();
float I2C_ReceiveFloat();

void main(){
   unsigned int  uiContador = 0;
   unsigned int  uiValor = 0;
   unsigned char ucStatus_inc = 0;
   unsigned int  uiValorAD;
   
   char valorTAP_string [8];
   char valorUmidade_string [8];

   PORTA = 1;
   TRISA = 1;                 // Configura PORTA pins como entrada
   TRISB.RB0=1;         // Define o pino RB0 do PORTB como entrada (botão).
   TRISC.RC3 = 1;       // SCL como entrada
   TRISC.RC4 = 1;       // SDA como entrada
   
   ADCON0 = 0b00000001;  // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
   ADCON1 = 0b11001110;  // Configura todos canais como Digital menos AN0 e REF Interna.
   ADCON2 = 0b10111110;  // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.

   Lcd_Init();
   Lcd_Cmd(_LCD_CURSOR_OFF);
   Lcd_Cmd(_LCD_CLEAR);

   PWM1_Init(5000);      // Inicializa módulo PWM com 5Khz
   PWM1_Start();        // Start PWM
   I2C1_Init(100000); // Inicializa o I2C como escravo
   
   while(1){
      // Recebe os dados
      if (I2C1_Is_Idle()){
         receberDados();
      }

      //Ativa Cooler
      uiValorAD= ADC_Read(0);     // Lê Canal AD 0
      uiValorAD*=0.249;            // Converte valor para o duty cycle
      if(flagCooler){
        PWM1_Set_Duty(uiValorAD);   // Envia o valor lido de "uiValorAD" para o módulo CCP1 pwm
        Delay_10us;
      } else {
        PWM1_Set_Duty(0);
      }
      
      //Botão apertado
      if((PORTB.RB0==0)&&(ucStatus_inc==0)){       // Incrementa somente uma vez quando a tecla for pressionada.
        uiContador++;
        ucStatus_inc=1;
        Lcd_Cmd(_LCD_CLEAR);
      }
      //Botão solto
      if((PORTB.RB0==1)&&(ucStatus_inc==1)){   // Volta a disponibilizar a op??o de incremento quando a tecla for solta.
        ucStatus_inc=0;
      }
      //delay_ms(100);  //Pode ser um debounce
      
      uiValor = uiContador%4;
      if (uiValor == 0){
         lcd_out(1,1,"Temperatura");
         FloatToStr (valorTemp,valorTAP_string);
         Ltrim(valorTAP_string);
         lcd_out(2,1,valorTAP_string);
      }
      else if(uiValor == 1){
         lcd_out(1,1,"Pressao Atmosf");
         FloatToStr (valorPressure,valorTAP_string);
         Ltrim(valorTAP_string);
         lcd_out(2,1,valorTAP_string);
      }
      else if(uiValor == 2){
         lcd_out(1,1,"Umidade do Solo");
         IntToStr (valorUmidade,valorUmidade_string);
         Ltrim(valorUmidade_string);
         lcd_out(2,1,valorUmidade_string);
      }
      else {
         lcd_out(1,1,"Altitude");
         FloatToStr (valorAltitude,valorTAP_string);
         Ltrim(valorTAP_string);
         lcd_out(2,1,valorTAP_string);
      }
   }
}

// Função para receber um byte via I2C
unsigned char I2C_ReceiveByte(unsigned char ack) {
  unsigned char dado = I2C1_Rd(ack);  // Lê um byte
  return dado;
}

// Função para receber um float via I2C
float I2C_ReceiveFloat() {
  union {
    float valor;
    unsigned char bytes[4];
  } floatUnion;
  int i;
  for (i = 0; i < 4; i++) {
    floatUnion.bytes[i] = I2C_ReceiveByte(1);
  }
  return floatUnion.valor;
}

// Função para receber um inteiro via I2C
int I2C_ReceiveInt() {
  union {
    int valor;
    unsigned char bytes[2];
  } intUnion;
  int i;
  for (i = 0; i < 2; i++) {
    intUnion.bytes[i] = I2C_ReceiveByte(1);
  }
  return intUnion.valor;
}

// Função para receber dados via I2C
void receberDados() {
  flagCooler = I2C_ReceiveByte(1);
  valorTemp = I2C_ReceiveFloat();
  valorPressure = I2C_ReceiveFloat();
  valorAltitude = I2C_ReceiveFloat();
  valorUmidade = I2C_ReceiveInt();
  I2C_ReceiveByte(0);
}
