/*
 * BlueTankProject.cpp
 *
 * Created: 22-08-2020 11:27:57
 * Author : Gustav
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "motor.h"

#define F_CPU 16000000 //CPU speed 

int main(void)
{
	initUART(9600, 8);
	DDRD &= ~(1<<0);  //set RX as input
	initMotor();
	
	while (1)
	{
		unsigned char RxByte= ReadChar();
		if(RxByte & 0b10000000){
			setMotor1(RxByte << 1);
			} else {
			setMotor2(RxByte << 1);
		}
	}
}