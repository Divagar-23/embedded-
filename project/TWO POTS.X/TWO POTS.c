/*
 * File:   TWO POTS.c
 * Author: Admin
 *
 * Created on 5 April, 2023, 2:49 PM
 */
#include <xc.h>
#define _XTAL_FREQ 4000000
#define RS RC5
#define RW RC6
#define EN RC7
int low=0;int high=0;int DV,DV1;
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
    lcd(0x80,0);
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
void adc_1 ()
{
    lcd(0x8A,0);
 ADCON1=0x80;
ADCON0=0X85;
GO=1;
while(GO);
high=ADRESH;
low=ADRESL;//DV=L+(H*256);
if(high==0)
{
DV1=low;
display(DV1);
}
if(high==1)
{
DV1=low+256;
display(DV1);
}
if(high==2)
{
DV1=low+512;
display(DV1);
}
if( high==3)
{  
DV1=low+768;
display(DV1);
}
} 
void voltage()
{
    lcd(0xc0,0);
    int a,b,c,d;
    float x;
    x=(DV*5.0)/1023.0;
    d=x*100;
    a=d/100;
    b=((d%100)/10);
    c=d%10;
    lcd(0x30+a,1);
    lcd(0x2e,1);
    lcd(0x30+b,1);
    lcd(0x30+c,1);
}
void voltage1()
{
    lcd(0xcA,0);
    int a,b,c,d;
    float x;
    x=(DV1*5.0)/1023.0;
    d=x*100;
    a=d/100;
    b=((d%100)/10);
    c=d%10;
    lcd(0x30+a,1);
    lcd(0x2e,1);
    lcd(0x30+b,1);
    lcd(0x30+c,1);
}
void main() 
{
    TRISA=0x03;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x03;
    lcd(0x38,0);
    lcd(0x0e,0);
    while(1)
    {
       adc();
       adc_1();
       voltage();
       voltage1();
    }
}