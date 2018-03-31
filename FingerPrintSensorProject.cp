#line 1 "E:/Embedded Systems Projects/FingerPrintProject/FingerPrintSensorProject.c"
#line 1 "e:/embedded systems projects/fingerprintproject/uart.h"
#line 1 "e:/embedded systems projects/fingerprintproject/common.h"
#line 1 "e:/embedded systems projects/fingerprintproject/type.h"
#line 16 "e:/embedded systems projects/fingerprintproject/type.h"
typedef unsigned char uint8_t ;
typedef signed char sint8_t ;
typedef unsigned short int uint16_t ;
typedef signed short int sint16_t ;
typedef unsigned int uint32_t ;
typedef signed int sint32_t ;
typedef double u64 ;
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
#line 3 "E:/Embedded Systems Projects/FingerPrintProject/FingerPrintSensorProject.c"
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D7 at RB3_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D4 at RB0_bit;


sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D7_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB0_bit;




int in;
uint8_t areEqual(uint8_t arr1[], uint8_t arr2[], uint8_t n, uint8_t m);
uint8_t name[]="magdy\n";
void main() {
 Uart_init(BR_9600);
 Lcd_Init();
 TRISA =0x00;
 TRISB =0x00;

 while(1){
 Uart_Write_String("magdy");
 Lcd_Out(1,1 ,Uart_Read_String());
#line 37 "E:/Embedded Systems Projects/FingerPrintProject/FingerPrintSensorProject.c"
 delay_ms(1000);
 }

}

uint8_t areEqual(uint8_t arr1[], uint8_t arr2[], uint8_t n, uint8_t m)
{


 if (n != m)
 return 0;



 for ( in=0; in<n; in++)
 if (arr1[in] != arr2[in])
 return 0;


 return 1;
}
