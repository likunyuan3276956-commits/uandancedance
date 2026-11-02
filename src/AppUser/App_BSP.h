/******************************************************************************************
//FileName 			:
//ProjectName  	:
//MCU 	       	:
//Security			:
//Fosc					:
//PLL INPUT  		:
//PLL OUTPUT 		:
//Fcpu					:
//Watch_Dog			:
//LVD						:
//Writen by 		:
//Date      		:

SDK Version		: AT32F415_Firmware_Library_V2.0.6

AT32F415RBT7   LQFP64 10x10mm 128KFlash
AT32F415RCT7   LQFP64 10x10mm 256KFlash

Version	V1.00	: 
(1)20240326		: First Release Version(BaseOn MiMi-KB V3.02)
Version	V1.01	: 
(1)20240617		: App Param Config
Version	V1.02	: 
(1)20240715		: Enter OTA By App
Version	V1.03	: 
(1)20240716		: App Param Config Bug
Version	V1.04	: 
(1)20240718		: Switch To RGBx25
Version	V1.05	: 
(1)20240719		: Mult Key Issue
Version	V1.06	: 
(1)20240720		: RAW Date Fort App Seni Config 
Version	V1.07	: 
(1)20240727		: Add 2P Mode
Version	V1.08	: 
(1)20240727		: Ex ADC INA219
Version	V1.09	: 
(1)20240727		: RAW ADC Data Continuous update
Version	V1.10	: 
(1)20240830		: Brightness For RGB
Version	V1.11	: 
(1)20240904		: Change RGB Deflaut Color
Version	V1.12	: 
(1)20240914		: Change RGB Deflaut Color 1&3=Green,2&4=Red
Version	V1.13	: 
(1)20240914		: Change RGB Deflaut Color 1&3=Blue,2&4=Red
Version	V1.14	: 
(1)20240921		: Production ID and FW Version
Version	V1.15	: 
(1)20240930		: Power On Sensor Scan
Version	V1.16	: 
(1)20241010		: Brightness For RGB

Version	V2.00	: 
(1)20241015		: Support New 9KEY PCBA
Version	V2.01	: 
(1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
Version	V2.02	: 
(1)20251007		: Support New 9KEY PCBA SW1&SW2 LED
Version	V2.03	: 
(1)20251208		: Change Defalut LED Color
Version	V2.04	: 
(1)20251209		: HID Mode ISSUE
Version	V2.05	: 
(1)20260103		: HID/KB Mode Latency ISSUE
Version	V2.06	: 
(1)20260112		: RGB Issue

Version	V2.11	: 
(1)20260614		: 5Key & 4Key macro £¨BaseOn V2.06)
(2)20260614		: 2P Key Mapping
(3)20260614		: 1,2P Select By Firmware
(4)20260614		: RGB Issure
(5)20260614		: App Set Param For 5Keys
Version	V2.12	: 
(1)20260629		: HID/KB Mode  Switch

******************************************************************************************/


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#ifndef __APP_BSP_H__
#define __APP_BSP_H__


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#define 	FW_VERSION_MAJOR       0x02
#define 	FW_VERSION_MINOR       12

#define 	HW_VERSION			       0x13


//============================================================================= 
//Version	V1.14	: (1)20240921		: Production ID and FW Version
#define 	PRODUCTION_ID_ADX	       0xA1   //ADX
#define 	PRODUCTION_ID_DDR	       0xA2   //DDR (Yuanpad)
#define 	PRODUCTION_ID_Zer	       0xA3   //ÖÐ¶þ(Laverita)
#define 	PRODUCTION_ID_YJI	       0xA4   //Òô»÷

#define 	PRODUCTION_ID			       PRODUCTION_ID_DDR
//============================================================================= 


#define LED_TYPE_RGB	                      1 //Version	V1.04	: (1)20240718		: Switch To RGBx25




#define DEFAULT_MODE              ( USBD_MODE_1PS | USBD_MODE_KBS )     // USBD_MODE_2PS  USBD_MODE_1PS | USBD_MODE_KBS   //Version	V2.06	: (1)20260112		: RGB Issue


//Version	V2.11	: (1)20260614		: 5Key & 4Key macro £¨BaseOn V2.06)
#define SENS_MODE_4KEY              4 
#define SENS_MODE_5KEY              5 
#define DEFAULT_KEY_NUMBER          SENS_MODE_5KEY    

#define DEFAULT_1P2P                USBD_MODE_2PS     //Version	V2.12	: (1)20260629		: HID/KB Mode  Switch




//Version	V2.11	: (1)20260614		: 5Key & 4Key macro £¨BaseOn V2.06)
#if (DEFAULT_KEY_NUMBER==SENS_MODE_5KEY)
#define USER_DEFAULT_COLOR_1        USER_COLOR_P
#define USER_DEFAULT_COLOR_2        USER_COLOR_P
#define USER_DEFAULT_COLOR_3        USER_COLOR_Y
#define USER_DEFAULT_COLOR_4        USER_COLOR_B
#define USER_DEFAULT_COLOR_5        USER_COLOR_B
#else
#define USER_DEFAULT_COLOR_1        USER_COLOR_B
#define USER_DEFAULT_COLOR_2        USER_COLOR_P
#define USER_DEFAULT_COLOR_3        USER_COLOR_P
#define USER_DEFAULT_COLOR_4        USER_COLOR_B
#define USER_DEFAULT_COLOR_5        USER_COLOR_B
#endif


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


#ifdef __cplusplus
extern "C" {
#endif

#include "stdio.h"
#include "at32f415.h"

/**
  * this header include define support list:
  * 1. at-start-f415 v1.x board
  * if define AT_START_F415_V1, the header file support at-start-f415 v1.x board
  */

#if !defined (AT_START_F415_V1)
#error "please select first the board at-start device used in your application (in at32f415_board.h file)"
#endif

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


//******************************************************************************
//
//------------- Constant  define    -------------------
//
//******************************************************************************
//============================================================================= 
#define PMCU_SYNC_H					              0xA5                        //
#define PMCU_SYNC_L					              0x5A	                      //
#define SYNC_LEN                          3					                  //
#define HEAD_LEN                          5					                  //
#define DATA_LEN                          5*4*2                       //  //Version	V2.11	: (5)20260614		: App Set Param For 5Keys
#define CRC8_LEN                          1                           //
#define PAKE_LEN                          HEAD_LEN+DATA_LEN+CRC8_LEN  //
#define MAXS_LEN                          SYNC_LEN+PAKE_LEN           //

//============================================================================= 
////Version	V1.01	: (1)20240617		: App Param Config  
#define FLASH_PAGE_SIZE                   2048        // this parameter depends on the specific model of the chip 
#define FLASH_DATA_ADDR_START             0x0800F800  //
#define FLASH_DATA_ADDR_WMODE             FLASH_DATA_ADDR_START+FLASH_PAGE_SIZE*0
#define FLASH_DATA_ADDR_SENSI             FLASH_DATA_ADDR_START+FLASH_PAGE_SIZE*1
#define FLASH_DATA_ADDR_COLOR             FLASH_DATA_ADDR_START+FLASH_PAGE_SIZE*2
#define FLASH_DATA_ADDR_DTICK             FLASH_DATA_ADDR_START+FLASH_PAGE_SIZE*3

#define FLASH_BUFEER_SIZE                 128

//Version	V1.02	: (1)20240715		: Enter OTA By App
#define FLASH_APP_ADDR							      0x08004000  	//User App Start address
#define IAP_CMD_FINISH_FLAG_ADDR          (FLASH_APP_ADDR - 0x800) 
#define IAP_DOWNLOAD_FLAG         	      0x41544B38


//#define USER_FLASH_ADDRESS_START         (0x0800F800)

#define AUTO_SENSI  							        200					  //Version	V1.15	: (1)20240930		: Power On Sensor Scan


#define DEFAULT_SENSI  							      800					  //
#define DEFAULT_DTICK  							      3   					//



//============================================================================= 
//
#define IO_PWM_FREQ       				        16000
#define IO_PWM_MAX_DUTY   					      100
#define IO_PWM_OFF_DUTY 						      0
//============================================================================= 
////Version	V1.04	: (1)20240718		: Switch To RGBx25
#define USER_COLOR_R     						      0x01
#define USER_COLOR_G     						      0x02
#define USER_COLOR_B     						      0x04
#define USER_COLOR_Y     						      USER_COLOR_R|USER_COLOR_G
#define USER_COLOR_P     						      USER_COLOR_R|USER_COLOR_B
#define USER_COLOR_C     						      USER_COLOR_G|USER_COLOR_B
#define USER_COLOR_W     						      USER_COLOR_R|USER_COLOR_G|USER_COLOR_B
      

//******************************************************************************
//
//------------- I/O Defs    -------------------
//
//******************************************************************************

//============================================================================= 
#define	GPIO_CONFIG(PORT,PIN,PREIH,MODE,PULL)	{ gpio_init_type gpio_init_struct;                                      \
                                                crm_periph_clock_enable(PREIH, TRUE);                                 \
                                                gpio_default_para_init(&gpio_init_struct);                            \
                                                gpio_init_struct.gpio_drive_strength  = GPIO_DRIVE_STRENGTH_STRONGER; \
                                                gpio_init_struct.gpio_out_type        = GPIO_OUTPUT_PUSH_PULL;        \
                                                gpio_init_struct.gpio_mode            = MODE;                         \
                                                gpio_init_struct.gpio_pins            = PIN;                          \
                                                gpio_init_struct.gpio_pull            = PULL;                         \
                                                gpio_init(PORT, &gpio_init_struct);}  

#define	GPIO_IO_SET(PORT,PIN)							      PORT->scr  = PIN
#define	GPIO_IO_CLR(PORT,PIN)							      PORT->clr  = PIN
#define GPIO_IO_TOGGLE(PORT,PIN)					      PORT->odt ^= PIN
#define	GPIO_IO_RDV(PORT,PIN)							      gpio_input_data_bit_read(PORT, PIN)

//============================================================================= IO Define For SWD
#define	IO_JLINK_SWC_OUTPUT()							GPIO_CONFIG(GPIOA,	PIN_14,	CRM_GPIOA_PERIPH_CLOCK,	GPIO_MODE_OUTPUT, GPIO_PULL_NONE)		// PA.14
#define	IO_JLINK_SWC_INPUT()							GPIO_CONFIG(GPIOA,	PIN_14,	CRM_GPIOA_PERIPH_CLOCK,	GPIO_MODE_OUTPUT, GPIO_PULL_NONE)
#define IO_JLINK_SWC_HIGH() 							GPIO_IO_SET(GPIOA,	PIN_14)
#define IO_JLINK_SWC_LOW() 								GPIO_IO_CLR(GPIOA,	PIN_14)
#define IO_JLINK_SWC_READ() 							GPIO_IO_RDV(GPIOA, 	PIN_14)
																					
#define	IO_JLINK_SWD_OUTPUT()							GPIO_CONFIG(GPIOA,	PIN_13,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_OUTPUT, GPIO_PULL_NONE)		// PA.13
#define	IO_JLINK_SWD_INPUT()							GPIO_CONFIG(GPIOA,	PIN_13,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)		//
#define IO_JLINK_SWD_HIGH() 							GPIO_IO_SET(GPIOA,	PIN_13)
#define IO_JLINK_SWD_LOW() 								GPIO_IO_CLR(GPIOA,	PIN_13)
#define IO_JLINK_SWD_READ() 							GPIO_IO_RDV(GPIOA, 	PIN_13)

//============================================================================= IO Define For USB
#define USB_DP_PIN          							GPIO_PINS_12						                                          //PA.12		Request USB OTG/Device
#define USB_DM_PIN          							GPIO_PINS_11						                                          //PA.11		Request USB OTG/Device
#define OTG_FS_ID_PIN          						GPIO_PINS_10						                                          //PA.10		Request USB OTG
#define OTG_FS_ID_VBUS         						GPIO_PINS_9							                                          //PA.9		Request USB Device
#define USB_GPIO            							GPIOA
#define USB_GPIO_RCC_CLK    							CRM_GPIOA_PERIPH_CLOCK

//#define HOST_POWERSW_VBUS              		GPIO_PINS_5							                                          //PB.5		Request USB Host Power Ctrl
//#define HOST_POWERSW_PORT_RCC         		CRM_GPIOB_PERIPH_CLOCK
//#define HOST_POWERSW_PORT            			GPIOB

//#define IO_IAP_MODE_INPUT()					      {	GPIO_CONFIG(GPIOA,	GPIO_PINS_15,	CRM_GPIOA_PERIPH_CLOCK,	GPIO_MODE_INPUT,GPIO_PULL_UP);	\
//																						crm_periph_clock_enable(CRM_IOMUX_PERIPH_CLOCK, TRUE);  \
//                                            gpio_pin_remap_config(SWJTAG_MUX_010, TRUE);	}           // PA.15/JTDI	// JTAG-DP Disabled and SW-DP Enabled 
//#define IO_IAP_MODE_READ()								GPIO_IO_RDV(GPIOA, 	GPIO_PINS_15)

//============================================================================= IO Define For UART1
//Uart1: BaudRate = 115200	:	Log  
#define IO_USART1_TXD_OUTPUT()						{ GPIO_CONFIG(GPIOB,	GPIO_PINS_6,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_MUX, GPIO_PULL_NONE)\
                                            crm_periph_clock_enable(CRM_IOMUX_PERIPH_CLOCK, TRUE);  \
                                            gpio_pin_remap_config(USART1_MUX, TRUE);}                                                 // PB.6 
#define	IO_USART1_RXD_INPUT()							GPIO_CONFIG(GPIOB,	GPIO_PINS_7,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_INPUT,GPIO_PULL_UP)		  // PB.7
#define IO_USART1_ENABLE()             		crm_periph_clock_enable(CRM_USART1_PERIPH_CLOCK, TRUE)

#define AT32_PRINT_UART                		USART1
//============================================================================= IO Define For UART2
//Uart2: BaudRate = 115200	:	
#define IO_USART2_TXD_OUTPUT()						GPIO_CONFIG(GPIOA,	GPIO_PINS_2,	CRM_GPIOA_PERIPH_CLOCK,	GPIO_MODE_MUX, GPIO_PULL_NONE)	  // PA.2 
#define	IO_USART2_RXD_INPUT()							GPIO_CONFIG(GPIOA,	GPIO_PINS_3,	CRM_GPIOA_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)		// PA.3
#define IO_USART2_ENABLE()             		crm_periph_clock_enable(CRM_USART2_PERIPH_CLOCK, TRUE)

//============================================================================= IO Define For UART3
//Uart3: BaudRate = 115200	:	PMCU 2
#define IO_USART3_TXD_OUTPUT()						GPIO_CONFIG(GPIOB,	GPIO_PINS_10,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_MUX, GPIO_PULL_NONE)    // PB.10 
#define	IO_USART3_RXD_INPUT()							GPIO_CONFIG(GPIOB,	GPIO_PINS_11,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)	  // PB.11
#define IO_USART3_ENABLE()             		crm_periph_clock_enable(CRM_USART3_PERIPH_CLOCK, TRUE)

//============================================================================= IO Define For UART4
//Uart4: BaudRate = 115200	:	
#define IO_UART4_TXD_OUTPUT()							GPIO_CONFIG(GPIOC,	GPIO_PINS_10,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_MUX, GPIO_PULL_NONE)		// PC.10 
#define	IO_UART4_RXD_INPUT()							GPIO_CONFIG(GPIOC,	GPIO_PINS_11,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)	  // PC.11
#define IO_UART4_ENABLE()             		crm_periph_clock_enable(CRM_UART4_PERIPH_CLOCK, TRUE)

//============================================================================= IO Define For UART5
//Uart5: BaudRate = 115200 : PMCU 1 
#define IO_UART5_TXD_OUTPUT()							GPIO_CONFIG(GPIOC,	GPIO_PINS_12,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_MUX, GPIO_PULL_NONE)		// PC.12 
#define	IO_UART5_RXD_INPUT()							GPIO_CONFIG(GPIOD,	GPIO_PINS_2,	CRM_GPIOD_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)		// PD.2
#define IO_UART5_ENABLE()             		crm_periph_clock_enable(CRM_UART5_PERIPH_CLOCK, TRUE)

//#define	IO_OPT_LED1_INPUT()							  GPIO_CONFIG(GPIOD,	GPIO_PINS_2,	CRM_GPIOD_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)   // PD.2
//#define IO_LED1_READ() 								    GPIO_IO_RDV(GPIOD, 	GPIO_PINS_2)
//#define	IO_OPT_LED1_OUTPUT()							GPIO_CONFIG(GPIOD,	GPIO_PINS_2,	CRM_GPIOD_PERIPH_CLOCK,	GPIO_MODE_OUTPUT, GPIO_PULL_NONE)	// PD.2
//#define IO_OPT_LED1_ON() 									GPIO_IO_SET(GPIOD,	GPIO_PINS_2)
//#define IO_OPT_LED1_OFF() 							  GPIO_IO_CLR(GPIOD,	GPIO_PINS_2)
//============================================================================= IO Define SDCARD
//sdio1_ck(pc4), sdio1_cmd(pc5), sdio1_d0(pc0), sdio1_d1(pc1), sdio1_d2(pc2), sdio1_d3(pc3)
//#define IO_SDCARD_PIN_REMAP()							{ crm_periph_clock_enable(CRM_SDIO1_PERIPH_CLOCK, TRUE)   \
//                                            crm_periph_clock_enable(CRM_IOMUX_PERIPH_CLOCK, TRUE);  \
//                                            gpio_pin_remap_config(SDIO1_GMUX_0100, TRUE);}
//#define IO_SDCARD_D0_PIN()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_0,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_MUX, GPIO_PULL_NONE)		// PC.0 
//#define IO_SDCARD_D1_PIN()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_1,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_MUX, GPIO_PULL_NONE)		// PC.1 
//#define IO_SDCARD_D2_PIN()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_2,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_MUX, GPIO_PULL_NONE)		// PC.2 
//#define IO_SDCARD_D3_PIN()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_3,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_MUX, GPIO_PULL_NONE)		// PC.3                                            
//#define IO_SDCARD_SCK_PIN()						    GPIO_CONFIG(GPIOC,	GPIO_PINS_4,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_MUX, GPIO_PULL_NONE)		// PC.4                                            
//#define IO_SDCARD_CMD_PIN()						    GPIO_CONFIG(GPIOC,	GPIO_PINS_5,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_MUX, GPIO_PULL_NONE)		// PC.5                                            
//#define IO_SDCARD_DET_PIN()						    GPIO_CONFIG(GPIOB,	GPIO_PINS_0,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)		// PB.0                                            
//#define IO_SDCARD_DET_READ() 							GPIO_IO_RDV(GPIOB, 	GPIO_PINS_0)

//============================================================================= 
//Version	V1.08	: (1)20240727		: Ex ADC INA219
#define ADDR_CX1		      					0x40*2
#define ADDR_VX1		      					0x41*2
#define ADDR_CY1		      					0x42*2
#define ADDR_VY1		      					0x43*2

#define ADDR_CX2		      					0x44*2
#define ADDR_VX2		      					0x45*2
#define ADDR_CY2		      					0x46*2
#define ADDR_VY2		      					0x47*2

#define ADDR_CC1		      					0x42*2
#define ADDR_CC2		      					0x43*2

#define REG_CONFIG		      				0x00
#define REG_SHUNT_VOL	      				0x01
#define REG_BUS_VOL		      				0x02
#define REG_POWER			      				0x03
#define REG_CURRENT		      				0x04
#define REG_CALIBRATION      				0x05

#define ADDR_CH1		      					0x40*2
#define ADDR_CH2		      					0x44*2
#define ADDR_CH3		      					0x43*2
#define ADDR_CH4		      					0x42*2

//============================================================================= IO Define For I2C
//
#define	SW_I2C_SCL_OUTPUT()								GPIO_CONFIG(GPIOB,	GPIO_PINS_8,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PB.8
#define SW_I2C_SCL_HIGH() 								GPIO_IO_SET(GPIOB,	GPIO_PINS_8)
#define SW_I2C_SCL_LOW() 									GPIO_IO_CLR(GPIOB,	GPIO_PINS_8)

#define	SW_I2C_SDA_OUTPUT()								GPIO_CONFIG(GPIOB,	GPIO_PINS_9,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PB.9
#define	SW_I2C_SDA_INPUT()								GPIO_CONFIG(GPIOB,	GPIO_PINS_9,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_INPUT,GPIO_PULL_UP)		  		//
#define SW_I2C_SDA_HIGH() 								GPIO_IO_SET(GPIOB,	GPIO_PINS_9)
#define SW_I2C_SDA_LOW() 									GPIO_IO_CLR(GPIOB,	GPIO_PINS_9)
#define SW_I2C_SDA_READ() 								GPIO_IO_RDV(GPIOB, 	GPIO_PINS_9)


#define	SW_I2C2_SCL_OUTPUT()							GPIO_CONFIG(GPIOC,	GPIO_PINS_11,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PC.11
#define SW_I2C2_SCL_HIGH() 								GPIO_IO_SET(GPIOC,	GPIO_PINS_11)
#define SW_I2C2_SCL_LOW() 								GPIO_IO_CLR(GPIOC,	GPIO_PINS_11)

#define	SW_I2C2_SDA_OUTPUT()							GPIO_CONFIG(GPIOC,	GPIO_PINS_12,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PC.12
#define	SW_I2C2_SDA_INPUT()								GPIO_CONFIG(GPIOC,	GPIO_PINS_12,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_INPUT,GPIO_PULL_UP)		  		//
#define SW_I2C2_SDA_HIGH() 								GPIO_IO_SET(GPIOC,	GPIO_PINS_12)
#define SW_I2C2_SDA_LOW() 								GPIO_IO_CLR(GPIOC,	GPIO_PINS_12)
#define SW_I2C2_SDA_READ() 								GPIO_IO_RDV(GPIOC, 	GPIO_PINS_12)

#define	SW_I2C3_SCL_OUTPUT()							GPIO_CONFIG(GPIOB,	GPIO_PINS_3,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PB3  // PD.2 //Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
#define SW_I2C3_SCL_HIGH() 								GPIO_IO_SET(GPIOB,	GPIO_PINS_3)
#define SW_I2C3_SCL_LOW() 								GPIO_IO_CLR(GPIOB,	GPIO_PINS_3)

#define	SW_I2C3_SDA_OUTPUT()							GPIO_CONFIG(GPIOB,	GPIO_PINS_4,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PB.4 // PB.3 //Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
#define	SW_I2C3_SDA_INPUT()								GPIO_CONFIG(GPIOB,	GPIO_PINS_4,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_INPUT,GPIO_PULL_UP)		  		//
#define SW_I2C3_SDA_HIGH() 								GPIO_IO_SET(GPIOB,	GPIO_PINS_4)
#define SW_I2C3_SDA_LOW() 								GPIO_IO_CLR(GPIOB,	GPIO_PINS_4)
#define SW_I2C3_SDA_READ() 								GPIO_IO_RDV(GPIOB, 	GPIO_PINS_4)

#define	SW_I2C4_SCL_OUTPUT()							GPIO_CONFIG(GPIOF,	GPIO_PINS_6,	CRM_GPIOF_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PF6  // PC.13  //Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
#define SW_I2C4_SCL_HIGH() 								GPIO_IO_SET(GPIOF,	GPIO_PINS_6)
#define SW_I2C4_SCL_LOW() 								GPIO_IO_CLR(GPIOF,	GPIO_PINS_6)

#define	SW_I2C4_SDA_OUTPUT()							GPIO_CONFIG(GPIOF,	GPIO_PINS_7,	CRM_GPIOF_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PF7  // PC.14  //Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
#define	SW_I2C4_SDA_INPUT()								GPIO_CONFIG(GPIOF,	GPIO_PINS_7,	CRM_GPIOF_PERIPH_CLOCK,	GPIO_MODE_INPUT,GPIO_PULL_UP)		  		//
#define SW_I2C4_SDA_HIGH() 								GPIO_IO_SET(GPIOF,	GPIO_PINS_7)
#define SW_I2C4_SDA_LOW() 								GPIO_IO_CLR(GPIOF,	GPIO_PINS_7)
#define SW_I2C4_SDA_READ() 								GPIO_IO_RDV(GPIOF, 	GPIO_PINS_7)

#define	SW_I2C5_SCL_OUTPUT()							GPIO_CONFIG(GPIOB,	GPIO_PINS_10,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PB.10
#define SW_I2C5_SCL_HIGH() 								GPIO_IO_SET(GPIOB,	GPIO_PINS_10)
#define SW_I2C5_SCL_LOW() 								GPIO_IO_CLR(GPIOB,	GPIO_PINS_10)

#define	SW_I2C5_SDA_OUTPUT()							GPIO_CONFIG(GPIOB,	GPIO_PINS_11,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PB.11
#define	SW_I2C5_SDA_INPUT()								GPIO_CONFIG(GPIOB,	GPIO_PINS_11,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_INPUT,GPIO_PULL_UP)		  		//
#define SW_I2C5_SDA_HIGH() 								GPIO_IO_SET(GPIOB,	GPIO_PINS_11)
#define SW_I2C5_SDA_LOW() 								GPIO_IO_CLR(GPIOB,	GPIO_PINS_11)
#define SW_I2C5_SDA_READ() 								GPIO_IO_RDV(GPIOB, 	GPIO_PINS_11)

#define	SW_I2C6_SCL_OUTPUT()							GPIO_CONFIG(GPIOB,	GPIO_PINS_2,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PB.2
#define SW_I2C6_SCL_HIGH() 								GPIO_IO_SET(GPIOB,	GPIO_PINS_2)
#define SW_I2C6_SCL_LOW() 								GPIO_IO_CLR(GPIOB,	GPIO_PINS_2)

#define	SW_I2C6_SDA_OUTPUT()							GPIO_CONFIG(GPIOA,	GPIO_PINS_10,	CRM_GPIOA_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PA.10
#define	SW_I2C6_SDA_INPUT()								GPIO_CONFIG(GPIOA,	GPIO_PINS_10,	CRM_GPIOA_PERIPH_CLOCK,	GPIO_MODE_INPUT,GPIO_PULL_UP)		  		//
#define SW_I2C6_SDA_HIGH() 								GPIO_IO_SET(GPIOA,	GPIO_PINS_10)
#define SW_I2C6_SDA_LOW() 								GPIO_IO_CLR(GPIOA,	GPIO_PINS_10)
#define SW_I2C6_SDA_READ() 								GPIO_IO_RDV(GPIOA, 	GPIO_PINS_10)


//============================================================================= IO Define For HC595
//
//#define	SW_595_RCK_OUTPUT()								GPIO_CONFIG(GPIOA,	GPIO_PINS_8,	CRM_GPIOA_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PA.8
//#define SW_595_RCK_HIGH() 								GPIO_IO_SET(GPIOA,	GPIO_PINS_8)
//#define SW_595_RCK_LOW() 									GPIO_IO_CLR(GPIOA,	GPIO_PINS_8)

//#define	SW_595_CLK_OUTPUT()								GPIO_CONFIG(GPIOC,	GPIO_PINS_9,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PC.9
//#define SW_595_CLK_HIGH() 								GPIO_IO_SET(GPIOC,	GPIO_PINS_9)
//#define SW_595_CLK_LOW() 									GPIO_IO_CLR(GPIOC,	GPIO_PINS_9)

//#define	SW_595_DAT_OUTPUT()								GPIO_CONFIG(GPIOC,	GPIO_PINS_8,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PC.8
//#define SW_595_DAT_HIGH() 								GPIO_IO_SET(GPIOC,	GPIO_PINS_8)
//#define SW_595_DAT_LOW() 									GPIO_IO_CLR(GPIOC,	GPIO_PINS_8)

////Version	V1.04	: (1)20240718		: Switch To RGBx25
//#define	IO_BTN_RGB_1_OUTPUT()							GPIO_CONFIG(GPIOC,	GPIO_PINS_8,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PC.8
//#define IO_BTN_RGB_1_H() 								  GPIO_IO_SET(GPIOC,	GPIO_PINS_8)
//#define IO_BTN_RGB_1_L() 									GPIO_IO_CLR(GPIOC,	GPIO_PINS_8)

//#define	IO_BTN_RGB_2_OUTPUT()							GPIO_CONFIG(GPIOC,	GPIO_PINS_9,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PC.9
//#define IO_BTN_RGB_2_H() 								  GPIO_IO_SET(GPIOC,	GPIO_PINS_9)
//#define IO_BTN_RGB_2_L() 									GPIO_IO_CLR(GPIOC,	GPIO_PINS_9)

//#define	IO_BTN_RGB_3_OUTPUT()					    GPIO_CONFIG(GPIOA,	GPIO_PINS_8,	CRM_GPIOA_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PA.8
//#define IO_BTN_RGB_3_H() 								  GPIO_IO_SET(GPIOA,	GPIO_PINS_8)
//#define IO_BTN_RGB_3_L() 									GPIO_IO_CLR(GPIOA,	GPIO_PINS_8)

//#define IO_BTN_RGB_4_OUTPUT()						  GPIO_CONFIG(GPIOB,	GPIO_PINS_3,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_OUTPUT, GPIO_PULL_NONE)		  // PB.3
//#define IO_BTN_RGB_4_H() 								  GPIO_IO_SET(GPIOB,	GPIO_PINS_3)
//#define IO_BTN_RGB_4_L() 							    GPIO_IO_CLR(GPIOB,	GPIO_PINS_3)


//#define IO_595_SCK_OUTPUT()                {GPIO_CONFIG (GPIOA, GPIO_PINS_9, CRM_GPIOA_PERIPH_CLOCK, GPIO_MODE_OUTPUT, GPIO_PULL_NONE);}   // PA.8   
//#define IO_595_RCK_OUTPUT()                {GPIO_CONFIG (GPIOC, GPIO_PINS_8, CRM_GPIOC_PERIPH_CLOCK, GPIO_MODE_OUTPUT, GPIO_PULL_NONE);}   // PC.9    
//#define IO_595_SER_OUTPUT()                {GPIO_CONFIG (GPIOC, GPIO_PINS_8, CRM_GPIOC_PERIPH_CLOCK, GPIO_MODE_OUTPUT, GPIO_PULL_NONE);}   // PC.8

//#define IO_595_SCK_HIGH()                 GPIO_SetBit(GPIOA, GPIO_PINS_9)
//#define IO_595_RCK_HIGH()                 GPIO_SetBit(GPIOC, GPIO_PINS_8)
//#define IO_595_SER_HIGH()                 GPIO_SetBit(GPIOC, GPIO_PINS_8)

//#define IO_595_SCK_LOW()                  GPIO_ClrBit(GPIOA, GPIO_PINS_9)
//#define IO_595_RCK_LOW()                  GPIO_ClrBit(GPIOC, GPIO_PINS_8)
//#define IO_595_SER_LOW()                  GPIO_ClrBit(GPIOC, GPIO_PINS_8)

//============================================================================= ADC Define
//#define ADC_DMA_ENABLE          	        1
#define MAX_ADC_CHAN							        16
#define MAX_VAL_CHAN							        9*4//16
#define ADC_NOISE_RANGE						        50

#define IO_ADC_CH00_INPUT()							  GPIO_CONFIG(GPIOA,	GPIO_PINS_0,	CRM_GPIOA_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PA.00
#define IO_ADC_CH01_INPUT()							  GPIO_CONFIG(GPIOA,	GPIO_PINS_1,	CRM_GPIOA_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PA.01
#define IO_ADC_CH02_INPUT()							  GPIO_CONFIG(GPIOA,	GPIO_PINS_2,	CRM_GPIOA_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PA.02
#define IO_ADC_CH03_INPUT()							  GPIO_CONFIG(GPIOA,	GPIO_PINS_3,	CRM_GPIOA_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PA.03
#define IO_ADC_CH04_INPUT()							  GPIO_CONFIG(GPIOA,	GPIO_PINS_4,	CRM_GPIOA_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PA.04
#define IO_ADC_CH05_INPUT()							  GPIO_CONFIG(GPIOA,	GPIO_PINS_5,	CRM_GPIOA_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PA.05
#define IO_ADC_CH06_INPUT()							  GPIO_CONFIG(GPIOA,	GPIO_PINS_6,	CRM_GPIOA_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PA.06
#define IO_ADC_CH07_INPUT()							  GPIO_CONFIG(GPIOA,	GPIO_PINS_7,	CRM_GPIOA_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PA.07

#define IO_ADC_CH08_INPUT()							  GPIO_CONFIG(GPIOB,	GPIO_PINS_0,	CRM_GPIOB_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PB.00
#define IO_ADC_CH09_INPUT()							  GPIO_CONFIG(GPIOB,	GPIO_PINS_1,	CRM_GPIOB_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PB.01
#define IO_ADC_CH10_INPUT()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_0,	CRM_GPIOC_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PC.00
#define IO_ADC_CH11_INPUT()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_1,	CRM_GPIOC_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PC.01
#define IO_ADC_CH12_INPUT()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_2,	CRM_GPIOC_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PC.02
#define IO_ADC_CH13_INPUT()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_3,	CRM_GPIOC_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PC.03
#define IO_ADC_CH14_INPUT()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_4,	CRM_GPIOC_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PC.04
#define IO_ADC_CH15_INPUT()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_5,	CRM_GPIOC_PERIPH_CLOCK,  GPIO_MODE_ANALOG, GPIO_PULL_NONE)	  // PC.05

//============================================================================= IO Define  
//#define	IO_PMCU1_S1_INPUT()							  GPIO_CONFIG(GPIOA,	GPIO_PINS_15,	CRM_GPIOA_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)		  // PA.15
//#define	IO_PMCU1_S2_INPUT()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_10,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)		  // PC.10
//#define	IO_PMCU1_S3_INPUT()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_11,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)		  // PC.11
//#define IO_PMCU1_S1_READ() 							  GPIO_IO_RDV(GPIOA, 	GPIO_PINS_15)
//#define IO_PMCU1_S2_READ() 							  GPIO_IO_RDV(GPIOC, 	GPIO_PINS_10)
//#define IO_PMCU1_S3_READ() 							  GPIO_IO_RDV(GPIOC, 	GPIO_PINS_11)

//#define	IO_PMCU2_S1_INPUT()							  GPIO_CONFIG(GPIOB,	GPIO_PINS_15,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)		  // PB.15
//#define	IO_PMCU2_S2_INPUT()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_6,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)		  // PC.6
//#define	IO_PMCU2_S3_INPUT()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_7,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)		  // PC.7
//#define IO_PMCU2_S1_READ() 							  GPIO_IO_RDV(GPIOB, 	GPIO_PINS_15)
//#define IO_PMCU2_S2_READ() 							  GPIO_IO_RDV(GPIOC, 	GPIO_PINS_6)
//#define IO_PMCU2_S3_READ() 							  GPIO_IO_RDV(GPIOC, 	GPIO_PINS_7)

//Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
#define	IO_SW_1_INPUT()								    GPIO_CONFIG(GPIOB,	GPIO_PINS_5,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_DOWN)		  // PB5  // PB.12
#define IO_SW_1_READ() 								    GPIO_IO_RDV(GPIOB, 	GPIO_PINS_5)

//Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
#define	IO_SW_2_INPUT()								    GPIO_CONFIG(GPIOC,	GPIO_PINS_13,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_DOWN)		  // PC13 // PB.13  
#define IO_SW_2_READ() 								    GPIO_IO_RDV(GPIOC, 	GPIO_PINS_13)

//Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
#define	IO_SW_LED1_OUTPUT()							  GPIO_CONFIG(GPIOD,	GPIO_PINS_2,	CRM_GPIOD_PERIPH_CLOCK,	GPIO_MODE_OUTPUT, GPIO_PULL_NONE)	    // PD2  // PF.7
#define IO_SW_LED1_OFF() 								  GPIO_IO_CLR(GPIOD,	GPIO_PINS_2)  //Version	V2.02	: (1)20251007		: Support New 9KEY PCBA SW1&SW2 LED
#define IO_SW_LED1_ON() 								  GPIO_IO_SET(GPIOD,	GPIO_PINS_2)  //Version	V2.02	: (1)20251007		: Support New 9KEY PCBA SW1&SW2 LED

//Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
#define	IO_SW_LED2_OUTPUT()							  GPIO_CONFIG(GPIOC,	GPIO_PINS_14,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_OUTPUT, GPIO_PULL_NONE)	    // PC14 // PF.6 
#define IO_SW_LED2_OFF() 								  GPIO_IO_CLR(GPIOC,	GPIO_PINS_14) //Version	V2.02	: (1)20251007		: Support New 9KEY PCBA SW1&SW2 LED
#define IO_SW_LED2_ON() 							    GPIO_IO_SET(GPIOC,	GPIO_PINS_14) //Version	V2.02	: (1)20251007		: Support New 9KEY PCBA SW1&SW2 LED


#define	IO_USB_PWR_DT_INPUT()						  GPIO_CONFIG(GPIOF,	GPIO_PINS_5,	CRM_GPIOF_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)	      // PF.5
#define IO_USB_PWR_READ() 							  GPIO_IO_RDV(GPIOF,	GPIO_PINS_5)
#define	IO_RGB_PWR_DT_INPUT()						  GPIO_CONFIG(GPIOF,	GPIO_PINS_4,	CRM_GPIOF_PERIPH_CLOCK,	GPIO_MODE_INPUT,  GPIO_PULL_UP)	      // PF.4
#define IO_RGB_PWR_READ() 							  GPIO_IO_RDV(GPIOF,	GPIO_PINS_4)


//============================================================================= 
//Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
#define IO_RGB_1_OUTPUT()						      GPIO_CONFIG(GPIOC,	GPIO_PINS_10,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_OUTPUT, GPIO_PULL_NONE)		  // PC10 // PB.5
#define IO_RGB_1_H() 								    	GPIO_IO_SET(GPIOC,	GPIO_PINS_10)
#define IO_RGB_1_L() 							      	GPIO_IO_CLR(GPIOC,	GPIO_PINS_10)

//Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
#define IO_RGB_2_OUTPUT()						      GPIO_CONFIG(GPIOA,	GPIO_PINS_15,	CRM_GPIOA_PERIPH_CLOCK,	GPIO_MODE_OUTPUT, GPIO_PULL_NONE)		  // PA15 // PB.4
#define IO_RGB_2_H() 								    	GPIO_IO_SET(GPIOA,	GPIO_PINS_15)
#define IO_RGB_2_L() 							      	GPIO_IO_CLR(GPIOA,	GPIO_PINS_15)


//Version	V1.04	: (1)20240718		: Switch To RGBx25
#define	IO_BTN_RGB_1_OUTPUT()							GPIO_CONFIG(GPIOB,	GPIO_PINS_14,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PB.14
#define IO_BTN_RGB_1_H() 								  GPIO_IO_SET(GPIOB,	GPIO_PINS_14)
#define IO_BTN_RGB_1_L() 									GPIO_IO_CLR(GPIOB,	GPIO_PINS_14)

#define	IO_BTN_RGB_2_OUTPUT()							GPIO_CONFIG(GPIOB,	GPIO_PINS_15,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PB.15
#define IO_BTN_RGB_2_H() 								  GPIO_IO_SET(GPIOB,	GPIO_PINS_15)
#define IO_BTN_RGB_2_L() 									GPIO_IO_CLR(GPIOB,	GPIO_PINS_15)

#define	IO_BTN_RGB_3_OUTPUT()							GPIO_CONFIG(GPIOC,	GPIO_PINS_6,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PC.6
#define IO_BTN_RGB_3_H() 								  GPIO_IO_SET(GPIOC,	GPIO_PINS_6)
#define IO_BTN_RGB_3_L() 									GPIO_IO_CLR(GPIOC,	GPIO_PINS_6)

#define	IO_BTN_RGB_4_OUTPUT()							GPIO_CONFIG(GPIOC,	GPIO_PINS_7,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PC.7
#define IO_BTN_RGB_4_H() 								  GPIO_IO_SET(GPIOC,	GPIO_PINS_7)
#define IO_BTN_RGB_4_L() 									GPIO_IO_CLR(GPIOC,	GPIO_PINS_7)

#define	IO_BTN_RGB_5_OUTPUT()							GPIO_CONFIG(GPIOC,	GPIO_PINS_8,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PC.8
#define IO_BTN_RGB_5_H() 								  GPIO_IO_SET(GPIOC,	GPIO_PINS_8)
#define IO_BTN_RGB_5_L() 									GPIO_IO_CLR(GPIOC,	GPIO_PINS_8)

#define	IO_BTN_RGB_6_OUTPUT()							GPIO_CONFIG(GPIOC,	GPIO_PINS_9,	CRM_GPIOC_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PC.9
#define IO_BTN_RGB_6_H() 								  GPIO_IO_SET(GPIOC,	GPIO_PINS_9)
#define IO_BTN_RGB_6_L() 									GPIO_IO_CLR(GPIOC,	GPIO_PINS_9)

#define	IO_BTN_RGB_7_OUTPUT()							GPIO_CONFIG(GPIOA,	GPIO_PINS_8,	CRM_GPIOA_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PA.8
#define IO_BTN_RGB_7_H() 								  GPIO_IO_SET(GPIOA,	GPIO_PINS_8)
#define IO_BTN_RGB_7_L() 									GPIO_IO_CLR(GPIOA,	GPIO_PINS_8)

//Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
#define	IO_BTN_RGB_8_OUTPUT()							GPIO_CONFIG(GPIOB,	GPIO_PINS_13,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PB13 // PA.15
#define IO_BTN_RGB_8_H() 								  GPIO_IO_SET(GPIOB,	GPIO_PINS_13)
#define IO_BTN_RGB_8_L() 									GPIO_IO_CLR(GPIOB,	GPIO_PINS_13)

//Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
#define	IO_BTN_RGB_9_OUTPUT()							GPIO_CONFIG(GPIOB,	GPIO_PINS_12,	CRM_GPIOB_PERIPH_CLOCK,	GPIO_MODE_OUTPUT,GPIO_PULL_NONE)		  // PB12 // PC.10
#define IO_BTN_RGB_9_H() 								  GPIO_IO_SET(GPIOB,	GPIO_PINS_12)
#define IO_BTN_RGB_9_L() 									GPIO_IO_CLR(GPIOB,	GPIO_PINS_12)



//******************************************************************************
//
//------------- Type Defs    -------------------
//
//******************************************************************************

typedef struct 
{
	unsigned char		Chan;
	unsigned short	Buf[MAX_VAL_CHAN];
//	unsigned short	Reg[MAX_VAL_CHAN];
	unsigned short	tmp[MAX_VAL_CHAN];

//	unsigned short	VBAT;
	unsigned short	ADC_Val1;
	unsigned short	ADC_Val2;
//  unsigned short	ADC_Val3;
//	unsigned short	ADC_Val4;
//	unsigned short	NTC;
}AppADC_t;


//******************************************************************************
//
//-------------  Variable  define   --------------------
//
//******************************************************************************




//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

//--------------------------------------------------------------- 
void App_BSP_Log_Uart_Init(uint32_t baudrate);

//--------------------------------------------------------------- 
void App_BSP_Delay_Init(void);
void App_BSP_Delay_US(uint32_t nus);
void App_BSP_Delay_MS(uint16_t nms);
void App_BSP_Delay_SEC(uint16_t sec);
void usb_delay_ms(uint32_t ms);
void usb_delay_us(uint32_t us);
unsigned char	 UPDATE_CRC (unsigned char *Buffer,unsigned char Len);
unsigned short UPDATE_CRC_16(unsigned char *Buffer,unsigned char Len);
void App_BSP_LogBuf(const unsigned char *str,unsigned char *Buffer,unsigned short Len);
void App_BSP16_LogBuf(const unsigned char *str,unsigned short *Buffer,unsigned short Len);

//---------------------------------------------------------------
//MCU Base TimeTick 1mS
void Timer1_Config(void);
void Timer3_Config(void);
void TMR_1mS_Interrupt_CB(void);

//---------------------------------------------------------------
void Timer1_PWM_Config(void);	  //TMR1 Config For PWM1 Channel 1~4:PA8,PA9,PA10,PA11
void Timer3_PWM_Config(void);   //TMR3 Config For PWM1 Channel 1~4:PA6,PA7,PB0,PB1
void Timer5_PWM_Config(void);		//TMR5 Config For PWM1 Channel 1~4:PA0,PA1,PA2,PA3
void PWM_Duty_Update(unsigned char Chan,unsigned short Duty);

void RGB_DMA_Driver_Data_Load(unsigned char *DataBuffer, unsigned short Length);
void RGB_DMA_Driver_Config(void);
void RGB_DMA_Driver_Start(void);

//---------------------------------------------------------------
//Configure PA0 as EXINT0 interrupt mode
void EXTI_INT0_Config(void);				
void EXTI_INT0_CB(void);

//---------------------------------------------------------------
void MCU_DMA_Config_For_ADC(void);
void MCU_ADC_Config_With_DMA(void);
void MCU_ADC_Config(void);
uint16_t GetADCValue(uint16_t Channel);

//Version	V1.08	: (1)20240727		: Ex ADC INA219
extern unsigned short SW_I2C1_ReadValue(unsigned char I2CAddr,unsigned char RegAddr);
extern unsigned short SW_I2C2_ReadValue(unsigned char I2CAddr,unsigned char RegAddr);
extern unsigned short SW_I2C3_ReadValue(unsigned char I2CAddr,unsigned char RegAddr);
extern unsigned short SW_I2C4_ReadValue(unsigned char I2CAddr,unsigned char RegAddr);
extern unsigned short SW_I2C5_ReadValue(unsigned char I2CAddr,unsigned char RegAddr);
extern unsigned short SW_I2C6_ReadValue(unsigned char I2CAddr,unsigned char RegAddr);


extern void App_RGB_CC_PowerUpdate(unsigned int Value);	

void CHK_ADC_SCAN(AppADC_t *AppADC);

void CHK_PWR_SCAN(AppADC_t *AppADC);
//---------------------------------------------------------------
//void HW_SPI_1_Slave_Config(void);
//void HW_SPI_1_RX_CB(void);
//void HW_SPI_1_TX_CB(void);

//---------------------------------------------------------------
void MCU_GPIO_Config(void);




//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


#ifdef __cplusplus
}
#endif

#endif

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

