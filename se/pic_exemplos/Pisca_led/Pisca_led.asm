
_main:

;Pisca_led.c,3 :: 		void main(){           // Função principal de qualquer programa escrito na linguagem C.
;Pisca_led.c,4 :: 		TRISB =0;            // Define todos os pinos do PORTB como saída.
	CLRF        TRISB+0 
;Pisca_led.c,5 :: 		PORTB = 0;           // Colocar todos os pinos em nível baixo.
	CLRF        PORTB+0 
;Pisca_led.c,6 :: 		while(1){           // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
L_main0:
;Pisca_led.c,7 :: 		PORTB.RB7=0;         // Todos os pinos do PORTB em 0.
	BCF         PORTB+0, 7 
;Pisca_led.c,8 :: 		Delay_ms(1000);  // Esta função é interna do compilador, portanto o tempo é de 1000ms ou 1 segundo.
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
;Pisca_led.c,9 :: 		PORTB.RB7=1;       // Todos os pinos do PORTB em 1.
	BSF         PORTB+0, 7 
;Pisca_led.c,10 :: 		Delay_ms(1000);  // Aguarda novamente 1 segundo.
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 1
	BRA         L_main3
	DECFSZ      R12, 1, 1
	BRA         L_main3
	DECFSZ      R11, 1, 1
	BRA         L_main3
	NOP
	NOP
;Pisca_led.c,11 :: 		}
	GOTO        L_main0
;Pisca_led.c,12 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
