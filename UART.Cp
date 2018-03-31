#line 1 "E:/Embedded Systems Projects/FingerPrintProject/UART.C"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/string.h"





void * memchr(void *p, char n, unsigned int v);
int memcmp(void *s1, void *s2, int n);
void * memcpy(void * d1, void * s1, int n);
void * memmove(void * to, void * from, int n);
void * memset(void * p1, char character, int n);
char * strcat(char * to, char * from);
char * strchr(char * ptr, char chr);
int strcmp(char * s1, char * s2);
char * strcpy(char * to, char * from);
int strlen(char * s);
char * strncat(char * to, char * from, int size);
char * strncpy(char * to, char * from, int size);
int strspn(char * str1, char * str2);
char strcspn(char * s1, char * s2);
int strncmp(char * s1, char * s2, char len);
char * strpbrk(char * s1, char * s2);
char * strrchr(char *ptr, char chr);
char * strstr(char * s1, char * s2);
char * strtok(char * s1, char * s2);
#line 1 "e:/embedded systems projects/fingerprintproject/type.h"
#line 16 "e:/embedded systems projects/fingerprintproject/type.h"
typedef unsigned char uint8_t ;
typedef signed char sint8_t ;
typedef unsigned short int uint16_t ;
typedef signed short int sint16_t ;
typedef unsigned int uint32_t ;
typedef signed int sint32_t ;
typedef double u64 ;
#line 1 "e:/embedded systems projects/fingerprintproject/utilites.h"
#line 1 "e:/embedded systems projects/fingerprintproject/uart.h"
#line 1 "e:/embedded systems projects/fingerprintproject/common.h"
#line 1 "e:/embedded systems projects/fingerprintproject/type.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/string.h"
#line 68 "e:/embedded systems projects/fingerprintproject/uart.h"
enum UART_BAUDRATE_t {
 BR_110 = 110,
 BR_300 = 300,
 BR_600 = 600,
 BR_1200 = 1200,
 BR_2400 = 2400,
 BR_4800 = 4800,
 BR_9600 = 9600,
 BR_14400 = 14400,
 BR_19200 = 19200,
 BR_28800 = 28800,
 BR_38400 = 38400,
 BR_56000 = 56000,
 BR_57600 = 57600,
 BR_115200 = 115200,
 BR_128000 = 128000,
 BR_153600 = 153600,
 BR_230400 = 230400,
 BR_256000 = 256000,
 BR_460800 = 460800,
 BR_921600 = 921600
};
#line 104 "e:/embedded systems projects/fingerprintproject/uart.h"
void Uart_init(uint32_t BaudRate);
void Uart_Transmit(uint8_t TxData);
uint8_t Uart_Receive();
void Uart_Write_String(uint8_t const * string);
uint8_t * Uart_Read_String();
#line 14 "E:/Embedded Systems Projects/FingerPrintProject/UART.C"
uint16_t i=0;
volatile uint8_t * g_RxArray ;

uint8_t arrBack[ 400 ];
#line 22 "E:/Embedded Systems Projects/FingerPrintProject/UART.C"
 void Uart_init(uint32_t BaudRate){
 uint8_t BR_Reg_Value;

 BR_Reg_Value =(( 8000000 /(BaudRate*64))-1);
  *((volatile uint8_t *)(0x99))  = BR_Reg_Value;


  *((volatile uint8_t *)(0x98))  &= ~(1<< 4 ) ;
  *((volatile uint8_t *)(0x18)) |=(1<< 7 ) ;


  *((volatile uint8_t *)(0x8C)) |=(1<< 5 ) ;


  *((volatile uint8_t *)(0x98)) |=(1<< 5 ) ;


  *((volatile uint8_t *)(0x18)) |=(1<< 4 ) ;


  *((volatile uint8_t *)(0x0B)) = *((volatile uint8_t *)(0x0B)) |(1<< 7 )|(1<< 6 ) ;
 }
#line 48 "E:/Embedded Systems Projects/FingerPrintProject/UART.C"
void Uart_Transmit(uint8_t TxData){
  *((volatile uint8_t *)(0x19))  = TxData ;
}
#line 55 "E:/Embedded Systems Projects/FingerPrintProject/UART.C"
uint8_t Uart_Receive(){
 return  *((volatile uint8_t *)(0x1A)) ;
}
#line 61 "E:/Embedded Systems Projects/FingerPrintProject/UART.C"
void Uart_Write_String(uint8_t const * string){
 while(*string != '\0')
 {
 Uart_Transmit(* string );
 string++;
 }

}
#line 72 "E:/Embedded Systems Projects/FingerPrintProject/UART.C"
uint8_t * Uart_Read_String(){

 return g_RxArray;
}
#line 79 "E:/Embedded Systems Projects/FingerPrintProject/UART.C"
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
