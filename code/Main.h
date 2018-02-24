#ifndef OS_H
#define OS_H

extern u32 tic_pc;
extern u32 tic_01;


#define	Enable				1
#define	Disable				0



//==========================================================

//OS timer
#define SYSTMR_PRIO				1		// 这是TIMER0运行的毫秒数1
#define TMREVENT_TICKS				50		// 500毫秒

#define OS_TIMER0_1MS             	(WORD)(0.001/(12.0/(float)SYS_XTAL))			//Timer0 run 12T
#define OS_TIMER0_BASE           	 10*OS_TIMER0_1MS   //10ms
#define SYSTMR_DATAL			(65536-SYSTMR_PRIO*(SYS_XTAL/12000))&0xFF
#define SYSTMR_DATAH			((65536-SYSTMR_PRIO*(SYS_XTAL/12000))>>8)&0xFF



//==========================================================
//Power manage Control data
#define End_of_SubAddr_Table     (BYTE code *)0
//Host command
#define	FIRMWARE_VERSION		 0x01		// 2012/03/01	
//==========================================================
#define HOST_CMD_NULL            0xFF
#define HOST_CMD_PWRDOWN         0x00
//==========================================================
#define EN_CHIPCONDOUBLE	0	// (0)表示禁止,(1)表示允许,是否使用时钟x2
#define UartTMR_Band		9600	//4800	//9600	//4800	//9600//115200	//9600	//串口通讯的波特率
#define UartTMR_SMOD		1		//SMOD = 1 时，n = 16; SMOD = 0 时，n=32;
#define UARTTMR_DATAL		(256-(SYS_XTAL*2*(EN_CHIPCONDOUBLE+1)/UartTMR_Band/32/12/(2-UartTMR_SMOD)))&0xFF //(256-(McuFosc/(UartTMR_Band * 32 * 6 * (2-UartTMR_SMOD))))&0xFF //256-(2*12000000*2/384/9600);
#define UARTTMR_DATAH		(256-(SYS_XTAL*2*(EN_CHIPCONDOUBLE+1)/UartTMR_Band/32/12/(2-UartTMR_SMOD)))&0xFF //256-(2*12000000*2/384/9600);

#define UART0_2400			OFF		//OK	
#define UART0_9600			OFF		//OK
#define UART0_19200			OFF		//OK
#define UART0_57600			OFF		//OK
#define UART0_115200		ON		//OK
#define UART0_230400		OFF  
#define UART0_256000		OFF   // this baud rate has 0.26% error rate
#define UART0_460800		0FF  //untest

#define BIT_RATE600		1
#define BIT_RATE1200		2
#define BIT_RATE2400		3
#define BIT_RATE4800		4
#define BIT_RATE9600		5
#define BIT_RATE14400	6
#define BIT_RATE19200	7
#define BIT_RATE38400	8
#define BIT_RATE57600	9
#define BIT_RATE115200	10
#define BIT_RATE230400	11


//==========================================================
//==========================================================

enum
{
  WD_RST_TIME_16MS=0x00,		//default value
  WD_RST_TIME_32MS,
  WD_RST_TIME_1S,
  WD_RST_TIME_2S,
};
//==========================================================
#define ACTIVE_WD_TIMER 		ON
#define OS_WD_FUN_DIS()         {rWDT_CTL |=0xA0;}   //Disable Watchdog function
#define OS_WD_FUN_2SEC()        {rWDT_CTL = WD_RST_TIME_2S ;}


#define GPIOF3_PIN   	    DefineBit(rGPIOF_DAT, bit3)
#define GPIOF3_PIN_OE       DefineBit(rGPIOF_OEN, bit3)
#define GPIOF3_PIN_PHN      DefineBit(rGPIOF_PHN, bit3)	

#define GPIOF2_PIN   	    DefineBit(rGPIOF_DAT, bit2)
#define GPIOF2_PIN_OE       DefineBit(rGPIOF_OEN, bit2)
#define GPIOF2_PIN_PHN      DefineBit(rGPIOF_PHN, bit2)	

#define GPIOF1_PIN   	    DefineBit(rGPIOF_DAT, bit1)
#define GPIOF1_PIN_OE       DefineBit(rGPIOF_OEN, bit1)
#define GPIOF1_PIN_PHN      DefineBit(rGPIOF_PHN, bit1)	

#define GPIOF0_PIN   	    DefineBit(rGPIOF_DAT, bit0)
#define GPIOF0_PIN_OE       DefineBit(rGPIOF_OEN, bit0)
#define GPIOF0_PIN_PHN      DefineBit(rGPIOF_PHN, bit0)	

#define GPIOE7_PIN   	    DefineBit(rGPIOE_DAT, bit7)
#define GPIOE7_PIN_OE       DefineBit(rGPIOE_OEN, bit7)
#define GPIOE7_PIN_PHN      DefineBit(rGPIOE_PHN, bit7)	

#define GPIOE6_PIN   	    DefineBit(rGPIOE_DAT, bit6)
#define GPIOE6_PIN_OE       DefineBit(rGPIOE_OEN, bit6)
#define GPIOE6_PIN_PHN      DefineBit(rGPIOE_PHN, bit6)

#define GPIOE5_PIN   	    DefineBit(rGPIOE_DAT, bit5)
#define GPIOE5_PIN_OE       DefineBit(rGPIOE_OEN, bit5)
#define GPIOE5_PIN_PHN      DefineBit(rGPIOE_PHN, bit5)

#define GPIOE4_PIN   	    DefineBit(rGPIOE_DAT, bit4)
#define GPIOE4_PIN_OE       DefineBit(rGPIOE_OEN, bit4)
#define GPIOE4_PIN_PHN      DefineBit(rGPIOE_PHN, bit4)

#define GPIOE3_PIN   	    DefineBit(rGPIOE_DAT, bit3)
#define GPIOE3_PIN_OE       DefineBit(rGPIOE_OEN, bit3)
#define GPIOE3_PIN_PHN      DefineBit(rGPIOE_PHN, bit3)

#define GPIOE2_PIN   	    DefineBit(rGPIOE_DAT, bit2)
#define GPIOE2_PIN_OE       DefineBit(rGPIOE_OEN, bit2)
#define GPIOE2_PIN_PHN      DefineBit(rGPIOE_PHN, bit2)

#define GPIOE1_PIN   	    DefineBit(rGPIOE_DAT, bit1)
#define GPIOE1_PIN_OE       DefineBit(rGPIOE_OEN, bit1)
#define GPIOE1_PIN_PHN      DefineBit(rGPIOE_PHN, bit1)

#define GPIOE0_PIN   	    DefineBit(rGPIOE_DAT, bit0)
#define GPIOE0_PIN_OE       DefineBit(rGPIOE_OEN, bit0)
#define GPIOE0_PIN_PHN      DefineBit(rGPIOE_PHN, bit0)

#define GPIOD7_PIN   	    DefineBit(rGPIOD_DAT, bit7)
#define GPIOD7_PIN_OE       DefineBit(rGPIOD_OEN, bit7)
#define GPIOD7_PIN_PHN      DefineBit(rGPIOD_PHN, bit7)

#define GPIOD6_PIN   	    DefineBit(rGPIOD_DAT, bit6)
#define GPIOD6_PIN_OE       DefineBit(rGPIOD_OEN, bit6)
#define GPIOD6_PIN_PHN      DefineBit(rGPIOD_PHN, bit6)

#define GPIOD5_PIN   	    DefineBit(rGPIOD_DAT, bit5)
#define GPIOD5_PIN_OE       DefineBit(rGPIOD_OEN, bit5)
#define GPIOD5_PIN_PHN      DefineBit(rGPIOD_PHN, bit5)

#define GPIOD4_PIN   	    DefineBit(rGPIOD_DAT, bit4)
#define GPIOD4_PIN_OE       DefineBit(rGPIOD_OEN, bit4)
#define GPIOD4_PIN_PHN      DefineBit(rGPIOD_PHN, bit4)

#define GPIOD3_PIN   	    DefineBit(rGPIOD_DAT, bit3)
#define GPIOD3_PIN_OE       DefineBit(rGPIOD_OEN, bit3)
#define GPIOD3_PIN_PHN      DefineBit(rGPIOD_PHN, bit3)

#define GPIOD2_PIN   	    DefineBit(rGPIOD_DAT, bit2)
#define GPIOD2_PIN_OE       DefineBit(rGPIOD_OEN, bit2)
#define GPIOD2_PIN_PHN      DefineBit(rGPIOD_PHN, bit2)

#define GPIOD1_PIN   	    DefineBit(rGPIOD_DAT, bit1)
#define GPIOD1_PIN_OE       DefineBit(rGPIOD_OEN, bit1)
#define GPIOD1_PIN_PHN      DefineBit(rGPIOD_PHN, bit1)

#define GPIOD0_PIN   	    DefineBit(rGPIOD_DAT, bit0)
#define GPIOD0_PIN_OE       DefineBit(rGPIOD_OEN, bit0)
#define GPIOD0_PIN_PHN      DefineBit(rGPIOD_PHN, bit0)

#define GPIOC7_PIN   	    DefineBit(rGPIOC_DAT, bit7)
#define GPIOC7_PIN_OE       DefineBit(rGPIOC_OEN, bit7)
#define GPIOC7_PIN_PHN      DefineBit(rGPIOC_PHN, bit7)

#define GPIOC6_PIN   	    DefineBit(rGPIOC_DAT, bit6)
#define GPIOC6_PIN_OE       DefineBit(rGPIOC_OEN, bit6)
#define GPIOC6_PIN_PHN      DefineBit(rGPIOC_PHN, bit6)

#define GPIOC5_PIN   	    DefineBit(rGPIOC_DAT, bit5)
#define GPIOC5_PIN_OE       DefineBit(rGPIOC_OEN, bit5)
#define GPIOC5_PIN_PHN      DefineBit(rGPIOC_PHN, bit5)

#define GPIOC4_PIN   	    DefineBit(rGPIOC_DAT, bit4)
#define GPIOC4_PIN_OE       DefineBit(rGPIOC_OEN, bit4)
#define GPIOC4_PIN_PHN      DefineBit(rGPIOC_PHN, bit4)

#define GPIOC3_PIN   	    DefineBit(rGPIOC_DAT, bit3)
#define GPIOC3_PIN_OE       DefineBit(rGPIOC_OEN, bit3)
#define GPIOC3_PIN_PHN      DefineBit(rGPIOC_PHN, bit3)

#define GPIOC2_PIN   	    DefineBit(rGPIOC_DAT, bit2)
#define GPIOC2_PIN_OE       DefineBit(rGPIOC_OEN, bit2)
#define GPIOC2_PIN_PHN      DefineBit(rGPIOC_PHN, bit2)

#define GPIOC1_PIN   	    DefineBit(rGPIOC_DAT, bit1)
#define GPIOC1_PIN_OE       DefineBit(rGPIOC_OEN, bit1)
#define GPIOC1_PIN_PHN      DefineBit(rGPIOC_PHN, bit1)

#define GPIOC0_PIN   	    DefineBit(rGPIOC_DAT, bit0)
#define GPIOC0_PIN_OE       DefineBit(rGPIOC_OEN, bit0)
#define GPIOC0_PIN_PHN      DefineBit(rGPIOC_PHN, bit0)

#define GPIOB7_PIN   	    DefineBit(rGPIOB_DAT, bit7)
#define GPIOB7_PIN_OE       DefineBit(rGPIOB_OEN, bit7)
#define GPIOB7_PIN_PHN      DefineBit(rGPIOB_PHN, bit7)	

#define GPIOB6_PIN   	    DefineBit(rGPIOB_DAT, bit6)
#define GPIOB6_PIN_OE       DefineBit(rGPIOB_OEN, bit6)
#define GPIOB6_PIN_PHN      DefineBit(rGPIOB_PHN, bit6)

#define GPIOB5_PIN   	    DefineBit(rGPIOB_DAT, bit5)
#define GPIOB5_PIN_OE       DefineBit(rGPIOB_OEN, bit5)
#define GPIOB5_PIN_PHN      DefineBit(rGPIOB_PHN, bit5)

#define GPIOB4_PIN   	    DefineBit(rGPIOB_DAT, bit4)
#define GPIOB4_PIN_OE       DefineBit(rGPIOB_OEN, bit4)
#define GPIOB4_PIN_PHN      DefineBit(rGPIOB_PHN, bit4)

#define GPIOB3_PIN   	    DefineBit(rGPIOB_DAT, bit3)
#define GPIOB3_PIN_OE       DefineBit(rGPIOB_OEN, bit3)
#define GPIOB3_PIN_PHN      DefineBit(rGPIOB_PHN, bit3)

#define GPIOB2_PIN   	    DefineBit(rGPIOB_DAT, bit2)
#define GPIOB2_PIN_OE       DefineBit(rGPIOB_OEN, bit2)
#define GPIOB2_PIN_PHN      DefineBit(rGPIOB_PHN, bit2)

#define GPIOB1_PIN   	    DefineBit(rGPIOB_DAT, bit1)
#define GPIOB1_PIN_OE       DefineBit(rGPIOB_OEN, bit1)
#define GPIOB1_PIN_PHN      DefineBit(rGPIOB_PHN, bit1)

#define GPIOB0_PIN   	    DefineBit(rGPIOB_DAT, bit0)
#define GPIOB0_PIN_OE       DefineBit(rGPIOB_OEN, bit0)
#define GPIOB0_PIN_PHN      DefineBit(rGPIOB_PHN, bit0)

#define GPIOA7_PIN   	    DefineBit(rGPIOA_DAT, bit7)
#define GPIOA7_PIN_OE       DefineBit(rGPIOA_OEN, bit7)
#define GPIOA7_PIN_PHN      DefineBit(rGPIOA_PHN, bit7)

#define GPIOA5_PIN   	    DefineBit(rGPIOA_DAT, bit5)
#define GPIOA5_PIN_OE       DefineBit(rGPIOA_OEN, bit5)
#define GPIOA5_PIN_PHN      DefineBit(rGPIOA_PHN, bit5)

#define GPIOA4_PIN   	    DefineBit(rGPIOA_DAT, bit4)
#define GPIOA4_PIN_OE       DefineBit(rGPIOA_OEN, bit4)
#define GPIOA4_PIN_PHN      DefineBit(rGPIOA_PHN, bit4)

#define GPIOA3_PIN   	    DefineBit(rGPIOA_DAT, bit3)
#define GPIOA3_PIN_OE       DefineBit(rGPIOA_OEN, bit3)
#define GPIOA3_PIN_PHN      DefineBit(rGPIOA_PHN, bit3)

#define GPIOA2_PIN   	    DefineBit(rGPIOA_DAT, bit2)
#define GPIOA2_PIN_OE       DefineBit(rGPIOA_OEN, bit2)
#define GPIOA2_PIN_PHN      DefineBit(rGPIOA_PHN, bit2)

#define GPIOA1_PIN   	    DefineBit(rGPIOA_DAT, bit1)
#define GPIOA1_PIN_OE       DefineBit(rGPIOA_OEN, bit1)
#define GPIOA1_PIN_PHN      DefineBit(rGPIOA_PHN, bit1)


#define USB_PowerSW	GPIOA5_PIN
#define  led0 				GPIOA4_PIN		


void Delay(WORD  ms);		                                                  
void wait_us(u16 us);
void Delayms(uint16 Time);


#define  ENABLE_FLASH_MODE
#define Debug_Eeprom


#ifdef ENABLE_FLASH_MODE 


//#define Debug_Eeprom





#define PARSAVETIME				2
#define F_PARSAVETIME			2

extern bdata uint8 ParAdjStateH;
extern bdata uint8 ParAdjStateL;



extern bit sF_Bit15;
extern bit sF_Bit14;
extern bit sF_Bit13;
extern bit sF_Bit12;
extern bit sF_Bit11;
extern bit sF_Bit10;
extern bit sF_Bit09;
extern bit sF_Bit08;

extern bit sF_Bit07;
extern bit sF_Bit06;
extern bit sF_Bit05;
extern bit sF_Bit04;
extern bit sF_Bit03;
extern bit sF_Bit02;
extern bit sF_Bit01;
extern bit sF_Bit00;


#define FLAG_link			0x01

#define DEF_BRIGHTNESS   32
#define DEF_CONTRAST   	32
#define DEF_Backlight   32
#define DEF_COLOR   32
#define DEF_SHARP   32
#define DEF_VOL   32



#define FLAG_BRI_CTRL		0x02

#define FLAG_DIRUD			0x04
#define FLAG_DIRRL			0x08
#define FLAG_V1MIRROR		0x10
#define FLAG_V2MIRROR		0x20

#define FLAG_AUDIOMUTE		0x40
#define FLAG_POWER			0x80


//	设置参数发生调整的状态
#define ActiveSave_RelPar()			sF_Bit15 = 1
#define ActiveSave_ADC()				sF_Bit14 = 1
#define ActiveSave_Color1()			sF_Bit13 = 1
#define ActiveSave_Backlight1()		sF_Bit12 = 1
#define ActiveSave_Video()			sF_Bit11 = 1
#define ActiveSave_Audio()			sF_Bit10 = 1
#define ActiveSave_ImageMode()		sF_Bit09 = 1
#define ActiveSave_AudioMode()		sF_Bit08 = 1

#define ActiveSave_Reset()			sF_Bit07= 1
#define ActiveSave_Volume()			sF_Bit06= 1
#define ActiveSave_Sharp()			sF_Bit05= 1
#define ActiveSave_Color()				sF_Bit04= 1
#define ActiveSave_Flag()				sF_Bit03= 1
#define ActiveSave_Backlight()			sF_Bit02= 1
#define ActiveSave_Contrast()			sF_Bit01= 1
#define ActiveSave_Brightness()		sF_Bit00= 1


//	清楚参数发生调整的状态
#define ClearState_RelPar()			sF_Bit15 = 0
#define ClearState_ADC()				sF_Bit14 = 0
#define ClearState_Color1()			sF_Bit13 = 0
#define ClearState_Backlight1()			sF_Bit12 = 0
#define ClearState_Video()				sF_Bit11 = 0
#define ClearState_Audio()				sF_Bit10 = 0
#define ClearState_ImageMode()		sF_Bit09 = 0
#define ClearState_AudioMode()		sF_Bit08 = 0

#define ClearState_Reset()				sF_Bit07=0
#define ClearState_Volume()			sF_Bit06= 0
#define ClearState_Sharp()			sF_Bit05= 0
#define ClearState_Color()				sF_Bit04= 0
#define ClearState_Flag()				sF_Bit03= 0
#define ClearState_Backlight()			sF_Bit02= 0
#define ClearState_Contrast()			sF_Bit01= 0
#define ClearState_Brightness()		sF_Bit00= 0


//	返回参数是否有调整的状态
#define GetState_RelPar()				sF_Bit15
#define GetState_ADC()				sF_Bit14
#define GetState_Color1()				sF_Bit13
#define GetState_Backlight1()			sF_Bit12
#define GetState_Video()				sF_Bit11
#define GetState_Audio()				sF_Bit10
#define GetState_ImageMode()			sF_Bit09
#define GetState_AudioMode()			sF_Bit08


#define GetState_Reset()				sF_Bit07
#define GetState_Volume()				sF_Bit06
#define GetState_Sharp()				sF_Bit05
#define GetState_Color()				sF_Bit04
#define GetState_Flag()				sF_Bit03
#define GetState_Backlight()			sF_Bit02
#define GetState_Contrast()			sF_Bit01
#define GetState_Brightness()			sF_Bit00

#define ClearParAdjState()			ParAdjStateL = 0x00,ParAdjStateH = 0x00



#define FWVersion				{0,0,1}

#define ReleaseDate				{1,5,0,6,1,6}

#define UserName				{'M','D','W'}


#define eepAdd_SYSPAR					0x3E00		// 显示模式无关参数的起始地址
#define eepAdd_PRODUCTID				0x3E20		// 产品ID的起始地址
#define 	ENABLE_PROGRAM				0x10	
#define 	ENABLE_ERASE					0x20


#define 	PROGRAM_TIMING				0x08		
#define 	ERASE_TIMING 					0x08

typedef struct {
	uint8  Brightness;			// 亮度
	uint8  Contrast;			// 对比度
	uint8  Backlight;			// 背光亮度控制
	uint8  Flag;				// 系统标志
	uint8  Color;
	uint8  Sharp;
	uint8  Volume;
	uint8  Reset;
	
	}SYSPAR;


extern SYSPAR  data SysPar;


#define SIZE_SYSPAR			sizeof(SYSPAR)		// 19 模式无关参数的字节数


#define     FLASH_BASE       		((BYTE volatile xdata*)0x0E80) 

void EepInit(void);
void Eep_Write(u16 Addr,u16 Num,u8 *buf);
void Eep_Read(u16 Addr,u16 Num,u8 *buf);
void EepLoadAllPar(void);
void EepSavePar(void);
void EraseFlash(void);


#endif




#endif
