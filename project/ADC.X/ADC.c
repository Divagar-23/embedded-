/*
 * File:   ADC.c
 * Author: Admin
 *
 * Created on 4 April, 2023, 2:09 PM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000
#define RS RC5
#define RW RC6
#define EN RC7
int low=0;int high=0;int DV;
void pulse()
{
    EN=1;
    __delay_ms(100);
    EN=0;
    __delay_ms(100);
}
void lcd(int a, int b)
{
    RS=b;
    RW=0;
    PORTD=a;
    pulse();  
}
void display(int k)
{
    lcd(0x80,0);
    int a,b,c,d;
    a=k/1000;
    b=((k%1000)/100);
    c=((k%100)/10);
    d=(k%10);
    lcd(0x30+a,1);
    lcd(0x30+b,1);
    lcd(0x30+c,1);
    lcd(0x30+d,1);
}
void adc ()
{
 ADCON1=0x80;
ADCON0=0X81;
GO=1;
while(GO);
high=ADRESH;
low=ADRESL;//DV=L+(H*256);
if(high==0)
{
DV=low;
display(DV);
}
if(high==1)
{
DV=low+256;
display(DV);
}
if(high==2)
{
DV=low+512;
display(DV);
}
if( high==3)
{
DV=low+768;
display(DV);
}
} //split DV and display in
void main() 
{
    TRISA=0x01;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    lcd(0x38,0);
    lcd(0x0e,0);
   // lcd(0x80,0);
    while(1)
    {
       adc();
    
    }
}
