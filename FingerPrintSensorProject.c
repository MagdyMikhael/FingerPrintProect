#include "UART.h"
// Lcd pinout settings
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D7 at RB3_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D4 at RB0_bit;

// Pin direction
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
            /*if(areEqual(Uart_Read_String(),name,6,6)){
                PORTA=0xff;
                delay_ms(1000);
             }*/
             delay_ms(1000);
    }

}

uint8_t areEqual(uint8_t arr1[], uint8_t arr2[], uint8_t n, uint8_t m)
{
    // If lengths of array are not equal means
    // array are not equal
    if (n != m)
        return 0;


    // Linearly compare elements
    for ( in=0; in<n; in++)
         if (arr1[in] != arr2[in])
            return 0;

    // If all elements were same.
    return 1;
}