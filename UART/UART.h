/*
 * UART.h
 *
 * Created: 25/03/2025 16:04:29
 *  Author: adria
 */ 


#ifndef UART_H
#define UART_H

#include <avr/io.h>
#include <stdint.h>

// Prototipos de funciones UART
void UART_Init(uint32_t baudrate);
void UART_Write(char data);
char UART_Read();
void UART_Write_Text(const char *text);

#endif /* UART_H */