/*
 * File:   4digital.c
 * Author: Admin
 *
 * Created on 17 March, 2023, 2:33 PM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
#define segment1 RA0
#define segment2 RA1
void first_button(int a, int b);
void second_button(int c, int d);
void display1(int);
void display2(int);
int cc[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
//int cd[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int i,j;
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
        
        if((segment1==1)&&(segment2==0))
        {
            first_button(0,99);
        }
        if((segment1==0)&&(segment2==1))
       {
           second_button(0,99);
        }
    }
           
}
void display1(int k)
    {
        
        RD3=1;RD2=1;RD1=1;RD0=0;
        PORTC=cc[k/10];
        __delay_ms(500);
        RD0=1;RD3=1;RD2=1;RD1=0;
        PORTC=cc[k%10];
        __delay_ms(500);
    }
void first_button(int a,int b)
    {
        for( i=a;i<=b;i++)
        {
          display1(i);
        }
     }
void second_button(int c,int d)
    {
        for(j=c;j<=d;j++)
        {
          display2(j);
        }
     }
void display2(int l)
    {
       RD0=1;RD1=1; RD3=1;RD2=0;
        PORTC=cc[l/10];
        __delay_ms(500);
        RD2=1;RD0=1;RD1=1;RD3=0;        
        PORTC=cc[l%10];
        __delay_ms(500);
    }