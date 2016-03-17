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
#include <stdio.h>
#include <math.h>

/*******************************************
*               D E F I N E                *
********************************************/
#define rad2deg(a) ((a*180)/PI)

#define PI 		3.14159265358979323846

#define L_M0_M1		70
#define L_M1_M2		120
#define L_M2_M3		105
#define L_M4_M5		40

#define X			0
#define Y			1
#define Z			2

#define N			0
#define O			1
#define A			2
#define P			3

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
int	d1, a2, a3, d5;
float	t1, t2, t3, t4, t5;

double T1_0[4][4];
double T2_0[4][4];
double T3_0[4][4];
double T4_0[4][4];
double T5_0[4][4];

/*******************************************
*          F U N C T I O N S    		   *
********************************************/

// Forward Kinematic
void Kinematic_init();
void Kinematic_test();
void Kinematic_getPosition(double dTabTheta[4], double dPoseMat[4][4]);

// Inverse Kinematic
void IKinematic_init();
void IKinematic_test();

#endif /* KINEMATIC_KINEMATIC_H_ */
