/*
 * File:   4pin.c
 * Author: Admin
 *
 * Created on 31 March, 2023, 10:22 AM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000
#define RS RD0
#define RW RD1
#define E RD2
#define R RB1
#define Y RB2
#define G RB3
int count;int j;
void firstlight()
{
    R=1;
    Y=0;
    G=0;
}
void secondlight()
{
    R=0;
    Y=1;
    G=0;
}
void thirdlight()
{
    R=0;
    Y=0;
    G=1;
}
void fourthlight()
{
    R=0;
    Y=0;
    G=0;
}
void pulse()
{
    E=1;
    __delay_ms(10);
    E=0;
    __delay_ms(10);
}
void lcd(int a, int b)
{
    RS=b;
    RW=0;
    PORTC=(a&0xf0)>>4;
    pulse();
    PORTC=(a&0x0f);
    pulse();
}
void display(int k)
{
   int a,b,c;
   a=k%100;
   b=((k%100)/10);
   c=(k%10);
   lcd(0x80,0);
   lcd(0x30+a,1);
   lcd(0x81,0);
   lcd(0x30+b,1);
   lcd(0x82,0);
   lcd(0x30+c,1);
}
void __interrupt() itr()
{
   if(T0IF==1)
   {
       count++;
       T0IF=0;
       TMR0=38;
      display(count);
//      if(count==36||count==72||count==144||count==216)
//      {
//          for(j=0;j<=3;j++)
//          {
//          RA0=1;
//          __delay_ms(2000);
//          RA0=0;
//          __delay_ms(2000);
//          }
//       }
    }
} 
void main() 
    {
        TRISA=0x00;
        TRISB=0x00;
        TRISC=0x00;
        TRISD=0x00;
        PORTA=0x00;
        PORTB=0x00;
        PORTC=0x00;
        PORTD=0x00;
        ANSEL=0x00;
        ANSELH=0x00;
        GIE=1;PEIE=1;T0IE=1;
        OPTION_REG=0x37;
        TMR0=38;
        lcd(0x02,0);
        lcd(0x28,0);
        lcd(0x0e,0);
        lcd(0x80,0);
        while(1)
        {
            if((count>=36)&&(count<=72))
            {
                firstlight();
            }
            if((count>=72)&&(count<=144))
            {
          secondlight();
            }
            if((count>=144)&&(count<=216))
            {
          thirdlight();
            }
            if((count>=216)&&(count<0))
            {
                fourthlight();
            }
        }
}
