/*
 * File:   without using key bouncing.c
 * Author: Admin
 *
 * Created on 15 March, 2023, 12:01 PM
 */


#include <xc.h>
#define _XTAL_FREQ 40000
void main() 
{
    int i ,flag,count;
    i=0;
    count=0;
    flag=0;
  TRISA=0x01;
  PORTA=0x00;
TRISC=0x0F;
PORTC=0x00;
TRISD=0x00;
PORTD=0x00;
while(1)
{
 if((RC0==1)||(RC1==1)||(RC2==1)||(RC3==1)&&(flag==0))
 {
     flag=1;
     
}
 if (flag==1)
 {
    count ++;
    flag ++;  
 }
 if ((RC0==0)||(RC1==0)||(RC2==0)||(RC3==0))
 {
     flag=0;
    
 }
     for(i=0;i<count;i++)
     {
         PORTD|=(1<<count-1);  
     }
 if(RA0==1)
 {
     
     
     PORTD=0X00;
     
 }
 count=0;
}
}
