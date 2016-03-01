/*
 ============================================================================
 Name        : beh_BBB_gpio.h
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 04/07/2013
 Description : Behaviour GPIO Lib Definitions Prototype Functions
 ============================================================================
 */

/*******************************************
*			  I N C L U D E 			   *			
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <errno.h>

#include "drv_BBB_gpio.h"

/*******************************************
*               D E F I N E                *			
********************************************/

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *			
********************************************/


/*******************************************
*	        F U N C T I O N S   	       *			
********************************************/

/*
 ============================================
 Function     : beh_BBB_gpio_init
 Parameter    : 
 Return Value : 
 Description  :
 ============================================
 */
void beh_BBB_gpio_init(void);

/*
 ============================================
 Function     : beh_BBB_gpio_conf_dir
 Parameter    : 
 Return Value : 
 Description  :
 ============================================
*/
void beh_BBB_gpio_conf_dir(GPIO_Pins ePin, unsigned char u8Dir);

/*
 ============================================
 Function     : beh_BBB_gpio_WritePin
 Parameter    : 
 Return Value : 
 Description  :
 ============================================
*/
void beh_BBB_gpio_WritePin(GPIO_Pins ePin, unsigned char u8Val );


/*
 ============================================
 Function     : beh_BBB_gpio_Read_DataBus() 
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
unsigned long beh_BBB_gpio_Read_DataBus( GPIO_Pins ePin, unsigned char u8Number);

/*
 ============================================
 Function     : beh_BBB_gpio_ReadPin
 Parameter    : 
 Return Value : 
 Description  :
 ============================================
*/
 unsigned char beh_BBB_gpio_ReadPin(GPIO_Pins ePin);
 
  /*
 ============================================
 Function     : beh_BBB_gpio_TogglePin
 Parameter    : 
 Return Value : 
 Description  :
 ============================================
 */
 void beh_BBB_gpio_TogglePin(GPIO_Pins ePin);

 /*
 ============================================
 Function     :  beh_BBB_gpio_toggle() 
 Parameter    : 
 Return Value : 
 Description  :
 ============================================
 */
void beh_BBB_gpio_Write_All_GPIO(unsigned char Port);

 /*
 ============================================
 Function     :  beh_BBB_gpio_Conf_ALL_GPIO() 
 Parameter    :
 Return Value :
 Description  :
 ============================================
 */
void beh_BBB_gpio_Conf_ALL_GPIO(GPIO_Pins ePin, unsigned char u8Dir, unsigned char u8Number);

/*
 ============================================
 Function     : beh_BBB_gpio_Write_DataBus_GPIO() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
void beh_BBB_gpio_Write_DataBus_GPIO( GPIO_Pins ePin, unsigned long u32Value, unsigned char u8Number);

