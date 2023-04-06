/*
 * File:   numlcd.c
 * Author: Admin
 *
 * Created on 10 March, 2023, 10:38 AM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
void type();
void address();
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
    while(1)
    {
    type();
    on();
    address();
    display();
    }
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
 
     void address()
     {
         RD5=0;
         RD6=0;
         PORTA=0x80;
         pulse();
     }
     void display()
     {
       RD5=1;
       RD6=0;
       PORTA='D';
       pulse();
     }
       
         
         
         
