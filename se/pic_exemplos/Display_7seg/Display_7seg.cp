#line 1 "C:/Users/mluca/OneDrive/Documentos/UNIFESP/UC's/2024-2/SE/PIC/Display_7seg/Display_7seg.c"


void main(){
 ADCON1 = 0x0f;
 TRISA = 0;
 PORTA = 0;
 TRISD = 0;
 PORTD = 0;
 do {
 PORTA.RA2= 1;
 PORTD = 0b11111101;
 Delay_ms(1);
 PORTA.RA2= 0;

 PORTA.RA3= 1;
 PORTD = 0b00111111;
 Delay_ms(1);
 PORTA.RA3= 0;

 PORTA.RA4= 1;
 PORTD = 0b01101101;
 Delay_ms(1);
 PORTA.RA4= 0;

 PORTA.RA5= 1;
 PORTD = 0b00000111;
 Delay_ms(1);
 PORTA.RA5= 0;
 } while (1);
 }
