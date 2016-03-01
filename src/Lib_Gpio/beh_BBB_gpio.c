/*
 ============================================================================
 Name        : beh_BBB_gpio.c
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 04/07/2013
 Description : Behaviour GPIO Lib Declaration Functions
 ============================================================================
 */

/*******************************************
*			  I N C L U D E 			   *			
********************************************/
#include "beh_BBB_gpio.h"

/*******************************************
*	 C O N S T A N T E  &  T Y P E D E F   *			
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *			
********************************************/
bb_gpio_pin *pPin;
/*******************************************
*	        F U N C T I O N S   	       *			
********************************************/

  /*
 ============================================
 Function     : beh_BBB_gpio_Conf_ALL_GPIO() 
 Parameter    : Pin name first Pin, Direction to set, number of pin to set 
 Return Value : void
 Description  :
 ============================================
 */
void beh_BBB_gpio_Conf_ALL_GPIO(GPIO_Pins ePin, unsigned char u8Dir, unsigned char u8Number){

	drv_BBB_gpio_Conf_ALL_GPIO( ePin, u8Dir, u8Number);
	
} 

/*
 ============================================
 Function     : beh_BBB_gpio_conf_dir
 Parameter    : Pin name first Pin, Direction to set
 Return Value : 
 Description  :
 ============================================
 */
void beh_BBB_gpio_conf_dir(GPIO_Pins ePin, unsigned char u8Dir){

	drv_BBB_gpio_conf_pin( ePin, u8Dir);
}

/*
 ============================================
 Function     : beh_BBB_gpio_init
 Parameter    : 
 Return Value : 
 Description  :
 ============================================
 */
void beh_BBB_gpio_init(void){
	
	// Init Driver BBB GPIO
	pPin = drv_BBB_gpio_init();
}

/*
 ============================================
 Function     : beh_BBB_gpio_Read_DataBus() 
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
unsigned long beh_BBB_gpio_Read_DataBus( GPIO_Pins ePin, unsigned char u8Number){

	return drv_BBB_gpio_Read_DataBus( ePin, u8Number);

}

 /*
 ============================================
 Function     : beh_BBB_gpio_ReadPin
 Parameter    : Pin name
 Return Value : value of the pin
 Description  :
 ============================================
 */
unsigned char beh_BBB_gpio_ReadPin(GPIO_Pins ePin){
	return drv_BBB_gpio_readdata(ePin);
 }
 
 /*
 ============================================
 Function     : beh_BBB_gpio_TogglePin
 Parameter    : Pin name
 Return Value : 
 Description  :
 ============================================
 */
 /*
 void beh_BBB_gpio_TogglePin(GPIO_Pins ePin){
	
	drv_BBB_gpio_toggle(ePin);
 }
 */
 
/*
 ============================================
 Function     : beh_BBB_gpio_Write_All_GPIO() 
 Parameter    : Port name
 Return Value : void
 Description  :
 ============================================
 */
/*
 void beh_BBB_gpio_Write_All_GPIO(unsigned char Port){

	drv_BBB_gpio_Write_All_GPIO(Port);
}
 */
 
/*
 ============================================
 Function     : beh_BBB_gpio_Write_DataBus_GPIO() 
 Parameter    : Pin name first Pin, Data to set, number of pin to set 
 Return Value : void
 Description  :
 ============================================
 */
void beh_BBB_gpio_Write_DataBus_GPIO( GPIO_Pins ePin, unsigned long u32Value, unsigned char u8Number){

	drv_BBB_gpio_Write_DataBus_GPIO( ePin, u32Value, u8Number);

}

 /*
 ============================================
 Function     : beh_BBB_gpio_WritePin
 Parameter    : Pin name, Value to set on the pin
 Return Value : 
 Description  :
 ============================================
 */
 void beh_BBB_gpio_WritePin(GPIO_Pins ePin, unsigned char u8Val ){
	
	if(u8Val == 0){
		drv_BBB_gpio_clrdata(ePin);
	}else {
		drv_BBB_gpio_setdata(ePin);
	}
 }
 