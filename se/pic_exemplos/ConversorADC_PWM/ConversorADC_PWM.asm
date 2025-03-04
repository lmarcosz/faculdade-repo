
_main:

;ConversorADC_PWM.c,9 :: 		void main(){
;ConversorADC_PWM.c,12 :: 		PORTA = 255;
	MOVLW       255
	MOVWF       PORTA+0 
;ConversorADC_PWM.c,13 :: 		TRISA = 255;                 // Configura PORTA pins como entrada
	MOVLW       255
	MOVWF       TRISA+0 
;ConversorADC_PWM.c,15 :: 		ADCON0 = 0b00000001;  // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
	MOVLW       1
	MOVWF       ADCON0+0 
;ConversorADC_PWM.c,16 :: 		ADCON1 = 0b11001110;  // Configura todos canais como Digital menos AN0 e REF Interna.
	MOVLW       206
	MOVWF       ADCON1+0 
;ConversorADC_PWM.c,17 :: 		ADCON2 = 0b10111110;  // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.
	MOVLW       190
	MOVWF       ADCON2+0 
;ConversorADC_PWM.c,19 :: 		PWM1_Init(5000);      // Inicializa módulo PWM com 5Khz
	BSF         T2CON+0, 0, 0
	BCF         T2CON+0, 1, 0
	MOVLW       99
	MOVWF       PR2+0, 0
	CALL        _PWM1_Init+0, 0
;ConversorADC_PWM.c,20 :: 		PWM1_Start();         // Start PWM
	CALL        _PWM1_Start+0, 0
;ConversorADC_PWM.c,21 :: 		while(1){   // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
L_main0:
;ConversorADC_PWM.c,23 :: 		uiValorAD= ADC_Read(0);     // Lê Canal AD 0
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
;ConversorADC_PWM.c,24 :: 		uiValorAD*=0.249;            // Converte valor para o duty cycle
	CALL        _word2double+0, 0
	MOVLW       219
	MOVWF       R4 
	MOVLW       249
	MOVWF       R5 
	MOVLW       126
	MOVWF       R6 
	MOVLW       124
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _double2word+0, 0
;ConversorADC_PWM.c,25 :: 		PWM1_Set_Duty(uiValorAD);   // Envia o valor lido de "uiValorAD" para o módulo CCP1 pwm
	MOVF        R0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;ConversorADC_PWM.c,27 :: 		}
	GOTO        L_main0
;ConversorADC_PWM.c,28 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
