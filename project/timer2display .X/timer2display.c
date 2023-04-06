/*
 * File:   timer2display.c
 * Author: Admin
 *
 * Created on 29 March, 2023, 2:51 PM
 */


#include <xc.h>
#define _XTAL_FREQ 40000000
#define RS RA5
#define RW RA6
#define EN RA7
int cc[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int c=0;
void pulse()
{
    EN=1;
    __delay_ms(10);
    EN=0;
    __delay_ms(10);
}
void lcd(int a, int b)
{
    RS=b;
    RW=0;
    PORTB=a;
    pulse();
}
void display()
{
    RD1=0;RD2=0;RD3=0;RD4=0;RD5=0;RD0=1;
    PORTB=cc[c%10];
    pulse();
    RD0=0;RD2=0;RD3=0;RD4=0;RD5=0;RD1=1;        
    PORTB=cc[c/10];
    pulse();
    RD1=0;RD0=0;RD3=0;RD4=0;RD5=0;RD2=1;        
    PORTB=cc[c%10];
    pulse();
    RD2=0;RD0=0;RD1=0;RD4=0;RD5=0;RD3=1;        
    PORTB=cc[c/10];
    pulse();
    RD3=0;RD2=0;RD1=0;RD0=0;RD5=0;RD4=1;        
    PORTB=cc[c%10];
    pulse();
    RD4=0;RD2=0;RD3=0;RD0=0;RD1=0;RD5=1;        
    PORTB=cc[c/10];
    pulse();
}
void main() 
{
    TRISA=0x00;
    PORTA=0x00;
    TRISB=0x00;
    PORTB=0x00;
    TRISC=0x00;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
        
    }
}
