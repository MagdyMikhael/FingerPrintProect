
_Uart_init:

;UART.C,22 :: 		void Uart_init(uint32_t BaudRate){
;UART.C,25 :: 		BR_Reg_Value =((FOSC/(BaudRate*64))-1);
	MOVLW      6
	MOVWF      R0+0
	MOVF       FARG_Uart_init_BaudRate+0, 0
	MOVWF      R4+0
	MOVF       FARG_Uart_init_BaudRate+1, 0
	MOVWF      R4+1
	MOVF       R0+0, 0
L__Uart_init6:
	BTFSC      STATUS+0, 2
	GOTO       L__Uart_init7
	RLF        R4+0, 1
	RLF        R4+1, 1
	BCF        R4+0, 0
	ADDLW      255
	GOTO       L__Uart_init6
L__Uart_init7:
	MOVLW      0
	MOVWF      R4+2
	MOVWF      R4+3
	MOVLW      0
	MOVWF      R0+0
	MOVLW      18
	MOVWF      R0+1
	MOVLW      122
	MOVWF      R0+2
	MOVLW      0
	MOVWF      R0+3
	CALL       _Div_32x32_S+0
	DECF       R0+0, 1
;UART.C,26 :: 		SPBRG = BR_Reg_Value;
	MOVLW      153
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;UART.C,29 :: 		clr_bit(TXSTA,SYNC);
	MOVLW      152
	MOVWF      R1+0
	MOVF       R1+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	BCF        R0+0, 4
	MOVF       R1+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;UART.C,30 :: 		set_bit(RCSTA,SPEN);
	MOVLW      24
	MOVWF      R1+0
	MOVF       R1+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	BSF        R0+0, 7
	MOVF       R1+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;UART.C,33 :: 		set_bit(PIE1,RCIE);
	MOVLW      140
	MOVWF      R1+0
	MOVF       R1+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	BSF        R0+0, 5
	MOVF       R1+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;UART.C,36 :: 		set_bit(TXSTA,TXEN);
	MOVLW      152
	MOVWF      R1+0
	MOVF       R1+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	BSF        R0+0, 5
	MOVF       R1+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;UART.C,39 :: 		set_bit(RCSTA,CREN);
	MOVLW      24
	MOVWF      R1+0
	MOVF       R1+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	BSF        R0+0, 4
	MOVF       R1+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;UART.C,42 :: 		set_two_bits(INTCON,GIE,PEIE);
	MOVLW      11
	MOVWF      R1+0
	MOVLW      11
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	BSF        R0+0, 7
	BSF        R0+0, 6
	MOVF       R1+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;UART.C,43 :: 		}
L_end_Uart_init:
	RETURN
; end of _Uart_init

_Uart_Transmit:

;UART.C,48 :: 		void Uart_Transmit(uint8_t TxData){
;UART.C,49 :: 		TXREG = TxData ;
	MOVLW      25
	MOVWF      FSR
	MOVF       FARG_Uart_Transmit_TxData+0, 0
	MOVWF      INDF+0
;UART.C,50 :: 		}
L_end_Uart_Transmit:
	RETURN
; end of _Uart_Transmit

_Uart_Receive:

;UART.C,55 :: 		uint8_t Uart_Receive(){
;UART.C,56 :: 		return RCREG;
	MOVLW      26
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
;UART.C,57 :: 		}
L_end_Uart_Receive:
	RETURN
; end of _Uart_Receive

_Uart_Write_String:

;UART.C,61 :: 		void Uart_Write_String(uint8_t const * string){
;UART.C,62 :: 		while(*string != '\0')
L_Uart_Write_String0:
	MOVF       FARG_Uart_Write_String_string+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       FARG_Uart_Write_String_string+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoICP+0
	MOVWF      R1+0
	MOVF       R1+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_Uart_Write_String1
;UART.C,64 :: 		Uart_Transmit(* string );
	MOVF       FARG_Uart_Write_String_string+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       FARG_Uart_Write_String_string+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoICP+0
	MOVWF      FARG_Uart_Transmit_TxData+0
	CALL       _Uart_Transmit+0
;UART.C,65 :: 		string++;
	INCF       FARG_Uart_Write_String_string+0, 1
	BTFSC      STATUS+0, 2
	INCF       FARG_Uart_Write_String_string+1, 1
;UART.C,66 :: 		}
	GOTO       L_Uart_Write_String0
L_Uart_Write_String1:
;UART.C,68 :: 		}
L_end_Uart_Write_String:
	RETURN
; end of _Uart_Write_String

_Uart_Read_String:

;UART.C,72 :: 		uint8_t * Uart_Read_String(){
;UART.C,74 :: 		return g_RxArray;
	MOVF       _g_RxArray+0, 0
	MOVWF      R0+0
;UART.C,75 :: 		}
L_end_Uart_Read_String:
	RETURN
; end of _Uart_Read_String

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;UART.C,79 :: 		void interrupt () {
;UART.C,80 :: 		if (RCIF_bit == 1) {
	BTFSS      RCIF_bit+0, BitPos(RCIF_bit+0)
	GOTO       L_interrupt2
;UART.C,81 :: 		RCIF_bit = 0;
	BCF        RCIF_bit+0, BitPos(RCIF_bit+0)
;UART.C,82 :: 		if (Uart_Receive() != ('\n')){
	CALL       _Uart_Receive+0
	MOVF       R0+0, 0
	XORLW      10
	BTFSC      STATUS+0, 2
	GOTO       L_interrupt3
;UART.C,83 :: 		g_RxArray[i]= Uart_Receive();
	MOVF       _i+0, 0
	ADDWF      _g_RxArray+0, 0
	MOVWF      FLOC__interrupt+0
	CALL       _Uart_Receive+0
	MOVF       FLOC__interrupt+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;UART.C,84 :: 		i++;
	INCF       _i+0, 1
;UART.C,85 :: 		}else{
	GOTO       L_interrupt4
L_interrupt3:
;UART.C,86 :: 		i=0;
	CLRF       _i+0
;UART.C,87 :: 		}
L_interrupt4:
;UART.C,88 :: 		}
L_interrupt2:
;UART.C,90 :: 		}
L_end_interrupt:
L__interrupt13:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

UART____?ag:

L_end_UART___?ag:
	RETURN
; end of UART____?ag
