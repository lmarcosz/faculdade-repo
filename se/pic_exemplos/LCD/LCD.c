//********************************************************************************
//
//                      PROGRAMA EXEMPLO: Display LCD 16x2.
//             OBJETIVO: Aprender a utilizar o LCD com o PIC18F4520.
//
//********************************************************************************

// --- Ligações entre PIC e LCD ---
sbit LCD_RS at RE2_bit;   // PINO 2 DO PORTD LIGADO AO RS DO DISPLAY
sbit LCD_EN at RE1_bit;   // PINO 3 DO PORTD LIGADO AO EN DO DISPLAY
sbit LCD_D7 at RD7_bit;  // PINO 7 DO PORTD LIGADO AO D7 DO DISPLAY
sbit LCD_D6 at RD6_bit;  // PINO 6 DO PORTD LIGADO AO D6 DO DISPLAY
sbit LCD_D5 at RD5_bit;  // PINO 5 DO PORTD LIGADO AO D5 DO DISPLAY
sbit LCD_D4 at RD4_bit;  // PINO 4 DO PORTD LIGADO AO D4 DO DISPLAY

// Selecionando direção de fluxo de dados dos pinos utilizados para a comunicação com display LCD
sbit LCD_RS_Direction at TRISE2_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 2 DO PORTD
sbit LCD_EN_Direction at TRISE1_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 3 DO PORTD
sbit LCD_D7_Direction at TRISD7_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 7 DO PORTD
sbit LCD_D6_Direction at TRISD6_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 6 DO PORTD
sbit LCD_D5_Direction at TRISD5_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 5 DO PORTD
sbit LCD_D4_Direction at TRISD4_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 4 DO PORTD

// --- Protótipo das Funções Auxiliares ---
void helloWorldPIC18();                        //Declara a função da mensagem no LCD, caractere por caractere


// --- Função Principal ---
void main()
{
     ADCON1  = 0x0F;                           //Configura os pinos como digitais

     Lcd_Init();                               //Inicializa módulo LCD
     Lcd_Cmd(_LCD_CURSOR_OFF);                 //Apaga cursor
     Lcd_Cmd(_LCD_CLEAR);                      //Limpa display

     while(1)
     {
         //helloWorldPIC18();
         lcd_out(1,3,"Temperatura");
         lcd_out(2,5,"30,45 C");
         delay_ms(2000);
         Lcd_Cmd(_LCD_CLEAR);
         
         lcd_out(1,5,"Altitude");
         lcd_out(2,7,"843m");
         delay_ms(2000);
         Lcd_Cmd(_LCD_CLEAR);
         
         lcd_out(1,1,"Umidade do Solo");
         lcd_out(2,7,"42%");
         delay_ms(2000);
         Lcd_Cmd(_LCD_CLEAR);
         
         lcd_out(1,2,"Pressao Atmosf");
         lcd_out(2,5,"0,9 atm");
         delay_ms(2000);
         Lcd_Cmd(_LCD_CLEAR);

     }
}

// --- Desenvolvimento das Funções Auxiliares ---

void helloWorldPIC18()    // Comente essa função
{
   lcd_chr(1,3,'H');
   lcd_chr_cp ('e');
   lcd_chr_cp ('l');
   lcd_chr_cp ('l');
   lcd_chr_cp ('o');
   lcd_chr_cp (' ');
   lcd_chr_cp ('W');
   lcd_chr_cp ('o');
   lcd_chr_cp ('r');
   lcd_chr_cp ('l');
   lcd_chr_cp ('d');

   lcd_chr(2,2,'P');
   lcd_chr_cp ('I');
   lcd_chr_cp ('C');
   lcd_chr_cp ('1');
   lcd_chr_cp ('8');
   lcd_chr_cp ('F');
   lcd_chr_cp ('4');
   lcd_chr_cp ('5');
   lcd_chr_cp ('2');
   lcd_chr_cp ('0');
}
