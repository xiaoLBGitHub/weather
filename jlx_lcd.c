#include "jlx_lcd.h"


void transfer_command_lcd(int cmd)
{
    LCD_CSL = 0;
    LCD_RS = 0;
    LCD_RD = 0;
    LCD_WR = 0;
    LCD_DATA = cmd;
    LCD_RD = 1;
    LCD_CSL = 1;
    LCD_RD = 0;
}

void transfer_data_lcd(int lcd_data)
{
    LCD_CSL = 0;
    LCD_RS = 1;
    LCD_RD = 0;
    LCD_WR = 0;
    LCD_DATA = lcd_data;
    LCD_RD = 1;
    LCD_CSL = 1;
    LCD_RD = 0;
}

void lcd_address(int page,int column)
{
    transfer_command_lcd(0xb0 + page - 1);
    transfer_command_lcd(0x10 + ((column>>4) & 0x0F));
    transfer_command_lcd(column & 0x0F);
}

void display_graphic_16x16(uint page,uint column,uchar *dp)
{
    uint i,j;
    LCD_CSL = 0;
    for (j = 0; j < 2; j++)
    {
        lcd_address(page,column);
        for (i = 0; i < 16; i++)
        {
            transfer_data_lcd(*dp);
            dp++;
        }
        page++;
    }
    LCD_CSL = 1;
}

void display_graphic_8x16(uint page,uchar column,uchar *dp)
{
    uint i,j;
    LCD_CSL = 0;
    for (j = 0; j < 2; j++)
    {
        lcd_address(page,column);
        for (i = 0; i < 8; i++)
        {
            transfer_data_lcd(*dp);
            dp++;
        }
        page++;
    }
    LCD_CSL = 1;
}

void display_graphic_16x32(uint page,uchar column,uchar *dp)
{
    uint i,j;
    LCD_CSL = 0;
    for (j = 0; j < 4; j++)
    {
        lcd_address(page,column);
        for (i = 0; i < 16; i++)
        {
            transfer_data_lcd(*dp);
            dp++;
        }
        page++;
    }
    LCD_CSL = 1;
}

void delayms(uint ms)		//@11.0592MHz
{
    unsigned char i, j;
    for(; ms-- ;ms > 0){
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j);
        } while (--i);
    }
}

void initial_lcd()
{
    LCD_CSL = 0;
    LCD_RST = 0;
    delayms(20);
    LCD_RST = 1;
    transfer_command_lcd(0xE2);
    transfer_command_lcd(0x2C);
    delayms(5);
    transfer_command_lcd(0x2E);
    delayms(5);
    transfer_command_lcd(0x2F);
    delayms(5);
    transfer_command_lcd(0x22);
    transfer_command_lcd(0x81);
    transfer_command_lcd(0x1B);
    transfer_command_lcd(0xA2);
    transfer_command_lcd(0xC8);
    transfer_command_lcd(0xA0);
    transfer_command_lcd(0x40);
    transfer_command_lcd(0xAF);
    LCD_CSL = 1;
}

void clear_screen()
{
    uchar i,j;
    for (i = 0; i < 4; i++)
    {
        LCD_CSL = 0;
        transfer_command_lcd(0xB0 + i);
        transfer_command_lcd(0x10);
        transfer_command_lcd(0x00);
        for (j = 0; j < 132; j++)
        {
            transfer_data_lcd(0x00);
        }        
    }    
}

void test_lcd()
{
    initial_lcd();
    display_graphic_16x32(0,0,zk_num[0]);
    display_graphic_16x32(0,16,zk_num[1]);
    display_graphic_16x32(0,32,zk_num[10]);
    display_graphic_16x32(0,48,zk_num[2]);
    display_graphic_16x32(0,64,zk_num[3]);    
}