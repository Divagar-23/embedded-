/*
 * File:   newmain.c
 * Author: Admin
 *
 * Created on 29 March, 2023, 10:39 AM
 */
#include <xc.h>
#define _XTAL_FREQ 4000000
#define RS RD5
#define RW RD6
#define EN RD7
int count=0; int a,b,e; int sec=0;
int min=0;
void pulse()
{
    EN=1;
    __delay_ms(10);
    EN=0;
    __delay_ms(10);   
}
void lcd(int a,int b)
{
    RS=b;
    RW=0;
    PORTB=a;
    pulse();
}
void display(int c,int d)
{
    a=(c/100);
    b=((c%100)/10);
    e=((c%100)%10);
    lcd(d,0);
    lcd(a+0x30,1);
   //  lcd(d,0);
     lcd(b+0x30,1);
    //  lcd(d,0);
      lcd(e+0x30,1);
}
void main()
{
   TRISB=0x00;
   PORTB=0x00;
   TRISD=0x00;
   PORTD=0x00;
   ANSELH=0x00;
   T1CON=0x39;
   lcd(0x38,0);
   lcd(0x0e,0);
  // lcd(0x80,0);
   TMR1=3036;
   while(1)
   {
       if(TMR1IF==1) 
      {
          count++;
          TMR1IF=0;
          TMR1=78;
       }
       if(count==2)
       {
           sec++;
           count=0;
       }
      if(sec>=60) 
      {
          sec=0;
          min++;
      }
      if(min>=60)
      {
        min=0;  
      }
      
      display(count,0x80);
        display(sec,0xC7); 
        display(min,0x8d);   
   }
}

