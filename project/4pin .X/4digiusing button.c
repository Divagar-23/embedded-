/*
 * File:   4digiusing button.c
 * Author: Admin
 *
 * Created on 17 March, 2023, 12:39 PM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
#define segment1 RA0
#define segment2 RA1
void first_button(int a, int b);
//void second_button(int c, int d);
void display(int);
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
    ANSLH=0x00;
    while(1)
    {
        if((segment1==1)&&(segment2==0))
        {
            first_button(0,99);
        }
      /*  if((segment1==0)&&(segment2==1))
       {
           second_button(99,0);
        }*/
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
void first_button(int a,int b)
    {
        for(i=a;i<=b;i++)
        {
          display(i);
        }
     }