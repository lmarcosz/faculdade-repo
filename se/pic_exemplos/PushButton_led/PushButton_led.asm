
_main:

;PushButton_led.c,3 :: 		void main() {
;PushButton_led.c,5 :: 		unsigned int  uiContador = 0;   // Variavel de armazenamento do contador.
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
	CLRF        main_ucStatus_inc_L0+0 
;PushButton_led.c,9 :: 		ADCON1 = 0x0f;       // Configura todos canais como Digital.
	MOVLW       15
	MOVWF       ADCON1+0 
;PushButton_led.c,11 :: 		TRISB.RB0=1;         // Define o pino RB0 do PORTB como entrada.
	BSF         TRISB+0, 0 
;PushButton_led.c,13 :: 		TRISB.RB7=0;         // Define o pino RB7 do PORTA como saida
	BCF         TRISB+0, 7 
;PushButton_led.c,15 :: 		while(1){
L_main0:
;PushButton_led.c,16 :: 		if((PORTB.RB0==0)&&(ucStatus_inc==0)){       // Incrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 0 
	GOTO        L_main4
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main4
L__main12:
;PushButton_led.c,17 :: 		uiContador++;
	INFSNZ      main_uiContador_L0+0, 1 
	INCF        main_uiContador_L0+1, 1 
;PushButton_led.c,18 :: 		ucStatus_inc=1;
	MOVLW       1
	MOVWF       main_ucStatus_inc_L0+0 
;PushButton_led.c,19 :: 		}
L_main4:
;PushButton_led.c,20 :: 		if((PORTB.RB0==1)&&(ucStatus_inc==1)){   // Volta a disponibilizar a op??o de incremento quando a tecla for solta.
	BTFSS       PORTB+0, 0 
	GOTO        L_main7
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main7
L__main11:
;PushButton_led.c,21 :: 		ucStatus_inc=0;
	CLRF        main_ucStatus_inc_L0+0 
;PushButton_led.c,22 :: 		}
L_main7:
;PushButton_led.c,23 :: 		delay_ms(100);
	MOVLW       2
	MOVWF       R11, 0
	MOVLW       4
	MOVWF       R12, 0
	MOVLW       186
	MOVWF       R13, 0
L_main8:
	DECFSZ      R13, 1, 1
	BRA         L_main8
	DECFSZ      R12, 1, 1
	BRA         L_main8
	DECFSZ      R11, 1, 1
	BRA         L_main8
	NOP
;PushButton_led.c,24 :: 		uiValor = uiContador%2;
	MOVLW       1
	ANDWF       main_uiContador_L0+0, 0 
	MOVWF       R1 
	MOVF        main_uiContador_L0+1, 0 
	MOVWF       R2 
	MOVLW       0
	ANDWF       R2, 1 
;PushButton_led.c,25 :: 		if (uiValor == 0){
	MOVLW       0
	XORWF       R2, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main14
	MOVLW       0
	XORWF       R1, 0 
L__main14:
	BTFSS       STATUS+0, 2 
	GOTO        L_main9
;PushButton_led.c,26 :: 		PORTB.RB7 = 0;
	BCF         PORTB+0, 7 
;PushButton_led.c,27 :: 		}
	GOTO        L_main10
L_main9:
;PushButton_led.c,29 :: 		PORTB.RB7 = 1;
	BSF         PORTB+0, 7 
;PushButton_led.c,30 :: 		}
L_main10:
;PushButton_led.c,31 :: 		}
	GOTO        L_main0
;PushButton_led.c,32 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
