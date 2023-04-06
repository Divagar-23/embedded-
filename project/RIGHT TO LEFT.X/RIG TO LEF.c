/*
 * File:   RIG TO LEF.c
 * Author: Admin
 *
 * Created on 11 March, 2023, 12:19 PM
 */



#include <xc.h>
#define _XTAL_FREQ 400000
//void type();
//void address1();
 void LCD(); 
//void address2();
void display(char *);
//void display2(char *);
//void on ();

int pulse()
{
    RD7=1;
    __delay_ms(100);
    RD7=0;
    __delay_ms(100);
}
void LCD(int a)
{
    RD5=0;
    RD6=0;
PORTA=a;
pulse();
}
void main()
{
    TRISA=0x00;
    PORTA=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    LCD(0x38);
    LCD(Ox0E);
    while(1)
    {
        RD5=0;RD6=0;
        FOR(i=0;i<=15;i++)
        {
        LCD(0x80+i );
    display("Divagar natarjaN");
    LCD(0xcf-i);
    display("BLOODY SWEET");
   PORTA=0x01;
    pulse();
    }
    }
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
       
   

 

