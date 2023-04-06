/*
 * File:   timer.c
 * Author: Admin
 *
 * Created on 25 March, 2023, 11:43 AM
 */
#include <xc.h>
#define _XTAL_FREQ 4000000
#define RS RC5
#define RW RC6
#define EN RC7
 int count=0; int dig1=0;int dig2=0;int dig3=0;
void pulse()
{
    EN=1;
    __delay_ms(15);
    EN=0;
    __delay_ms(15);
}
void lcd(int a,int b)
{
  RS=b;
  RW=0;
  PORTB=a;
  pulse();  
}
void timer(int a ,int b)
{
     if(count<=a)
       RC0=1;
        if(count>a)
           {
             RC0=0;
           }
          if(count==b)
            {
              count=0;
            }     
}
void main()
{
   TRISC=0x00;
   PORTC=0x00;
   TRISB=0x00;
   PORTB=0x00;
   ANSEL=0x00;
   ANSELH=0x00;
   lcd(0x38,0);
   lcd(0x0e,0);
   OPTION_REG=0x07;
   TMR0=38;
   while(1)
   {
       if(T0IF==1)
       {
           count++;
            dig1=count/100;
            dig2=((count%100)/10);
            dig3=count%10;
            lcd(0x80,0);
            lcd(dig1+0x30,1);
            lcd(0x81,0);
            lcd(dig2+0x30,1);
           lcd(0x82,0);
            lcd(dig3+0x30,1); 
            T0IF=0;
         }
            timer(180,180);
            timer(90,180);
            timer(54,180);
   }
}
