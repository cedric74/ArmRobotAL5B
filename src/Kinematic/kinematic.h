/*
 * kinematic.h
 *
 *  Created on: Mar 8, 2016
 *      Author: cedrictoncanier
 */

#ifndef KINEMATIC_KINEMATIC_H_
#define KINEMATIC_KINEMATIC_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include <math.h>

/*******************************************
*               D E F I N E                *
********************************************/
#define PI 		3.14159265358979323846

#define L_M0_M1		70
#define L_M1_M2		120
#define L_M2_M3		105
#define L_M4_M5		40


/*******************************************
*   P R O T O T Y P E   F U N C T I O N S  *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
int	d1, a2, a3, d5;
int	t1, t2, t3, t4, t5;

double T1_0[4][4];
double T2_0[4][4];
double T3_0[4][4];
double T4_0[4][4];
double T5_0[4][4];

/*******************************************
*          F U N C T I O N S    		   *
********************************************/
void Kinematic_init();
void Kinematic_test();

#endif /* KINEMATIC_KINEMATIC_H_ */
