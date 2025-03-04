#line 1 "C:/Users/mluca/OneDrive/Documentos/UNIFESP/UC's/2024-2/SE/PIC/Buzzer/Buzzer.c"


void main()
{
 TRISC.RC1 = 0;

 while(1)
 {
 PORTC.RC1 = ~PORTC.RC1;
 delay_ms(1000);
 }
}
