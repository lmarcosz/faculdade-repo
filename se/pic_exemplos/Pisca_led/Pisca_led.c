//Exemplo: Pisca_leds

void main(){           // Fun��o principal de qualquer programa escrito na linguagem C.
   TRISB =0;            // Define todos os pinos do PORTB como sa�da.
   PORTB = 0;           // Colocar todos os pinos em n�vel baixo.
   while(1){           // Aqui definimos uma condi��o sempre verdadeira como parametro, portanto todo o bloco ser� repetido indefinidamente.
      PORTB.RB7=0;         // Todos os pinos do PORTB em 0.
      Delay_ms(1000);  // Esta fun��o � interna do compilador, portanto o tempo � de 1000ms ou 1 segundo.
      PORTB.RB7=1;       // Todos os pinos do PORTB em 1.
      Delay_ms(1000);  // Aguarda novamente 1 segundo.
   }
}