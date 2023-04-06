/*
 * File:   two sedment.c
 * Author: Admin
 *
 * Created on 6 March, 2023, 3:38 PM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
void main() 
{
    TRISA=0x00;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
        int i,j;
         char cc[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80};
          char ce[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80};
         for(i=9;i>0;i--)
         {
         
          for(j=9;j>0;j--)
          {
               RC1=0;RC0=1;
            PORTA=cc[i];
            __delay_ms(100);
          
            RC0=0;RC1=1;
            PORTA=ce[j];
            __delay_ms(100);
          }
         }
    }
}
