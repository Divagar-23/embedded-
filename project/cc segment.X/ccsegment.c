/*
 * File:   ccsegment.c
 * Author: Admin
 *
 * Created on 7 March, 2023, 12:52 PM
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
         char cc[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x4F};
          char ce[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x4F};
         for(i=0;i<10;i++)
         {
         
          for(j=0;j<10;j++)
          {
               RC1=1;RC0=0;
            PORTA=cc[i];
            __delay_ms(1000);
          
            RC0=1;RC1=0;
            PORTA=ce[j];
            __delay_ms(1000);
          }
         }
    }
}
