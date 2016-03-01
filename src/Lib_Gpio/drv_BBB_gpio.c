/*
 ============================================================================
 Name        : drv_BBB_gpio.c
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 04/07/2013
 Description : Driver GPIO Lib Declaration Functions 
 ============================================================================
 */

/*******************************************
*			  I N C L U D E 			   *			
********************************************/
#include "drv_BBB_gpio.h"

/*******************************************
*               D E F I N E                *			
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *			
********************************************/
const unsigned long array_start_addr_port[] = 
{
	GPIO0_START_ADDR,
	GPIO1_START_ADDR,
	GPIO2_START_ADDR,
	GPIO3_START_ADDR,
};

const unsigned char array_dr_BBB_gpio_pin_bank[] = 
{
	-1, -1,  1,  1,  1,		// P8_1  -> P8_5
	 1,  2,  2,  2,  2,		// P8_6  -> P8_10
	 1,  1,  0,  0,  1, 	// P8_11 -> P8_15
	 1,  0,  2,  0,  1, 	// P8_16 -> P8_20
	 1,  1,  1,  1,  1, 	// P8_21 -> P8_25
	 1,  2,  2,  2,  2, 	// P8_26 -> P8_30
	 0,  0,  0,  2,  0, 	// P8_31 -> P9_35
	 2,  2,  2,  2,  2, 	// P8_36 -> P8_40
	 2,  2,  2,  2,  2, 	// P8_41 -> P8_45
	 2,						// P8_46
	-1, -1, -1, -1, -1, 	// P9_1  -> P9_5
	-1, -1, -1, -1, -1, 	// P9_6  -> P9_10
	 0,  1,  0,  1,  1, 	// P9_11 -> P9_15
	 1,  0,  0,  0,  0,		// P9_16 -> P9_20
	 0,  0,  1,  0,  3, 	// P9_21 -> P9_25
	 0,  3,  3,  3,  3, 	// P9_26 -> P9_30
	 3, -1, -1, -1, -1, 	// P9_31 -> P9_35
	-1, -1, -1, -1, -1, 	// P9_36 -> P9_40
	 3,  0, -1, -1, -1, 	// P9_41 -> P9_45
	-1						// P9_46
};

const unsigned char array_dr_BBB_gpio_pin_id[] = 
{
	-1, -1,  6,  7,  2,		// P8_1  -> P8_5
	 3,  2,  3,  5,  4,		// P8_6  -> P8_10
	13, 12, 23, 26, 15, 	// P8_11 -> P8_15
	14, 27,  1, 22, 31, 	// P8_16 -> P8_20
	30,  5,  4,  1,  0, 	// P8_21 -> P8_25
	29, 22, 24, 23, 25, 	// P8_26 -> P8_30
	10, 11,  9, 17,  8, 	// P8_31 -> P9_35
	16, 14, 15, 12, 13, 	// P8_36 -> P8_40
	10, 11,  8,  9,  6, 	// P8_41 -> P8_45
	 7,						// P8_46
	-1, -1, -1, -1, -1, 	// P9_1  -> P9_5
	-1, -1, -1, -1, -1,		// P9_6  -> P9_10
	30, 28, 31, 18, 16, 	// P9_11 -> P9_15
	19,  5,  4, 13, 12, 	// P9_16 -> P9_20
	 3,  2, 17, 15, 21, 	// P9_21 -> P9_25
	14, 19, 17, 15, 16, 	// P9_26 -> P9_30
	14, -1, -1, -1, -1, 	// P9_31 -> P9_35
	-1, -1, -1, -1, -1, 	// P9_36 -> P9_40
	20,  7, -1, -1, -1, 	// P9_41 -> P9_45
	-1						// P9_46
};

const unsigned long array_dr_BBB_gpio_pin_offset[] =
{
	0x0000, 0x0000, 0x0818, 0x081C, 0x0808,	// P8_1  -> P8_5
	0x080C, 0x0890, 0x0894, 0x089C, 0x0898,	// P8_6  -> P8_10
	0x0834, 0x0830, 0x0824, 0x0828, 0x083C,	// P8_11 -> P8_15
	0x0838, 0x082C, 0x088C, 0x0820, 0x0884,	// P8_16 -> P8_20
	0x0880, 0x0814, 0x0810, 0x0804, 0x0800,	// P8_21 -> P8_25
	0x087C, 0x08E0, 0x08E8, 0x08E4, 0x08EC,	// P8_26 -> P8_30
	0x08D8, 0x08DC, 0x08D4, 0x08CC, 0x08D0,	// P8_31 -> P8_35
	0x08C8, 0x08C0, 0x08C4, 0x08B8, 0x08BC,	// P8_36 -> P8_40
	0x08B0, 0x08B4, 0x08A8, 0x08AC, 0x08A0,	// P8_41 -> P8_45
	0x08A4,					// P8_46
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	// P9_1  -> P9_5
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	// P9_6  -> P9_10
	0x0870, 0x0878, 0x0874, 0x0848, 0x0840,	// P9_11 -> P9_15
	0x084C, 0x095C, 0x0958, 0x097C, 0x0978,	// P9_16 -> P9_20
	0x0954, 0x0950, 0x0844, 0x0984, 0x09AC,	// P9_21 -> P9_25
	0x0980, 0x09A4, 0x099C, 0x0994, 0x0998,	// P9_26 -> P9_30
	0x0990, 0x0000, 0x0000, 0x0000, 0x0000,	// P9_31 -> P9_35
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	// P9_36 -> P9_40
	0x09A8, 0x0964, 0x0000, 0x0000, 0x0000,	// P9_41 -> P9_45
	0x0000					// P9_46
};

volatile void *control_module = NULL;
bb_gpio_pin *pPin;

bb_gpio_port * iAdresse_AdressBus = NULL;
bb_gpio_port * iAdresse_DataBus = NULL; 
/*
	#define ADRESS_ADRESSBUS	0x1B058
	#define ADRESS_DATABUS		0x1B038   // 0x12038
#else
	#define ADRESS_ADRESSBUS	77912
	#define ADRESS_DATABUS	    77880
*/

unsigned char u8FlagConfAdressBus = ADRESS_BUS_NO_CONFIG;


/*******************************************
*	        F U N C T I O N S   	       *			
********************************************/

/*
 ============================================
 Function     : drv_BBB_gpio_readdata() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
unsigned char drv_BBB_gpio_readdata(GPIO_Pins ePin){
	
	// Variables Declarations
	unsigned char u8Port, u8PinGPIO;
	unsigned long u32PinOffset;

	// Get Port of the Pin
	u8Port = array_dr_BBB_gpio_pin_bank[ePin];
	
	// Get Pin GPIO of the Pin
	u8PinGPIO = array_dr_BBB_gpio_pin_id[ePin];
	
	// Get Offset Control Value
	u32PinOffset = array_dr_BBB_gpio_pin_offset[ePin];
	
	// Set Pin struct
	pPin->port 			= ports[u8Port];
	pPin->pin_num		= u8PinGPIO;
	pPin->control_offset = u32PinOffset;
	
	return   ((*(pPin->port->datain_reg) & (1 << pPin->pin_num))  >> pPin->pin_num);
}

/*
 ============================================
 Function     : drv_BBB_gpio_clrdata() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
void drv_BBB_gpio_clrdata(GPIO_Pins ePin){
	
	// Variables Declarations
	unsigned char u8Port, u8PinGPIO;
	unsigned long u32PinOffset;

	// Get Port of the Pin
	u8Port = array_dr_BBB_gpio_pin_bank[ePin];
	
	// Get Pin GPIO of the Pin
	u8PinGPIO = array_dr_BBB_gpio_pin_id[ePin];
	
	// Get Offset Control Value
	u32PinOffset = array_dr_BBB_gpio_pin_offset[ePin];
	
	// Set Pin struct
	pPin->port 			= ports[u8Port];
	pPin->pin_num		= u8PinGPIO;
	pPin->control_offset = u32PinOffset;
	
	*(pPin->port->clrdataout_reg) = (1 << pPin->pin_num);
	
}

/*
 ============================================
 Function     : drv_BBB_gpio_setdata() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
void drv_BBB_gpio_setdata(GPIO_Pins ePin){
	
	// Variables Declarations
	unsigned char u8Port, u8PinGPIO;
	unsigned long u32PinOffset;
	
	// Get Port of the Pin
	u8Port = array_dr_BBB_gpio_pin_bank[ePin];

	// Get Pin GPIO of the Pin
	u8PinGPIO = array_dr_BBB_gpio_pin_id[ePin];

	// Get Offset Control Value
	u32PinOffset = array_dr_BBB_gpio_pin_offset[ePin];

	
	// Set Pin struct
	pPin->port 			= ports[u8Port];
	pPin->pin_num		= u8PinGPIO;
	pPin->control_offset = u32PinOffset;
	
	*(pPin->port->setdataout_reg) = (1 << pPin->pin_num);
}

/*
 ============================================
 Function     : setup() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
bb_gpio_pin * drv_BBB_gpio_init() {
	int i;
	int fd = open("/dev/mem", O_RDWR);
	
	pPin = malloc(sizeof(bb_gpio_pin));

	for(i=0; i<4; i++) {
		ports[i] = malloc(sizeof(bb_gpio_port));

		ports[i]->gpio_addr = mmap(0, GPIO_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, array_start_addr_port[i]);

		if(ports[i]->gpio_addr == MAP_FAILED) {
			perror("Unable to map GPIO");
			exit(1);
		}

		ports[i]->oe_reg         = ports[i]->gpio_addr + GPIO_OE;
		ports[i]->setdataout_reg = ports[i]->gpio_addr + GPIO_SETDATAOUT;
		ports[i]->clrdataout_reg = ports[i]->gpio_addr + GPIO_CLEARDATAOUT;
		ports[i]->datain_reg     = ports[i]->gpio_addr + GPIO_DATAIN;
		ports[i]->dataout_reg    = ports[i]->gpio_addr + GPIO_DATAOUT;
	}

	control_module = mmap(0, CONTROL_MODULE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CONTROL_MODULE_START_ADDR);

	if(control_module == MAP_FAILED) {
		perror("Unable to map Control Module");
		exit(1);
	}

	close(fd);
	
	return pPin;
}

/*
 ============================================
 Function     : drv_BBB_gpio_conf_pull() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
void drv_BBB_gpio_conf_pull( GPIO_Pins ePin, unsigned char u8Pull){

	volatile unsigned int *control_reg  = control_module + (array_dr_BBB_gpio_pin_offset[ePin]);
	
	switch(u8Pull) {
		case NO_PULL:
			*control_reg = PIN_MODE7 | PIN_PULLUD_DISABLED | PIN_RX_DISABLED;
			break;
		case PULL_UP_EN:
			*control_reg = PIN_MODE7 | PIN_PULLUD_ENABLED | PIN_PULLUP | PIN_RX_DISABLED;
			break;
		case PULL_DOWN_EN:
			*control_reg = PIN_MODE7 | PIN_PULLUD_ENABLED | PIN_PULLDOWN | PIN_RX_DISABLED;
			break;
		default:
			break;
	}	
}

/*
 ============================================
 Function     : configure_pin() 
 Parameter    : pin, bb_gpio_pin pointer
 Return Value : void
 Description  :
 ============================================
 */
void drv_BBB_gpio_conf_pin( GPIO_Pins ePin, unsigned char u8Dir){

	// Variables Declarations
	unsigned char u8Port, u8PinGPIO;
	unsigned long u32PinOffset;
	
	// Get Port of the Pin
	u8Port = array_dr_BBB_gpio_pin_bank[ePin];
	if(u8Port == -1){
		printf("\n Error: No Valid Pin\n ");
	}
	//printf("\n u8Port : %i", u8Port);
	
	// Get Pin GPIO of the Pin
	u8PinGPIO = array_dr_BBB_gpio_pin_id[ePin];
	if(u8PinGPIO == -1){
		printf("\n Error: No Valid Pin\n ");
	}
	//printf("\n u8PinGPIO : %i", u8PinGPIO);
	
	// Get Offset Control Value
	u32PinOffset = array_dr_BBB_gpio_pin_offset[ePin];
	if(u32PinOffset == -1){
		printf("\n Error: No Valid Pin\n ");
	}
	//printf("\n u32PinOffset : %X\n", u32PinOffset);
	
	// Set Pin struct
	pPin->port 			= ports[u8Port];
	pPin->pin_num		= u8PinGPIO;
	pPin->control_offset = u32PinOffset;
	volatile unsigned int *control_reg  = control_module + pPin->control_offset;
	
	switch(u8Dir) {
		case OUTPUT:
			*(pPin->port->oe_reg) &= ~(1 << pPin->pin_num); // 0 in OE is output enable
			//*control_reg = PIN_MODE7 | PIN_PULLUD_DISABLED | PIN_RX_DISABLED;
			break;
		case INPUT:
			*(pPin->port->oe_reg) |= (1 << pPin->pin_num); // 1 in OE is input
			//*control_reg = PIN_MODE7 | PIN_PULLUD_DISABLED | PIN_RX_ENABLED;
			break;
		case INPUT_PULL_UP_EN:
			*(pPin->port->oe_reg) |= (1 << pPin->pin_num); // 1 in OE is input
			*control_reg = PIN_MODE7 | PIN_PULLUD_ENABLED | PIN_PULLUP | PIN_RX_ENABLED;
			break;
		case INPUT_PULL_DOWN_EN:
			*(pPin->port->oe_reg) |= (1 << pPin->pin_num); // 1 in OE is input
			*control_reg = PIN_MODE7 | PIN_PULLUD_ENABLED | PIN_PULLDOWN | PIN_RX_ENABLED;
			break;
		default:
			break;
	}	
}

/*
 ============================================
 Function     : drv_BBB_gpio_Conf_ALL_GPIO() 
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
 void drv_BBB_gpio_Conf_ALL_GPIO( GPIO_Pins ePin, unsigned char u8Dir, unsigned char u8Number){

	// Variables Declarations
	unsigned char u8Port, u8PinGPIO;
	unsigned long u32PinOffset;
	int i;
	unsigned long int lVal;
	volatile unsigned int *control_reg;
	
	// Init Value
	
	// Get Port of the Pin
	u8Port = array_dr_BBB_gpio_pin_bank[ePin];
	if(u8Port == -1){
		printf("\n Error: No Valid Pin\n ");
	}
	//printf("\n u8Port : %i", u8Port);
	
	// Get Pin GPIO of the Pin
	u8PinGPIO = array_dr_BBB_gpio_pin_id[ePin];
	if(u8PinGPIO == -1){
		printf("\n Error: No Valid Pin\n ");
	}
	//printf("\n u8PinGPIO : %i", u8PinGPIO);
	
	// Get Offset Control Value
	u32PinOffset = array_dr_BBB_gpio_pin_offset[ePin];
	if(u32PinOffset == -1){
		printf("\n Error: No Valid Pin\n ");
	}
	//printf("\n u32PinOffset : %X\n", u32PinOffset);
	
	// Set Pin struct
	pPin->port 			= ports[u8Port];
	pPin->pin_num		= u8PinGPIO;
	pPin->control_offset = u32PinOffset;
	
	lVal = (0xFFFFFFFF  << (u8Number));

	// Init Pointer control Module
	control_reg  = control_module + pPin->control_offset;
	 
	 // Init Address Bus Data and Bus Address
	if(u8FlagConfAdressBus ==  ADRESS_BUS_NO_CONFIG){
		int iAdress = (int)pPin->port;
		iAdresse_DataBus   = (bb_gpio_port *)((iAdress & 0xFF000) | 0x38);
		iAdresse_AdressBus = (bb_gpio_port *)((iAdress & 0xFF000) | 0x58);	
		u8FlagConfAdressBus = ADRESS_BUS_CONFIG_OK;
	}
	
	switch(u8Dir) {
		case OUTPUT:
			lVal = (lVal <<  pPin->pin_num) | (lVal >> (32 -  pPin->pin_num));
			*(pPin->port->oe_reg) &= lVal ;

			// Mux Mode
			for( i= 0; i < u8Number ; i++){
				*control_reg = PIN_MODE7 | PIN_PULLUD_ENABLED | PIN_PULLUP | PIN_RX_DISABLED;
				control_reg  = control_reg + 4;
			}
			
		break;
			
		case INPUT:
			lVal = ~(lVal <<  pPin->pin_num) | (lVal >> (32 -  pPin->pin_num));
			*(pPin->port->oe_reg) |= lVal ;

			// Mux Mode
			for( i= 0; i < u8Number ; i++){
				*control_reg = PIN_MODE7 | PIN_PULLUD_DISABLED | PIN_RX_DISABLED;
				control_reg  = control_reg + 4;
			}
			
		break;
		
		case INPUT_PULL_UP_EN:
			lVal = ~(lVal <<  pPin->pin_num) | (lVal >> (32 -  pPin->pin_num));
			*(pPin->port->oe_reg) |= lVal ;

			// Mux Mode
			for( i= 0; i < u8Number ; i++){
				*control_reg = PIN_MODE7 | PIN_PULLUD_ENABLED | PIN_PULLUP | PIN_RX_ENABLED;
				control_reg  = control_reg + 4;
			}
			
		break;
		
		case INPUT_PULL_DOWN_EN:
			lVal = ~(lVal <<  pPin->pin_num) | (lVal >> (32 -  pPin->pin_num));
			*(pPin->port->oe_reg) |= lVal ;
			
			// Mux Mode
			for( i= 0; i < u8Number ; i++){
				*control_reg = PIN_MODE7 | PIN_PULLUD_ENABLED | PIN_PULLDOWN | PIN_RX_ENABLED;
				control_reg  = control_reg + 4;
			}
		break;
		
		default:
			break;
	}
}
 
 /*
 ============================================
 Function     : drv_Conf_DataBus_OUTPUT() 
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
void drv_Conf_DataBus_OUTPUT(void){
	
	pPin->port = (bb_gpio_port *)iAdresse_DataBus; //ADRESS_DATABUS;
   *(pPin->port->oe_reg) &= 0xFFF00FFF ;
   	
}

 /*
 ============================================
 Function     : drv_Conf_DataBus_INPUT() 
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
void drv_Conf_DataBus_INPUT(void){
	
	pPin->port = (bb_gpio_port *) iAdresse_DataBus; // ADRESS_DATABUS;
	*(pPin->port->oe_reg) |=  0x000FF000;
}

/*
 ============================================
 Function     : drv_BBB_gpio_Write_DataBus_GPIO() 
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
void drv_BBB_gpio_Write_DataBus_GPIO( GPIO_Pins ePin, unsigned long u32Value, unsigned char u8Number){

	// Variables Declarations
	unsigned char u8Port, u8PinGPIO;
	unsigned long u32PinOffset;
	unsigned long int lVal;
	
	
	// Get Port of the Pin
	u8Port = array_dr_BBB_gpio_pin_bank[ePin];
	if(u8Port == -1){
		printf("\n Error: No Valid Pin\n ");
	}
	
	// Get Pin GPIO of the Pin
	u8PinGPIO = array_dr_BBB_gpio_pin_id[ePin];
	if(u8PinGPIO == -1){
		printf("\n Error: No Valid Pin\n ");
	}
	
	// Get Offset Control Value
	u32PinOffset = array_dr_BBB_gpio_pin_offset[ePin];
	if(u32PinOffset == -1){
		printf("\n Error: No Valid Pin\n ");
	}
	//printf("\n u32PinOffset : %X\n", u32PinOffset);
	
	// Set Pin struct
	pPin->port 			= ports[u8Port];
	pPin->pin_num		= u8PinGPIO;
	pPin->control_offset = u32PinOffset;
	
	// Init Value
	lVal = (0xFFFFFFFF  << (u8Number));
	
	//printf("\n u32Value 0: %X\n", u32Value);
	
	unsigned long int s = ~(0xFFFFFFFF  << pPin->pin_num) ;
	
	lVal = (lVal << pPin->pin_num)  | s;
	//printf("\n lVal1 : %X\n", lVal);
	
	// Ecriture des 1
	u32Value = ( u32Value << pPin->pin_num) ;
	//printf("\n u32Value 1: %X\n", u32Value);


	// Ecriture des 0
	//printf("\n *(pPin->port->dataout_reg) : %X\n", *(pPin->port->dataout_reg));
	*(pPin->port->dataout_reg) = *(pPin->port->dataout_reg) & lVal;
	//printf("\n *(pPin->port->dataout_reg) 1: %X\n", *(pPin->port->dataout_reg));
	
	// Ecriture des 1
	//printf("\n *(pPin->port->dataout_reg) : %X\n", *(pPin->port->dataout_reg));
	*(pPin->port->dataout_reg) = *(pPin->port->dataout_reg) | u32Value;
	//printf("\n *(pPin->port->dataout_reg) 1: %X\n", *(pPin->port->dataout_reg));
	
}

/*
 ============================================
 Function     : drv_Write_DataBus() 
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
void drv_Write_DataBus( unsigned long int lValue){

	pPin->port = (bb_gpio_port *)iAdresse_DataBus; //iAdresse_DataBus;	
	*(pPin->port->dataout_reg) = lValue;
 }
 
/*
 ============================================
 Function     : drv_Write_AdressBus() 
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
void drv_Write_AdressBus(unsigned long u32Value){
 
	pPin->port 			= (bb_gpio_port *)iAdresse_AdressBus; //iAdresse_AdressBus; //  0x12058
	*(pPin->port->dataout_reg) =  (*(pPin->port->dataout_reg) & 0xFFFFFFC1)  |(u32Value << 1);	
}

/*
 ============================================
 Function     : drv_BBB_gpio_Write_DataBus_GPIO() 
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
 unsigned long drv_BBB_gpio_Read_DataBus( GPIO_Pins ePin, unsigned char u8Number){

	// Variables Declarations
	unsigned char u8Port, u8PinGPIO;
	unsigned long u32PinOffset;
	unsigned long int lVal;
	
	
	// Get Port of the Pin
	u8Port = array_dr_BBB_gpio_pin_bank[ePin];
	if(u8Port == -1){
		printf("\n Error: No Valid Pin\n ");
	}
	
	// Get Pin GPIO of the Pin
	u8PinGPIO = array_dr_BBB_gpio_pin_id[ePin];
	if(u8PinGPIO == -1){
		printf("\n Error: No Valid Pin\n ");
	}
	
	// Get Offset Control Value
	u32PinOffset = array_dr_BBB_gpio_pin_offset[ePin];
	if(u32PinOffset == -1){
		printf("\n Error: No Valid Pin\n ");
	}
	//printf("\n u32PinOffset : %X\n", u32PinOffset);
	
	// Set Pin struct
	pPin->port 			= ports[u8Port];
	pPin->pin_num		= u8PinGPIO;
	pPin->control_offset = u32PinOffset;
	
		
	// Init Value
	lVal = ~(0xFFFFFFFF  << (u8Number));	
	lVal =  (lVal << pPin->pin_num);
	
	//printf("\n lVal  Masque: %X\n", lVal);
	
	// Lecture
	//printf("\n datain_reg: %X\n", (*(pPin->port->datain_reg) & (lVal)));
	 return (*(pPin->port->datain_reg) & (lVal));
	 
}

/*
 ============================================
 Function     : drv_Read_DataBus() 
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
unsigned char drv_Read_DataBus(  unsigned long int lMask){

	pPin->port =  (bb_gpio_port *)iAdresse_DataBus; //iAdresse_DataBus;	//0x13038;
	
	if( ((*(pPin->port->datain_reg) & (lMask)) >> 0xC) != 0){
		return 1;
	}else{
		return 0; 
	}
}

/*
 ============================================
 Function     : teardown() 
 Parameter    : void
 Return Value : void
 Description  :
 ============================================
 */
void teardown() {
	int i;
	
	for(i=0; i<4; i++) {
		free(ports[i]);
	}
}


