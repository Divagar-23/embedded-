/*
 * File:   on and off.c
 * Author: Admin
 *
 * Created on 17 March, 2023, 10:05 AM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
#define forbut RA0
#define resbut RA1
void forward_button(int a, int b);
void reverse_button(int c, int d);
void display(int);
int i,j;
int flag=0;
int cc[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void main() 
{
    TRISA=0x03;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
        if((forbut==0)&&(resbut==0)&&(flag==0))
        {
            PORTC=0x3F;
        }
        if((forbut==1)&&(resbut==0)&&(flag==0))
        {
            forward_button(0,99);
        }
        if((forbut==0)&&(resbut==1)&&(flag==0))
       {
           reverse_button(99,0);
        }
        if(flag==1)
        {
            reverse_button(i,0);
            //i=99;
        }
        if(flag==2)
        {
            forward_button(j,99);
           // j=0;
        }
    }
    }
  void display(int k)
    {
        RD1=1;RD0=0;
        PORTC=cc[k/10];
        __delay_ms(500);
        RD0=1;RD1=0;
        PORTC=cc[k%10];
        __delay_ms(500);
    }
 void forward_button(int a,int b)
    {
        for(i=a;i<=b;i++)
        {
          display(i);
           if((forbut==0)&&(resbut==1))
        {
               flag=1;
           // reverse_button(i,0);
            break;
        }
        }
   }
 void reverse_button(int c, int d)
 {
     for(j=c;j>=d;j--)
     {
         display(j);
          if((forbut==1)&&(resbut==0))
        {
              flag=2;
            //forward_button(j,99);
            break;
        }
     }
      
 }
 
