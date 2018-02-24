#ifndef OPTION_H
#define OPTION_H
//====================================================
//OS
#define SYS_XTAL                XTAL_12M
//Xtal
#define XTAL_8M 				(8*1000000)	
#define XTAL_10M 				(10*1000000)
#define XTAL_11M 				(11059200)
#define XTAL_12M 				(12*1000000)
#define XTAL_13M 				(13*1000000)
#define XTAL_14M 				(14*1000000)
#define XTAL_16M 				(16*1000000)
#define XTAL_20M 				(20*1000000)
#define XTAL_22M 				(22114800)	
#define XTAL_24M 				(24*1000000)
#define XTAL_25M 				(25*1000000)
#define XTAL_26M 				(26*1000000)
#define XTAL_28M 				(28*1000000)
//External Reset Pin
#define EXTERNAL_RESET			ON
//Micro Source Clock
#define IRC_12M		0x00
#define EXT_12M		0x04
#define IRC_32K		0x08
#define EXT_32K		0x0C
//RC Osc calibration	  
#define EXTERNAL_12M			ON
#define EXTERNAL_32K			ON
#define REF_OSC_CAL_VALUE       (WORD)(SYS_XTAL/32768)
#define OSC_CAL_RANGE           4
#define ROSC_DEFAULT_12MHZ		0x56	//One sample
//====================================================
#define WT56F216_LQFP44			1
#define WT56F216_SOP28 			2
#define WT56F216_PACKAGE		WT56F216_LQFP44
//====================================================
//Uart Debug
#define ENABLE_UARTDEBUG_MODE	0
#define UART0	1
#define UART1	0				
#define UART_DEBUG_PORT 		UART1


#define ENABLE_I2C_MODE 		ON		// Slave-I2C for debug & Test


#define GPIO_POLL_TIME			10
#define SYSTEM_POLL_TIME		70		//200ms
#define DKEY_POLL_TIME			1		//10ms
#define ADC_POLL_TIME			10		//100ms

#define RTC_POLL_TIME			50		//1000ms
#define DISPLAY_POLL_TIME		10		//100ms




#define YEAR_DEFAULT 	2012
//====================================================

//#define ENABLE_APIDKEY_MODE		1
#define ENABLE_ADC_MODE				0
#define ENABLE_LED_MODE				1
#endif