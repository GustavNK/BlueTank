/*
 * mg996r.h
 *
 * Created: 09-01-2020 21:03:13
 *  Author: Gustav
 */ 


#ifndef MG996R_H_
#define MG996R_H_

void initServo();			//Servo control on D9/PB1 (OC1A)
void setServo(char angle);  //0-255  0*-160*

#endif /* MG996R_H_ */