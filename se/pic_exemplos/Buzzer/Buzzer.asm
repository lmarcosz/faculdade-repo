
_main:

;Buzzer.c,3 :: 		void main()
;Buzzer.c,5 :: 		TRISC.RC1 = 0;      //PORT C configurado como saída
	BCF         TRISC+0, 1 
;Buzzer.c,7 :: 		while(1)
L_main0:
;Buzzer.c,9 :: 		PORTC.RC1 = ~PORTC.RC1;   //inversão de estado
	BTG         PORTC+0, 1 
;Buzzer.c,10 :: 		delay_ms(1000);   //delay de 1000 milisegundos
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 1
	BRA         L_main2
	DECFSZ      R12, 1, 1
	BRA         L_main2
	DECFSZ      R11, 1, 1
	BRA         L_main2
	NOP
	NOP
;Buzzer.c,11 :: 		}
	GOTO        L_main0
;Buzzer.c,12 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
