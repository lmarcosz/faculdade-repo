
_main:

;Display_7seg.c,3 :: 		void main(){ // função principal do programa
;Display_7seg.c,4 :: 		ADCON1 = 0x0f; //configura todos os pinos como I/O
	MOVLW       15
	MOVWF       ADCON1+0 
;Display_7seg.c,5 :: 		TRISA = 0; //define porta como saida
	CLRF        TRISA+0 
;Display_7seg.c,6 :: 		PORTA = 0; //resseta todos os pinos do porta
	CLRF        PORTA+0 
;Display_7seg.c,7 :: 		TRISD = 0; //define portd como saida
	CLRF        TRISD+0 
;Display_7seg.c,8 :: 		PORTD = 0; //seta todos os pinos do portd
	CLRF        PORTD+0 
;Display_7seg.c,9 :: 		do { //inicio da rotina de loop
L_main0:
;Display_7seg.c,10 :: 		PORTA.RA2= 1; //liga primeiro display
	BSF         PORTA+0, 2 
;Display_7seg.c,11 :: 		PORTD = 0b11111101; //escreve digito 6
	MOVLW       253
	MOVWF       PORTD+0 
;Display_7seg.c,12 :: 		Delay_ms(1); //delay de 1ms
	MOVLW       3
	MOVWF       R12, 0
	MOVLW       151
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 1
	BRA         L_main3
	DECFSZ      R12, 1, 1
	BRA         L_main3
	NOP
	NOP
;Display_7seg.c,13 :: 		PORTA.RA2= 0; //desliga primeiro display
	BCF         PORTA+0, 2 
;Display_7seg.c,15 :: 		PORTA.RA3= 1; //liga segundo display
	BSF         PORTA+0, 3 
;Display_7seg.c,16 :: 		PORTD = 0b00111111; //escreve digito 0
	MOVLW       63
	MOVWF       PORTD+0 
;Display_7seg.c,17 :: 		Delay_ms(1); //delay de 1ms
	MOVLW       3
	MOVWF       R12, 0
	MOVLW       151
	MOVWF       R13, 0
L_main4:
	DECFSZ      R13, 1, 1
	BRA         L_main4
	DECFSZ      R12, 1, 1
	BRA         L_main4
	NOP
	NOP
;Display_7seg.c,18 :: 		PORTA.RA3= 0; //desliga terceiro display
	BCF         PORTA+0, 3 
;Display_7seg.c,20 :: 		PORTA.RA4= 1; //liga terceiro display
	BSF         PORTA+0, 4 
;Display_7seg.c,21 :: 		PORTD = 0b01101101; //escreve digito 5
	MOVLW       109
	MOVWF       PORTD+0 
;Display_7seg.c,22 :: 		Delay_ms(1); //delay de 1ms
	MOVLW       3
	MOVWF       R12, 0
	MOVLW       151
	MOVWF       R13, 0
L_main5:
	DECFSZ      R13, 1, 1
	BRA         L_main5
	DECFSZ      R12, 1, 1
	BRA         L_main5
	NOP
	NOP
;Display_7seg.c,23 :: 		PORTA.RA4= 0; //desliga terceiro display
	BCF         PORTA+0, 4 
;Display_7seg.c,25 :: 		PORTA.RA5= 1; //liga quarto display
	BSF         PORTA+0, 5 
;Display_7seg.c,26 :: 		PORTD = 0b00000111; //escreve digito 7
	MOVLW       7
	MOVWF       PORTD+0 
;Display_7seg.c,27 :: 		Delay_ms(1); //delay de 1ms
	MOVLW       3
	MOVWF       R12, 0
	MOVLW       151
	MOVWF       R13, 0
L_main6:
	DECFSZ      R13, 1, 1
	BRA         L_main6
	DECFSZ      R12, 1, 1
	BRA         L_main6
	NOP
	NOP
;Display_7seg.c,28 :: 		PORTA.RA5= 0; //desliga quarto display
	BCF         PORTA+0, 5 
;Display_7seg.c,29 :: 		} while (1);
	GOTO        L_main0
;Display_7seg.c,30 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
