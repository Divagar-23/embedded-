/*
 * File:   interrupts.c
 * Author: Admin
 *
 * Created on 30 March, 2023, 11:21 AM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000

//int flag=0;
void __interrupt() itr()
{ if(INTF==1)
{
RC0=1; 
INTF=0;
}
}
void main() 
{
    GIE=1;PEIE=1;INTE=1;
    TRISB=0x01;
    PORTB=0x00;
    TRISC=0x00;
    PORTC=0x00;
    ANSELH=0x00;
    while(1)
    {
        RC1=1;
        __delay_ms(1000);
        RC1=0;
        __delay_ms(1000);
      //__interrupt();  
    }
}
