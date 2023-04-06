/*
 * File:   button.c
 * Author: Admin
 *
 * Created on 20 March, 2023, 12:18 PM
 */


#include <xc.h>
#define _XTAL_FREQ 40000
void display(int);
void LCD(int a,int b)
{
    RC5=0;
    RC6=0;
    PORTD=a;
    pulse();
}
int pulse ()
{
    RC7=1;
    __delay_ms(1000);
    RC7=0;
    __delay_ms(1000);
}
void display(int i)
{
   RC5=1;
   RC6=0;
   PORTD=i;
   pulse();
}
int count=0;
int cc[]={0X3f,0x0f,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x4f};
void main() 
{
    TRISA=0xFF;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
        LCD(0x38,0);
         LCD(0x0E,0);
    while(1)
    {
        if(RA0==1)
        {
            for(int i=0;i<=count;i++)
            {
       LCD(0x80,0);
       display(cc[i]);
       count++;
       if(count==10)
       {
           count=0;
       }
           }
       }
    
   }       
    
}
