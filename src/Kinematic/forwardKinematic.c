/*
 * kinematic.c
 *
 *  Created on: Mar 8, 2016
 *      Author: cedrictoncanier
 *
 *      Denavit-Hartenberg convention, 4 Degree Of Freedom
 *
 *
 *      DH Table:
 *
 *		i:		thetai:  	d:		ai:		alpha:
 *		1		theta1		70mm	00mm		-90d
 *		2		theta2-90d	00mm	120mm		 00d
 *		3		theta3		00mm	105mm		 00d
 *		4		theta4-90d	00mm	00mm		-90d
 *		5		theta5		40mm	00mm		 00d
 *
 *
 */



/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "kinematic.h"
#include <string.h>
/*******************************************
*               D E F I N E                *
********************************************/

/*******************************************
*   P R O T O T Y P E   F U N C T I O N S  *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
double T2_1[4][4];
double T3_2[4][4];
double T4_3[4][4];
double T5_4[4][4];

/*******************************************
*          F U N C T I O N S    		   *
********************************************/
void initT1_0(double m[4][4]);
void initT2_1(double m[4][4]);
void initT3_2(double m[4][4]);
void initT4_3(double m[4][4]);
void initT5_4(double m[4][4]);

void Kinematic_multi(double p[4][4],double q[4][4],double r[4][4]);
void Kinematic_displayMatrix(double m[4][4]);

/*
 ============================================
 Function     : Kinematic_getPosition()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Kinematic_getPosition(double dTabTheta[4], double dPoseMat[4][4]){

	// Define Value parameter
	d1 = L_M0_M1;
	a2 = L_M1_M2;
	a3 = L_M2_M3;
	d5 = L_M4_M5;

	// Define Angles
	t1 = dTabTheta[0] ;
	t2 = dTabTheta[1] ;
	t3 = dTabTheta[2] ;
	t4 = dTabTheta[3] ;
	t5 = dTabTheta[4] ;

	// Init Matrix
	initT1_0(T1_0);
	initT2_1(T2_1);
	initT3_2(T3_2);
	initT4_3(T4_3);
	initT5_4(T5_4);

	// Get Position
	Kinematic_multi(T1_0, T2_1, T2_0);
	Kinematic_multi(T2_0, T3_2, T3_0);
	Kinematic_multi(T3_0, T4_3, T4_0);
	Kinematic_multi(T4_0, T5_4, T5_0);

	// Display
//	printf("\nDisplay T2_0 :");
//	Kinematic_displayMatrix(T2_0);
//
//	printf("\nDisplay T3_0 :");
//	Kinematic_displayMatrix(T3_0);
//
//	printf("\nDisplay T4_0 :");
//	Kinematic_displayMatrix(T4_0);


	// Test Remove Negative Sign
	printf("\n Before T5_0[i][j]: %f", T5_0[2][3]);
	printf("\nDisplay T5_0 :");
	int i, j;
	for(i = 0; i < 4 ; i++){
		for(j = 0; j < 4; j++){
			if(j == 3){
				T5_0[i][j] = round(T5_0[i][j]);
			}
		}
	}
	printf("\n After T5_0[i][j]: %f", T5_0[2][3]);

	printf("\nDisplay T5_0 :");
	Kinematic_displayMatrix(T5_0);

	// Matrix Copy
	//int i;
	for(i = 0; i<4; i++)
	{
		memcpy(&dPoseMat[i], &T5_0[i], sizeof(T5_0[i]));
	}

//	printf("\nDisplay PoseMat :");
//	Kinematic_displayMatrix(dPoseMat);
}


/*
 ============================================
 Function     : Kinematic_test()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Kinematic_test(){

	// Init Distance, Angle and Matrix
	Kinematic_init();

	// Get Position
	Kinematic_multi(T1_0, T2_1, T2_0);
	Kinematic_multi(T2_0, T3_2, T3_0);
	Kinematic_multi(T3_0, T4_3, T4_0);
	Kinematic_multi(T4_0, T5_4, T5_0);

	// Display
	printf("\nDisplay T2_0 :");
	Kinematic_displayMatrix(T2_0);

	printf("\nDisplay T3_0 :");
	Kinematic_displayMatrix(T3_0);

	printf("\nDisplay T4_0 :");
	Kinematic_displayMatrix(T4_0);

	printf("\nDisplay T5_0 :");
	Kinematic_displayMatrix(T5_0);

}

/*
 ============================================
 Function     : Kinematic_init()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Kinematic_init(){

	// Define Value parameter
	d1 = L_M0_M1;
	a2 = L_M1_M2;
	a3 = L_M2_M3;
	d5 = L_M4_M5;

	// Define Angles
	t1 = 0  *(PI/180);
	t2 = 0  *(PI/180);
	t3 = 90 *(PI/180);
	t4 = 90 *(PI/180);
	t5 = 0  *(PI/180);

	// Init Matrix
	initT1_0(T1_0);
	initT2_1(T2_1);
	initT3_2(T3_2);
	initT4_3(T4_3);
	initT5_4(T5_4);
}


/*
 ============================================
 Function     : initT1_0()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void initT1_0(double m[4][4]){
	m[0][0] = cos(t1);	m[0][1] = 0;	m[0][2]= -sin(t1);	m[0][3] = 0;
	m[1][0] = sin(t1);	m[1][1] = 0;	m[1][2]= cos(t1);	m[1][3] = 0;
	m[2][0] = 0; 		m[2][1] = -1;	m[2][2]= 0;			m[2][3] = d1;
	m[3][0] = 0; 		m[3][1] = 0;	m[3][2]= 0;			m[3][3] = 1;
}

/*
 ============================================
 Function     : initT2_1()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void initT2_1(double m[4][4]){
	m[0][0] = sin(t2);	m[0][1] = cos(t2);	m[0][2]= 0;	m[0][3] = a2*sin(t2);
	m[1][0] = -cos(t2);	m[1][1] = sin(t2);	m[1][2]= 0;	m[1][3] = -a2*cos(t2);
	m[2][0] = 0; 		m[2][1] = 0;		m[2][2]= 1;	m[2][3] = 0;
	m[3][0] = 0; 		m[3][1] = 0;		m[3][2]= 0;	m[3][3] = 1;
}

/*
 ============================================
 Function     : initT3_2()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void initT3_2(double m[4][4]){
	m[0][0] = cos(t3);	m[0][1] = -sin(t3);	m[0][2]= 0;	m[0][3] = a3*cos(t3);
	m[1][0] = sin(t3);	m[1][1] = cos(t3);	m[1][2]= 0;	m[1][3] = a3*sin(t3);
	m[2][0] = 0; 		m[2][1] = 0;		m[2][2]= 1;	m[2][3] = 0;
	m[3][0] = 0; 		m[3][1] = 0;		m[3][2]= 0;	m[3][3] = 1;
}

/*
 ============================================
 Function     : initT3_2()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void initT4_3(double m[4][4]){
	m[0][0] = sin(t4);	m[0][1] = 0;	m[0][2]= cos(t4);	m[0][3] = 0;
	m[1][0] = -cos(t4);	m[1][1] = 0;	m[1][2]= sin(t4);	m[1][3] = 0;
	m[2][0] = 0; 		m[2][1] = -1;	m[2][2]= 0;			m[2][3] = 0;
	m[3][0] = 0; 		m[3][1] = 0;	m[3][2]= 0;			m[3][3] = 1;
}

/*
 ============================================
 Function     : initT5_4()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void initT5_4(double m[4][4]){
	m[0][0] = cos(t5);	m[0][1] = -sin(t5);	m[0][2]= 0;	m[0][3] = 0;
	m[1][0] = sin(t5);	m[1][1] = cos(t5);	m[1][2]= 0;	m[1][3] = 0;
	m[2][0] = 0; 		m[2][1] = 0;		m[2][2]= 1;	m[2][3] = d5;
	m[3][0] = 0; 		m[3][1] = 0;		m[3][2]= 0;	m[3][3] = 1;
}

/*
 ============================================
 Function     : Kinematic_multi()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Kinematic_multi(double p[4][4],double q[4][4],double r[4][4])
{
	int i,j,k;

	for (i=0; i<4; i++)
	{
		for (j=0; j<4; j++)
		{
			r[i][j]=0;
			for (k=0; k<4; k++)
			{
				r[i][j] += p[i][k]*q[k][j];
			}
		}
	}
}

/*
 ============================================
 Function     : Kinematic_displayMatrix()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Kinematic_displayMatrix(double m[4][4])
{
	int i,j;
	printf("\n\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(j == 3){
				printf("%.2f  ", m[i][j]);
			}else{
				printf("%.2f  ", rad2deg(m[i][j]));
			}
		}
		printf("\n");
	}
}
