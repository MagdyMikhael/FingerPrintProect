
_main:

;FingerPrintSensorProject.c,24 :: 		void main() {
;FingerPrintSensorProject.c,25 :: 		Uart_init(BR_9600);
	MOVLW      128
	MOVWF      FARG_Uart_init_BaudRate+0
	MOVLW      37
	MOVWF      FARG_Uart_init_BaudRate+1
	CALL       _Uart_init+0
;FingerPrintSensorProject.c,26 :: 		Lcd_Init();
	CALL       _Lcd_Init+0
;FingerPrintSensorProject.c,27 :: 		TRISA =0x00;
	CLRF       TRISA+0
;FingerPrintSensorProject.c,28 :: 		TRISB =0x00;
	CLRF       TRISB+0
;FingerPrintSensorProject.c,30 :: 		while(1){
L_main0:
;FingerPrintSensorProject.c,31 :: 		Uart_Write_String("magdy");
	MOVLW      ?lstr_1_FingerPrintSensorProject+0
	MOVWF      FARG_Uart_Write_String_string+0
	MOVLW      hi_addr(?lstr_1_FingerPrintSensorProject+0)
	MOVWF      FARG_Uart_Write_String_string+1
	CALL       _Uart_Write_String+0
;FingerPrintSensorProject.c,32 :: 		Lcd_Out(1,1 ,Uart_Read_String());
	CALL       _Uart_Read_String+0
	MOVF       R0+0, 0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	CALL       _Lcd_Out+0
;FingerPrintSensorProject.c,37 :: 		delay_ms(1000);
	MOVLW      11
	MOVWF      R11+0
	MOVLW      38
	MOVWF      R12+0
	MOVLW      93
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
	NOP
	NOP
;FingerPrintSensorProject.c,38 :: 		}
	GOTO       L_main0
;FingerPrintSensorProject.c,40 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_areEqual:

;FingerPrintSensorProject.c,42 :: 		uint8_t areEqual(uint8_t arr1[], uint8_t arr2[], uint8_t n, uint8_t m)
;FingerPrintSensorProject.c,46 :: 		if (n != m)
	MOVF       FARG_areEqual_n+0, 0
	XORWF      FARG_areEqual_m+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_areEqual3
;FingerPrintSensorProject.c,47 :: 		return 0;
	CLRF       R0+0
	GOTO       L_end_areEqual
L_areEqual3:
;FingerPrintSensorProject.c,51 :: 		for ( in=0; in<n; in++)
	CLRF       _in+0
	CLRF       _in+1
L_areEqual4:
	MOVLW      128
	XORWF      _in+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__areEqual10
	MOVF       FARG_areEqual_n+0, 0
	SUBWF      _in+0, 0
L__areEqual10:
	BTFSC      STATUS+0, 0
	GOTO       L_areEqual5
;FingerPrintSensorProject.c,52 :: 		if (arr1[in] != arr2[in])
	MOVF       _in+0, 0
	ADDWF      FARG_areEqual_arr1+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R1+0
	MOVF       _in+0, 0
	ADDWF      FARG_areEqual_arr2+0, 0
	MOVWF      FSR
	MOVF       R1+0, 0
	XORWF      INDF+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_areEqual7
;FingerPrintSensorProject.c,53 :: 		return 0;
	CLRF       R0+0
	GOTO       L_end_areEqual
L_areEqual7:
;FingerPrintSensorProject.c,51 :: 		for ( in=0; in<n; in++)
	INCF       _in+0, 1
	BTFSC      STATUS+0, 2
	INCF       _in+1, 1
;FingerPrintSensorProject.c,53 :: 		return 0;
	GOTO       L_areEqual4
L_areEqual5:
;FingerPrintSensorProject.c,56 :: 		return 1;
	MOVLW      1
	MOVWF      R0+0
;FingerPrintSensorProject.c,57 :: 		}
L_end_areEqual:
	RETURN
; end of _areEqual
