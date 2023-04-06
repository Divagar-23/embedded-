/*
 * File:   interchange.c
 * Author: Admin
 *
 * Created on 20 March, 2023, 10:39 AM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
#define button1 RA0
#define button2 RA1
#define button3 RA2
#define led RC0
int flag=0;
void main() 
{
    TRISA=0x07;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
        if(flag==0)
        {
        if(button1==1)
        {
            RC0=1;
        }
        if(button2==1)
        {
            RC0=0;
        }
        if(button3==1)
        {
            flag=1;
        }
        }
        if(flag==1)
        {
       if(button1==1)
       {
           RC0=0;
       }
        if(button2==1)
        {
            RC0=1;
            
        }
        if(button3==1)
        {
            flag=0;
        }
        }
    }
    
}
