#line 1 "C:/Users/mluca/OneDrive/Documentos/UNIFESP/UC's/2024-2/SE/projeto final 2/projeto_final_2.c"



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

int flagCooler = 0;
float valorAltitude = 0;
float valorPressure = 0;
float valorTemp = 0;
int valorUmidade = 0;

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
 TRISC.RC1 = 0;
 TRISC.TRISC6 = 0;
 TRISC.TRISC7 = 1;

 ADCON0 = 0b00000001;
 ADCON1 = 0b11001110;
 ADCON2 = 0b10111110;

 Lcd_Init();
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Cmd(_LCD_CLEAR);

 PWM1_Init(5000);
 PWM1_Start();

 UART1_Init(9600);
 Delay_ms(100);

 while(1){

 flagCooler = UART1_Read();


 uiValorAD= ADC_Read(0);
 uiValorAD*=0.249;
 if(flagCooler == 1){
 PWM1_Set_Duty(uiValorAD);
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

 uiValor = uiContador%4;
 if (uiValor == 0){
 lcd_out(1,1,"Temperatura");
 FloatToStr(valorTemp, valorTAP_string);
 Ltrim(valorTAP_string);
 lcd_out(2,1,valorTAP_string);
 }
 else if(uiValor == 1){
 lcd_out(1,1,"Pressao Atmosf");
 FloatToStr(valorPressure, valorTAP_string);
 Ltrim(valorTAP_string);
 lcd_out(2,1,valorTAP_string);
 }
 else if(uiValor == 2){
 lcd_out(1,1,"Umidade do Solo");
 IntToStr(valorUmidade, valorUmidade_string);
 Ltrim(valorUmidade_string);
 lcd_out(2,1,valorUmidade_string);
 }
 else {
 lcd_out(1,1,"Altitude");
 FloatToStr(valorAltitude, valorTAP_string);
 Ltrim(valorTAP_string);
 lcd_out(2,1,valorTAP_string);
 }
 }
}
