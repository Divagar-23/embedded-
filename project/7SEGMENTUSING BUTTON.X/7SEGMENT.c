/*
 * File:   i7SEGMENT.c
 * Author: Admin
 *
 * Created on 16 March, 2023, 10:56 AM
 */


#include <xc.h>
#define _XTAL_FREQ 40000

void main() 
{
    int count=0;
   
    char cc[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
    TRISA=0x02;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
       if(RA0==1) 
       {
           count++;
       }
       while(RA0==1);
       PORTC=cc[count];
    }
}