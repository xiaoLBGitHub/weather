#include "Timer.h"

#define FOSC 11059200L
#define T1MS (65536-FOSC/12/1000)   //1ms timer calculation method in 12T mode

void clock_count();

unsigned char Minute,Second;    //计时的分与秒
unsigned int MsCounter;         //计时的毫秒计时
unsigned char StartClockFlag;   //开始计时的标志位

void timer0_init()
{
    TMOD = 0x01;                    //set timer0 as mode1 (16-bit)
    TL0 = T1MS;                     //initial timer0 low byte
    TH0 = T1MS >> 8;                //initial timer0 high byte
    TR0 = 1;                        //timer0 start running
    ET0 = 1;                        //enable timer0 interrupt
    EA = 1;                         //open global interrupt switch
}

void tm0_isr() interrupt 1 using 1
{
    TL0 = T1MS;                     //reload timer0 low byte
    TH0 = T1MS >> 8;                //reload timer0 high byte
    clock_count();
}

void clock_count()
{
    if(StartClockFlag == 1){
        MsCounter++;
        if(MsCounter >= 1000){
            MsCounter = 0;
            Second++;
            if(Second >= 60){
                Second = 0;
                Minute++;
            }
        }
    }
}

void reset_clock()
{
    MsCounter = 0;
    Minute = 0;
    Second = 0;
    StartClockFlag = 0;
}

void start_clock()
{
    StartClockFlag = 1;
}

void pause_clock()
{
    StartClockFlag = 0;
}
