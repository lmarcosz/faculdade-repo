// ********************************************************************************
//             PROGRAMA EXEMPLO: Leitura do canal A/D AN0 e utilização do
//                             no PWM para acionar a ventoinha.
//
//                    OBJETIVO: Aprender a utilizar o canal PWM.
//
// ********************************************************************************

void main(){
   unsigned int  uiValorAD;     // Variavel que armazena o valor do A/D.

   PORTA = 255;
   TRISA = 255;                 // Configura PORTA pins como entrada

   ADCON0 = 0b00000001;  // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
   ADCON1 = 0b11001110;  // Configura todos canais como Digital menos AN0 e REF Interna.
   ADCON2 = 0b10111110;  // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.

   PWM1_Init(5000);      // Inicializa módulo PWM com 5Khz
   PWM1_Start();         // Start PWM
   while(1){   // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.

      uiValorAD= ADC_Read(0);     // Lê Canal AD 0
      uiValorAD*=0.249;            // Converte valor para o duty cycle
      PWM1_Set_Duty(uiValorAD);   // Envia o valor lido de "uiValorAD" para o módulo CCP1 pwm
      Delay_10us;
   }
}