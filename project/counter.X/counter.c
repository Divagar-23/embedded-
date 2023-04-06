/*
 * File:   counter.c
 * Author: Admin
 *
 * Created on 3 April, 2023, 2:49 PM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000
#define RS RC5
#define RW RC6
#define EN RC7
void pulse()
{
    EN=1;
   __delay_us(50);
    EN=0;
   __delay_us(50);
}
void lcd(int a,int b)
{
  RS=b;
  RW=0;
  PORTD=a;
  pulse(); 
}
void display(int k)
{
    //lcd(0x80,0);
    int a,b,c;
    a=k/100;
    b=((k%100)/10);
    c=(k%10);
   lcd(0x80,0);
    lcd(0x30+a,1);
   lcd(0x81,0);
    lcd(0x30+b,1);
    lcd(0x82,0);
    lcd(0x30+c,1);
}
void main()
{
    TRISA=0x10;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    OPTION_REG=0x20;
    TMR0=0;
     lcd(0x38,0);
    lcd(0x0e,0);
    //lcd(0x80,0);
    while(1)
    {
        display(TMR0);
    }
}