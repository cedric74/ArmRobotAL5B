/*
 * Control_Servo.c
 *
 *  Created on: Feb 28, 2016
 *      Author: cedrictoncanier
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include	"Control_Servo.h"

/*******************************************
*               D E F I N E                *
********************************************/

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

// Example Pince
ePwm servoM1 =  	PWM_P8_13;

// m1   00D = 2250000
// m1   90D = 1450000
// m1  180D = 625000
/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/

/*
 ============================================
 Function     : Control_Servo_init()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Control_Servo_init(){

	// Init Servo Pince
	Lib_Servo_init(servoM1);
}

/*
 ============================================
 Function     : Control_Servo_init()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Control_Servo_Rotate(eServo_Rotate valueRotate){

	// Turn Servo to Center Position
	Lib_Servo_Control(servoM1, CENTER);

}
