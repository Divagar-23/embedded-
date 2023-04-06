/*
 * File:   interlock.c
 * Author: Admin
 *
 * Created on 15 March, 2023, 2:07 PM
 */


#include <xc.h>
#define _XTAL_FREQ 40000
void main() 
{
    
    TRISA=0xFF;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
        if (RA0==1&&RA2==0&&RC1==0)
        {
            RC0=1;
          
        }
        if(RC0==0&&RA1==1&&RA2==0)
        {
            RC1=1;
        }
        
            if(RA2==1)
            {
                RC0=0;
                RC1=0;
                        
            }
        
    }
}
