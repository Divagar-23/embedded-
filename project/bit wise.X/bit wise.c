/*
 * File:   bit wise
 * Author: divagar
 *
 * Created on 3 March, 2023, 12:45 PM
 */


#include <pic.h>
#define _XTAL_FREQ400000
void delay(int j)
{#include <pic.h>

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
    TRISE=0x00;
    PORTE=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
        int i;
        for(i=0;i<=8;i=i+2)
        {
            PORTA |=1<<i;
            delay(1000);
        }
            for(i=0;i<=8;i=i+2)
            {
            PORTB |=1<<i;
            delay(1000);
            }
            for(i=0;i<=8;i=i+2)
            {
            PORTC |=1<<i;
            delay(1000);
            }
            for(i=0;i<=8;i=i+2)
            {
            PORTD |=1<<i;
            delay(1000);
            }
            for(i=0;i<=8;i=i+2)
            {
            PORTE|=1<<i;
            delay(1000);
            
        }
    }
            
    return;
}
