/*
 * File:   foorloop.c
 * Author: Admin
 *
 * Created on 3 March, 2023, 12:45 PM
 */


#include <pic.h>
#define _XTAL_FREQ400000
void delay(int j)
{
    while(j--);
}
void main()
{
    TRISA=0x00;
    PORTA=0x00;
    TRISB=0x00;
    PORTB=0x00;
    TRISC=0x00;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    TRISE=0x00;
    PORTE=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
        int i,j,k,l,m;
        for(i=0;i<=8;i++)
        {
            PORTA=1<<i;
            delay(1000);
        }
            for(j=0;j<=8;j++)
            {
            PORTB=1<<j;
            delay(1000);
            }
            for(k=0;k<=8;k++)
            {
            PORTC=1<<k;
            delay(1000);
            }
            for(l=0;l<=8;l++)
            {
            PORTD=1<<l;
            delay(1000);
            }
            for(m=0;m<=8;m++)
            {
            PORTE=1<<m;
            delay(1000);
            }
        
    }
            
    return;
}
