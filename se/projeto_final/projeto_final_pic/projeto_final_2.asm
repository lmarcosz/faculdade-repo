
_main:

;projeto_final_2.c,25 :: 		void main(){
;projeto_final_2.c,26 :: 		unsigned int  uiContador = 0;
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
	CLRF        main_uiValor_L0+0 
	CLRF        main_uiValor_L0+1 
	CLRF        main_ucStatus_inc_L0+0 
;projeto_final_2.c,34 :: 		PORTA = 1;
	MOVLW       1
	MOVWF       PORTA+0 
;projeto_final_2.c,35 :: 		TRISA = 1;            // Configura PORTA como entrada
	MOVLW       1
	MOVWF       TRISA+0 
;projeto_final_2.c,36 :: 		TRISB.RB0=1;         // Define o pino RB0 do PORTB como entrada (botão).
	BSF         TRISB+0, 0 
;projeto_final_2.c,37 :: 		TRISC.RC1 = 0;      //PORT C configurado como saída (buzzer)
	BCF         TRISC+0, 1 
;projeto_final_2.c,38 :: 		TRISC.TRISC6 = 0;  // TX como saída
	BCF         TRISC+0, 6 
;projeto_final_2.c,39 :: 		TRISC.TRISC7 = 1;  // RX como entrada
	BSF         TRISC+0, 7 
;projeto_final_2.c,41 :: 		ADCON0 = 0b00000001;  // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
	MOVLW       1
	MOVWF       ADCON0+0 
;projeto_final_2.c,42 :: 		ADCON1 = 0b11001110;  // Configura todos canais como Digital menos AN0 e REF Interna.
	MOVLW       206
	MOVWF       ADCON1+0 
;projeto_final_2.c,43 :: 		ADCON2 = 0b10111110;  // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.
	MOVLW       190
	MOVWF       ADCON2+0 
;projeto_final_2.c,45 :: 		Lcd_Init();
	CALL        _Lcd_Init+0, 0
;projeto_final_2.c,46 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;projeto_final_2.c,47 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;projeto_final_2.c,49 :: 		PWM1_Init(5000);      // Inicializa módulo PWM
	BSF         T2CON+0, 0, 0
	BCF         T2CON+0, 1, 0
	MOVLW       99
	MOVWF       PR2+0, 0
	CALL        _PWM1_Init+0, 0
;projeto_final_2.c,50 :: 		PWM1_Start();        // Start PWM
	CALL        _PWM1_Start+0, 0
;projeto_final_2.c,52 :: 		UART1_Init(9600);  // Inicializa a comunicação
	BSF         BAUDCON+0, 3, 0
	CLRF        SPBRGH+0 
	MOVLW       207
	MOVWF       SPBRG+0 
	BSF         TXSTA+0, 2, 0
	CALL        _UART1_Init+0, 0
;projeto_final_2.c,53 :: 		Delay_ms(100); //Estabilização do USART
	MOVLW       2
	MOVWF       R11, 0
	MOVLW       4
	MOVWF       R12, 0
	MOVLW       186
	MOVWF       R13, 0
L_main0:
	DECFSZ      R13, 1, 1
	BRA         L_main0
	DECFSZ      R12, 1, 1
	BRA         L_main0
	DECFSZ      R11, 1, 1
	BRA         L_main0
	NOP
;projeto_final_2.c,55 :: 		while(1){
L_main1:
;projeto_final_2.c,57 :: 		flagCooler = UART1_Read();
	CALL        _UART1_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _flagCooler+0 
	MOVLW       0
	MOVWF       _flagCooler+1 
;projeto_final_2.c,60 :: 		uiValorAD= ADC_Read(0);     // Lê Canal AD 0
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       main_uiValorAD_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValorAD_L0+1 
;projeto_final_2.c,61 :: 		uiValorAD*=0.249;            // Converte valor para o duty cycle
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
	MOVF        R0, 0 
	MOVWF       main_uiValorAD_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValorAD_L0+1 
;projeto_final_2.c,62 :: 		if(flagCooler == 1){
	MOVLW       0
	XORWF       _flagCooler+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main20
	MOVLW       1
	XORWF       _flagCooler+0, 0 
L__main20:
	BTFSS       STATUS+0, 2 
	GOTO        L_main3
;projeto_final_2.c,63 :: 		PWM1_Set_Duty(uiValorAD);   // Envia o valor lido de "uiValorAD" para o módulo CCP1 pwm
	MOVF        main_uiValorAD_L0+0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;projeto_final_2.c,64 :: 		} else {
	GOTO        L_main4
L_main3:
;projeto_final_2.c,65 :: 		PWM1_Set_Duty(0);
	CLRF        FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;projeto_final_2.c,66 :: 		}
L_main4:
;projeto_final_2.c,69 :: 		if((PORTB.RB0==0)&&(ucStatus_inc==0)){       // Incrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 0 
	GOTO        L_main7
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main7
L__main18:
;projeto_final_2.c,70 :: 		uiContador++;
	INFSNZ      main_uiContador_L0+0, 1 
	INCF        main_uiContador_L0+1, 1 
;projeto_final_2.c,71 :: 		ucStatus_inc=1;
	MOVLW       1
	MOVWF       main_ucStatus_inc_L0+0 
;projeto_final_2.c,72 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;projeto_final_2.c,73 :: 		}
L_main7:
;projeto_final_2.c,75 :: 		if((PORTB.RB0==1)&&(ucStatus_inc==1)){   // Volta a disponibilizar a op??o de incremento quando a tecla for solta.
	BTFSS       PORTB+0, 0 
	GOTO        L_main10
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main10
L__main17:
;projeto_final_2.c,76 :: 		ucStatus_inc=0;
	CLRF        main_ucStatus_inc_L0+0 
;projeto_final_2.c,77 :: 		}
L_main10:
;projeto_final_2.c,79 :: 		uiValor = uiContador%4;
	MOVLW       3
	ANDWF       main_uiContador_L0+0, 0 
	MOVWF       R1 
	MOVF        main_uiContador_L0+1, 0 
	MOVWF       R2 
	MOVLW       0
	ANDWF       R2, 1 
	MOVF        R1, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        R2, 0 
	MOVWF       main_uiValor_L0+1 
;projeto_final_2.c,80 :: 		if (uiValor == 0){
	MOVLW       0
	XORWF       R2, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main21
	MOVLW       0
	XORWF       R1, 0 
L__main21:
	BTFSS       STATUS+0, 2 
	GOTO        L_main11
;projeto_final_2.c,81 :: 		lcd_out(1,1,"Temperatura");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_projeto_final_2+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_projeto_final_2+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;projeto_final_2.c,82 :: 		FloatToStr(valorTemp, valorTAP_string);
	MOVF        _valorTemp+0, 0 
	MOVWF       FARG_FloatToStr_fnum+0 
	MOVF        _valorTemp+1, 0 
	MOVWF       FARG_FloatToStr_fnum+1 
	MOVF        _valorTemp+2, 0 
	MOVWF       FARG_FloatToStr_fnum+2 
	MOVF        _valorTemp+3, 0 
	MOVWF       FARG_FloatToStr_fnum+3 
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_FloatToStr_str+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_FloatToStr_str+1 
	CALL        _FloatToStr+0, 0
;projeto_final_2.c,83 :: 		Ltrim(valorTAP_string);
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_Ltrim_string+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_Ltrim_string+1 
	CALL        _Ltrim+0, 0
;projeto_final_2.c,84 :: 		lcd_out(2,1,valorTAP_string);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;projeto_final_2.c,85 :: 		}
	GOTO        L_main12
L_main11:
;projeto_final_2.c,86 :: 		else if(uiValor == 1){
	MOVLW       0
	XORWF       main_uiValor_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main22
	MOVLW       1
	XORWF       main_uiValor_L0+0, 0 
L__main22:
	BTFSS       STATUS+0, 2 
	GOTO        L_main13
;projeto_final_2.c,87 :: 		lcd_out(1,1,"Pressao Atmosf");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_projeto_final_2+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_projeto_final_2+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;projeto_final_2.c,88 :: 		FloatToStr(valorPressure, valorTAP_string);
	MOVF        _valorPressure+0, 0 
	MOVWF       FARG_FloatToStr_fnum+0 
	MOVF        _valorPressure+1, 0 
	MOVWF       FARG_FloatToStr_fnum+1 
	MOVF        _valorPressure+2, 0 
	MOVWF       FARG_FloatToStr_fnum+2 
	MOVF        _valorPressure+3, 0 
	MOVWF       FARG_FloatToStr_fnum+3 
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_FloatToStr_str+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_FloatToStr_str+1 
	CALL        _FloatToStr+0, 0
;projeto_final_2.c,89 :: 		Ltrim(valorTAP_string);
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_Ltrim_string+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_Ltrim_string+1 
	CALL        _Ltrim+0, 0
;projeto_final_2.c,90 :: 		lcd_out(2,1,valorTAP_string);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;projeto_final_2.c,91 :: 		}
	GOTO        L_main14
L_main13:
;projeto_final_2.c,92 :: 		else if(uiValor == 2){
	MOVLW       0
	XORWF       main_uiValor_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main23
	MOVLW       2
	XORWF       main_uiValor_L0+0, 0 
L__main23:
	BTFSS       STATUS+0, 2 
	GOTO        L_main15
;projeto_final_2.c,93 :: 		lcd_out(1,1,"Umidade do Solo");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr3_projeto_final_2+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr3_projeto_final_2+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;projeto_final_2.c,94 :: 		IntToStr(valorUmidade, valorUmidade_string);
	MOVF        _valorUmidade+0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        _valorUmidade+1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       main_valorUmidade_string_L0+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(main_valorUmidade_string_L0+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;projeto_final_2.c,95 :: 		Ltrim(valorUmidade_string);
	MOVLW       main_valorUmidade_string_L0+0
	MOVWF       FARG_Ltrim_string+0 
	MOVLW       hi_addr(main_valorUmidade_string_L0+0)
	MOVWF       FARG_Ltrim_string+1 
	CALL        _Ltrim+0, 0
;projeto_final_2.c,96 :: 		lcd_out(2,1,valorUmidade_string);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_valorUmidade_string_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_valorUmidade_string_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;projeto_final_2.c,97 :: 		}
	GOTO        L_main16
L_main15:
;projeto_final_2.c,99 :: 		lcd_out(1,1,"Altitude");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr4_projeto_final_2+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr4_projeto_final_2+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;projeto_final_2.c,100 :: 		FloatToStr(valorAltitude, valorTAP_string);
	MOVF        _valorAltitude+0, 0 
	MOVWF       FARG_FloatToStr_fnum+0 
	MOVF        _valorAltitude+1, 0 
	MOVWF       FARG_FloatToStr_fnum+1 
	MOVF        _valorAltitude+2, 0 
	MOVWF       FARG_FloatToStr_fnum+2 
	MOVF        _valorAltitude+3, 0 
	MOVWF       FARG_FloatToStr_fnum+3 
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_FloatToStr_str+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_FloatToStr_str+1 
	CALL        _FloatToStr+0, 0
;projeto_final_2.c,101 :: 		Ltrim(valorTAP_string);
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_Ltrim_string+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_Ltrim_string+1 
	CALL        _Ltrim+0, 0
;projeto_final_2.c,102 :: 		lcd_out(2,1,valorTAP_string);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;projeto_final_2.c,103 :: 		}
L_main16:
L_main14:
L_main12:
;projeto_final_2.c,104 :: 		}
	GOTO        L_main1
;projeto_final_2.c,105 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
