/*
 ============================================================================
 Name        : lib_uart_main.c
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 10/02/2015
 Description : 
 ============================================================================
 */
 /*******************************************
*			  I N C L U D E 			   *			
********************************************/
#include "Lib_main.h"

/*******************************************
*               D E F I N E                *			
********************************************/

/*******************************************
*   P R O T O T Y P E   F U N C T I O N S  *			
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *			
********************************************/
#define	TICK_LOOP_MAIN_500_MS		500000
#define	TICK_LOOP_MAIN_1_S	   		1000000

#define	TICK_LOOP_MAIN_5_S	   		5000000

/*******************************************
*          F U N C T I O N S    		   *
********************************************/

/*
 ============================================
 Function     : main()
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
int main(int argc, char *argv[])
{
	// Init
	Init();

	// Main Loop
	do{
		//
		// ...
		Control_Servo_Rotate();

		// Sleep
		usleep(TICK_LOOP_MAIN_1_S);

	}while(1);

	return 0;
}

/*
 ============================================
 Function     : Init()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Init(){

	// Print Version
	printf("%s \n" , START_FILE);

	// Start WatchDog
	watch_dog_start();

	// init Control Servo
	Control_Servo_init();

}
