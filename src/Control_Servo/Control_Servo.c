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
#define		DELAYS_1_S				   1000000	// in us,
#define		DELAYS_5_S				   5000000	// in us,

#define    NUMBER_SERVO					5

typedef struct{
	ePwm pwm;
	int iMin;
	int iMax;
	int iAx;
	int iB;
}sServo;

sServo sTabServo[]={
//			     Pwm, Min Val,  Max Value,    Ax,      B
/* M0 */{  PWM_P8_13,       0,			0,     0,      0},
/* M1 */{  PWM_P8_13,  625000,    2250000, 	9027, 629167},
/* M2 */{  PWM_P8_13,       0,			0,     0,      0},
/* M3 */{  PWM_P8_13,       0,			0,     0,      0},
/* M4 */{  PWM_P8_13,       0,			0,     0,      0},
};

// m1   00D = 2250000
// m1   90D = 1450000
// m1  180D = 625000
/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
int Control_Servo_GetPulseValue(eServo servo, int iAngle);

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
	Lib_Servo_init(sTabServo[Servo_M1].pwm);
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

	// Test Servo 1
	int iCurrentAngle = 0;
	Lib_pwm_control(sTabServo[Servo_M1].pwm, PERIOD_20_MS, Control_Servo_GetPulseValue(sTabServo[Servo_M1].pwm, iCurrentAngle));
	usleep(DELAYS_1_S);
	int i = 0;
	for(i = 0; iCurrentAngle<= 180; i++){
		Lib_pwm_control(sTabServo[Servo_M1].pwm, PERIOD_20_MS, Control_Servo_GetPulseValue(sTabServo[Servo_M1].pwm, iCurrentAngle));
		iCurrentAngle += 10;
		usleep(DELAYS_500_MS);
	};

}

/*
 ============================================
 Function     : Control_Servo_GetPulseValue()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int Control_Servo_GetPulseValue(eServo servo, int iAngle){

	int iReturn = ((sTabServo[Servo_M1].iAx * iAngle) + sTabServo[Servo_M1].iB);
	printf("Value = %i , Angle: %i\n", iReturn, iAngle);

	if( iReturn< sTabServo[Servo_M1].iMin){
		return sTabServo[Servo_M1].iMin;
	}
	if(iReturn > sTabServo[Servo_M1].iMax){
		return sTabServo[Servo_M1].iMax;
	}
	return iReturn;

}
