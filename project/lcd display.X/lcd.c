/*
 * File:   lcd.c
 * Author: divagar
 *
 * Created on 9 March, 2023, 2:27 PM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
void main()
{
    TRISA=0x00;
    PORTA=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    RD5=0;
    RD6=0;
    PORTA=0x38;
    RD7=1;
    __delay_ms(1000);
    RD7=0;
    
    RD5=0;
    RD6=0;
    PORTA=0x0E;
    RD7=1;
    __delay_ms(1000);
    RD7=0;
   /* RD5=0;
        RD6=0;
        PORTA=0x83;
        RD7=1;
        __delay_ms(1000);
        RD7=0;*/
    
    while(1)
    {
        RD5=0;
        RD6=0;
        PORTA=0x83;
        RD7=1;
        __delay_ms(1000);
        RD7=0;
        RD5=1;RD6=0;
        PORTA='D';
        RD7=1;
        __delay_ms(1000);
        RD7=0;
               RD5=1;RD6=0;
        PORTA='I';
        RD7=1;
        __delay_ms(100);
        RD7=0;
        RD5=1;RD6=0;
        PORTA='V';
        RD7=1;
        __delay_ms(1000);
        RD7=0;
        RD5=1;RD6=0;
        PORTA='A';
        RD7=1;
        __delay_ms(1000);
        RD7=0;
        RD5=1;RD6=0;
        PORTA='G';
        RD7=1;
        __delay_ms(1000);
        RD7=0;
        RD5=1;RD6=0;
        PORTA='A';
        RD7=1;
        __delay_ms(1000);
        RD7=0;

        __delay_ms(1000);
        RD7=0;
        RD5=1;RD6=0;
        PORTA='R';
        RD7=1;
        __delay_ms(1000);
        RD7=0;
        

        
  
        RD5=0;
        RD6=0;
        PORTA=0x1C;
        RD7=1;
        __delay_ms(1000);
        RD7=0;
        
        
    }
    return;
}