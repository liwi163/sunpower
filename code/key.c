#include "gheader.h"


/*
********************************************************************************
*		定义键盘状态机的状态
********************************************************************************
*/
#define KEY_STATE_UP					1      /* Key scanning states used in KeyScan()                   */
#define KEY_STATE_DEBOUNCE				2
#define KEY_STATE_RPT_START_DLY		3
#define KEY_STATE_RPT_DLY				4

/*
********************************************************************************
*		键盘模块所使用的静态变量
********************************************************************************
*/
static uint8  	KeyBuf[KEY_BUF_SIZE];
static uint8 	KeyBufInLx;
static uint8 	KeyBufOutLx;
static uint8 	KeyScanState;
static uint8 	KeyRptStartDlyCtr;
static uint8 	KeyRptDlyCtr;
static uint16   KeyDownTmr;


/*
********************************************************************************
*		键盘模块的全局变量定义
********************************************************************************
*/
bit Flg_KeyLock=0;
bit Flg_KeyOnePress = 0;
uint8 IR_RptCount;

/*
********************************************************************************
*		键盘模块所使用的静态功能函数定义
********************************************************************************
*/
 void KeyBufIn(u8 key);
static u8 KeyGetKeyCode(void);
static u8 KeyIsDown(void);


/*
********************************************************************************  
* 	函 数 名: KeyBufIn
* 	功能描述: 按键代码放入到键盘缓冲区中
* 	输    入: key	:按键的代码
* 	返    回: 无
********************************************************************************
*/
 void KeyBufIn(u8 key)
{
	u8 tmp;
	tmp = KeyBufInLx + 1;
	if (tmp == KEY_BUF_SIZE) tmp = 0;
	if (tmp == KeyBufOutLx)  return;		//如果尾指针加1以后等于头指针，则表示命令队列已满
	KeyBufInLx = tmp;
	KeyBuf[KeyBufInLx] = key;
}

/*
********************************************************************************  
* 	函 数 名: KeyIsDown
* 	功能描述: 判断有没有按键按下去
* 	输    入: 无
* 	返    回: 0		: 没有按键按下
*             1		: 有按键按下
********************************************************************************
*/
static u8 KeyIsDown(void)
{
	if (KeyGetKeyCode() == KEYCODE_NOPRESS)  {
		Flg_KeyOnePress = 0;
		return 0;
		}
	
	else  {
		if (KeyDownTmr < 0xFFFF)  KeyDownTmr++;
		return 1;
		}
}

/*
*************************************************************************
设计		liwei
文件		ADC_Init
功能		主函数入口
*************************************************************************
*/

void ADC_Init(void)
{


	GPIOB6_PIN_OE=1;
	GPIOB6_PIN_PHN=1;
	rGPIOB_FUN1|=0x30;  // B6设置为ADC 输出



	GPIOB5_PIN_OE=1;
	GPIOB5_PIN_PHN=1;
	rGPIOB_FUN1|=0x0c;  // B5设置为ADC 输出



	GPIOB4_PIN_OE=1;
	GPIOB4_PIN_PHN=1;
	rGPIOB_FUN1|=0x03;  // B4设置为ADC 输出


	GPIOB3_PIN_OE=1;
	GPIOB3_PIN_PHN=1;
	rGPIOB_FUN2|=0xc0;  // B3设置为ADC 输出


	GPIOB2_PIN_OE=1;
	GPIOB2_PIN_PHN=1;
	rGPIOB_FUN2|=0x30;  // B2设置为ADC 输出

	GPIOB1_PIN_OE=1;
	GPIOB1_PIN_PHN=1;
	rGPIOB_FUN2|=0x0c;  // B1设置为VREF ADC 参考电压


	GPIOB0_PIN_OE=1;
	GPIOB0_PIN_PHN=1;
	rGPIOB_FUN2|=0x03;  // B0设置为ADC 输出

	GPIOA7_PIN_OE=1;
	GPIOA7_PIN_PHN=1;
	rGPIOA_FUN1|=0xc0;  //A7设置为ADC 输出

	
	rADC_CTL = 0x80;      // 连续转换模式
	//ADC converter speed 125KHz
	rADC_SEL = 0x80 +VREF_FROM_VDD;
	//Select AD Channel
	//rADC_ENCH = ADC_CH1;		//Select ADC channe	
	
	//Enable ADC power
	//rADC_CTL &= 0x7F;			//Enable low speed adc(bit7=0) 	

	Delayms(1);


	//Enable Continuous mode
	//rADC_CTL |= 0x20;			
}


WORD DRV_ReadAnalogChannel(BYTE AD_Channel)
{
	WORD AdcWdata;
	BYTE AdcBdata; 
	
	//rADC_SEL = 0x80;
	rADC_SEL = 0x80 + 0;//VREF_FROM_AREF;//VREF_FROM_VDD;


	
	rADC_ENCH = AD_Channel;		//Select ADC channe	
	//rADC_TMPS &= 0xFE;			//Disable EN_ADC_TMPS
	//select VerF
	//rADC_VREF = VREF_FROM_VDD;
	rADC_CTL &= 0x7F;			//Enable low speed adc(bit7=0) 	
	_nop_();
	rADC_CTL |= 0x40;			//=1:Start ADC converter
	do
	{
	_nop_();
	}
	while(rADC_CTL & 0x40);	//1=>0:convert finish
	AdcWdata = 0;
	#if 0
	//For ADC Tool
	PMCTL_DATA[7] = AD_Channel;
	PMCTL_DATA[8] = rADC_DATAH;
	PMCTL_DATA[9] = rADC_DATAL & 0x0F;
	#endif
	AdcBdata = rADC_DATAL;
	AdcBdata = AdcBdata & 0x0F;
	AdcWdata = rADC_DATAH;
	AdcWdata = AdcWdata << 4;
	AdcWdata = AdcWdata + AdcBdata;


	//DRV_Printf("Show rADC_DATAH = %d \r\n",rADC_DATAH);
	//DRV_Printf("Show rADC_DATAL = %d \r\n",rADC_DATAL);	
	return AdcWdata;		
}


WORD API_AverageADCData(BYTE ADC_Channel)
{
#define ADC_SUM_TIME		16	
#define	ADC_SORTING_SIZE	0x03	
	
BYTE R7;

WORD ADC_TotalData;

	ADC_TotalData = 0;
	for(R7=0;R7<ADC_SUM_TIME;R7++)
	{		
		//Delay(10);
		ADC_TotalData = ADC_TotalData + DRV_ReadAnalogChannel(ADC_Channel);	
	}
	ADC_TotalData = ADC_TotalData / ADC_SUM_TIME;	
	return ADC_TotalData;

}










/*
********************************************************************************  
* 	函 数 名		: KeyGetKeyCode
* 	功能描述	: 通过ADC值确定按的那个功能按键
* 	输    入		: 无
* 	返    回		: 按键码
*            				
********************************************************************************
*/
//#define	EN_DEBUG_MSG

u8 KeyGetKeyCode(void)
{

		if(GPIOA1_PIN==0)
			{
				return 	KEYCODE_VOLDOWN;
			}
		else if(GPIOA2_PIN==0)
			{
				return 	KEYCODE_VOLUP;
			}
		else if(GPIOA3_PIN==0)
			{
				return 	KEYCODE_MUTE;
			}
		else
			{
				return KEYCODE_NOPRESS;
			}
			


#if 0	
       u8 i=0,keytemp;
	uint16 KeyIn0;
//	KeyIn2 = GetADCValue(ADC_CH2);
	KeyIn0= GetADCValue(ADC_CH0);
	#if defined(EN_DEBUG_MSG)
	
	if(KeyIn0>0)
	Printf("\r\nKeyIn0 ADC Value is: %02bx", (u8)(KeyIn0>>4) );

	#endif
	
	if ((KeyIn0<10)) return    KEYCODE_NOPRESS;


	keytemp=(u8)(KeyIn0>>4);
	for (i = 0; i < sizeof(KeycodeArry0); i++)  {
	if ((keytemp >= KeycodeArry0[i][0]) && (keytemp <= KeycodeArry0[i][1]))
	break;
	}	
	if (i >= 6) return	 KEYCODE_NOPRESS;
	else return  KeycodeArry0[i][2];

#endif
		

	}

/*
********************************************************************************  
* 	函 数 名: KeyGetKey
* 	功能描述: 从键盘缓冲区中读按键代码，如果缓冲区是空则返回0xff
* 	输    入: 无
* 	返    回: 按键的代码
********************************************************************************
*/
uint8 KeyGetKey(void)
{
	if (KeyBufOutLx == KeyBufInLx )  return 0xFF;
	KeyBufOutLx++;
	if (KeyBufOutLx == KEY_BUF_SIZE)  KeyBufOutLx = 0;
	return KeyBuf[KeyBufOutLx];
}




/*
********************************************************************************  
* 	函 数 名: KeyInit
* 	功能描述: 键盘模块初始化，要正确使用键盘模块的功能，要首先调用初始化
* 	输    入: 无
* 	返    回: 0		: 键盘缓冲区中没有按键
*             1		: 键盘缓冲区中有按键
********************************************************************************
*/
void KeyInit(void)
{
	uint8 i;
	
	KeyBufInLx 		= KEY_BUF_SIZE - 1;
	KeyBufOutLx 	= KEY_BUF_SIZE - 1;
	KeyScanState 	= KEY_STATE_UP;
	KeyDownTmr 	= 0;
	//IrAckCount	= 0;
	for (i=0; i< KEY_BUF_SIZE; i++) KeyBuf[i] = 0xFF;
	Flg_KeyLock		= 0;
}
/*
********************************************************************************  
* 	函 数 名: KeyHit
* 	功能描述: 应用程序调用该函数判断键盘缓冲区有无按键
* 	输    入: 无
* 	返    回: 无
********************************************************************************
*/
bit KeyHit(void)
{
	if (KeyBufOutLx == KeyBufInLx )  return 0;
	else  return 1;
}



/*
********************************************************************************  
* 	函 数 名: KeyGetKeyDownTime
* 	功能描述: 返回按键按下去的时间，这个时间是扫描时间间隔的计数值
* 	输    入: 无
* 	返    回: 按键按下去的时间
********************************************************************************
*/
uint16 KeyGetKeyDownTime(void)
{
	return KeyDownTmr;
}

void KeyDownTimeClear(void)
{
	KeyDownTmr = 0;
}



/*
********************************************************************************  
* 	函 数 名: KeyScan
* 	功能描述: 这是整个键盘模块的核心，完成整个键盘状态机的处理
* 	输    入: 无
* 	返    回: 按键按下去的时间
********************************************************************************
*/
void KeyScan(void)
{
	if (Flg_KeyLock)  return;						// 按键被锁定，不进行任何处理
	
	switch (KeyScanState)  {
		case  KEY_STATE_UP:							// 按键没有按下，要查看有没有按键
			if (KeyIsDown())  {						// 检查是否有按键按下
				IR_RptCount = 0;
				KeyScanState = KEY_STATE_DEBOUNCE;	// 有按键按下，改变按键扫描的状态
				//KeyDownTmr = 0;					// 按键按下的时间清零
				}
			KeyDownTmr = 0;
			break;

		case  KEY_STATE_DEBOUNCE:					// 按键已按下，获取扫描码，放入缓冲区
			if (KeyIsDown())  {						// 检查是否有按键按下
				KeyBufIn(KeyGetKeyCode());			// 获取扫描码，并放入缓冲区
				KeyRptStartDlyCtr = KEY_RPT_START_DLY;	// 启动自动重复功能
				KeyScanState = KEY_STATE_RPT_START_DLY;	// 转换按键扫描状态
				}

			else  KeyScanState = KEY_STATE_UP;		// 没有键按下，改变按键扫描状态
			break;

		case  KEY_STATE_RPT_START_DLY:				// 等待启动自动重复
			if (KeyIsDown())  {					// 检查按键是否一直按着
				if (KeyRptStartDlyCtr)  {			// 检查是否需要延时
					KeyRptStartDlyCtr--;
					if (KeyRptStartDlyCtr == 0)  {	// 检查延时时间到了没有
						KeyBufIn(KeyGetKeyCode());
						KeyRptDlyCtr = KEY_RPT_DLY;	// 设置下一次重复的延时间隔
						KeyScanState = KEY_STATE_RPT_DLY;
						}
					}
				}
			
			else  KeyScanState = KEY_STATE_DEBOUNCE;	// 键没有按下，改变扫描状态
			break;

		case  KEY_STATE_RPT_DLY:					// 等待下一次重复
			if (KeyIsDown())  {						// 检查按键是否一直按着
				if (KeyRptDlyCtr)  {				// 检查是否需要延时
					KeyRptDlyCtr--;
					if (KeyRptDlyCtr == 0)  {		// 检查延时时间到了没有
						KeyBufIn(KeyGetKeyCode());
						KeyRptDlyCtr = KEY_RPT_DLY;	// 设置下一次重复的延时间隔
						}
					}
				}

			else  KeyScanState = KEY_STATE_DEBOUNCE;	// 键没有按下，改变扫描状态
			break;
		}
}


