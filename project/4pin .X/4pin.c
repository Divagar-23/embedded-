/*
 * File:   4pin.c
 * Author: Admin
 *
 * Created on 13 March, 2023, 10:29 AM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
#define RS RC5
#define RW RC6
#define EN RC7
void LCD(int a ,int b)
{
    RS=b;
    RW=0;
    PORTD=((a& 0xf0)>>4);
    pulse();
    PORTD=(a) & (0x0f);
    pulse();
}
int pulse()
{
    EN=1;
    __delay_ms(100);
    EN=0;
    __delay_ms(100);
}

void main()
{
    TRISC=0x00;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    LCD(0x02,0);
    LCD(0x28,0);
    LCD(0x0E,0);
    while(1)
    {
       LCD(0x80,0);
       LCD(0x41,1);
    }
}
