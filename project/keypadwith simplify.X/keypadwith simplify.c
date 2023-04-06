/*
 * File:   keypadwith simplify.c
 * Author: Admin
 *
 * Created on 23 March, 2023, 1:02 PM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
#define RS RD5
#define RW RD6
#define EN RD7
void pad (int a,int b ,int c);
void pulse()
{
    EN=1;
    __delay_ms(100);
    EN=0;
    __delay_ms(100);   
}

void lcd(int x,int y)
{
    RS=y;
    RW=0;
    PORTB=x;
    pulse();
}

void function(char * name)
{
    RS=1;
    RW=0;
    while(*name)
    {
        PORTB=*name++;
        pulse();
    }
}
int count=0;
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
      if(RC0==1||RC1==1||RC2==1)
      {
          pad(0x31,0x34,0x37);
      while(RC0==1||RC1==1||RC2==1);
      count++;
      }
      RD0=0;RD1=1;RD2=0;
      if(RC0==1||RC1==1||RC2==1)
      {
          pad(0x32,0x35,0x38);
      while(RC0==1||RC1==1||RC2==1);
      count++;
      }
      RD0=0;RD1=0;RD2=1;
      if(RC0==1||RC1==1||RC2==1)
      {
          pad(0x33,0x36,0x39);
      while(RC0==1||RC1==1||RC2==1);
      count++;
      }
           if(RC3==1)
      {
    if(count ==10)
    {
        pad(0xc0,0);
        function("calling");
    }
    if(count!=10)
    {
        pad(0xc0,0);
        function("Not valid");
    }   
    }
}}
  
void pad(int a,int b,int c)
{
 if(RC0==1)
 lcd(a,=1)
  if(RC1==1)
 lcd(b,1);
 if(RC2==1)
 lcd(c,1);
// if(RC3==1)
// pad(d,1); 
}

