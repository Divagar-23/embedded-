/*
 * File:   calling.c
 * Author: Admin
 *
 * Created on 22 March, 2023, 2:35 PM
 */
#include <xc.h>
#define _XTAL_FREQ 400000
#define RS RD5
#define RW RD6
#define EN RD7
void firstrow ();
void secondrow();
void thirdrow ();
void pulse()
{
    EN=1;
    __delay_ms(100);
    EN=0;
    __delay_ms(100);
}
void address(int z)
{
    RS=0;RW=0;
    PORTB=z;
    pulse();
}
void pad(int a,int b)
{
  RS=b;
  RW=0;
PORTB=a ; 
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
int x,count=0;
void main() 
{
    TRISB=0x00;
    PORTB=0x00;
    TRISC=0xFF;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    pad(0x38,0);
    pad(0x0E,0);
    pad(0x80,0);
    while(1)
   {
       {
        firstrow();
      if(RC0==1)
      {
          address(x);
          pad(0x31,1);
          while(RC0==1);
          count++;
      }
      if(RC1==1)
      {
          address(x);
          pad(0x34,1);
          while(RC1==1);
          count++;
      }
      if(RC2==1)
      {
          address(x);
          pad(0x37,1);
          while(RC2==1);
          count++;
      }
        secondrow();
      if(RC0==1)
      {
          address(x);
          pad(0x32,1);
          while(RC0==1);
          count++;
      }
      if(RC1==1)
      {
          address(x);
          pad(0x35,1);
          while(RC1==1);
          count++;
      }
      if(RC2==1)
      {
          address(x);
          pad(0x38,1);
          while(RC2==1);
          count++;
      }
      if(RC3==1)
      {
          address(x);
          pad(0x30,1);
          while(RC3==1);
          count++;
      } 
       thirdrow ();
      if(RC0==1)
      {
          address(x);
          pad(0x33,1);
          while(RC0==1);
          count++;
      }
      if(RC1==1)
      {
          address(x);
          pad(0x36,1);
          while(RC1==1);
          count++;
      }
      if(RC2==1)
      {
          address(x);
          pad(0x39,1);
          while(RC2==1);
          count++;
      }     
  }
            firstrow();
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
void firstrow()
{
    RD1=0;
    RD2=0;
    RD0=1;
}
void secondrow()
{
    RD0=0;
    RD2=0;
    RD1=1;
}
void thirdrow()
{
    RD1=0;
    RD0=0;
    RD2=1;
}

