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
#define		PERIOD_20_MS		20000000

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
typedef struct{
	ePwm pwm;
	int iMin;
	int iMax;
	int iAx;
	int iB;
}sServo;

sServo sTabServo[]={
//			     Pwm, Min Val,  Max Value,    Ax,      B
/* M0 */{  PWM_P8_13,  509167,    2304027, 	9971, 509167},
/* M1 */{  PWM_P9_31,  625000,    2250000, 	9027, 629167},
/* M2 */{  PWM_P9_14,  509167,    2304027, 	9971, 509167},
/* M3 */{  PWM_P9_31,       0,			0,     0,      0},
/* M4 */{  PWM_P9_31,       0,			0,     0,      0},
};

//P8_13, P9_14, P9_21, P9_31, P9_42


// PWM_P9_31,  625000,    2250000, 	9027, 629167

// TODO, P9_14 definir les specs
/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	   F U N C T I O N S   L O C A L S 	   *
********************************************/
int Lib_Servo_GetPulseValue(eServo servo, int iAngle);

/*
 ============================================
 Function     : Lib_Servo_init()
 Parameter    : eServo
 Return Value : void
 Description  :
 ============================================
 */
void Lib_Servo_init(eServo servo){

	// Set Polarity to 0
	Lib_pwm_init(sTabServo[servo].pwm);

	// Set Run to 1
	Lib_pwm_start(sTabServo[servo].pwm);
}

/*
 ============================================
 Function     : Lib_Servo_Control_Pwm()
 Parameter    : eServo, int
 Return Value :
 Description  :
 ============================================
 */
void Lib_Servo_Control(eServo servo,  int iAngle)
{
	// Get Pulse value from Angle value
	int iVal = Lib_Servo_GetPulseValue(servo, iAngle);

	// Set Pulse, Period to Pwm Output
	Lib_pwm_control(sTabServo[servo].pwm, PERIOD_20_MS, iVal);
}

/*
 ============================================
 Function     : Lib_Servo_GetPulseValue()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int Lib_Servo_GetPulseValue(eServo servo, int iAngle){

	int iReturn = ((sTabServo[servo].iAx * iAngle) + sTabServo[servo].iB);
	printf("Value = %i , Angle: %i\n", iReturn, iAngle);

	if( iReturn< sTabServo[servo].iMin){
		return sTabServo[servo].iMin;
	}
	if(iReturn > sTabServo[servo].iMax){
		return sTabServo[servo].iMax;
	}
	return iReturn;
}
