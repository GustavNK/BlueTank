/*
 * ADC.h
 *
 * Created: 27-11-2019 10:09:48
 *  Author: Gustav
 */ 


#ifndef ADC_H_
#define ADC_H_

void initADC();
void startADC0();	//start ADC0
void startADC1();	//start ADC1
int getADC();		//10-bit data from ADC register

#endif /* ADC_H_ */