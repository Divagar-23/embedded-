/*
 * File:   9LED AM=ND 9 BUTTON.c
 * Author: Admin
 *
 * Created on 14 March, 2023, 3:13 PM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
void main ()
{
    TRISA=0x01;
    PORTA=0x00;
    TRISC=0xFF;
    PORTC=0x00;
    TRISD=0x00;
    PORRTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
      if(RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==1)  
      {
          RD0=1;
      }
    }
}
