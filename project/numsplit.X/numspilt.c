/*
 * File:   numspilt.c
 * Author: Admin
 *
 * Created on 13 March, 2023, 2:45 PM
 */
#include <pic.h>
#define _XTAL_FREQ 400000
#define RS RC5
#define RW RC6
#define EN RC7
void display();
int pulse()
{
    RC7=1;
    __delay_ms(1000);
    RC7=0;
    __delay_ms(1000);
}
void LCD(int a,int b)
{
    RS=b;
    RW=0;
       PORTD=((a& 0xf0)>>4);
    pulse();
    PORTD=(a&0X0f);
    pulse();
}

void main()
{
    TRISC=0x00;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    LCD(0x02,0);
    LCD(0x28,0);
    LCD(0x0E,0);
    while(1)
    {
        LCD(0x80,0);
       // LCD('D',1);
    display();
}
}
 
void display()
     {
     int i,a,b,c,d;
   for(i=1;i<=9999;i++)
     {
       a=(i/1000);
       b=((i%1000)/100);
       c=((i/100)%10);
       d=i%10;
       LCD(0x80,0);
          RC5=1;
          RC6=0;
         // LCD(0x083,0);
     
          LCD((0x30+a),1);
         
        //  LCD(0x82,0);
         
          LCD((0x30+b),1);
          
         // LCD(0x81,0);
         
           LCD((0x30+c),1);
         
          //LCD(0x80,0);
         
           LCD((0x30+d),1);
         __delay_ms(100);
        
     }
     }

     
     
         



