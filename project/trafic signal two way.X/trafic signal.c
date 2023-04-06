/* 
 * File:   trafic signal.c
 * Author: Admin
 *
 * Created on 28 March, 2023, 2:20 PM
 */
#include <xc.h>
#define _XTAL_FREQ 4000000
#define RS RD5
#define RW RD6
#define EN RD7
#define wave1_red RC6
#define wave1_yellow RC7
#define wave1_green RC2
#define wave2_red RC3
#define wave2_yellow RC4
#define wave2_green RC5
int count=0;
void pulse()
{
    EN=1;
    __delay_ms(10);
    EN=0;
    __delay_ms(10);
}
void lcd(int a,int b)
{
  RS=b;
  RW=0;
  PORTB=a;
  pulse();  
}
void traffic(int c,int d)
{
   if(count<=c)
   {
       wave1_red=1;
       wave2_green=1;
   }
   if(count>c&&count<d)
   {
       wave1_red=0;
       wave2_green=0;
       wave1_yellow=1;
       wave2_yellow=1;
   }
   if(count>d)
   {
      wave1_red=0;
       wave2_green=0; 
   }
}
void main()
{
    
   TRISC=0x00;
   PORTC=0x00;
   TRISB=0x00;
   PORTB=0x00;
   TRISD=0x00;
   PORTD=0x00;
   ANSEL=0x00;
   ANSELH=0x00;
   lcd(0x38,0);
   lcd(0x0e,0);
   lcd(0x80,0);
   OPTION_REG=0x07;
   TMR0=38;
   while(1)
   {
       if(T0IF==1)
       {
           count++;
           T0IF=0;
       }
       traffic(20,20);
       traffic(10,10);
      traffic(34,40);
   
 }
}