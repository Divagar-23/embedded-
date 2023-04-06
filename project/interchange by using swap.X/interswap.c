/*
 * File:   interswap.c
 * Author: Admin
 *
 * Created on 20 March, 2023, 11:46 AM
 */
#include <xc.h>
#define _XTAL_FREQ 400000
#define button1 RA0
#define button2 RA1
#define button3 RA2
#define led RC0
void main() 
{
    TRISA=0x07;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    int a=1,b=0;
    
    while(1)
    {
        if(RA0==1)
        {
            RC0=a;
        }
         if(RA1==1) 
         {
             RC0=b;
         }
        if(RA2==1)
        {
           int temp=a;
               a=b;
            b=temp;
        }
        while(RA2==1);
        
    }
        
    }
