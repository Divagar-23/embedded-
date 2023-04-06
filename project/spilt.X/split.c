/*
 * File:   split.c
 * Author: divagar
 *
 * Created on 10 March, 2023, 3:28 PM
 */


#include <pic.h>
#define _XTAL_FREQ 400000
#define RS RC5
#define RW RC6
#define EN RC7
void display();
void LCD(int a )
{
    RS=0;
    RW=0;
    PORTD=a;
    pulse();
}
int pulse()
{
    RC7=1;
    __delay_ms(1000);
    RC7=0;
    __delay_ms(1000);
}
void main()
{
    TRISA=0x00;
    PORTA=0x00;
    TRISD=0x00;
    PORTD=0x00 
    LCD(0x38,0);
    LCD(0x0E,0);
    while()
        LCD(0x80,0);
        
    display();
}
 
void display()
     {
     int i,a,b,c,d;
   for(i=0;i<9999;i++)
     {
         a=i\10;
         b=i%\10;
         c=b%10;
         d=b\10;
          RD5=1;
          RD6=0;
          PORTA=0x30+d;
          pulse();
           PORTA=0x30+c;
          pulse();
           PORTA=0x30+b;
          pulse();
           PORTA=0x30+a;
          pulse();
        
     }
     }
     }
     }
         


