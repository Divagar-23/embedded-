/*
 * File:   odd even.c
 * Author: divagar
 *
 * Created on 3 March, 2023, 3:26 PM
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
        for(i=0;i<8;i=i+2)
        {
            PORTA|=1<<i;
            delay(5000);
      
        }
            for(j=0;j<8;j=j+2)
            {
            PORTB |=1<<j;
            delay(1000);
            }
            for(k=0;k<8;k=k+2)
            {
            PORTC |=1<<k;
            delay(1000);
            }
            for(l=0;l<8;l=l+2)
            {
            PORTD |=1<<l;
            delay(1000);
            }
            for(m=0;m<=8;m=m+2)
            {
            PORTE|=1<<m;
            delay(1000);
            
        }
    }
  
        for(i=7;i>=0;i=i-2)
        {
            PORTA|=1<<i;
            delay(1000);
      
        }
            for(j=0;j<8;j=j+2)
            {
            PORTB |=1<<j;
            delay(1000);
            }
            for(k=0;k<8;k=k+2)
            {
            PORTC |=1<<k;
            delay(1000);
            }
            for(l=0;l<8;l=l+2)
            {
            PORTD |=1<<l;
            delay(1000);
            }
            for(m=0;m<=8;m=m+2)
            {
            PORTE|=1<<m;
            delay(1000);
            
        }
    }
            
    return;
}

