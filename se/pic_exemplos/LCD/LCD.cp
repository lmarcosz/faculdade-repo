#line 1 "C:/Users/mluca/OneDrive/Documentos/UNIFESP/UC's/2024-2/SE/PIC/LCD/LCD.c"








sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;


sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;


void helloWorldPIC18();



void main()
{
 ADCON1 = 0x0F;

 Lcd_Init();
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Cmd(_LCD_CLEAR);

 while(1)
 {

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



void helloWorldPIC18()
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
