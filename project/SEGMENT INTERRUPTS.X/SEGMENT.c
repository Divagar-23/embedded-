/*
 * File:   SEGMENT.c
 * Author: Admin
 *
 * Created on 30 March, 2023, 12:46 PM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000
int cc[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int i,j;
void __interrupt() itr()
{
    if(INTF==1)
{
for(j=i;j<10;j--) 
{
    PORTA=cc[j];
    __delay_ms(1000);
}
INTF=0;
}
}
void main() 
{
    GIE=1;PEIE=1;INTE=1;
    TRISA=0x00;
    PORTA=0x00;
    TRISB=0x01;
    PORTB=0x00;
    TRISC=0x00;
    PORTC=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
      
        for(i=0;i<10;i++) 
    {
    PORTC=cc[i];
    __delay_ms(1000);
      }
    }
}
