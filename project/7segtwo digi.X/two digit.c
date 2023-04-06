/*
 * File:   two digit.c
 * Author: Admin
 *
 * Created on 16 March, 2023, 11:47 AM
 */


#include <xc.h>
#define _XTAL_FREQ 40000
void main() 
{
    int i,j,k,m;
    char cc[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
    //char cd[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
    TRISA=0x01;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
     if((RA0==1)&&(RA1==0))
     {
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                RD1=1;RD0=0;
                PORTC=cc[i];
                __delay_ms(7000);
                RD0=1;RD1=0;
                PORTC=cc[j];
                __delay_ms(7000);
                 if((RA0==1)&&(RA1==0))
                {   
                   break;
                 }
            }
         if((RA0==0)&&(RA1==1))
        {
            break;
        }
        }   
    }
     if((RA1==1)&&(RA0==0))
     {
        for(k=i;k>=0;k--)
        {
            for(m=j;m>=0;m--)
            {
                RD1=1;RD0=0;
                PORTC=cc[k];
                __delay_ms(7000);
                RD0=1;RD1=0;
                PORTC=cc[m];
                __delay_ms(7000);
            }
        }
     }
     
}
}
