/*
 * File:   two button.c
 * Author: Admin
 *
 * Created on 29 March, 2023, 6:46 AM
 */
#include<pic.h>
#define _XTAL_FREQ 4000000
#define RS RC5
#define RW RC6
#define E  RC7
#define button1 RA0
#define button2 RA1
void pulse();
void timer(int);
void LCD(int,int);
void display(int);
int count=0,count1=0;
void main()
{
    TRISA=0X03;
    PORTA=0X00;
    TRISC=0X00;
    PORTC=0X00;
    TRISD=0X00;
    PORTD=0X00;
    ANSEL=0x00;
    OPTION_REG=0x85;
    TMR0=130;
    LCD(0x02,0);
    LCD(0X28,0);
    LCD(0X0E,0);
    LCD(0X80,0);
    while(1)
    {
        if (button1==1)
        {
            LCD(0x80,0);
            count++;
            display(count); 
            while(button1==1);
        }
        if (button2==1)
        {
            while(button2==1);
            RC0=1;
            timer(5); 
            RC0=0;   
        }
    }   
}
void pulse()
{
    E=1;
    __delay_us(50);
    E=0;
    __delay_us(50);
}
void LCD(int g,int h)
{
    RS=h;
    RW=0;
    PORTD=(g&0xf0)>>4;
    pulse();
    PORTD=(g&0x0f);
    pulse();
}
void timer(int m)
{
    int time=0,cnt=0;
    while (m>time)
    {
      if (T0IF==1) 
      {
          cnt++;
          T0IF=0;
          TMR0=130;
      }
      if (cnt==125)
      {
          time++;
          cnt=0;
      }
    }
}
void display(int k)
{
    int a,b,c;
    a=k/100;
    b=(k%100)/10;
    c=k%10;
    LCD(0x30+a,1);
    LCD(0x30+b,1);
    LCD(0x30+c,1);
}
