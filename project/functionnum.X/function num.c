/*
 * File:   function num.c
 * Author: divagar
 *
 * Created on 10 March, 2023, 12:39 PM
 */




#include <pic.h>
#define _XTAL_FREQ 400000
void type();
void display();
void on ();
int pulse()
{
    RD7=1;
    __delay_ms(1000);
    RD7=0;
    __delay_ms(1000);
}
void main()
{
    TRISA=0x00;
    PORTA=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;  
    type();
    on();
    display();
}
 void type ()
 {
    RD5=0;
    RD6=0;
    PORTA=0x38;
    pulse();
 }
 void on()
 {
    RD5=0;
    RD6=0;
    PORTA=0x0E;
    pulse();
 }
void display()
     {
     int i,j,k;
     for(i=0;i<=9;i++)
     {
         for(j=0;j<=9;j++)
         {
             for(k=0;k<=9;k++)
             {
          RD5=0;
          RD6=0;
          PORTA=0x80;
          pulse();
          RD5=1;
          RD6=0;
          PORTA=0x30+i;
          pulse();
          PORTA=0x30+j;
          pulse();
          PORTA=0x30+k;
          pulse();
     }
     }
     }
     }
         
