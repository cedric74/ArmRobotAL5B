/*
 * Lib_Servo.h
 *
 *  Created on: Mar 31, 2015
 *      Author: cedric
 */

#ifndef LIB_SERVO_H_
#define LIB_SERVO_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "../Lib_Gpio/beh_BBB_gpio.h"
#include "../Lib_PWM/Lib_PWM.h"

/*******************************************
*               D E F I N E                *
********************************************/

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
typedef enum {
	Servo_M0  = 0,
	Servo_M1  = 1,
	Servo_M2  = 2,
	Servo_M3  = 3,
	Servo_M4  = 4,
	Number_Servo = 5,
}eServo;

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
int iCurrentPosSonar;

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
void 	Lib_Servo_init(eServo servo);
void 	Lib_Servo_Control(eServo servo,  int iAngle);

#endif /* LIB_SERVO_H_ */
