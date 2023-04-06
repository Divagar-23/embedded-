/*
 * File:   7segment.c
 * Author: divagar
 *
 * Created on 6 March, 2023, 11:22 AM
 */


#include <pic.h>
#define _XTAL_FREQ 400000
void main() 
{
    TRISA=0x00;
    PORTA=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
        PORTA=0x06;
          __delay_ms(10000);
          PORTA=0x6d;
          __delay_ms(5000);
          PORTD=0xf9;
          __delay_ms(3000);
          
    }
    
    return;
}
