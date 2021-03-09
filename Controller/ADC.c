/*
 * ADC.c
 *
 * Created: 27-11-2019 10:09:40
 * Author: Gustav
 */ 
#include "ADC.h"
#include <avr/io.h>
#include <stdlib.h>

void initADC()
{
	DDRC = 0x00;
	ADMUX = 0b01000000;			//REF 01   ADLAR 0    MUX 00000
	ADCSRA |= (1<<ADEN);		//ADEN 1
	ADCSRA &= ~(1<<ADIF);		//ADIF 0
	ADCSRA |= 0b00000111;		//ADP 111
}

void startADC0()
{
	ADMUX = 0b01000000;			//MUX 00000 = ADC0 (A0/PC0)
	ADCSRA |= (1<<ADSC);		//ADC on
	while(ADCSRA & (1<<ADSC)){}	//Wait for finish
}

void startADC1()
{
	ADMUX = 0b01000001;			//MUX 00001 = ADC1 (A1/PC1)
	ADCSRA |= (1<<ADSC);		//ADC on
	while(ADCSRA & (1<<ADSC)){}	//Wait for finish
}

int getADC()
{
	return ADC;
}