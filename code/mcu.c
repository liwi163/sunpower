#include "gheader.h"

u8 ResetStatus;

bdata bit m_b10ms;
bdata bit m_b100ms;
bdata bit m_b500ms;
bdata bit m_b1000ms;

#ifdef UART0
u8 RS_buf[RS_BUF_MAX];
data u8 RS_in=0,RS_out=0;
bit RS_Xbusy=0;
#endif

/*
*************************************************************************
设计		liwei
文件		main
功能		主函数入口
*************************************************************************
*/
void InitMcuReg(void)
{

	rRC_LADJ = rRC_CALIBRATION_DATA;
	ResetStatus = rRESET_FLG;
	rRESET_FLG |= 0x80;
	
	rRC_CALIB_EN = 0x80;	
	rSOURCE_CLK_SLT = 0xA0;		      //内部12M晶振
	rSYS_CTL &=~0x80;				//数字滤波功能
	rWDT_CTL |=0xA0;				//关闭看门狗
	
	rSYS_CTL &=~0x80;				//Enable reset have digital filter
	rLVD_CTL = 0xA0;		
	EA = 1;							//全局中断

//	rSOURCE_CLK_SLT|=0x03;               // 1T

}



/*
*************************************************************************
设计		liwei
文件		main
功能		主函数入口
*************************************************************************
*/
void InitMcuPort(void)
{
	GPIOA1_PIN_OE=0;
	GPIOA2_PIN_OE=0;
	GPIOA3_PIN_OE=0;

	GPIOA1_PIN_PHN=0; /*上拉*/
	GPIOA2_PIN_PHN=0; /*上拉*/
	GPIOA3_PIN_PHN=0; /*上拉*/
	
	//GPIOB1_PIN=0;
	//GPIOB2_PIN=0;
	//GPIOB3_PIN=0;

	GPIOA4_PIN_OE=1;
	GPIOA5_PIN_OE=1;

	GPIOA5_PIN=0;
	GPIOA4_PIN=0;

}




/*
*************************************************************************
设计		liwei
文件		InitSysTimer
功能		系统时钟初始化使用定时器0
*************************************************************************
*/

void InitSysTimer(void)
{
	TMOD|=0x01;						// 定时器0使用16位定时器
	TL0= SYSTMR_DATAL;					// 载入定时器初始值
	TH0= SYSTMR_DATAH;
	ET0= 1;							// 允许定时中断1
	TR0= 1;								// 启动定时器
}


/*
*************************************************************************
设计		liwei
文件		Timer0INT
功能		定时器0中断执行函数
*************************************************************************
*/

void Timer0INT(void) interrupt 1
{
	TR0=0;
	TL0= SYSTMR_DATAL;					// 载入定时器初始值
	TH0= SYSTMR_DATAH;
	TR0=1;
	tic_01++;
	tic_pc++;

	if((tic_01%10)==0)
		{
			m_b10ms=1;
		}
	
	if((tic_01%100)==0){
			m_b100ms=1;
		}	

	if((tic_01%500)==0){
			m_b500ms=1;
		}		
	if((tic_01%1000)==0){
			m_b1000ms=1;
		}
	
}

bit Flg_KeyScanDly = 1;

void SysTimer(void)
{
	if(m_b10ms)
		{
			m_b10ms=0;
			Flg_KeyScanDly = ~Flg_KeyScanDly;
			if (Flg_KeyScanDly) KeyScan();
		}

	if(m_b1000ms)
		{
			m_b1000ms=0;
			ShowQCicon();
			EepSavePar();
		}
	
	if(m_b500ms)
		{
			m_b500ms=0;
			DisplayAll();
			led0=~led0;
			//ReadADC(ADC_CH0);
			//ReadADC(ADC_CH2);
			//ReadADC(ADC_CH3);
		}
	
}



#ifdef UART0

/*
*************************************************************************
设计		liwei
文件		InitUartPort
功能		串口中断函数
			这里使用UART 0作为串口调试端口
			使用一个专用的定时器来做波特率
			发生器
			串口0使用的IO口位: TX0 B 路径 22pin
										   RX0 B 路径 21pin
				
*************************************************************************
*/

void SelectUart0Baudrate(BYTE BitRateIndex)
{
	switch(BitRateIndex)
	{
		case BIT_RATE600:
			rSBRG0H = 0xCE;
			rSBRG0L = 0x20;
			break;
		case BIT_RATE1200:
			rSBRG0H = 0xA7;
			rSBRG0L = 0x10;
			break;
		case BIT_RATE2400:
			rSBRG0H = 0x93;
			rSBRG0L = 0x88;
			break;
		case BIT_RATE4800:
			rSBRG0H = 0x89;
			rSBRG0L = 0xC4;
			break;
		case BIT_RATE9600:
			rSBRG0H = 0x84;
			rSBRG0L = 0xE2;
			break;
		case BIT_RATE14400:
			rSBRG0H = 0x83;
			rSBRG0L = 0x40;
			break;
		case BIT_RATE19200:
			rSBRG0H = 0x82;
			rSBRG0L = 0x71;
			break;
		case BIT_RATE38400:
			rSBRG0H = 0x81;
			rSBRG0L = 0x38;		
			break;
		case BIT_RATE57600:
			rSBRG0H = 0x80;
			rSBRG0L = 0xD0;			
			break;
		case BIT_RATE115200:
			rSBRG0H = 0x80;
			rSBRG0L = 0x68;	
			break;
		case BIT_RATE230400:
			rSBRG0H = 0x80;
			rSBRG0L = 0x34;				
			break;
		default:
			rSBRG0H = 0x80;
			rSBRG0L = 0x68;
			break;
	}	
}


/*
*************************************************************************
设计		liwei
文件		InitUartPort
功能		串口中断函数
			这里使用UART 0作为串口调试端口
			串口0使用定时器1作为可变频率发生器
			串口0使用的IO口位: TX0 B 路径 22pin
									     RX0 B 路径 21pin
				
*************************************************************************
*/

void InitUartPort(void)
{
	GPIOB7_PIN_OE=0;  // rx 输入
	GPIOC0_PIN_OE=1;  // tx 输出
	rGPIOB_FUN1|=0x40; // b7设置为RX 当这位设置为RXB时c0会自动设置为TXB

	//SelectUart0Baudrate(BIT_RATE9600);
	SelectUart0Baudrate(BIT_RATE115200);

	
	SCON0=0x50;  // 模式1
	
	ES = 1;				/*打开串口中断*/ 

}

/*
*******************************************************************************
设计		liwei
文件		uart0_int
功能		串口中断处理


*******************************************************************************

*/

void uart0_int(void) interrupt 4 using 1
{
	if( RI ) {					//--- Receive interrupt ----
		RI = 0;
		RS_buf[RS_in++] = SBUF0;
		if( RS_in>=RS_BUF_MAX ) RS_in = 0;
	}

	if( TI ) {					//--- Transmit interrupt ----
		TI = 0;
		RS_Xbusy=0;
	}
}

/*
*******************************************************************************
设计		liwei
文件		RS_ready
功能		串口中断处理


*******************************************************************************
*/
BYTE RS_ready(void)
{
	if( RS_in == RS_out ) return 0;
	else return 1;
}

/*
*******************************************************************************
设计		liwei
文件		RS_rx
功能		接收函数


*******************************************************************************
*/

BYTE RS_rx(void)
{
	BYTE	ret;
	ES = 0;
	ret = RS_buf[RS_out];
	RS_out++;
	if(RS_out >= RS_BUF_MAX) 
		RS_out = 0;
	ES = 1;

	return ret;
}



/*
*******************************************************************************
设计		liwei
文件		RS_rx
功能		发送函数


*******************************************************************************

*/
void RS_tx(BYTE tx_buf)
{
	while(RS_Xbusy);

	ES = 0;			// To protect interrupt between SBUF and RS_Xbusy when it's slow
	SBUF0 = tx_buf;
	RS_Xbusy=1;
	ES = 1;
}


#endif
