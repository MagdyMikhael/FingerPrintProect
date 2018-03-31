/***********************************************************
********************* # Includes ***************************
***********************************************************/

#include <string.h>
#include "type.h"
#include "utilites.h"
#include "UART.h"


/***********************************************************
********************* Global Variables *********************
***********************************************************/
uint16_t i=0;
volatile uint8_t * g_RxArray ;

uint8_t arrBack[BackStrLen];

/***********************************************************
***************** Function Definitions *********************
***********************************************************/
 void Uart_init(uint32_t BaudRate){
     uint8_t BR_Reg_Value;
     //setting baudRate
     BR_Reg_Value =((FOSC/(BaudRate*64))-1);
     SPBRG = BR_Reg_Value;
     
     //Enable the asynchronous serial port by clearing bit SYNC and setting bit SPEN.
     clr_bit(TXSTA,SYNC);
     set_bit(RCSTA,SPEN);

     //If interrupts are desired, then set enable bit TXIE,RCIE.
     set_bit(PIE1,RCIE);
     
     //Enable the transmission by setting bit TXEN.
     set_bit(TXSTA,TXEN);
     
     //Enable the reception by setting bit CREN.
     set_bit(RCSTA,CREN);
     
     //If using interrupts, ensure that GIE and PEIE are set
     set_two_bits(INTCON,GIE,PEIE);
 }

/*----------------------------------------------------------
----------------------------------------------------------*/

void Uart_Transmit(uint8_t TxData){
     TXREG = TxData ;
}

/*----------------------------------------------------------
----------------------------------------------------------*/

uint8_t Uart_Receive(){
     return RCREG;
}

/*----------------------------------------------------------
----------------------------------------------------------*/
void Uart_Write_String(uint8_t const * string){
   while(*string != '\0')
  {
    Uart_Transmit(* string );
    string++;
  }

}

/*----------------------------------------------------------
----------------------------------------------------------*/
uint8_t * Uart_Read_String(){

     return g_RxArray;
}

/*----------------------------------------------------------
----------------------------------------------------------*/
void interrupt () {
  if (RCIF_bit == 1) {
      RCIF_bit = 0;
      if (Uart_Receive() != ('\n')){
        g_RxArray[i]= Uart_Receive();
        i++;
      }else{
            i=0;
      }
  }

}