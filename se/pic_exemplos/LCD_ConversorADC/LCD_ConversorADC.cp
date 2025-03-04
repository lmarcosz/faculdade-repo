#line 1 "C:/Users/mluca/OneDrive/Documentos/UNIFESP/UC's/2024-2/SE/PIC/LCD_ConversorADC/LCD_ConversorADC.c"








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

char pot1_string [8];
char pot2_string [8];
char apagar [] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

unsigned int pot1 = 0;
unsigned int pot2 = 0;

void main()
{
 TRISA0_bit = 1;
 TRISA1_bit = 1;

 ADCON1 = 0b00001110;
 ADC_Init();
 CMCON = 0b00000111;

 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);

 while(1)
 {
 pot1 = ADC_Get_Sample(0);
 pot2 = ADC_Get_Sample(1);

 IntToStr (pot1,pot1_string);
 IntToStr (pot2,pot2_string);

 Ltrim(pot1_string);
 Ltrim(pot2_string);

 Lcd_Out(1,1,"S1:");
 Lcd_Out_Cp(pot1_string);

 Lcd_Out(1,9,"S2:");
 Lcd_Out_Cp(pot2_string);

 delay_ms(100);
 }
}
