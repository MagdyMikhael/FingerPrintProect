#ifndef UART_H_
#define UART_H_

/***********************************************************
********************* # Includes ***************************
***********************************************************/
 #include "common.h"
 #include "type.h"
 #include <string.h>
/***********************************************************
**************** Definitions and Configrations *************
***********************************************************/

#define Buffer_Length 20
#define BackStrLen 400
//definitions of  registers
//-------------------------------------------
#define TXSTA *((volatile uint8_t *)(0x98))
#define RCSTA *((volatile uint8_t *)(0x18))
#define SPBRG *((volatile uint8_t *)(0x99))
#define PIR1 *((volatile uint8_t *)(0x0C))
#define TXREG *((volatile uint8_t *)(0x19))
#define RCREG *((volatile uint8_t *)(0x1A))
#define PIE1 *((volatile uint8_t *)(0x8C))
#define INTCON *((volatile uint8_t *)(0x0B))

//configration of registers bits
//-------------------------------------------

//TXSTA Bits
#define TX9D 0
#define TRMT 1
#define BRGH 2

#define SYNC 4
#define TXEN 5
#define TX9 6
#define CSRC 7

//RCSTA Bits
#define RX9D 0
#define OERR 1
#define OERR 2
#define OERR 3
#define CREN 4
#define SREN 5
#define RX9 6
#define SPEN 7

//PIE1 Bits
#define TXIE 4
#define RCIE 5

//PIR1 Bits
#define TXIF 4
#define RCIF 5

//INTCON Bits
#define PEIE 6
#define GIE 7
/***********************************************************
************ Extern Moudle shared global variables *********
***********************************************************/

/***********************************************************
********************* Enums ********************************
***********************************************************/
enum UART_BAUDRATE_t {
    BR_110    = 110,
    BR_300    = 300,
    BR_600    = 600,
    BR_1200   = 1200,
    BR_2400   = 2400,
    BR_4800   = 4800,
    BR_9600   = 9600,
    BR_14400  = 14400,
    BR_19200  = 19200,
    BR_28800  = 28800,
    BR_38400  = 38400,
    BR_56000  = 56000,
    BR_57600  = 57600,
    BR_115200 = 115200,
    BR_128000 = 128000,
    BR_153600 = 153600,
    BR_230400 = 230400,
    BR_256000 = 256000,
    BR_460800 = 460800,
    BR_921600 = 921600
};


/***********************************************************
********************* Structures and Unions ****************
***********************************************************/

/***********************************************************
********************* Functions Like Macros ****************
***********************************************************/


/***********************************************************
********************* Functions Prototypes *****************
***********************************************************/
void Uart_init(uint32_t BaudRate);
void Uart_Transmit(uint8_t TxData);
uint8_t Uart_Receive();
void Uart_Write_String(uint8_t const * string);
uint8_t * Uart_Read_String();





#endif  // UART_H_