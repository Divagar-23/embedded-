/*
 * File:   LED AND BUTTON.c
 * Author: Admin
 *
 * Created on 14 March, 2023, 3:38 PM
 */


#include <xc.h>
#define _XTAL_FREQ 400000

void main()
{
    TRISA=0x01;
    PORTA=0x00;
    TRISC=0xFF;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    
    while(1)
    {
        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==1)&&(RA0==0))
        {
            RD0=1;
        }
        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==2)&&(RA0==0))
        {
            RD1=1;
        }
        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==3)&&(RA0==0))
        {
            RD2=1;
        }
        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==4)&&(RA0==0))
        {
            RD3=1;
        }
        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==5)&&(RA0==0))
        {
            RD4=1;
        }
        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==6)&&(RA0==0))
        {
            RD5=1;
        }
        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==7)&&(RA0==0))
        {
            RD6=1;
        }
        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==8)&&(RA0==0))
        {
            RD7=1;
        }
        if(RA0==1)
        {
            PORTD=0x00;
        }
            
    }
    
}
