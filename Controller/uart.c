/************************************************
* "uart.c":                                     *
* Implementation file for Mega2560 UART driver. *
* Using UART 0.                                 *
* Henning Hargaard, 5/4 2019                    *
*************************************************/
#include <avr/io.h>
#include <stdlib.h>
#include "uart.h"

// Target CPU frequency
#define XTAL 16000000

/*************************************************************************
UART 0 initialization:
    Asynchronous mode.
    Baud rate = var BaudRate.
    Data bits = var DataBit.
    RX and TX enabled.
    No interrupts enabled.
    Number of Stop Bits = 1.
    No Parity.
*************************************************************************/
void InitUART(unsigned long BaudRate, unsigned char DataBit)
{
	UCSR0B = 0b00011000;
	UBRR0 = XTAL / (16 * BaudRate) - 1;
	
	switch(DataBit){
	case 5:
		UCSR0C |= 0b00000000;
		break;
	case 6:
		UCSR0C |= 0b00000010;
		break;
	case 7: 
		UCSR0C |= 0b00000100;
		break;
	case 8:
		UCSR0C |= 0b00000110;
		break;
	default:
		UCSR0C |= 0b00000110;
	}
}

/*************************************************************************
  Returns 0 (FALSE), if the UART has NOT received a new character.
  Returns value <> 0 (TRUE), if the UART HAS received a new character.
*************************************************************************/
unsigned char CharReady()
{
	return (UCSR0A & (1<<RXC0));
}

/*************************************************************************
Awaits new character received.
Then this character is returned.
*************************************************************************/
char ReadChar()
{
	while(!CharReady()){}
	return UDR0;
}

/*************************************************************************
Awaits transmitter register ready.
Then send the character.
Parameter :
	Tegn : Character for sending. 
*************************************************************************/
void SendChar(char Tegn)
{
	while( !( UCSR0A & (1<<UDRE0) ) ){}
	UDR0 = Tegn;
}

/*************************************************************************
Sends 0 terminated string.
Parameter:
   Streng: Pointer to the string. 
*************************************************************************/
void SendString(char* Streng)
{
	while(*Streng != 0){
		SendChar(*Streng);
		Streng++;	
	}
}

/*************************************************************************
Converts the integer "Tal" to an ASCII string - and then sends this string
using the USART.
Makes use of the C standard library <stdlib.h>.
Parameter:
    Tal: The integer to be converted and sent. 
*************************************************************************/
void SendInteger(int Tal)
{
	#define SIZE 7
	char intArray[SIZE];
	
	itoa(Tal, intArray, 10);
	SendString(intArray);
}

/************************************************************************/