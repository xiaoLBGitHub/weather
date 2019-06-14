#include "STC89C5xRC.H"
#include "intrins.h"
#include "Timer.h"
#include "zk_16x32.h"

int main()
{
    timer0_init();
    initial_lcd();
    while(1){
        
    }
}


void show_timer_clock()
{
    unsigned char temp_minute,temp_second,i;
    unsigned char clock_bit[4];

    temp_minute = Minute%100;
    temp_second = Second;

    clock_bit[0] = temp_minute / 10;
    clock_bit[1] = temp_minute % 10;
    clock_bit[2] = temp_second / 10;
    clock_bit[3] = temp_second % 10;


    display_graphic_16x32(0,16,zk_num[clock_bit[0]]);
    display_graphic_16x32(0,32,zk_num[clock_bit[1]]);
    display_graphic_16x32(0,56,zk_num[clock_bit[10]]);
    display_graphic_16x32(0,80,zk_num[clock_bit[2]]);
    display_graphic_16x32(0,96,zk_num[clock_bit[3]]);

}
