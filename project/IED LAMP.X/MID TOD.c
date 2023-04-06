/*
 * File:   MID TOD.c
 * Author: Admin
 *
 * Created on 4 March, 2023, 2:56 PM
 */


#include <pic.h>
#define _XTAL_FREQ 400000
/*void delay(int j)
{
while(j--);
}*/
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
    ANSEL=0x00;
    ANSELH=0x00;
    int i,j,a,;
    for(i=3,j=4;i!=-1,j<8;i--,j=j+1)
    {
        PORTA|=1<<i;
        PORTA|=1<<j;
       __delay_ms(3000);
    } 
    for(a=0;a<=4;a=a+1)
    {
        PORTA &=~(1<<a);
        __delay_ms(3000);
    } 
    for(b=8;b=>5;b--)
    {
        PORTA&=~(1<<b);
        __delay_ms(3000);
    }
    return;
}
