/*
 * Lib_PWM.c
 *
 *  Created on: 2015-04-01
 *      Author: cedric
 */


/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Lib_PWM.h"

/*******************************************
*               D E F I N E                *
********************************************/

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
const char strsInitBonePwm[Number_Pwm][BUFFER_SIZE]={
		BONE_P8_13,
		BONE_P9_14,
		BONE_P9_21,
		BONE_P9_31,
		BONE_P9_42,
};

const char strsPwmControl[Number_Pwm][BUFFER_SIZE]={
		PATH_P8_13,
		PATH_P9_14,
		PATH_P9_21,
		PATH_P9_31,
		PATH_P9_42,
};

int iTabOffset[Number_Pwm]={0};
/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
char cPath[BUFFER_SIZE];

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
/*
 ============================================
 Function     : Lib_pwm_init()
 Parameter    : ePwm
 Return Value : int
 Description  :
 ============================================
 */
int Lib_pwm_init(ePwm pwm){
	// Declaration Variables
	int fd;
	char buffer[BUFFER_SIZE];
	int iOffset = 0;

	// Instructions

	// Add Cape inside Slots

	snprintf(buffer, BUFFER_SIZE, "echo ");
	strcat(buffer, strsInitBonePwm[pwm]);
	strcat(buffer," > /sys/devices/bone_capemgr.9/slots");

	printf("\n %s \n", buffer);
	system(buffer);

	// Wait Time to Load The Cape Into The Slots
	usleep(500000);

	// Find Value Offset
	do{
		snprintf(cPath, BUFFER_SIZE, strsPwmControl[pwm]);

		// Convert Integer to String
		char str[2];
		sprintf(str, ".%d", iOffset);
		strcat(cPath,str);

		// Copy  Path
		snprintf(buffer , BUFFER_SIZE, cPath);
		strcat(buffer,PATH_RUN);

		iOffset++;
		if(iOffset > OFFSET_11_22){
			// Error to Find Offset for Pwm
			printf("\n Error Open File : %s \n", buffer);

			// Stop Program
			exit(0);
		}

		// Try To Open File
		fd = open(buffer, O_WRONLY);


		printf("\n Test : %s \n", buffer);
	}while(fd < 0);

	// Save Offset
	iTabOffset[pwm] = iOffset-1;

	// Run -> 0
	sprintf(buffer, "%d", 0);
	printf("run : %s, Offset : %d \n", buffer, (iOffset-1) );
	write(fd, buffer, BUFFER_SIZE);

	// Close descriptor File
	close (fd);

	// Polarity -> 0
	snprintf(buffer, BUFFER_SIZE, cPath);
	strcat(buffer,PATH_POLARITY);
	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n Error Open File : %s \n", buffer);
		return ERROR_PWM_OPEN;
	}

	sprintf(buffer, "%d", 0);
	write(fd, buffer, BUFFER_SIZE);

	// Close descriptor File
	close (fd);

	printf(" Init Pwm Ok \n");
	return 0;
}
/*
 ============================================
 Function     : Lib_pwm_start()
 Parameter    : ePwm
 Return Value : int
 Description  :
 ============================================
*/
int Lib_pwm_start(ePwm pwm){
	// Declaration Variables
	int fd;
	char buffer[BUFFER_SIZE];

	// Instructions

	// Get Path
	snprintf(cPath, BUFFER_SIZE, strsPwmControl[pwm]);

	// Set Offset

	if( iTabOffset[pwm] > 0){
		// Convert Integer to String
		char str[3];
		sprintf(str, ".%d", iTabOffset[pwm]);
		strcat(cPath,str);
	}else{
		// Error
		return 0;
	}

	// ----- Echo 1 > RUN
	snprintf(buffer, BUFFER_SIZE, cPath);
	strcat(buffer,PATH_RUN);

	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n Error Open File : %s \n", buffer);
		return ERROR_PWM_OPEN;
	}

	sprintf(buffer, "%d", 1);
	printf("run : %s, \n", buffer);
	write(fd, buffer, BUFFER_SIZE);
	// Close descriptor File
	close (fd);

	return 0;
}

/*
 ============================================
 Function     : Lib_pwm_control()
 Parameter    :
 Return Value : int
 Description  :
 ============================================
*/
int Lib_pwm_control(ePwm pwm, int iPeriod, int iDuty )
{
	// Declaration Variables
	int fd;
	char buffer[BUFFER_SIZE];


	// Instructions

	// Get the path
	snprintf(cPath, BUFFER_SIZE, strsPwmControl[pwm]);

	// Set Offset
	if( iTabOffset[pwm] > 0){
		// Convert Integer to String
		char str[2];
		sprintf(str, ".%d", iTabOffset[pwm]);
		strcat(cPath,str);
	}else{
		// Error
		return 0;
	}
	snprintf(buffer, BUFFER_SIZE, cPath);
	// ----- Echo value > PERIOD
	strcat(buffer,PATH_PERIOD);
	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n Error Open File : %s \n", buffer);
		return ERROR_PWM_OPEN;
	}

	sprintf(buffer, "%d", iPeriod);
	//printf("iPeriod : %s, ", buffer);
	write(fd, buffer, BUFFER_SIZE);

	// Close descriptor File
	close (fd);

	// ----- Echo value > DUTY
	snprintf(buffer, BUFFER_SIZE, cPath);
	strcat(buffer,PATH_DUTY);

	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n Error Open File : %s \n", buffer);
		return ERROR_PWM_OPEN;
	}
	sprintf(buffer, "%d", iDuty);
	//printf("duty : %s\n", buffer);
	write(fd, buffer, BUFFER_SIZE);

	// Close descriptor File
	close (fd);

	return NO_ERROR_PWM;
}


/*
 ============================================
 Function     : Lib_pwm_stop()
 Parameter    :ePwm
 Return Value : int
 Description  :
 ============================================
*/
int Lib_pwm_stop(ePwm pwm){
	// Declaration Variables
	int fd;
	char buffer[BUFFER_SIZE];


	// Instructions

	// Get Path
	snprintf(cPath, BUFFER_SIZE, strsPwmControl[pwm]);

	// Set Offset
	if( iTabOffset[pwm] > 0){
		// Convert Integer to String
		char str[2];
		sprintf(str, ".%d", iTabOffset[pwm]);
		strcat(cPath,str);
	}else{
		// Error
		return 0;
	}

	// ----- Echo 0 > RUN
	snprintf(buffer, BUFFER_SIZE, cPath);
	strcat(buffer,PATH_RUN);

	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n Error Open File : %s \n", buffer);
		return ERROR_PWM_OPEN;
	}

	sprintf(buffer, "%d", 0);
	printf("run : %s\n", buffer);
	write(fd, buffer, BUFFER_SIZE);
	// Close descriptor File
	close (fd);

	return 0;
}

