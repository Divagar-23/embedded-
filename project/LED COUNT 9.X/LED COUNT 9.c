/*
 * File:   LED COUNT 9.c
 * Author: Admin
 *
 * Created on 15 March, 2023, 10:53 AM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
void main ()
{ 
    int count;
    count=0;
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
        if((RC0==1)||(RC1==1)||(RC2==1)||(RC3==1)||(RC4==1)||(RC5==1)||(RC6==1)||(RC7==1))
        {
            
            count++;
        }
        while((RC0==1)||(RC1==1)||(RC2==1)||(RC3==1)||(RC4==1)||(RC5==1)||(RC6==1)||(RC7==1));
        PORTD|=1<<(count-1);
        
        if(RA0==1)
        {
            count=0;
            PORTD=0x00;
            while(RA0==1);
        }
    }   
}
