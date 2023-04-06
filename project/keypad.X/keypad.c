/*
 * File:   keypad.c
 * Author: Admin
 *
 * Created on 21 March, 2023, 11:40 AM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
#define RS RD5
#define RW RD6
#define EN RD7
void pulse()
{
    EN=1;
    __delay_ms(100);
    EN=0;
    __delay_ms(100);   
}

void lcd(int a,int b)
{
    RS=b;
    RW=0;
    PORTB=a;
    pulse();
}
void pad(int a,int b,int c,int d)
{
 if(RC0==1)
 lcd(a,1);
 if(RC1==1)
 lcd(b,1);
 if(RC2==1)
 lcd(c,1);
 if(RC3==1)
 lcd(d,1);
}

void main() 
{
  TRISA=0x00;
  PORTA=0x00;
  TRISB=0x00;
  PORTB=0x00;
  TRISC=0xff;
  PORTC=0x00;
  TRISD=0x00;
  PORTD=0x00;
  lcd(0x38,0);
  lcd(0x0E,0);
  lcd(0x80,0);
  while(1)
  {
      RD0=1;RD1=0;RD2=0;
      if(RC0==1||RC1==1||RC2==1||RC3==1)
      {
          pad(0x31,0x34,0x37,0x2a);
      while(RC0==1||RC1==1||RC2==1||RC3==1);
      }
      RD0=0;RD1=1;RD2=0;
      if(RC0==1||RC1==1||RC2==1||RC3==1)
      {
          pad(0x32,0x35,0x38,0x30);
      while(RC0==1||RC1==1||RC2==1||RC3==1);
      }
      RD0=0;RD1=0;RD2=1;
      if(RC0==1||RC1==1||RC2==1||RC3==1)
      {
          pad(0x33,0x36,0x39,0x23);
      while(RC0==1||RC1==1||RC2==1||RC3==1);
      }
  }
}
