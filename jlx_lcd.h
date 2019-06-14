#ifndef _JLX_LCD_H_
#define _JLX_LCD_H_

#include "STC89C5xRC.H"
#include "zk_16x32.h"


sbit LCD_WR = P2^5;
sbit LCD_RD = P2^7;
sbit LCD_RS = P2^3;
sbit LCD_CSL = P2^6;
sbit LCD_RST = P2^4;

sfr LCD_DATA = P0;

void test_lcd();
void clear_screen();
void initial_lcd();
void display_graphic_16x32(uint page,uchar column,uchar *dp);

#endif