#line 1 "C:/Users/mluca/OneDrive/Documentos/UNIFESP/UC's/2024-2/SE/PIC/ProjetoFinal_PIC/ProjetoFinal_PIC.c"



sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;


sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;

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


 unsigned int uiContador = 0;
 unsigned int uiValor = 0;
 unsigned char ucStatus_inc = 0;
 unsigned int uiValorAD;

 char valorTAP_string [8];
 char valorUmidade_string [8];

 PORTA = 1;
 TRISA = 1;
 TRISB.RB0=1;
 TRISC.RC3 = 1;
 TRISC.RC4 = 1;

 ADCON0 = 0b00000001;
 ADCON1 = 0b11001110;
 ADCON2 = 0b10111110;

 Lcd_Init();
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Cmd(_LCD_CLEAR);

 PWM1_Init(5000);
 PWM1_Start();
 I2C1_Init(100000);

 while(1){

 if (I2C1_Is_Idle()){
 receberDados();
 }


 uiValorAD= ADC_Read(0);
 uiValorAD*=0.249;
 if(flagCooler){
 PWM1_Set_Duty(uiValorAD);
 Delay_10us;
 } else {
 PWM1_Set_Duty(0);
 }


 if((PORTB.RB0==0)&&(ucStatus_inc==0)){
 uiContador++;
 ucStatus_inc=1;
 Lcd_Cmd(_LCD_CLEAR);
 }

 if((PORTB.RB0==1)&&(ucStatus_inc==1)){
 ucStatus_inc=0;
 }
 delay_ms(100);

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


unsigned char I2C_ReceiveByte(unsigned char ack) {
 unsigned char dado = I2C1_Rd(ack);
 return dado;
}


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


void receberDados() {
 flagCooler = I2C_ReceiveByte(1);
 valorTemp = I2C_ReceiveFloat();
 valorPressure = I2C_ReceiveFloat();
 valorAltitude = I2C_ReceiveFloat();
 valorUmidade = I2C_ReceiveInt();
 I2C_ReceiveByte(0);
}
