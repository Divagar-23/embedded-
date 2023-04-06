/*
 * File:   loop with 7.c
 * Author: divagar
 *
 * Created on 6 March, 2023, 2:07 PM
 */


#include <pic.h>
#define _XTAL_FREQ 400000
void main()
//char number(100)={3F,06,5B,4F,66,6D,7D,07,7F,4F}
{
    TRISA=0x00;
    PORTA=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
        
        char cc[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07};
        char ca[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8};
        int i,j;
     for(i=0;i<8;i++)
    {
        PORTA=cc[i];
        __delay_ms(10000);
    }
        for(j=0;j<8;j++)
        {
        PORTD=ca[j];
        __delay_ms(10000);
    }
}