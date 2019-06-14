#ifndef _UART_H
#define _UART_H

#include "STC89C5xRC.H"
#include "intrins.h"

#define FOSC 11059200L      //System frequency
#define BAUD 115200           //UART baudrate


void uart_init();
void SendString(char *s);
void send_mult_data(unsigned char *dat,unsigned char len);
#endif