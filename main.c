/*
 * main.c
 *
 * Created: 3/25/2025 3:56:12 PM
 *  Author: Adrian Pascual
 * Parte 2: Botones en ATMega328P 
 */ 

#include <xc.h>
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "UART/UART.h"

void setupInterrupts(void);

int main(void)
{
	UART_Init(9600);
	setupInterrupts();

	while (1)
	{
	}
}

void setupInterrupts(void) {
	// Configurar pines como entrada 
	cli();
	
	DDRC = 0b11000000; // Habilitar como salida y PC5 como entrada
	PORTC = 0;	// Limpiar el puerto C
	
	PCICR |= (1 << PCIE0) | (1 << PCIE1); // Habilitar interrupciones para el puerto B y C
	// Habilitar interrupciones en los pines 
	PCMSK1 |= (1 << PCINT8) | (1 << PCINT9) | (1 << PCINT10) | (1 << PCINT11) | (1 << PCINT12) | (1 << PCINT13); // Habilitar las interrupciones externas para PC
	
	sei();
}

ISR(PCINT1_vect) {
	
	if (!(PINC & (1 << PINC0))) {
		UART_Write_Text("\n\r");
		UART_Write_Text("w");
		
	} else if (!(PINC & (1 << PINC1))) {
		UART_Write_Text("\n\r");
		UART_Write_Text("s");
		
	} else if (!(PINC & (1 << PINC2))) {
		UART_Write_Text("\n\r");
		UART_Write_Text("a");
		
	} else if (!(PINC & (1 << PINC3))) {
		UART_Write_Text("\n\r");
		UART_Write_Text("d");
		
	} else if (!(PINC & (1 << PINC4))) {
		UART_Write_Text("\n\r");
		UART_Write_Text("1");
		
	} else if (!(PINC & (1 << PINC5))) {
		UART_Write_Text("\n\r");
		UART_Write_Text("2");
	}
	
}