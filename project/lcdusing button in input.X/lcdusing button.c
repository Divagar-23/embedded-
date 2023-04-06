/*
 * File:   lcdusing button.c
 * Author: Admin
 *
 * Created on 21 March, 2023, 10:32 AM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000
#define button1 RA0
#define button2 RA1
#define button3 RA2
//#define RS RC5
//#define RW RC6
//#define EN RC7
int count,count1,total=0;
void pulse();
void lcd(int,int);
void display(int );

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
    lcd(0x38,0);
    lcd(0x0E,0);      
    while(1)
    {
        if(button1==1)
        {
            lcd(0x80,0);
            count++;
            display(count);
            while(button1==1);
        }
        if(button2==1)
        {
            lcd(0x8c,0);
            count1++;
            display(count1);
            while(button2==1);
        }
        if(button3==1)
        {
            lcd(0xc7,0);
            total=count+count1;
            display(total-1);
            while(button3==1);
        }
        }           
        }
void pulse()
{
    RC7=1;
    __delay_ms(100);
    RC7=0;   
    __delay_ms(100);      
}
void lcd(int g,int h)
{
    RC5=h;
    RC6=0;
    PORTD=g;
    pulse();
}
void display(int c)
{
    lcd((0x30+(c-1)/10),1);
    lcd((0x30+(c-1)%10),1);
}
    