/*
 * motor.h
 *
 * Created: 10-01-2020 15:27:48
 *  Author: Gustav
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include <avr/io.h>

void initMotor();
void setMotor1(char speed);
void setMotor2(char speed);


#endif /* MOTOR_H_ */