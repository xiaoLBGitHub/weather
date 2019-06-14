#ifndef _MAIN_H
#define _MAIN_H

#include "STC89C5xRC.H"

#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long

sbit LED_RED = P3^3;
sbit LED_YEL = P3^4;
sbit LED_BLU = P3^5;

sbit DHT_IO = P1^4;





#endif