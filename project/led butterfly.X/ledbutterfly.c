/*
 * File:   ledbutterfly.c
 * Author: Admin
 *
 * Created on 4 March, 2023, 10:52 AM
 */
#include <pic.h>
#define _XTAL_FREQ 400000
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
    TRISE=0x00;
    PORTE=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    int i;
    for (i=0;i<8;i=i+1)
    {
        PORTA|=1<<i;
        PORTC|=1<<i;
        __delay_ms(3000);
    }
    for(i=7;i>=0;i=i-1)
    {
        PORTA&=~(1<<i);
        PORTC&=~(1<<i);
       __delay_ms(3000);
    }
 
    for (i=0;i<8;i=i+1)
    {
        PORTB|=1<<i;
        PORTD|=1<<i;
        __delay_ms(2000);
    }
    for(i=7;i>=0;i=i-1)
    {
        PORTB&=~(1<<i);
        PORTD&=~(1<<i);
       __delay_ms(2000);
    }    
}
