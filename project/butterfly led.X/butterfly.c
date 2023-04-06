/*
 * File:   butterfly.c
 * Author: divagar
 *
 * Created on 4 March, 2023, 10:20 AM
 */
#include <pic.h>
#define _XTAL_FREQ 400000
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
        for(i=0;i<8;i=i+2)
        {
            PORTA|=1<<i;
            delay(30000);
        }
            
          for(i=7;i>=0;i=i-2)  
          {
              PORTA|=1<<i;
              delay(30000);
          }
         for(i=0;i<8;i=i+2)
        {
            PORTB|=1<<i;
            delay(30000);
        }
       
    }}

