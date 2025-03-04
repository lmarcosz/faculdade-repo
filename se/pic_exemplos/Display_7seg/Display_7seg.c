// Exemplo: Uso do Display 7Seg

void main(){ // função principal do programa
    ADCON1 = 0x0f; //configura todos os pinos como I/O
    TRISA = 0; //define porta como saida
    PORTA = 0; //resseta todos os pinos do porta
    TRISD = 0; //define portd como saida
    PORTD = 0; //seta todos os pinos do portd
  do { //inicio da rotina de loop
    PORTA.RA2= 1; //liga primeiro display
    PORTD = 0b11111101; //escreve digito 6
    Delay_ms(1); //delay de 1ms
    PORTA.RA2= 0; //desliga primeiro display

    PORTA.RA3= 1; //liga segundo display
    PORTD = 0b00111111; //escreve digito 0
    Delay_ms(1); //delay de 1ms
    PORTA.RA3= 0; //desliga terceiro display

    PORTA.RA4= 1; //liga terceiro display
    PORTD = 0b01101101; //escreve digito 5
    Delay_ms(1); //delay de 1ms
    PORTA.RA4= 0; //desliga terceiro display

    PORTA.RA5= 1; //liga quarto display
    PORTD = 0b00000111; //escreve digito 7
    Delay_ms(1); //delay de 1ms
    PORTA.RA5= 0; //desliga quarto display
  } while (1);
    }