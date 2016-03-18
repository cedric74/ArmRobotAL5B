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
static double dTheta[5];
static double dTheta_2[5];


/*******************************************
*          F U N C T I O N S    		   *
********************************************/

// Define Pose to Test
//#define		POSE_1	1
//#define		POSE_2	1
//#define		POSE_3	1
#define			POSE_4	1
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
#if POSE_1
	nx = 1;		ox = 0;		ax = 0;		px = 105;
	ny = 0;		oy = -1;	ay = 0;		py = 0;
	nz = 0;		oz = 0;		az =-1;		pz = 150;
#elif POSE_2
	// Define pose #2
	/**
	 *		  |-
	 *		    |
	 * 		  	|
	 * 			|
	 */
	nx = 1;		ox = 0;		ax = 0;		px = -105;
	ny = 0;		oy = -1;	ay = 0;		py = 0;
	nz = 0;		oz = 0;		az =-1;		pz = 150;

#elif POSE_3
	// Define pose #3
	/**
	 *		 -
	 *		  |
	 * 		   _
	 * 			|
	 */
	nx = 1;		ox = 0;		ax = 0;		px = 160;
	ny = 0;		oy = -1;	ay = 0;		py = 0;
	nz = 0;		oz = 0;		az =-1;		pz = 175;
#elif POSE_4
	// Define pose #4
	/**
	 * 		  __
	 * 		 /	|
	 */
	nx = 1;		ox = 0;		ax = 0;		px = 120;
	ny = 0;		oy = -1;	ay = 0;		py = 0;
	nz = 0;		oz = 0;		az =-1;		pz = 0;
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

	// Print Pose
	printf("\nPose :  px: %.2f\n	py: %.2f\n	pz: %.2f\n", px, py, pz);

	IKinematic_getTheta1();
	IKinematic_getTheta5();
	IKinematic_getTheta3();
	IKinematic_getTheta2();
	IKinematic_getTheta4();
	printf("\nSolution 1");
	printf("\ntheta1 = %.2f", rad2deg(dTheta[0]));
	printf("\ntheta2 = %.2f", rad2deg(dTheta[1]));
	printf("\ntheta3 = %.2f", rad2deg(dTheta[2]));
	printf("\ntheta4 = %.2f", rad2deg(dTheta[3]));
	printf("\ntheta5 = %.2f\n", rad2deg(dTheta[4]));

	// Get Position by forward kinematic
	double dPose[4][4];
	Kinematic_getPosition(dTheta, dPose);

	// Test if Ok
	if((dPose[X][P] == px) && (dPose[Y][P] == py) && (dPose[Z][P] == pz) ){
		printf("\n Pose OK	\n");
	}else{
		printf("\n Pose Not OK	\n");

		if(dPose[X][P] != px)
		printf("\n dPose[X][P] =  %f ; px = %f	\n" , dPose[X][P], px);
		if(dPose[Y][P] != py)
		printf("\n dPose[Y][P] =  %f ; py = %f	\n" , dPose[Y][P], py);
		if(dPose[Z][P] != pz)
		printf("\n dPose[Z][P] =  %f ; pz = %f	\n" , dPose[Z][P], pz);
	}


//	printf("\nSolution 2");
//	printf("\ndTheta[0] = %.2f", rad2deg(dTheta_2[0]));
//	printf("\ntheta2 = %.2f", rad2deg(dTheta_2[1]));
//	printf("\ntheta3 = %.2f", rad2deg(dTheta_2[2]));
//	printf("\ntheta4 = %.2f", rad2deg(dTheta_2[3]));
//	printf("\ntheta5 = %.2f\n", rad2deg(dTheta_2[4]));

}

/*
 ============================================
 Function     : IKinematic_getdTheta[0]()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void IKinematic_getTheta1(){

	int iValueA = pow(ay,2)+ pow(ax,2);
	int iValueP = pow(py,2)+ pow(px,2);

	if(iValueA != 0){
		dTheta[0] = atan2(ay,ax);
		dTheta_2[0] = atan2(-ay,-ax);
	}else if(iValueP !=0){
		dTheta[0] = atan2(py,px);
		dTheta_2[0] = atan2(-py,-px);
	}else{
		// Arbitrary
		dTheta[0] = atan2(ay,ax);
		dTheta_2[0] = atan2(-ay,-ax);
	}
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
	dTheta[4] = atan2(
			nx*sin(dTheta[0])-ny*cos(dTheta[0]),
			ox*sin(dTheta[0])- oy*cos(dTheta[0])
	);

	dTheta_2[4] = atan2(
				nx*sin(dTheta_2[0])-ny*cos(dTheta_2[0]),
				ox*sin(dTheta_2[0])- oy*cos(dTheta_2[0])
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
	dTheta[2] = acos(
			(	pow((px-40*ax),2) + pow((py-40*ay),2) +
					pow((pz-70-40*az),2) - 25425)/ 25200);

	// Test if Theta3 is real number
	if (isnan(dTheta[2]) != 0){
//		printf("\ntheta3 radian= %.2f", theta3);
		dTheta[2] = 0;
	}
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

	double r1 =  -40*ax*cos(dTheta[0]) -40*ay*sin(dTheta[0]) +px*cos(dTheta[0])+py*sin(dTheta[0]);
	double r2 =  70+40*az-pz;

	dTheta[1] = atan2 ((105*r2*sin(dTheta[2])) + (105*r1*cos(dTheta[2])) + (120*r1),
			       (-105*r2*cos(dTheta[2])) + (105*r1*sin(dTheta[2]))-(120*r2));



	r1 =  -40*ax*cos(dTheta_2[0]) -40*ay*sin(dTheta_2[0]) +px*cos(dTheta_2[0])+py*sin(dTheta_2[0]);

	dTheta_2[1] = atan2 ((105*r2*sin(dTheta[2])) + (105*r1*cos(dTheta[2])) + (120*r1),
				   (-105*r2*cos(dTheta[2])) + (105*r1*sin(dTheta[2]))-(120*r2));
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

	double theta234 = atan2(ax*cos(dTheta[0])+ay*sin(dTheta[0]),az);
	dTheta[3] = theta234-dTheta[1]-dTheta[2];


	theta234 = atan2(ax*cos(dTheta_2[0])+ay*sin(dTheta_2[0]),az);
	dTheta_2[3] = theta234-dTheta_2[1]-dTheta_2[2];

}
