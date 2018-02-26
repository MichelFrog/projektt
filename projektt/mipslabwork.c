/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
/*
void user_isr( void )
{
        count++;
        IFS(0)=0;
        if (count==10) {
            time2string(textstring, mytime);
            display_string(3, textstring);
            display_update();
            tick(&mytime);
            count=0;
        }
return;
    }
*/
/* Lab-specific initialization goes here */


void labinit( void )
{
    PORTD = PORTD | 0x000000f0; // NEW initialed 1110 0000 for BTN1,2,3,4??
    TRISD |= (0x3f << 5);   //0011 1111 -> 0111 1110 0000
    //PORTD = PORTD | 0x00000070; //OLD
    //TRISD |= (0x3f << 5); //OLD
    volatile int * trise = (volatile int *) 0xbf886100;
    volatile int * porte = (volatile int *) 0xbf886110;
    *porte=0;
    PORTD |= (0x7f0); //0111 1111 0000
    T2CONSET = 0x70;
    PR2 = 31250;
    IPC(2)=0x1f;
  //IPC(1)=0;         //NEW
    IFS(0)=0;
    IEC(0)=0x100;

    enable_interrupt();
    T2CONSET = 0x8000;

  return;
}
