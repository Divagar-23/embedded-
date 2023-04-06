/*
 * File:   button.c
 * Author: Admin
 *
 * Created on 14 March, 2023, 10:32 AM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
#define  green RA0
#define  red   RA2
void main()
{
    TRISA=0x01;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
         if (green==1&&red==0)
         {
           RC0=1;
         }
         if (red==0)
         {
        RC0=0;
         }
         if (green==red)
         {
             RC0=0;
         }
         }
    
}
