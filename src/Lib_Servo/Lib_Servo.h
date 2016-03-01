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
#define 	SERVO_SONAR			P9_14
#define		PERIOD_20_MS		20000000

// duty Value for Servo Sonar

#define     SERVO_CENTER		1650000

#define    	SERVO_0_LEFT		500000
#define		SERVO_22_5_LEFT		787500
#define		SERVO_45_LEFT		1075000
#define		SERVO_67_5_LEFT		1362500

#define    	SERVO_0_RIGHT		2600000
#define		SERVO_22_5_RIGHT	2362500
#define		SERVO_45_RIGHT		2125000
#define		SERVO_67_5_RIGHT	1887500

#define		SERVO_STEP			50000


/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
typedef enum{
	LEFT_0 				= 0 ,
	LEFT_22_5			= 1 ,
	LEFT_45				= 2 ,
	LEFT_67_5           = 3 ,
	CENTER              = 4 ,
	RIGHT_67_5          = 5 ,
	RIGHT_45            = 6 ,
	RIGHT_22_5          = 7 ,
	RIGHT_0             = 8 ,
	RIGHT_STEP			= 9 ,
	LEFT_STEP           = 10,
	NBE_SONAR_ROTATE 	= 11,
}eServo_Rotate;


/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
int iCurrentPosSonar;

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
void 	Lib_Servo_Control(eServo_Rotate valueRotate, ePwm pwm);
void 	Lib_Servo_init(ePwm pwm);

#endif /* LIB_SERVO_H_ */
