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

sbit BTN_1 = P2^0;
sbit BTN_2 = P2^1;
sbit BTN_3 = P2^2;

sbit LCD_WR = P2^5;
sbit LCD_RD = P2^7;
sbit LCD_RS = P2^3;
sbit LCD_CSL = P2^6;
sbit LCD_RST = P2^4;

sfr LCD_DATA = P0;

#endif