/*
 * File:   atm.c
 * Author: Admin
 *
 * Created on 23 March, 2023, 2:42 PM
 */
#include <xc.h>
#define _XTAL_FREQ 4000000
#define RS RD5
#define RW RD6
#define EN RD7
int cc[]={0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};int sum=0;
void pulse()
{
    EN=1;
    __delay_ms(100);
    EN=0;
    __delay_ms(100);
}
void LCD(int a,int b)
{
    RS=b;
    RW=0;
    PORTB=a;
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

void pad(int c,int d,int e)
{
     int count[10];int i=0;
    if(RC0==1)
    {
        LCD (cc[c],1);
        count[i]=c;
        sum=(sum*10)+count[i];
        i++;
    }
    if(RC1==1)
    {
        LCD (cc[d],1);
        count[i]=d;
        sum=(sum*10)+count[i];
        i++;
    }
    if(RC2==1)
    {
        LCD (cc[e],1); 
        count[i]=e;
        sum=(sum*10)+count[i];
        i++;
    }
}
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
void keypad ()
{
    firstrow();
      if(RC0==1||RC1==1||RC2==1)
      {
          pad(1,4,7);
          while(RC0==1||RC1==1||RC2==1);
      }
    secondrow();  
      if(RC0==1||RC1==1||RC2==1)
      {
          pad(2,5,8);
          while(RC0==1||RC1==1||RC2==1);
      }
      thirdrow ();
       if(RC0==1||RC1==1||RC2==1)
      {
          pad(3,6,9);
          while(RC0==1||RC1==1||RC2==1);
      }     
  }  
void main()
{
    TRISB=0x00;
    PORTB=0x00;
    TRISC=0xff;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    LCD(0x38,0);
    LCD(0x0e,0);
    int flag=0;
    while(1)
    {
        if(flag==0)
        {
            LCD(0x80,0);
            function("username:");
            flag=1;
            keypad();
            while(flag==0);
        }
        keypad();
           if(RC3==1)
           {
              if(sum==123)
               {
                  LCD(0xc2,0);
            function("password:");
            sum=0;
            keypad();
              }
              else
              {
                  LCD(0x01,0);
                  LCD(0xc3,0);
                  function("invalid");
              }
           } 
        if (RC3==1)
            {
            if(sum==456)
            {
                LCD(0xc0,0);
                LCD(0x01,0);
                function("welcometodarkworld");
            }
                else
              {
                  LCD(0x01,0);
                  LCD(0xc5,0);
                  function("wrongpassword");
              }
            
        }    
            
         
  }
}   
 

