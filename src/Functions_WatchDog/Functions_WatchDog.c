/*
 * Functions_WatchDog.c
 *
 *  Created on: Mar 3, 2015
 *      Author: cedric
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Functions_WatchDog.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define TIME_SLEEP_20_S		20
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
 Function     : Thread_Watch_Reset()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Thread_Watch_Reset(){
	do{
		watch_dog_clear();
		sleep(TIME_SLEEP_20_S);
	}while(1);
}

/*
 ============================================
 Function     : watch_dog_start()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void watch_dog_start(void){

	// Declarations Variables
	pthread_t thread_watchdog;

	// Start Watch dog
	fWatchdog = open(WATCHDOGDEV , O_WRONLY);	//"w"
	if(fWatchdog < 0){
		printf("Error of Start WTDG\n");
		return ;
	}
	printf("Start WTDG\n");

	// Thread Execute WatchDog Reset
	pthread_create (&thread_watchdog, NULL, &Thread_Watch_Reset, NULL);
}

/*
 ============================================
 Function     : watch_dog_clear()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void watch_dog_clear(void){
	ioctl(fWatchdog, WDIOC_KEEPALIVE, NULL);
	//printf("Clear WTDG\n");
}

/*
 ============================================
 Function     : watch_dog_stop()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void watch_dog_stop(void){
	close(fWatchdog);
	printf("Close WTDG\n");
}
