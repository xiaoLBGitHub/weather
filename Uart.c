/*
    ESP8266-01的通讯波特率为：115200 8个数据位 1个停止位 无奇偶校验
*/

#include "Uart.h"

bit busy;

void uart_init()
{
    SCON = 0x50;
    TMOD = 0x20;            //Set Timer1 as 8-bit auto reload mode
    TH1 = TL1 = -(FOSC/12/32/BAUD); //Set auto-reload vaule
    TR1 = 1;                //Timer1 start run
    ES = 1;                 //Enable UART interrupt
    EA = 1;                 //Open master interrupt switch

}

void Uart_Isr() interrupt 4 using 1
{
    if (RI)
    {
        RI = 0;             //Clear receive interrupt flag
        
    }
    if (TI)
    {
        TI = 0;             //Clear transmit interrupt flag
        busy = 0;           //Clear transmit busy flag
    }
}

void SendData(BYTE dat)
{
    while (busy);           //Wait for the completion of the previous data is sent
    busy = 1;
    SBUF = dat;             //Send data to UART buffer
}

/*----------------------------
Send a string to UART
Input: s (address of string)
Output:None
----------------------------*/
void SendString(char *s)
{
    while (*s)              //Check the end of the string
    {
        SendData(*s++);     //Send current char and increment string ptr
    }
}

void send_mult_data(unsigned char *dat,unsigned char len)
{
    unsigned char i=0;
    for(i=0;i<len;i++){
        SendData(dat[i]);
    }
}
