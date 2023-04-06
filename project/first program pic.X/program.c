/*
 * File:   program.c
 * Author: divagar
 *
 * Created on 2 March, 2023, 3:27 PM
 */


#include<pic.h>
#define _XTAL_FREQ400000
void delay(int j)
{
    while(j--);
}
void main()
{
    TRISA=0x00;
    PORTA=0x00;
    TRISB=0x00;
    PORTB=0x00;
    TRISC=0x00;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
    PORTA=0xFF;
    delay(1000);
    PORTB=0x00;
    delay(1000);
    PORTB=0xFF;
    delay(1000);
    PORTC=0xFF;
    delay(1000);
    PORTD=0xFF;
    delay(1000);
   // PORTD=0xFF;
    }
}
