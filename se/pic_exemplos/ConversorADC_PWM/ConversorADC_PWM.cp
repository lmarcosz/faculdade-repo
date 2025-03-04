#line 1 "C:/Users/mluca/OneDrive/Documentos/UNIFESP/UC's/2024-2/SE/PIC/ConversorADC_PWM/ConversorADC_PWM.c"








void main(){
 unsigned int uiValorAD;

 PORTA = 255;
 TRISA = 255;

 ADCON0 = 0b00000001;
 ADCON1 = 0b11001110;
 ADCON2 = 0b10111110;

 PWM1_Init(5000);
 PWM1_Start();
 while(1){

 uiValorAD= ADC_Read(0);
 uiValorAD*=0.249;
 PWM1_Set_Duty(uiValorAD);
 Delay_10us;
 }
}
