/*
 * inverseKinematic.c
 *
 *  Created on: Mar 10, 2016
 *      Author: cedrictoncanier
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "kinematic.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define rad2deg(a) ((a*180)/PI)
/*******************************************
*   P R O T O T Y P E   F U N C T I O N S  *
********************************************/
void IKinematic_getTheta1();
void IKinematic_getTheta5();
void IKinematic_getTheta3();
void IKinematic_getTheta2();
void IKinematic_getTheta4();

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
// Rotation in Radian
double nx,ny,nz,ox,oy,oz,ax,ay,az;

// Pose from F0 in mm
double px,py,pz;

// Angle in Radian
static double theta1, theta2, theta3, theta4, theta5;

/*******************************************
*          F U N C T I O N S    		   *
********************************************/

/*
 ============================================
 Function     : IKinematic_init()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void IKinematic_init(){

	// Define pose #1
	/**
	 *		   _
	 * 		  |	|
	 * 			|
	 */
#if TEST_1
	nx = 1;		ox = 0;		ax = 0;		px = 105;
	ny = 0;		oy = -1;	ay = 0;		py = 0;
	nz = 0;		oz = 0;		az =-1;		pz = 150;
#else
	// Define pose #2
	/**
	 *		  |-
	 *		    |
	 * 		  	|
	 * 			|
	 */
	nx = 1;		ox = 0;		ax = 0;		px = 105;
	ny = 0;		oy = -1;	ay = 0;		py = 0;
	nz = 0;		oz = 0;		az =-1;		pz = 230;
#endif

}

/*
 ============================================
 Function     : IKinematic_test()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void IKinematic_test(){

	// Init Pose
	IKinematic_init();

	IKinematic_getTheta1();
	IKinematic_getTheta5();
	IKinematic_getTheta3();
	IKinematic_getTheta2();
	IKinematic_getTheta4();
	printf("\ntheta1 = %.2f", rad2deg(theta1));
	printf("\ntheta2 = %.2f", rad2deg(theta2));
	printf("\ntheta3 = %.2f", rad2deg(theta3));
	printf("\ntheta4 = %.2f", rad2deg(theta4));
	printf("\ntheta5 = %.2f\n", rad2deg(theta5));


}

/*
 ============================================
 Function     : IKinematic_getTheta1()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void IKinematic_getTheta1(){
	theta1 = atan2(py,px);
}

/*
 ============================================
 Function     : IKinematic_getTheta5()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void IKinematic_getTheta5(){
	theta5 = atan2(
			nx*sin(theta1)-ny*cos(theta1),
			ox*sin(theta1)- oy*cos(theta1)
	);
}

/*
 ============================================
 Function     : IKinematic_getTheta3()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void IKinematic_getTheta3(){
	theta3 = acos(
			(	pow((px-40*ax),2) + pow((py-40*ay),2) +
					pow((pz-70-40*az),2) - 25425)/ 25200);
}

/*
 ============================================
 Function     : IKinematic_getTheta2()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void IKinematic_getTheta2(){

	double r1 =  -40*ax*cos(theta1) -40*ay*sin(theta1) +px*cos(theta1)+py*sin(theta1);
	double r2 =  70+40*az-pz;

	theta2 = atan2 ((105*r2*sin(theta3)) + (105*r1*cos(theta3)) + (120*r1),
			       (-105*r2*cos(theta3)) + (105*r1*sin(theta3))-(120*r2));
}

/*
 ============================================
 Function     : IKinematic_getTheta4()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void IKinematic_getTheta4(){

	double theta234 = atan2(ax*cos(theta1)+ay*sin(theta1),az);

	theta4 = theta234-theta2-theta3;
}
