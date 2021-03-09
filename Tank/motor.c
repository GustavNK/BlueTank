/*
 * motor.c
 *
 * Created: 10-01-2020 15:27:58
 *  Author: Gustav
 * 
 * Remember common GND with Arduino!
 */ 
#include <avr/io.h>

void initMotor()
{
	DDRB |= (1<<PORTB3);	//PB3 output (D11)
	PORTB &= ~(1<<PORTB3);	//PB3 off
	DDRD |= (1<<PORTD3);	//PD3 output (D3)
	PORTD &= ~(1<<PORTD3);	//PD3 off
	
	TCCR2A = 0b10100001;	//COM2A 10  WGM 001  CS2 110
	TCCR2B = 0b00000110;
	OCR2A = 0;				//OC2A PWM 0% duty cycle
	OCR2B = 0;				//OC2B PWM 0% duty cycle
	
	DDRD |= (1<<PORTD4) | (1<<PORTD5) | (1<<PORTD6) | (1<<PORTD7); //PD4-7 as output (D4-7)
	PORTD |= (1<<PORTD4) | (1<<PORTD6);  //Turn on D4 & D6
	PORTD &= ~(1<<PORTD5) & ~(1<<PORTD7); //Turn off D5 & D7 
}

void setMotor1(char speed)
{
	if (speed > (255 / 2))
	{
		PORTD |= (1<<PORTD4);
		PORTD &= ~(1<<PORTD5);
		char speed_ = (speed - (255/2)) * 2;
		OCR2B = speed_ > 30 ? speed_ : 0;			
	} else
	{
		PORTD &= ~(1<<PORTD4);
		PORTD |= (1<<PORTD5);
		char speed_ = (~speed - (255/2)) * 2;
		OCR2B = speed_ > 30 ? speed_ : 0;
	}
}

void setMotor2(char speed)
{
	if (speed > (255 / 2))
	{
		PORTD |= (1<<PORTD6);
		PORTD &= ~(1<<PORTD7);
		char speed_ = (speed - (255/2)) * 2;
		OCR2A = speed_ > 30 ? speed_ : 0;
	} else
	{
		PORTD &= ~(1<<PORTD6);
		PORTD |= (1<<PORTD7);
		char speed_ = (~speed - (255/2)) * 2;
		OCR2A = speed_ > 30 ? speed_ : 0;
		}
	}