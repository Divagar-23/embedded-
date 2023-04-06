/*
 * File:   4DISPLAY.c
 * Author: DIVAGAR
 *
 * Created on 7 March, 2023, 2:49 PM
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
        int i,j,k,m;
         char cc[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80};
          char ce[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80};
          char cm[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80};
          char ck[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80};
         for(i=0;i<10;i++)
         {
         
          for(j=0;j<10;j++)
          {
              for(k=0;k<10;k++)
              {
                  for(m=0;m<10;m++)
                  {
               RC0=0;RC1=0;RC2=0;RC3=1;
            PORTA=cc[i];
            __delay_ms(100);
          
            RC3=0;RC0=0;RC1=0;RC2=1;
            PORTA=ce[j];
            __delay_ms(100);
             RC2=0;RC0=0;RC3=0;RC1=1;
            PORTA=cm[k];
            __delay_ms(100);
             RC1=0;RC2=0;RC3=0;RC0=1;
            PORTA=ck[m];
            __delay_ms(100);
          }
         }
          }
         }
    }
}
