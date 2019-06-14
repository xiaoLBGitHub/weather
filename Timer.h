#ifndef _TIMER_H
#define _TIMER_H

#include "STC89C5xRC.H"

extern  unsigned char Minute,Second;    //计时的分与秒

void timer0_init();
void reset_clock();
void start_clock();
void pause_clock();

#endif