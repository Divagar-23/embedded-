/*
 * File:   count wise.c
 * Author: Admin
 *
 * Created on 14 March, 2023, 12:10 PM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
#define switch1 RC0
#define switch2 RC1
#define output RC7

void main()
{
    TRISC=0x03;
    PORTC=0x00;
    
    int i,j;
        i=0;
        j=0;
    while(1)
    {
        
        if (switch1==1)
        {
        
            i++;
            while(switch1==1);
         }
        
        if((switch2==1)&&(switch1==0))
        {   
        for(j=0;j<i;j++)
        {
            output=1;
            __delay_ms(1000);
            output=0;
            __delay_ms(1000);
        }
        i=0;
        }
     }
}