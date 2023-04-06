/*
 * File:   4CCSEG.c
 * Author: DIVAGAR
 *
 * Created on 7 March, 2023, 3:49 PM
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
         char cc[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0xFF,0x6F};
          char ce[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0xFF,0x6F};
          char cm[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0xFF,0x6F};
          char ck[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0xFF,0x6F};
         for(i=0;i<10;i++)
         {
         
          for(j=0;j<10;j++)
          {
              for(k=0;k<10;k++)
              {
                  for(m=0;m<10;m++)
                  {
               RC1=1;RC2=1;RC3=1;RC0=0;
            PORTA=cc[i];
            __delay_ms(150);
          
            RC0=1;RC2=1;RC3=1;RC1=0;
            PORTA=ce[j];
            __delay_ms(150);
             RC1=1;RC0=1;RC3=1;RC2=0;
            PORTA=cm[k];
            __delay_ms(150);
             RC2=1;RC1=1;RC0=1;RC3=0;
            PORTA=ck[m];
            __delay_ms(150);
          }
         }
          }
         }
    }
}
