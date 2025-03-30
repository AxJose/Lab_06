/*
 * UART.c
 *
 * Created: 25/03/2025 16:04:07
 *  Author: adria
 */ 


#include "UART.h"
#include <avr/io.h>
#include <stdio.h>

// Inicializar UART para Arduino (ATmega328P)
void UART_Init(uint32_t baudrate) {
	DDRD |= (1<<DDD1);
	DDRD &= ~(1<<DDD0);
	UCSR0A = 0;
	UCSR0B = 0;
	UCSR0B |= (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0);
	UCSR0C = 0;
	UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);
	UBRR0 = 103;
}

// Enviar un car�cter por UART
void UART_Write(char data) {
	while (!(UCSR0A & (1 << UDRE0))); // Esperar buffer vac�o
	UDR0 = data;
}

// Recibir un car�cter por UART
char UART_Read() {
	while (!(UCSR0A & (1 << RXC0))); // Esperar dato disponible
	return UDR0;
}

// Enviar un texto por UART
void UART_Write_Text(const char *text) {
	while (*text) {
		UART_Write(*text++);
	}
}