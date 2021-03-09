/*
 * mg996r.c
 *
 * Created: 09-01-2020 21:04:00
 *  Author: Gustav
 *
 *
 * Brown = GND
 * Red = 5V
 * Orange = PWM (D9/PB1)
 * 
 * Controlled by PWM  
 * 5% = 0°  PWM 10% = 160°
 */

 #include <avr/io.h>
 #include "mg996r.h"

 void initServo()
 {
 DDRB |= (1 <<PORTB1);		//PB1 output
	PORTB &= ~(1<<PORTB1);		//PB1 off
	TCCR1A = 0b10000010;		//COM1A 10  WGM1 0101  CS1 100
	TCCR1B = 0b00000100;		// 50Hz
	OCR1A = 25;					// duty cycle 5% (position 0*)
}

void setServo(char angle)
{
	OCR1A = 18 + (angle / 5);	//5%-10% dutycycle
}