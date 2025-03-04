
_main:

;LCD_ConversorADC.c,31 :: 		void main()
;LCD_ConversorADC.c,33 :: 		TRISA0_bit = 1;  // CONFIGURA O PINO EM QUE SE ENCONTRA A PORTA ANALÓGICA AN0 COMO ENTRADA
	BSF         TRISA0_bit+0, BitPos(TRISA0_bit+0) 
;LCD_ConversorADC.c,34 :: 		TRISA1_bit = 1;  // CONFIGURA O PINO EM QUE SE ENCONTRA A PORTA ANALÓGICA AN1 COMO ENTRADA
	BSF         TRISA1_bit+0, BitPos(TRISA1_bit+0) 
;LCD_ConversorADC.c,36 :: 		ADCON1 = 0b00001110; //0b00001100;//SELECIONA OS PINOS 1, 2 DO PORTA COMO ENTRADAS ANALÓGICAS (AN0, AN1)
	MOVLW       14
	MOVWF       ADCON1+0 
;LCD_ConversorADC.c,37 :: 		ADC_Init();//INICIALIZA MÓDULO ANALGÓGICO
	CALL        _ADC_Init+0, 0
;LCD_ConversorADC.c,38 :: 		CMCON = 0b00000111;//DESABILITA COMPARADORES INTERNOS
	MOVLW       7
	MOVWF       CMCON+0 
;LCD_ConversorADC.c,40 :: 		Lcd_Init();//INICIALIZA DISPLAY LCD
	CALL        _Lcd_Init+0, 0
;LCD_ConversorADC.c,41 :: 		Lcd_Cmd(_LCD_CLEAR);//ENVIA O COMANDO DE LIMPAR TELA PARA O DISPLAY LCD
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;LCD_ConversorADC.c,42 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);// ENVIA O COMANDO DE DESLIGAR CURSOR PARA O DISPLAY LCD
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;LCD_ConversorADC.c,44 :: 		while(1)
L_main0:
;LCD_ConversorADC.c,46 :: 		pot1 = ADC_Get_Sample(0);//RECEBE O VALOR DE TENSÃO DO POTENCIOMETRO NA PORTA AN0
	CLRF        FARG_ADC_Get_Sample_channel+0 
	CALL        _ADC_Get_Sample+0, 0
	MOVF        R0, 0 
	MOVWF       _pot1+0 
	MOVF        R1, 0 
	MOVWF       _pot1+1 
;LCD_ConversorADC.c,47 :: 		pot2 = ADC_Get_Sample(1);//RECEBE O VALOR DE TENSÃO DO POTENCIOMETRO NA PORTA AN1
	MOVLW       1
	MOVWF       FARG_ADC_Get_Sample_channel+0 
	CALL        _ADC_Get_Sample+0, 0
	MOVF        R0, 0 
	MOVWF       _pot2+0 
	MOVF        R1, 0 
	MOVWF       _pot2+1 
;LCD_ConversorADC.c,49 :: 		IntToStr (pot1,pot1_string);//CONVERTE O VALOR DO TIPO INTEIRO OBTIDO PELO CONVERSOR AD NA PORTA AN0 PARA UMA STRING
	MOVF        _pot1+0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        _pot1+1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       _pot1_string+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(_pot1_string+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;LCD_ConversorADC.c,50 :: 		IntToStr (pot2,pot2_string);//CONVERTE O VALOR DO TIPO INTEIRO OBTIDO PELO CONVERSOR AD NA PORTA AN1 PARA UMA STRING
	MOVF        _pot2+0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        _pot2+1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       _pot2_string+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(_pot2_string+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;LCD_ConversorADC.c,52 :: 		Ltrim(pot1_string);//REMOVE TODOS OS ESPAÇOS EM BRANCO LOCALIZADOS A ESQUERDA DO PRIMEIRO CHAR DA STRING COM O VALOR DE AN0
	MOVLW       _pot1_string+0
	MOVWF       FARG_Ltrim_string+0 
	MOVLW       hi_addr(_pot1_string+0)
	MOVWF       FARG_Ltrim_string+1 
	CALL        _Ltrim+0, 0
;LCD_ConversorADC.c,53 :: 		Ltrim(pot2_string);//REMOVE TODOS OS ESPAÇOS EM BRANCO LOCALIZADOS A ESQUERDA DO PRIMEIRO CHAR DA STRING COM O VALOR DE AN1
	MOVLW       _pot2_string+0
	MOVWF       FARG_Ltrim_string+0 
	MOVLW       hi_addr(_pot2_string+0)
	MOVWF       FARG_Ltrim_string+1 
	CALL        _Ltrim+0, 0
;LCD_ConversorADC.c,55 :: 		Lcd_Out(1,1,"S1:");//ESCREVE A MENSAGEM POT1 NA PRIMEIRA LINHA E PRIMEIRA COLUNA DO DISPLAY LCD
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_LCD_ConversorADC+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_LCD_ConversorADC+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;LCD_ConversorADC.c,56 :: 		Lcd_Out_Cp(pot1_string);//ESCREVE O VALOR OBTIDO DO CONVERSOR A/D NA POSIÇÃO EM QUE SE ENCONTRA O CURSOR DO DISPLAY
	MOVLW       _pot1_string+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(_pot1_string+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;LCD_ConversorADC.c,58 :: 		Lcd_Out(1,9,"S2:");//ESCREVE A MENSAGEM POT2 NA PRIMEIRA LINHA E DECIMA PRIMEIRA COLUNA DO DISPLAY LCD
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       9
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_LCD_ConversorADC+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_LCD_ConversorADC+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;LCD_ConversorADC.c,59 :: 		Lcd_Out_Cp(pot2_string);//ESCREVE O VALOR OBTIDO DO CONVERSOR A/D NA POSIÇÃO EM QUE SE ENCONTRA O CURSOR DO DISPLAY
	MOVLW       _pot2_string+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(_pot2_string+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;LCD_ConversorADC.c,61 :: 		delay_ms(100);// AGUARDA 0,1 s
	MOVLW       2
	MOVWF       R11, 0
	MOVLW       4
	MOVWF       R12, 0
	MOVLW       186
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 1
	BRA         L_main2
	DECFSZ      R12, 1, 1
	BRA         L_main2
	DECFSZ      R11, 1, 1
	BRA         L_main2
	NOP
;LCD_ConversorADC.c,62 :: 		}
	GOTO        L_main0
;LCD_ConversorADC.c,63 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
