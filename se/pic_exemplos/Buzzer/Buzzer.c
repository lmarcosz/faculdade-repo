//Exemplo Uso do Buzzer

void main()
{
  TRISC.RC1 = 0;      //PORT C configurado como sa�da

  while(1)
  {
    PORTC.RC1 = ~PORTC.RC1;   //invers�o de estado
    delay_ms(1000);   //delay de 1000 milisegundos
  }
}