/*
 * File:   doble.c
 * Author: Admin
 *
 * Created on 14 March, 2023, 11:43 AM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
#define  switch1 RA0
#define  switch2 RA2
void main()
{
    TRISA=0x20;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
         if (switch1==1&&switch2==0)
         {
           RC0=1;
         }
         if (switch1==0&&switch2==0)
         {
        RC0=0;
         }
         if (switch1==1&&switch2==1)
         {
             RC0=0;
         }
         if(switch1==0&&switch2==1)
         {
             RC0=1;
         }
         }
    
}

