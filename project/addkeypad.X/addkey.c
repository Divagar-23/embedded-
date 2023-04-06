/*
 * File:   addkey.c
 * Author: Admin
 *
 * Created on 22 March, 2023, 11:35 AM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
#define RS RD5
#define RW RD6
#define EN RD7
void address(int a );
void pad(int a,int b);
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
  RS=b;RW=0;
PORTB=a ; 
pulse();
}
int count=0,count1=0,x,flag=0;
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
  ANSEL=0x00;
  ANSELH=0x00;
  pad(0x38,0);
  pad(0x0E,0);
  while(1)
  {
      if(flag==0)
      {
          x=0x80;
      }
      if(flag==1)
      {
          x=0x8f;
      }
     
      if(flag==0)
      {
      RD1=0;RD2=0;RD0=1;
      if(RC0==1)
      {
          address(x);
          pad(0x31,1);
          count=0x31;
      }
      if(RC1==1)
      {
          address(x);
          pad(0x34,1);
          count=0x34;
      }
      if(RC2==1)
      {
          address(x);
          pad(0x37,1);
          count=0x37;
      }
      RD0=0;RD1=1;RD2=0;
      if(RC0==1)
      {
          address(x);
          pad(0x32,1); 
          count=0x32;
      }
      if(RC1==1)
      {
          address(x);
          pad(0x35,1);
          count=0x35;
      }
      if(RC2==1)
      {
          address(x);
          pad(0x38,1);  
          count=0x38;
      }
      if(RC3==1)
      {
          address(x);
          pad(0x30,1);
          count=0x30;
      } 
      RD0=0;RD1=0;RD2=1;
      if(RC0==1)
      {
          address(x);
          pad(0x33,1);
          count=0x33;
      }
      if(RC1==1)
      {
          address(x);
          pad(0x36,1); 
          count=0x36;
      }
      if(RC2==1)
      {
          address(x);
          pad(0x39,1);
          count=0x39;
      }
      }
      RD0=0;RD1=0;RD2=1;
      if(RC3==1)
      {
         flag=1;       
      }
      if(flag==1)
      {
       RD0=1;RC1=0;RC2=0;
      if(RC0==1)
      {
          address(x);
          pad(0x31,1);
          count1=0x31;
      }
      if(RC1==1)
      {
          address(x);
          pad(0x34,1); 
          count1=0x34;
      }
      if(RC2==1)
      {
          address(x);
          pad(0x37,1);
          count1=0x37;
      }
      RD0=0;RD1=1;RD2=0;
      if(RC0==1)
      {
          address(x);
          pad(0x32,1);
          count1=0x32;
      }
      if(RC1==1)
      {
          address(x);
          pad(0x35,1);
          count1=0x35;
      }
      if(RC2==1)
      {
          address(x);
          pad(0x38,1);
          count1=0x38;
      }
      
      RD0=0;RD1=0;RD2=1;
      if(RC0==1)
      {
          address(x);
          pad(0x33,1); 
          count1=0x33;
      }
      if(RC1==1)
      {
          address(x);
          pad(0x36,1); 
          count1=0x36;
      }
      if(RC2==1)
      {
          address(x);
          pad(0x39,1);
          count1=0x39;
      }
      }
        RD1=0;RD2=0;RD0=1;
        if(RC3==1)
        {
            address(0xc7);
            pad(count+count1-0x30,1);
            
           
        }
      
  }
 
}
