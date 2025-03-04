// Exemplo: Uso do PushButton

void main() {

   unsigned int  uiContador = 0;   // Variavel de armazenamento do contador.
   unsigned int  uiValor = 0;      // Variavel auxiliar para exibi??o do contador.
   unsigned char ucStatus_inc = 0; // Variavel de tratamento do incremento.

   ADCON1 = 0x0f;       // Configura todos canais como Digital.

   TRISB.RB0=1;         // Define o pino RB0 do PORTB como entrada.

   TRISB.RB7=0;         // Define o pino RB7 do PORTA como saida

   while(1){
     if((PORTB.RB0==0)&&(ucStatus_inc==0)){       // Incrementa somente uma vez quando a tecla for pressionada.
           uiContador++;
           ucStatus_inc=1;
     }
     if((PORTB.RB0==1)&&(ucStatus_inc==1)){   // Volta a disponibilizar a op??o de incremento quando a tecla for solta.
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