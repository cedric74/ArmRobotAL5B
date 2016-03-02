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
#define		DELAYS_500_MS				500000	// in us,
#define		DELAYS_5_S				   5000000	// in us,

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
static int Control_Servo_Calcul(int iAngle);

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
void Control_Servo_Rotate(){

	// Turn Servo to Center Position
	Lib_pwm_control(servoM1, PERIOD_20_MS, 1450000);

	usleep(DELAYS_500_MS);

	Lib_pwm_control(servoM1, PERIOD_20_MS, 2250000);

	usleep(DELAYS_500_MS);

	Lib_pwm_control(servoM1, PERIOD_20_MS, 1450000);


	usleep(DELAYS_500_MS);

	Lib_pwm_control(servoM1, PERIOD_20_MS, 625000);

	usleep(DELAYS_500_MS);


	Lib_pwm_control(servoM1, PERIOD_20_MS, 1450000);
//
	// ------
//	Lib_pwm_control(servoM1, PERIOD_20_MS, Control_Servo_Calcul(90));
//
//	usleep(DELAYS_500_MS);
//
//	Lib_pwm_control(servoM1, PERIOD_20_MS, Control_Servo_Calcul(0));
//
//	usleep(DELAYS_500_MS);
//
//	Lib_pwm_control(servoM1, PERIOD_20_MS, Control_Servo_Calcul(90));
//
//	usleep(DELAYS_500_MS);
//
//	Lib_pwm_control(servoM1, PERIOD_20_MS, Control_Servo_Calcul(180));

}

/*
 ============================================
 Function     : Control_Servo_Calcul()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
static int Control_Servo_Calcul(int iAngle){
	// y = 812500x - 183333
	int iReturn = ((812500 * iAngle) - 183333);
	printf("Value = %i\n", iReturn);
	return iReturn;

}
