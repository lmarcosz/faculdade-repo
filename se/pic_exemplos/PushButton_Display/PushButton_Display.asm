
_main:

;PushButton_Display.c,3 :: 		void main(){
;PushButton_Display.c,5 :: 		unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	MOVLW       63
	MOVWF       main_ucMask_L0+0 
	MOVLW       6
	MOVWF       main_ucMask_L0+1 
	MOVLW       91
	MOVWF       main_ucMask_L0+2 
	MOVLW       79
	MOVWF       main_ucMask_L0+3 
	MOVLW       102
	MOVWF       main_ucMask_L0+4 
	MOVLW       109
	MOVWF       main_ucMask_L0+5 
	MOVLW       125
	MOVWF       main_ucMask_L0+6 
	MOVLW       7
	MOVWF       main_ucMask_L0+7 
	MOVLW       127
	MOVWF       main_ucMask_L0+8 
	MOVLW       111
	MOVWF       main_ucMask_L0+9 
;PushButton_Display.c,14 :: 		ADCON1 = 0x0f;       // Configura todos canais como Digital.
	MOVLW       15
	MOVWF       ADCON1+0 
;PushButton_Display.c,16 :: 		TRISB.RB0=1;         // Define o pino RB0 do PORTB como entrada.
	BSF         TRISB+0, 0 
;PushButton_Display.c,17 :: 		TRISB.RB1=1;         // Define o pino RB1 Do PORTB como entrada.
	BSF         TRISB+0, 1 
;PushButton_Display.c,19 :: 		TRISA.RA2=0;         // Define o pino RA2 do PORTA como saida(Sele??o Display 1).
	BCF         TRISA+0, 2 
;PushButton_Display.c,20 :: 		TRISA.RA3=0;         // Define o pino RA3 do PORTA como saida(Sele??o Display 2).
	BCF         TRISA+0, 3 
;PushButton_Display.c,21 :: 		TRISA.RA4=0;         // Define o pino RA4 do PORTA como saida(Sele??o Display 3).
	BCF         TRISA+0, 4 
;PushButton_Display.c,22 :: 		TRISA.RA5=0;         // Define o pino RA5 do PORTA como saida(Sele??o Display 4).
	BCF         TRISA+0, 5 
;PushButton_Display.c,24 :: 		TRISD = 0;           // Define todos os pinos Do PORTD como saida.
	CLRF        TRISD+0 
;PushButton_Display.c,26 :: 		ucStatus_inc=0;      // Inicializa a variavel com o valor 0.
	CLRF        main_ucStatus_inc_L0+0 
;PushButton_Display.c,27 :: 		ucStatus_dec=0;      // Inicializa a variavel com o valor 0.
	CLRF        main_ucStatus_dec_L0+0 
;PushButton_Display.c,28 :: 		uiContador=0;        // Inicializa a variavel com o valor 0.
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
;PushButton_Display.c,30 :: 		while(1){            // Aqui definimos uma condi??o sempre verdadeira como parametro, portanto todo o bloco ser? repetido indefinidamente.
L_main0:
;PushButton_Display.c,33 :: 		if((PORTB.RB0==0)&&(ucStatus_inc==0)){   // Incrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 0 
	GOTO        L_main4
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main4
L__main23:
;PushButton_Display.c,34 :: 		ucStatus_inc=1;                       // Variavel de travamento do incremento.
	MOVLW       1
	MOVWF       main_ucStatus_inc_L0+0 
;PushButton_Display.c,35 :: 		uiContador++;                         // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
	INFSNZ      main_uiContador_L0+0, 1 
	INCF        main_uiContador_L0+1, 1 
;PushButton_Display.c,36 :: 		if(uiContador>9999){ // Define o valor maximo a ser mostrado no displays como 9999.
	MOVF        main_uiContador_L0+1, 0 
	SUBLW       39
	BTFSS       STATUS+0, 2 
	GOTO        L__main25
	MOVF        main_uiContador_L0+0, 0 
	SUBLW       15
L__main25:
	BTFSC       STATUS+0, 0 
	GOTO        L_main5
;PushButton_Display.c,37 :: 		uiContador=0;
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
;PushButton_Display.c,38 :: 		}
L_main5:
;PushButton_Display.c,39 :: 		}
L_main4:
;PushButton_Display.c,40 :: 		if((PORTB.RB0==1)&&(ucStatus_inc==1)){   // Volta a disponibilizar a op??o de incremento quando a tecla for solta.
	BTFSS       PORTB+0, 0 
	GOTO        L_main8
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main8
L__main22:
;PushButton_Display.c,41 :: 		ucStatus_inc=0;
	CLRF        main_ucStatus_inc_L0+0 
;PushButton_Display.c,42 :: 		}
L_main8:
;PushButton_Display.c,44 :: 		if((PORTB.RB1==0)&&(ucStatus_dec==0)){   // Decrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 1 
	GOTO        L_main11
	MOVF        main_ucStatus_dec_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main11
L__main21:
;PushButton_Display.c,45 :: 		ucStatus_dec=1;                       // Variavel de travamento do decremento.
	MOVLW       1
	MOVWF       main_ucStatus_dec_L0+0 
;PushButton_Display.c,46 :: 		uiContador--;                         // Esse operador aritmetico(--) realiza o mesmo que variavel = variavel - 1.
	MOVLW       1
	SUBWF       main_uiContador_L0+0, 1 
	MOVLW       0
	SUBWFB      main_uiContador_L0+1, 1 
;PushButton_Display.c,47 :: 		if(uiContador>9999){  // Define o valor maximo quando ocorrer a transicao (decremento) de 0 para 9999.
	MOVF        main_uiContador_L0+1, 0 
	SUBLW       39
	BTFSS       STATUS+0, 2 
	GOTO        L__main26
	MOVF        main_uiContador_L0+0, 0 
	SUBLW       15
L__main26:
	BTFSC       STATUS+0, 0 
	GOTO        L_main12
;PushButton_Display.c,48 :: 		uiContador=9999;
	MOVLW       15
	MOVWF       main_uiContador_L0+0 
	MOVLW       39
	MOVWF       main_uiContador_L0+1 
;PushButton_Display.c,49 :: 		}
L_main12:
;PushButton_Display.c,50 :: 		}
L_main11:
;PushButton_Display.c,51 :: 		if((PORTB.RB1==1)&&(ucStatus_dec==1)){   // Volta a disponibilizar a op??o de incremento quando a tecla for solta.
	BTFSS       PORTB+0, 1 
	GOTO        L_main15
	MOVF        main_ucStatus_dec_L0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main15
L__main20:
;PushButton_Display.c,52 :: 		ucStatus_dec=0;
	CLRF        main_ucStatus_dec_L0+0 
;PushButton_Display.c,53 :: 		}
L_main15:
;PushButton_Display.c,55 :: 		uiValor = uiContador;                   // Coloca o conteudo da variavel do contador na varaivel auxiliar.
	MOVF        main_uiContador_L0+0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        main_uiContador_L0+1, 0 
	MOVWF       main_uiValor_L0+1 
;PushButton_Display.c,58 :: 		PORTD = ucMask[uiValor%10];              // Pega modulo da divisao por 10 e coloca o valor no PORTD.
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiContador_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiContador_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L+0 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0L+1 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;PushButton_Display.c,59 :: 		PORTA.RA5 = 1;                           // Liga o transistor associado ao display 1.
	BSF         PORTA+0, 5 
;PushButton_Display.c,60 :: 		Delay_ms(2);                             // Delay para escrita no display.
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main16:
	DECFSZ      R13, 1, 1
	BRA         L_main16
	DECFSZ      R12, 1, 1
	BRA         L_main16
	NOP
;PushButton_Display.c,61 :: 		PORTA.RA5 = 0;                           // Desliga o transistor associado ao display 1.
	BCF         PORTA+0, 5 
;PushButton_Display.c,62 :: 		uiValor/=10;                             // Divide variavel por 10 para definir a dezena.
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValor_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValor_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValor_L0+1 
;PushButton_Display.c,64 :: 		PORTD = ucMask[uiValor%10];
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16X16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L+0 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0L+1 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;PushButton_Display.c,65 :: 		PORTA.RA4 = 1;
	BSF         PORTA+0, 4 
;PushButton_Display.c,66 :: 		Delay_ms(2);
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main17:
	DECFSZ      R13, 1, 1
	BRA         L_main17
	DECFSZ      R12, 1, 1
	BRA         L_main17
	NOP
;PushButton_Display.c,67 :: 		PORTA.RA4 = 0;
	BCF         PORTA+0, 4 
;PushButton_Display.c,68 :: 		uiValor/=10;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValor_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValor_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValor_L0+1 
;PushButton_Display.c,70 :: 		PORTD = ucMask[uiValor%10];
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16X16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L+0 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0L+1 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;PushButton_Display.c,71 :: 		PORTA.RA3 = 1;
	BSF         PORTA+0, 3 
;PushButton_Display.c,72 :: 		Delay_ms(2);
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main18:
	DECFSZ      R13, 1, 1
	BRA         L_main18
	DECFSZ      R12, 1, 1
	BRA         L_main18
	NOP
;PushButton_Display.c,73 :: 		PORTA.RA3 = 0;
	BCF         PORTA+0, 3 
;PushButton_Display.c,74 :: 		uiValor/=10;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValor_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValor_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValor_L0+1 
;PushButton_Display.c,76 :: 		PORTD = ucMask[uiValor%10];
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16X16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L+0 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0L+1 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;PushButton_Display.c,77 :: 		PORTA.RA2 = 1;
	BSF         PORTA+0, 2 
;PushButton_Display.c,78 :: 		Delay_ms(2);
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main19:
	DECFSZ      R13, 1, 1
	BRA         L_main19
	DECFSZ      R12, 1, 1
	BRA         L_main19
	NOP
;PushButton_Display.c,79 :: 		PORTA.RA2 = 0;
	BCF         PORTA+0, 2 
;PushButton_Display.c,80 :: 		}
	GOTO        L_main0
;PushButton_Display.c,81 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
