/*
 * Controller.c
 *
 * Created: 07-01-2020 22:25:52
 * Author : Gustav
 
 TODO:
 -Remove _delay_ms() from code, to see if code can run without delays
  
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "uart.h"
#include "ADC.h"

//send for motor1	"1xxxxxxx"
//send for motor0	"0xxxxxxx"

int main(void)
{	
    InitUART(9600, 8);
	initADC();
	
	while (1) 
    {
		//A0 VRx controller		Wheel
		startADC0();
		_delay_ms(50);								//VRx  left/right
		SendChar((getADC() >> 3) | 0b10000000);		//Right shift for 7-bit char with MSB as parity
		_delay_ms(100);
		//A1 VRy controller		Motor
		startADC1();
		_delay_ms(50);							//VRy  up/down
		SendChar((getADC() >> 3) & 0b01111111);		//Right shift for 7-bit char with MSB as parity
		_delay_ms(100);
    }
	return 0;
}