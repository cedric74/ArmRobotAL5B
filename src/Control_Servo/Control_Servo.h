/*
 * Control_Servo.h
 *
 *  Created on: Feb 28, 2016
 *      Author: cedrictoncanier
 */

#ifndef CONTROL_SERVO_CONTROL_SERVO_H_
#define CONTROL_SERVO_CONTROL_SERVO_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include	"../Lib_Servo/Lib_Servo.h"

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
*               D E F I N E                *
********************************************/
void 	Control_Servo_init();
void 	Control_Servo_Rotate();

#endif /* CONTROL_SERVO_CONTROL_SERVO_H_ */
