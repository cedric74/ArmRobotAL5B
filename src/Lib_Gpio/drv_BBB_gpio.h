/*
 ============================================================================
 Name        : drv_BBB_gpio.h
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 04/07/2013
 Description : Driver GPIO Lib Definitions Prototype Functions
 ============================================================================
 */
#ifndef _DRV_BBB_GPIO_H 
#define _DRV_BBB_GPIO_H

/*******************************************
*			  I N C L U D E 			   *			
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <errno.h>
#include <unistd.h>

/*******************************************
*               D E F I N E                *			
********************************************/
#define CONTROL_MODULE_START_ADDR	0x44E10000
#define CONTROL_MODULE_END_ADDR		0x44E11FFF
#define CONTROL_MODULE_SIZE	(CONTROL_MODULE_END_ADDR - CONTROL_MODULE_START_ADDR)

#define PIN_RX_DISABLED 0
#define PIN_RX_ENABLED  (1<<5)

#define PIN_PULLUD_DISABLED 0
#define PIN_PULLUD_ENABLED (1<<3)

#define PIN_PULLUP (1<<4)
#define PIN_PULLDOWN 0

#define PIN_SLEW_FAST 0
#define PIN_SLEW_SLOW (1<<6)

#define PIN_MODE0 0
#define PIN_MODE1 1 
#define PIN_MODE2 2 
#define PIN_MODE3 3 
#define PIN_MODE4 4 
#define PIN_MODE5 5 
#define PIN_MODE6 6 
#define PIN_MODE7 7 

#define GPIO_SIZE			0x2000
#define GPIO0_START_ADDR 	0x44E07000
#define GPIO1_START_ADDR 	0x4804C000
#define GPIO2_START_ADDR 	0x481AC000
#define GPIO3_START_ADDR 	0x481AE000

#define GPIO_OE 			0x134
#define GPIO_SETDATAOUT 	0x194
#define GPIO_CLEARDATAOUT 	0x190
#define GPIO_DATAIN			0x138
#define GPIO_DATAOUT		0x13C

#define	OUTPUT				0
#define	INPUT				1	
#define INPUT_PULL_UP_EN	2
#define	INPUT_PULL_DOWN_EN	3


#define	NO_PULL				0
#define	PULL_UP_EN			1
#define PULL_DOWN_EN		2	

#define GPIO0 				0
#define GPIO1 				1
#define GPIO2				2
#define GPIO3 				3

// Flag Config Adress Bus
#define ADRESS_BUS_NO_CONFIG	0
#define ADRESS_BUS_CONFIG_OK	1

#define HIGH				1
#define LOW					0


/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *			
********************************************/
typedef struct {
	volatile void *gpio_addr;
	volatile unsigned int *oe_reg;
	volatile unsigned int *setdataout_reg;
	volatile unsigned int *clrdataout_reg;
	volatile unsigned int *datain_reg;
	volatile unsigned int *dataout_reg;
} bb_gpio_port;

typedef struct {
	bb_gpio_port *port;
	unsigned char pin_num;
	unsigned short control_offset;
} bb_gpio_pin;

typedef enum{
		P8_1,  P8_2,  P8_3,  P8_4,  P8_5,
		P8_6,  P8_7,  P8_8,  P8_9,  P8_10,
		P8_11, P8_12, P8_13, P8_14, P8_15,
		P8_16, P8_17, P8_18, P8_19, P8_20,
		P8_21, P8_22, P8_23, P8_24, P8_25,
		P8_26, P8_27, P8_28, P8_29, P8_30,
		P8_31, P8_32, P8_33, P8_34, P8_35,
		P8_36, P8_37, P8_38, P8_39, P8_40,
		P8_41, P8_42, P8_43, P8_44, P8_45,
		P8_46,
		P9_1,  P9_2,  P9_3,  P9_4,  P9_5,
		P9_6,  P9_7,  P9_8,  P9_9,  P9_10,
		P9_11, P9_12, P9_13, P9_14, P9_15,
		P9_16, P9_17, P9_18, P9_19, P9_20,
		P9_21, P9_22, P9_23, P9_24, P9_25,
		P9_26, P9_27, P9_28, P9_29, P9_30,
		P9_31, P9_32, P9_33, P9_34, P9_35,
		P9_36, P9_37, P9_38, P9_39, P9_40,
		P9_41, P9_42, P9_43, P9_44, P9_45,
		P9_46
} GPIO_Pins;
	
/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *			
********************************************/
bb_gpio_port *ports[4];

/*******************************************
*	        F U N C T I O N S   	       *			
********************************************/
void drv_Conf_DataBus_OUTPUT(void);
void drv_Conf_DataBus_INPUT(void);
void drv_Write_DataBus( unsigned long int lValue);

unsigned char drv_Read_DataBus(  unsigned long int lMask);
void drv_Write_AdressBus(unsigned long u32Value);
void drv_BBB_gpio_conf_pull( GPIO_Pins ePin, unsigned char u8Pull);

/*
 ============================================
 Function     : configure_pin() 
 Parameter    : pin, bb_gpio_pin pointer
 Return Value : void
 Description  :
 ============================================
 */
void drv_BBB_gpio_conf_pin( GPIO_Pins ePin, unsigned char u8Dir);

/*
 ============================================
 Function     : drv_BBB_gpio_Write_DataBus_GPIO() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
void drv_BBB_gpio_Write_DataBus_GPIO( GPIO_Pins ePin, unsigned long u32Value, unsigned char u8Number);

/*
 ============================================
 Function     : drv_BBB_gpio_toggle() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
//unsigned long int drv_BBB_gpio_Write_All_GPIO(unsigned char Port);

/*
 ============================================
 Function     : drv_BBB_gpio_toggle() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
void drv_BBB_gpio_toggle(GPIO_Pins ePin);

/*
 ============================================
 Function     : drv_BBB_gpio_readdata() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
unsigned char drv_BBB_gpio_readdata(GPIO_Pins ePin);

/*
 ============================================
 Function     : drv_BBB_gpio_clrdata() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
void drv_BBB_gpio_clrdata(GPIO_Pins ePin);

/*
 ============================================
 Function     : drv_BBB_gpio_setdata() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
void drv_BBB_gpio_setdata(GPIO_Pins ePin);

/*
 ============================================
 Function     : drv_BBB_gpio_init() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
bb_gpio_pin * drv_BBB_gpio_init();

/*
 ============================================
 Function     : drv_BBB_gpio_Conf_ALL_GPIO() 
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
void drv_BBB_gpio_Conf_ALL_GPIO( GPIO_Pins ePin, unsigned char u8Dir, unsigned char u8Number);

/*
 ============================================
 Function     : drv_BBB_gpio_Read_DataBus() 
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
unsigned long drv_BBB_gpio_Read_DataBus( GPIO_Pins ePin, unsigned char u8Number);

/*
 ============================================
 Function     : teardown() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
void teardown();


#endif

