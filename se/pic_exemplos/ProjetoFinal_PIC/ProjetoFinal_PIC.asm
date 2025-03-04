
_main:

;ProjetoFinal_PIC.c,30 :: 		void main(){
;ProjetoFinal_PIC.c,33 :: 		unsigned int  uiContador = 0;
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
	CLRF        main_uiValor_L0+0 
	CLRF        main_uiValor_L0+1 
	CLRF        main_ucStatus_inc_L0+0 
;ProjetoFinal_PIC.c,41 :: 		PORTA = 1;
	MOVLW       1
	MOVWF       PORTA+0 
;ProjetoFinal_PIC.c,42 :: 		TRISA = 1;                 // Configura PORTA pins como entrada
	MOVLW       1
	MOVWF       TRISA+0 
;ProjetoFinal_PIC.c,43 :: 		TRISB.RB0=1;         // Define o pino RB0 do PORTB como entrada (botão).
	BSF         TRISB+0, 0 
;ProjetoFinal_PIC.c,44 :: 		TRISC.RC3 = 1;       // SCL como entrada
	BSF         TRISC+0, 3 
;ProjetoFinal_PIC.c,45 :: 		TRISC.RC4 = 1;       // SDA como entrada
	BSF         TRISC+0, 4 
;ProjetoFinal_PIC.c,47 :: 		ADCON0 = 0b00000001;  // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
	MOVLW       1
	MOVWF       ADCON0+0 
;ProjetoFinal_PIC.c,48 :: 		ADCON1 = 0b11001110;  // Configura todos canais como Digital menos AN0 e REF Interna.
	MOVLW       206
	MOVWF       ADCON1+0 
;ProjetoFinal_PIC.c,49 :: 		ADCON2 = 0b10111110;  // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.
	MOVLW       190
	MOVWF       ADCON2+0 
;ProjetoFinal_PIC.c,51 :: 		Lcd_Init();
	CALL        _Lcd_Init+0, 0
;ProjetoFinal_PIC.c,52 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;ProjetoFinal_PIC.c,53 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;ProjetoFinal_PIC.c,55 :: 		PWM1_Init(5000);      // Inicializa módulo PWM com 5Khz
	BSF         T2CON+0, 0, 0
	BCF         T2CON+0, 1, 0
	MOVLW       99
	MOVWF       PR2+0, 0
	CALL        _PWM1_Init+0, 0
;ProjetoFinal_PIC.c,56 :: 		PWM1_Start();        // Start PWM
	CALL        _PWM1_Start+0, 0
;ProjetoFinal_PIC.c,57 :: 		I2C1_Init(100000); // Inicializa o I2C como escravo
	MOVLW       20
	MOVWF       SSPADD+0 
	CALL        _I2C1_Init+0, 0
;ProjetoFinal_PIC.c,59 :: 		while(1){
L_main0:
;ProjetoFinal_PIC.c,61 :: 		if (I2C1_Is_Idle()){
	CALL        _I2C1_Is_Idle+0, 0
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_main2
;ProjetoFinal_PIC.c,62 :: 		receberDados();
	CALL        _receberDados+0, 0
;ProjetoFinal_PIC.c,63 :: 		}
L_main2:
;ProjetoFinal_PIC.c,66 :: 		uiValorAD= ADC_Read(0);     // Lê Canal AD 0
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       main_uiValorAD_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValorAD_L0+1 
;ProjetoFinal_PIC.c,67 :: 		uiValorAD*=0.249;            // Converte valor para o duty cycle
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
;ProjetoFinal_PIC.c,68 :: 		if(flagCooler){
	MOVF        _flagCooler+0, 0 
	IORWF       _flagCooler+1, 0 
	BTFSC       STATUS+0, 2 
	GOTO        L_main3
;ProjetoFinal_PIC.c,69 :: 		PWM1_Set_Duty(uiValorAD);   // Envia o valor lido de "uiValorAD" para o módulo CCP1 pwm
	MOVF        main_uiValorAD_L0+0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;ProjetoFinal_PIC.c,71 :: 		} else {
	GOTO        L_main4
L_main3:
;ProjetoFinal_PIC.c,72 :: 		PWM1_Set_Duty(0);
	CLRF        FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;ProjetoFinal_PIC.c,73 :: 		}
L_main4:
;ProjetoFinal_PIC.c,76 :: 		if((PORTB.RB0==0)&&(ucStatus_inc==0)){       // Incrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 0 
	GOTO        L_main7
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main7
L__main25:
;ProjetoFinal_PIC.c,77 :: 		uiContador++;
	INFSNZ      main_uiContador_L0+0, 1 
	INCF        main_uiContador_L0+1, 1 
;ProjetoFinal_PIC.c,78 :: 		ucStatus_inc=1;
	MOVLW       1
	MOVWF       main_ucStatus_inc_L0+0 
;ProjetoFinal_PIC.c,79 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;ProjetoFinal_PIC.c,80 :: 		}
L_main7:
;ProjetoFinal_PIC.c,82 :: 		if((PORTB.RB0==1)&&(ucStatus_inc==1)){   // Volta a disponibilizar a op??o de incremento quando a tecla for solta.
	BTFSS       PORTB+0, 0 
	GOTO        L_main10
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main10
L__main24:
;ProjetoFinal_PIC.c,83 :: 		ucStatus_inc=0;
	CLRF        main_ucStatus_inc_L0+0 
;ProjetoFinal_PIC.c,84 :: 		}
L_main10:
;ProjetoFinal_PIC.c,85 :: 		delay_ms(100);  //Pode ser um debounce
	MOVLW       2
	MOVWF       R11, 0
	MOVLW       4
	MOVWF       R12, 0
	MOVLW       186
	MOVWF       R13, 0
L_main11:
	DECFSZ      R13, 1, 1
	BRA         L_main11
	DECFSZ      R12, 1, 1
	BRA         L_main11
	DECFSZ      R11, 1, 1
	BRA         L_main11
	NOP
;ProjetoFinal_PIC.c,87 :: 		uiValor = uiContador%4;
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
;ProjetoFinal_PIC.c,88 :: 		if (uiValor == 0){
	MOVLW       0
	XORWF       R2, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main27
	MOVLW       0
	XORWF       R1, 0 
L__main27:
	BTFSS       STATUS+0, 2 
	GOTO        L_main12
;ProjetoFinal_PIC.c,89 :: 		lcd_out(1,1,"Temperatura");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_ProjetoFinal_PIC+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_ProjetoFinal_PIC+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ProjetoFinal_PIC.c,90 :: 		FloatToStr (valorTemp,valorTAP_string);
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
;ProjetoFinal_PIC.c,91 :: 		Ltrim(valorTAP_string);
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_Ltrim_string+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_Ltrim_string+1 
	CALL        _Ltrim+0, 0
;ProjetoFinal_PIC.c,92 :: 		lcd_out(2,1,valorTAP_string);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ProjetoFinal_PIC.c,93 :: 		}
	GOTO        L_main13
L_main12:
;ProjetoFinal_PIC.c,94 :: 		else if(uiValor == 1){
	MOVLW       0
	XORWF       main_uiValor_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main28
	MOVLW       1
	XORWF       main_uiValor_L0+0, 0 
L__main28:
	BTFSS       STATUS+0, 2 
	GOTO        L_main14
;ProjetoFinal_PIC.c,95 :: 		lcd_out(1,1,"Pressao Atmosf");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_ProjetoFinal_PIC+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_ProjetoFinal_PIC+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ProjetoFinal_PIC.c,96 :: 		FloatToStr (valorPressure,valorTAP_string);
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
;ProjetoFinal_PIC.c,97 :: 		Ltrim(valorTAP_string);
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_Ltrim_string+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_Ltrim_string+1 
	CALL        _Ltrim+0, 0
;ProjetoFinal_PIC.c,98 :: 		lcd_out(2,1,valorTAP_string);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ProjetoFinal_PIC.c,99 :: 		}
	GOTO        L_main15
L_main14:
;ProjetoFinal_PIC.c,100 :: 		else if(uiValor == 2){
	MOVLW       0
	XORWF       main_uiValor_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main29
	MOVLW       2
	XORWF       main_uiValor_L0+0, 0 
L__main29:
	BTFSS       STATUS+0, 2 
	GOTO        L_main16
;ProjetoFinal_PIC.c,101 :: 		lcd_out(1,1,"Umidade do Solo");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr3_ProjetoFinal_PIC+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr3_ProjetoFinal_PIC+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ProjetoFinal_PIC.c,102 :: 		IntToStr (valorUmidade,valorUmidade_string);
	MOVF        _valorUmidade+0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        _valorUmidade+1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       main_valorUmidade_string_L0+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(main_valorUmidade_string_L0+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;ProjetoFinal_PIC.c,103 :: 		Ltrim(valorUmidade_string);
	MOVLW       main_valorUmidade_string_L0+0
	MOVWF       FARG_Ltrim_string+0 
	MOVLW       hi_addr(main_valorUmidade_string_L0+0)
	MOVWF       FARG_Ltrim_string+1 
	CALL        _Ltrim+0, 0
;ProjetoFinal_PIC.c,104 :: 		lcd_out(2,1,valorUmidade_string);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_valorUmidade_string_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_valorUmidade_string_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ProjetoFinal_PIC.c,105 :: 		}
	GOTO        L_main17
L_main16:
;ProjetoFinal_PIC.c,107 :: 		lcd_out(1,1,"Altitude");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr4_ProjetoFinal_PIC+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr4_ProjetoFinal_PIC+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ProjetoFinal_PIC.c,108 :: 		FloatToStr (valorAltitude,valorTAP_string);
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
;ProjetoFinal_PIC.c,109 :: 		Ltrim(valorTAP_string);
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_Ltrim_string+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_Ltrim_string+1 
	CALL        _Ltrim+0, 0
;ProjetoFinal_PIC.c,110 :: 		lcd_out(2,1,valorTAP_string);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_valorTAP_string_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_valorTAP_string_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ProjetoFinal_PIC.c,111 :: 		}
L_main17:
L_main15:
L_main13:
;ProjetoFinal_PIC.c,112 :: 		}
	GOTO        L_main0
;ProjetoFinal_PIC.c,113 :: 		}
L_end_main:
	GOTO        $+0
; end of _main

_I2C_ReceiveByte:

;ProjetoFinal_PIC.c,116 :: 		unsigned char I2C_ReceiveByte(unsigned char ack) {
;ProjetoFinal_PIC.c,117 :: 		unsigned char dado = I2C1_Rd(ack);  // Lê um byte
	MOVF        FARG_I2C_ReceiveByte_ack+0, 0 
	MOVWF       FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
;ProjetoFinal_PIC.c,118 :: 		return dado;
;ProjetoFinal_PIC.c,119 :: 		}
L_end_I2C_ReceiveByte:
	RETURN      0
; end of _I2C_ReceiveByte

_I2C_ReceiveFloat:

;ProjetoFinal_PIC.c,122 :: 		float I2C_ReceiveFloat() {
;ProjetoFinal_PIC.c,128 :: 		for (i = 0; i < 4; i++) {
	CLRF        I2C_ReceiveFloat_i_L0+0 
	CLRF        I2C_ReceiveFloat_i_L0+1 
L_I2C_ReceiveFloat18:
	MOVLW       128
	XORWF       I2C_ReceiveFloat_i_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__I2C_ReceiveFloat32
	MOVLW       4
	SUBWF       I2C_ReceiveFloat_i_L0+0, 0 
L__I2C_ReceiveFloat32:
	BTFSC       STATUS+0, 0 
	GOTO        L_I2C_ReceiveFloat19
;ProjetoFinal_PIC.c,129 :: 		floatUnion.bytes[i] = I2C_ReceiveByte(1);
	MOVLW       I2C_ReceiveFloat_floatUnion_L0+0
	ADDWF       I2C_ReceiveFloat_i_L0+0, 0 
	MOVWF       FLOC__I2C_ReceiveFloat+0 
	MOVLW       hi_addr(I2C_ReceiveFloat_floatUnion_L0+0)
	ADDWFC      I2C_ReceiveFloat_i_L0+1, 0 
	MOVWF       FLOC__I2C_ReceiveFloat+1 
	MOVLW       1
	MOVWF       FARG_I2C_ReceiveByte_ack+0 
	CALL        _I2C_ReceiveByte+0, 0
	MOVFF       FLOC__I2C_ReceiveFloat+0, FSR1L+0
	MOVFF       FLOC__I2C_ReceiveFloat+1, FSR1H+0
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;ProjetoFinal_PIC.c,128 :: 		for (i = 0; i < 4; i++) {
	INFSNZ      I2C_ReceiveFloat_i_L0+0, 1 
	INCF        I2C_ReceiveFloat_i_L0+1, 1 
;ProjetoFinal_PIC.c,130 :: 		}
	GOTO        L_I2C_ReceiveFloat18
L_I2C_ReceiveFloat19:
;ProjetoFinal_PIC.c,131 :: 		return floatUnion.valor;
	MOVF        I2C_ReceiveFloat_floatUnion_L0+0, 0 
	MOVWF       R0 
	MOVF        I2C_ReceiveFloat_floatUnion_L0+1, 0 
	MOVWF       R1 
	MOVF        I2C_ReceiveFloat_floatUnion_L0+2, 0 
	MOVWF       R2 
	MOVF        I2C_ReceiveFloat_floatUnion_L0+3, 0 
	MOVWF       R3 
;ProjetoFinal_PIC.c,132 :: 		}
L_end_I2C_ReceiveFloat:
	RETURN      0
; end of _I2C_ReceiveFloat

_I2C_ReceiveInt:

;ProjetoFinal_PIC.c,135 :: 		int I2C_ReceiveInt() {
;ProjetoFinal_PIC.c,141 :: 		for (i = 0; i < 2; i++) {
	CLRF        I2C_ReceiveInt_i_L0+0 
	CLRF        I2C_ReceiveInt_i_L0+1 
L_I2C_ReceiveInt21:
	MOVLW       128
	XORWF       I2C_ReceiveInt_i_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__I2C_ReceiveInt34
	MOVLW       2
	SUBWF       I2C_ReceiveInt_i_L0+0, 0 
L__I2C_ReceiveInt34:
	BTFSC       STATUS+0, 0 
	GOTO        L_I2C_ReceiveInt22
;ProjetoFinal_PIC.c,142 :: 		intUnion.bytes[i] = I2C_ReceiveByte(1);
	MOVLW       I2C_ReceiveInt_intUnion_L0+0
	ADDWF       I2C_ReceiveInt_i_L0+0, 0 
	MOVWF       FLOC__I2C_ReceiveInt+0 
	MOVLW       hi_addr(I2C_ReceiveInt_intUnion_L0+0)
	ADDWFC      I2C_ReceiveInt_i_L0+1, 0 
	MOVWF       FLOC__I2C_ReceiveInt+1 
	MOVLW       1
	MOVWF       FARG_I2C_ReceiveByte_ack+0 
	CALL        _I2C_ReceiveByte+0, 0
	MOVFF       FLOC__I2C_ReceiveInt+0, FSR1L+0
	MOVFF       FLOC__I2C_ReceiveInt+1, FSR1H+0
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;ProjetoFinal_PIC.c,141 :: 		for (i = 0; i < 2; i++) {
	INFSNZ      I2C_ReceiveInt_i_L0+0, 1 
	INCF        I2C_ReceiveInt_i_L0+1, 1 
;ProjetoFinal_PIC.c,143 :: 		}
	GOTO        L_I2C_ReceiveInt21
L_I2C_ReceiveInt22:
;ProjetoFinal_PIC.c,144 :: 		return intUnion.valor;
	MOVF        I2C_ReceiveInt_intUnion_L0+0, 0 
	MOVWF       R0 
	MOVF        I2C_ReceiveInt_intUnion_L0+1, 0 
	MOVWF       R1 
;ProjetoFinal_PIC.c,145 :: 		}
L_end_I2C_ReceiveInt:
	RETURN      0
; end of _I2C_ReceiveInt

_receberDados:

;ProjetoFinal_PIC.c,148 :: 		void receberDados() {
;ProjetoFinal_PIC.c,149 :: 		flagCooler = I2C_ReceiveByte(1);
	MOVLW       1
	MOVWF       FARG_I2C_ReceiveByte_ack+0 
	CALL        _I2C_ReceiveByte+0, 0
	MOVF        R0, 0 
	MOVWF       _flagCooler+0 
	MOVLW       0
	MOVWF       _flagCooler+1 
;ProjetoFinal_PIC.c,150 :: 		valorTemp = I2C_ReceiveFloat();
	CALL        _I2C_ReceiveFloat+0, 0
	MOVF        R0, 0 
	MOVWF       _valorTemp+0 
	MOVF        R1, 0 
	MOVWF       _valorTemp+1 
	MOVF        R2, 0 
	MOVWF       _valorTemp+2 
	MOVF        R3, 0 
	MOVWF       _valorTemp+3 
;ProjetoFinal_PIC.c,151 :: 		valorPressure = I2C_ReceiveFloat();
	CALL        _I2C_ReceiveFloat+0, 0
	MOVF        R0, 0 
	MOVWF       _valorPressure+0 
	MOVF        R1, 0 
	MOVWF       _valorPressure+1 
	MOVF        R2, 0 
	MOVWF       _valorPressure+2 
	MOVF        R3, 0 
	MOVWF       _valorPressure+3 
;ProjetoFinal_PIC.c,152 :: 		valorAltitude = I2C_ReceiveFloat();
	CALL        _I2C_ReceiveFloat+0, 0
	MOVF        R0, 0 
	MOVWF       _valorAltitude+0 
	MOVF        R1, 0 
	MOVWF       _valorAltitude+1 
	MOVF        R2, 0 
	MOVWF       _valorAltitude+2 
	MOVF        R3, 0 
	MOVWF       _valorAltitude+3 
;ProjetoFinal_PIC.c,153 :: 		valorUmidade = I2C_ReceiveInt();
	CALL        _I2C_ReceiveInt+0, 0
	MOVF        R0, 0 
	MOVWF       _valorUmidade+0 
	MOVF        R1, 0 
	MOVWF       _valorUmidade+1 
;ProjetoFinal_PIC.c,154 :: 		I2C_ReceiveByte(0);
	CLRF        FARG_I2C_ReceiveByte_ack+0 
	CALL        _I2C_ReceiveByte+0, 0
;ProjetoFinal_PIC.c,155 :: 		}
L_end_receberDados:
	RETURN      0
; end of _receberDados
