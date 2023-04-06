/*
 * File:   two string.c
 * Author: Admin
 *
 * Created on 11 March, 2023, 11:30 AM
 */

#include <xc.h>
#define _XTAL_FREQ 400000
void type();
void address1();
void address2();
void display(char *);
//void display2(char *);
void on ();

int pulse()
{
    RD7=1;
    __delay_ms(500);
    RD7=0;
    __delay_ms(500);
}
//char a[]={"DIVAGAR natarjan"};
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
    while(1)
    {
        address1();
    display("divagar natarjaN");
    address2();
    display("BLOODY SWEET");
    //display2("divagar natarjan");
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
 
     void address1()
     {
         RD5=0;
         RD6=0;
         PORTA=0x80;
         pulse();
         RD5=0;
         RD6=0;
         PORTA=0x1c;
         pulse();
         
     }
     void address2()
     {
         RD5=0;
         RD6=0;
         PORTA=0xC0;
         pulse();
         RD5=0;RD6=0;
         PORTA=0x1C;
         pulse();
         
     }
     void display(char *name)
     {
         
                RD5=1;
                 RD6=0;

         int i;
         for(i=0;name[i]!='\0';i++)
         {
      
       PORTA=name[i];
       pulse();
     }
     }
       
         
         
         

 
