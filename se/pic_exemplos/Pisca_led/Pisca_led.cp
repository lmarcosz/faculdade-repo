#line 1 "C:/Users/mluca/OneDrive/Documentos/UNIFESP/UC's/2024-2/SE/PIC/Pisca_led/Pisca_led.c"


void main(){
 TRISB =0;
 PORTB = 0;
 while(1){
 PORTB.RB7=0;
 Delay_ms(1000);
 PORTB.RB7=1;
 Delay_ms(1000);
 }
}
