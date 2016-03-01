/*
 * Functions_WatchDog.h
 *
 *  Created on: Mar 3, 2015
 *      Author: cedric
 */

#ifndef FUNCTIONS_WATCHDOG_H_
#define FUNCTIONS_WATCHDOG_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include <linux/watchdog.h>
#include  <pthread.h>

/*******************************************
*               D E F I N E                *
********************************************/
#define WATCHDOGDEV "/dev/watchdog"

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
int 		fWatchdog;

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
void Thread_Watch_Reset(void);
void watch_dog_clear(void);
void watch_dog_start(void);
void watch_dog_stop(void);

#endif /* FUNCTIONS_WATCHDOG_H_ */
