/*
 * Lib_Servo.c
 *
 *  Created on: Mar 31, 2015
 *      Author: cedric
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include	"Lib_Servo.h"

/*******************************************
*               D E F I N E                *
********************************************/

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
 Function     : Lib_Servo_Control_Pwm()
 Parameter    : eServo_Rotate, ePwm
 Return Value :
 Description  :
 ============================================
 */
void Lib_Servo_Control(eServo_Rotate valueRotate, ePwm pwm)
{
	switch(valueRotate){
		case CENTER :
			Lib_pwm_control(pwm, PERIOD_20_MS, SERVO_CENTER);
			iCurrentPosSonar = SERVO_CENTER;
			printf(" SERVO_CENTER\n");
		break;
		// Position
		case LEFT_0:
			Lib_pwm_control(pwm, PERIOD_20_MS, SERVO_0_LEFT);
			iCurrentPosSonar = SERVO_0_LEFT;
			printf(" SERVO_0_LEFT\n");
		break;
		case RIGHT_0:
			Lib_pwm_control(pwm, PERIOD_20_MS, SERVO_0_RIGHT);
			iCurrentPosSonar = SERVO_0_RIGHT;
			printf(" SERVO_0_RIGHT\n");
		break;

		case LEFT_22_5:
			Lib_pwm_control(pwm, PERIOD_20_MS, SERVO_22_5_LEFT);
			iCurrentPosSonar = SERVO_22_5_LEFT;
			printf(" SERVO_22_5_LEFT\n");
		break;

		case RIGHT_22_5:
			Lib_pwm_control(pwm, PERIOD_20_MS, SERVO_22_5_RIGHT);
			iCurrentPosSonar = SERVO_22_5_RIGHT;
			printf(" SERVO_22_5_RIGHT\n");
		break;

		case LEFT_45:
			Lib_pwm_control(pwm, PERIOD_20_MS, SERVO_45_LEFT);
			iCurrentPosSonar = SERVO_45_LEFT;
			printf(" SERVO_45_LEFT\n");
		break;

		case RIGHT_45:
			Lib_pwm_control(pwm, PERIOD_20_MS, SERVO_45_RIGHT);
			iCurrentPosSonar = SERVO_45_RIGHT;
			printf(" SERVO_45_RIGHT\n");
		break;


		case LEFT_67_5:
			Lib_pwm_control(pwm, PERIOD_20_MS, SERVO_67_5_LEFT);
			iCurrentPosSonar = SERVO_67_5_LEFT;
			printf(" SERVO_67_5_LEFT\n");
		break;

		case RIGHT_67_5:
			Lib_pwm_control(pwm, PERIOD_20_MS, SERVO_67_5_RIGHT);
			iCurrentPosSonar = SERVO_67_5_RIGHT;
			printf(" SERVO_67_5_RIGHT\n");
		break;


		case RIGHT_STEP:
			if(iCurrentPosSonar < SERVO_0_RIGHT){
				iCurrentPosSonar += SERVO_STEP;
				Lib_pwm_control(pwm, PERIOD_20_MS, iCurrentPosSonar);
				printf(" RIGHT_STEP\n");
			}

		break;

		case LEFT_STEP:
			if(iCurrentPosSonar > SERVO_0_LEFT){
				iCurrentPosSonar -= SERVO_STEP;
				Lib_pwm_control(pwm, PERIOD_20_MS, iCurrentPosSonar);
				printf(" LEFT_STEP\n");
			}
		break;

		default :
			//... Nothing To Do
		break;

	}
}
/*
 ============================================
 Function     : Lib_Servo_init()
 Parameter    : ePwm
 Return Value : void
 Description  :
 ============================================
 */
void Lib_Servo_init(ePwm pwm){

	// Set Polarity to 0
	Lib_pwm_init(pwm);

	// Set Run to 1
	Lib_pwm_start(pwm);

	// Set Servo Sonar to Center Position
	Lib_pwm_control(pwm, PERIOD_20_MS, SERVO_CENTER);
	iCurrentPosSonar = SERVO_CENTER;
	printf(" SERVO_CENTER\n");
}
