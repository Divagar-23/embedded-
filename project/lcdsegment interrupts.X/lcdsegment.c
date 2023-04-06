/*
 * File:   lcdsegment.c
 * Author: Admin
 *
 * Created on 30 March, 2023, 2:48 PM
 */


#include <xc.h>
#define _XTAL_FREQ 40000000
#define RS RA0
#define RW RA1
#define EN RA2
int cc[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int i,j;
void pulse()
{
    EN=1;
    __delay_ms(10);
    EN-0;
    __delay_ms(10);
}
void lcd(int a, int b)
{
    RS=b;
    RW=0;
    PORTC=(a&0xf0)>>4;
    pulse();
    PORTC=(a&0x0f);
    pulse();
}
void __interrupt() itr()
{
    if(INTF==1)
{
for(j=i;j<10;j--) 
{
    PORTC=cc[j];
    __delay_ms(1000);
}
INTF=0;
}
}
void main() 
{
    GIE=1;PEIE=1;INTE=1;
    TRISA=0x00;
    TRISB=0x01;
    TRISC=0x00;
    TRISD=0x00;
    PORTA=0x00;
    PORTB=0x00;
    PORTC=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    lcd(0x02,0);
    lcd(0x28,0);
    lcd(0x0e,0);
    lcd(0x80,0);
    while(1)
    {
      for(i=0;i<=9;i++)
      {
          PORTD=cc[i];
          __delay_ms(50);
      }
    }
}
