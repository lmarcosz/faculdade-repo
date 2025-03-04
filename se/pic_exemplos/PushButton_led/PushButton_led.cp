#line 1 "C:/Users/mluca/OneDrive/Documentos/UNIFESP/UC's/2024-2/SE/PIC/PushButton_led/PushButton_led.c"


void main() {

 unsigned int uiContador = 0;
 unsigned int uiValor = 0;
 unsigned char ucStatus_inc = 0;

 ADCON1 = 0x0f;

 TRISB.RB0=1;

 TRISB.RB7=0;

 while(1){
 if((PORTB.RB0==0)&&(ucStatus_inc==0)){
 uiContador++;
 ucStatus_inc=1;
 }
 if((PORTB.RB0==1)&&(ucStatus_inc==1)){
 ucStatus_inc=0;
 }
 delay_ms(100);
 uiValor = uiContador%2;
 if (uiValor == 0){
 PORTB.RB7 = 0;
 }
 else{
 PORTB.RB7 = 1;
 }
 }
}
