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
#define		DELAYS_500_MS				500000	// in us,
#define		DELAYS_1_S				   1000000	// in us,
#define		DELAYS_2_S				   2000000	// in us,
#define		DELAYS_5_S				   5000000	// in us,
/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

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

	// Init Servo
	Lib_Servo_init(Servo_M1);
	Lib_Servo_init(Servo_M0);

	// Init Position Servo
	Lib_Servo_Control(Servo_M0, 0);
	Lib_Servo_Control(Servo_M1, 0);
}

/*
 ============================================
 Function     : Control_Servo_test()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Control_Servo_test(){

	Lib_Servo_Control(Servo_M0, 0);
	Lib_Servo_Control(Servo_M1, 0);
	usleep(DELAYS_2_S);

	Lib_Servo_Control(Servo_M0, 90);
	Lib_Servo_Control(Servo_M1, 90);
	usleep(DELAYS_2_S);

	Lib_Servo_Control(Servo_M0, 180);
	Lib_Servo_Control(Servo_M1, 180);
	usleep(DELAYS_2_S);

	Lib_Servo_Control(Servo_M0, 25);
	Lib_Servo_Control(Servo_M1, 25);
	usleep(DELAYS_2_S);

}

