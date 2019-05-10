#include "gheader.h"
/*
*************************************************************************
设计		liwei
文件		LCD
功能		LCD的配置和使用函数
		    	我们使用了56F216的A模式lcd驱动

LCD 建模
     A
 F       B
     G
 E       C
     D
		    	
*************************************************************************
github 2019.5.10
*/

u8  DispNum[8];  	/*10个数字电压的十位只有2段但也用一个数字表示*/
u8 idata DispBuff[19]=0; /*显示buff这里有19个字节*/
union FlageGrup Uicon[3]=0;

DATA u8 Effe=0;
DATA u8 usb1V=0,usb1A=0,usb2V=0,usb2A=0;


BYTE code DIGIT_CODE[]={
	
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F,				       // '0'
	SEG_B|SEG_C,								          	       // '1'
	SEG_A|SEG_B|SEG_D|SEG_E|SEG_G,				    			// '2'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_G,				    			// '3'
	SEG_B|SEG_C|SEG_F|SEG_G,					       	 	// '4'
	SEG_A|SEG_C|SEG_D|SEG_F|SEG_G,				   		 	// '5'
	SEG_A|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G,					// '6'
	SEG_A|SEG_B|SEG_C|SEG_F,						      		// '7'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G,				// '8'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_F|SEG_G,					// '9'
	/*10_31*/
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,
	0x00,								                                    /*空白*/
	
	SEG_A|SEG_I|SEG_K|SEG_M,								// '!'
	SEG_B|SEG_J,											// '"'
	SEG_D|SEG_E|SEG_F|SEG_J|SEG_G|SEG_H|SEG_M,				// '#'
	SEG_D|SEG_E|SEG_F|SEG_J|SEG_G|SEG_M,					// 'o'
	SEG_C|SEG_F|SEG_K|SEG_L,								// '%'
	SEG_A|SEG_C|SEG_D|SEG_E|SEG_I|SEG_K|SEG_G|SEG_N,		// '&'
	SEG_K,													// '''
	SEG_K|SEG_N,											// '('
	SEG_I|SEG_L,											// ')'
	SEG_I|SEG_J|SEG_K|SEG_G|SEG_H|SEG_L|SEG_M|SEG_N,		// '*'
	SEG_J|SEG_G|SEG_H|SEG_M,								// '+'
	SEG_L,													// ','
	SEG_G|SEG_H,											// '-'
	SEG_M,													// '.'
	SEG_K|SEG_L,											// '/'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F,					// '0'
	SEG_B|SEG_C,											// '1'
	SEG_A|SEG_B|SEG_D|SEG_E|SEG_G|SEG_H,					// '2'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_G|SEG_H,					// '3'
	SEG_B|SEG_C|SEG_F|SEG_G|SEG_H,							// '4'
	SEG_A|SEG_C|SEG_D|SEG_F|SEG_G|SEG_H,					// '5'
	SEG_A|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G|SEG_H,				// '6'
	SEG_A|SEG_B|SEG_C|SEG_F,								// '7'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G|SEG_H,		// '8'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_F|SEG_G|SEG_H,				// '9'
	SEG_J|SEG_M,											// ':'
	SEG_J|SEG_L,											// '//'
	SEG_K|SEG_N,											// '<'
	SEG_D|SEG_G|SEG_H,										// '='
	SEG_I|SEG_L,											// '>'
	SEG_A|SEG_B|SEG_F|SEG_H|SEG_M,							// '?'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_G|SEG_M,				// '@'
	SEG_A|SEG_B|SEG_C|SEG_E|SEG_F|SEG_G|SEG_H,				// 'A'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_J|SEG_H|SEG_M,				// 'B'
	SEG_A|SEG_D|SEG_E|SEG_F,								// 'C'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_J|SEG_M,					// 'D'
	SEG_A|SEG_D|SEG_E|SEG_F|SEG_G|SEG_H,					// 'E'
	SEG_A|SEG_E|SEG_F|SEG_G|SEG_H,							// 'F'
	SEG_A|SEG_C|SEG_D|SEG_E|SEG_F|SEG_H,					// 'G'
	SEG_B|SEG_C|SEG_E|SEG_F|SEG_G|SEG_H,					// 'H'
	SEG_A|SEG_D|SEG_J|SEG_M,								// 'I'
	SEG_B|SEG_C|SEG_D|SEG_E,								// 'J'
	SEG_E|SEG_F|SEG_K|SEG_G|SEG_N,							// 'K'
	SEG_D|SEG_E|SEG_F,										// 'L'
	SEG_B|SEG_C|SEG_E|SEG_F|SEG_I|SEG_K,					// 'M'
	SEG_B|SEG_C|SEG_E|SEG_F|SEG_A,					// 'N'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F,					// 'O'
	SEG_A|SEG_B|SEG_E|SEG_F|SEG_G|SEG_H,					// 'P'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_N,				// 'Q'
	SEG_A|SEG_B|SEG_E|SEG_F|SEG_G|SEG_H|SEG_N,				// 'R'
	SEG_A|SEG_C|SEG_D|SEG_F|SEG_G|SEG_H,							// 'S'
	SEG_A|SEG_J|SEG_M,										// 'T'
	SEG_B|SEG_C|SEG_D|SEG_E|SEG_F,							// 'U'
	SEG_E|SEG_F|SEG_K|SEG_L,								// 'V'
	SEG_B|SEG_C|SEG_E|SEG_F|SEG_L|SEG_N,					// 'W'
	SEG_I|SEG_K|SEG_L|SEG_N,								// 'X'
	SEG_B|SEG_C|SEG_D|SEG_F|SEG_G|SEG_H,					// 'Y'
	SEG_A|SEG_D|SEG_K|SEG_L,								// 'Z'
	0x0000, 												// '['
	0x0000, 												// '\'
	0x0000, 												// ']'
	0x0000, 												// '^'
	SEG_D,													// '_'
	SEG_K,													// '''
	SEG_A|SEG_B|SEG_C|SEG_E|SEG_F|SEG_G|SEG_H,				// 'A'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_J|SEG_H|SEG_M,				// 'B'
	SEG_A|SEG_D|SEG_E|SEG_F,								// 'C'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_J|SEG_M,					// 'D'
	SEG_A|SEG_D|SEG_E|SEG_F|SEG_G|SEG_H,					// 'E'
	SEG_A|SEG_E|SEG_F|SEG_G|SEG_H,							// 'F'
	SEG_A|SEG_C|SEG_D|SEG_E|SEG_F|SEG_H,					// 'G'
	SEG_B|SEG_C|SEG_E|SEG_F|SEG_G|SEG_H,					// 'H'
	SEG_A|SEG_D|SEG_J|SEG_M,								// 'I'
	SEG_B|SEG_C|SEG_D|SEG_E,								// 'J'
	SEG_E|SEG_F|SEG_K|SEG_G|SEG_N,							// 'K'
	SEG_D|SEG_E|SEG_F,										// 'L'
	SEG_B|SEG_C|SEG_E|SEG_F|SEG_I|SEG_K,					// 'M'
	SEG_A|SEG_B|SEG_C|SEG_E|SEG_F,							// 'N'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F,					// 'O'
	SEG_A|SEG_B|SEG_E|SEG_F|SEG_G|SEG_H,					// 'P'
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_N,				// 'Q'
	SEG_A|SEG_B|SEG_E|SEG_F|SEG_G|SEG_H|SEG_N,				// 'R'
	SEG_A|SEG_C|SEG_D|SEG_F|SEG_G|SEG_H,							// 'S'
	SEG_A|SEG_J|SEG_M,										// 'T'
	SEG_B|SEG_C|SEG_D|SEG_E|SEG_F,							// 'U'
	SEG_E|SEG_F|SEG_K|SEG_L,								// 'V'
	SEG_B|SEG_C|SEG_E|SEG_F|SEG_L|SEG_N,					// 'W'
	SEG_I|SEG_K|SEG_L|SEG_N,								// 'X'
	SEG_B|SEG_C|SEG_D|SEG_F|SEG_G|SEG_H,					// 'Y'
	SEG_A|SEG_D|SEG_K|SEG_L,								// 'Z'


	
};

u8 code LCD_String[STR_MAX][4]={
	
"OFF ",
"ON  ",
"SCAN",
};

/*
*************************************************************************
设计		liwei
文件		DIGIT_POS_BIT
功能		每个8的每个笔画的位置
                  共4个8字每个8字7个笔画

LCD 建模
     A
 F       B
     G
 E       C
     D
		    	
define px(a,b)   ( (a<<4)|b)   // a表示地址偏移量起始地址为0x80
                                              b表示com0~com3
*************************************************************************
*/

BYTE code DIGIT_POS_BIT[]=
{
	      //  A            B        C           D           E             F            G       
	     px(14,3),px(14,2),px(14,1),px(14,0),px(15,1),px(15,3),px(15,2),		// 第1个8字
	     px(12,3),px(12,2),px(12,1),px(12,0),px(13,1),px(13,3),px(13,2),		// 第2个8字
            px(10,3),px(10,2),px(10,1),px(10,0),px(11,1),px(11,3),px(11,2),		// 第3个8字
            px(8,3),  px(8,2), px(8,1),  px(8,0),  px(9,1), px(9,3),  px(9,2),		// 第4个8字

		px(1,0),px(1,1),px(1,2),px(1,3),px(0,3),px(0,1),px(0,2),				// 第5个8字
             px(3,0),px(3,1),px(3,2),px(3,3),px(2,3),px(2,1),px(2,2),				// 第6个8字
	       px(5,0),px(5,1),px(5,2),px(5,3),px(4,3),px(4,1),px(4,2),				// 第7个8字
             px(7,0),px(7,1),px(7,2),px(7,3),px(6,3),px(6,1),px(6,2),				// 第8个8字

	
};

u8 code ICON_POS_BIT[]=
{  
       	// T        T1        T2      T3         T4        BC1       BC2         L1
	  px(2,0),px(9,0),px(13,0),px(18,0),px(18,1),px(15,0),px(11,0),px(16,3),
	  // L2	   L3		  L4		L5		L6          L7	         L8	      L9	
	  px(16,2),px(16,1),px(16,0),px(17,0),px(17,1),px(17,2),px(17,3),px(18,3),
	  	// L10
	  px(18,2),NOT_SHOW, NOT_SHOW, NOT_SHOW,NOT_SHOW, NOT_SHOW, NOT_SHOW,NOT_SHOW,
};




/*
*************************************************************************
设计		liwei
文件		DisplayIcon
功能		显示数字之外的图标文字信息

*************************************************************************
*/

void DisplayIcon(void)
{
	u8 i,j,offset,p,x,temp,px;
	
	for(i=0;i<3;i++)  // 暂时定义2组图标
		{
			temp=i*8;
			for(j=0,offset=1;j<8;j++,offset<<=1)
				{
					px=ICON_POS_BIT[temp+j];
            				p = px >>3;  //high 5 bits index
					x = px & 0x7;//low  3 bits shift
					if(Uicon[i].Bb&offset)DispBuff[p]|=(1<<x);
					else DispBuff[p]&=(~(1<<x));
				}
		}
	
	
	for(i=0;i<=18;i++)
		{
			PBYTE[0x80+i]=DispBuff[i]; // 写数据到缓存区
		}
}



/*
*************************************************************************
设计		liwei
文件		DisplayNumber
功能		数字显示函数在LCD中显示10个数字

*************************************************************************
*/

void DisplayNumber(void)
{
	u8 i,j,p,x,px,temp;
	u16 dispmask,offset;
	for(i=0;i<8;i++)
		{
			dispmask=DIGIT_CODE[DispNum[i]];   //获得每个数字
			temp=i*7;
			for(j=0,offset=1;j<7;j++,offset<<=1)   // 获得每个数字的每个笔画
				{
					p=temp+j;
					x=DispBuff[p];
					px=DIGIT_POS_BIT[p];
					p=(px>>3);//地址偏移
					
					px = (1<<(px&0x7));				//low  3 bits shift
					x=DispBuff[p];
					if(dispmask&offset) x|=px;
					else x&=(~px);
					DispBuff[p]=x;
					
				}
		}
	for(i=0;i<=18;i++)
		{
			PBYTE[0x80+i]=DispBuff[i]; // 写数据到缓存区
		}
}

/*
*************************************************************************
设计		liwei
文件		DisplayClear
功能	      按模式分别清除字符

*************************************************************************
*/

void DisplayClear(u8 mode)
{
	u8 i;
	switch(mode)
		{	
			case CLEAR_ALL: for(i=0;i<=18;i++){PBYTE[0x80+i]=0;};
			break;
			case CLEAR_ICON:
				Uicon[0].Bb=0x00;
				Uicon[1].Bb=0x00;
				Uicon[2].Bb=0x00;

				DisplayIcon();
				break;
			case CLEAR_NUM_ALL:
				for(i=0;i<8;i++)
					{
						DispNum[i]=0x00;
					}
				DisplayNumber();
				break;
		}
}





/*
*************************************************************************
设计		liwei
文件		LCD
功能		LCD的配置和使用函数
		    	我们使用了56F216的A模式lcd驱动

*************************************************************************
*/

void LCDInit(void)
{

	//Set GPIO as output
	//ACOM port : GPIOC1 - GPIOC4
	rGPIOC_OEN |= 0x1E;	

	//rGPIOC_FUN2|=0x54;  // c2   c3  设置为com2 com1
	//rGPIOC_FUN1|=0x55;  //       c4  设置为com0         c5 c6 c7为seg 0  seg 1 seg2

	
	//ASEG : ASEG0 - ASEG18
	//ASEG0 - 2 = GPIOC5 - GPIOC7
	rGPIOC_OEN |= 0xE0;
 	//ASEG3 - 10 = GPIOD0 - GPIOD7
	rGPIOD_OEN |= 0xFF;	
	//ASEG11 - 18 = GPIOE0 - GPIOE7
	rGPIOE_OEN |= 0xFF;

	//ASEG0 - 18 复用功能开启

	rGPIOC_FUN2|=0x55;  
	rGPIOC_FUN1|=0x55;  


      rGPIOD_FUN1|=0x55; 
	rGPIOD_FUN2|=0x55;  
	
	rGPIOE_FUN1|=0x55;  
	rGPIOE_FUN2|=0x55;  

	//GPIOC2_PIN_OE=GPIOC3_PIN_OE=GPIOC4_PIN_OE=GPIOC5_PIN_OE=GPIOC6_PIN_OE=GPIOC7_PIN_OE=1;
	//GPIOD0_PIN_OE=GPIOD1_PIN_OE=GPIOD2_PIN_OE=GPIOD3_PIN_OE=GPIOD4_PIN_OE=GPIOD5_PIN_OE=GPIOD6_PIN_OE=GPIOD7_PIN_OE=1;
	//GPIOE0_PIN_OE=GPIOE1_PIN_OE=1;  // e0 e1 设置为输出

	//rGPIOC_FUN2|=0x50;  // c2   c3  设置为com2 com1
	//rGPIOC_FUN1|=0x55;  //       c4  设置为com0         c5 c6 c7为seg 0  seg 1 seg2

	//rGPIOD_FUN1|=0x55;  // d0 d1 d2 d3 为seg3 seg4 seg5 seg 6
	//rGPIOD_FUN2|=0x55;  // d4 d5 d6 d7 为seg7 seg8 seg9 seg 10
	//rGPIOE_FUN2|=0x05;  // e0 e1 为seg11 seg 12

	rWTMR_SLT |= 0x01;	//watch time = 31.25ms	
	rWTMR_CTL = 0x20;	//致能WTMR，清除WTMR事件

	
	rLCD_CTL1 = 0x00;		//关闭,正常负载,模式A
	rLCD_CTL2 = 0x06;		//256Hz	//clk:000;bias:01:1/3;duty:10:1/4
	
	rLCD_CVLS = 0x10;		//For VDD=5V
	
	//rLCD_CVLS = 0x1e;		//For VDD=3.3V


//	rLCD_PSC=0x08;                  //液晶正常驱动模式

#if 0
	rLCD_DAT2 = 0x01;

	/*
	rLCD_DAT0 = 0x0f;
	rLCD_DAT1 = 0x0f;
	rLCD_DAT2 = 0x0f;
	rLCD_DAT3 = 0x0f;
	rLCD_DAT4 = 0x0f;
	rLCD_DAT5 = 0x0f;
	rLCD_DAT6 = 0x0f;
	rLCD_DAT7 = 0x0f;
	rLCD_DAT8 = 0x0f;
	rLCD_DAT9 = 0x0f;
	rLCD_DAT10 = 0x0f;
	rLCD_DAT11 = 0x0f;
	rLCD_DAT12 = 0x0f;
	rLCD_DAT13 = 0x0f;
	rLCD_DAT14 = 0x0f;
	rLCD_DAT15 = 0x0f;
	rLCD_DAT16 = 0x0f;
	rLCD_DAT17 = 0x0f;
	rLCD_DAT18 = 0x0f;
	*/
	
#else

	 DispNum[0]=0;
	 DispNum[1]=0;
	 DispNum[2]=0;
	 DispNum[3]=0;
	//////////////
	 DispNum[4]=0;
	 DispNum[5]=0;
	 DispNum[6]=0;
	 DispNum[7]=0;
       /////////////



	 ICON_T     =1; 
	 ICON_T1    =1; 
	 ICON_T2    =1; 
	 ICON_T3    =1; 
	 ICON_T4    =1; 
	 ICON_BC1  =1; 
	 ICON_BC2  =1; 
	 ICON_L1    =0; 
	 
	 ICON_L2    =1; 
	 ICON_L3    =1; 
	 ICON_L4    =1; 
	 ICON_L5    =1; 
	 ICON_L6    =1; 
	 ICON_L7    =1; 
	 ICON_L8    =1; 

	 ICON_L9    =1; 
	 ICON_L10  =1; 

	DisplayNumber();
	DisplayIcon();

	//DisplayClear(CLEAR_ALL);
	//DisplayClear(CLEAR_NUM_ALL);
	// ICON_T     =1; 

#endif



	rSEG_EN0=0xff;			// 使能输出g0~g7
	rSEG_EN1=0xff;			// 使能输出 g8~g12
	rSEG_EN2=0xff;			// 使能输出 g8~g12
	rLCD_CTL1 = 0x00;		//关闭,正常负载,模式A
	rLCD_CTL2 = 0x06;		//256Hz	//clk:000;bias:01:1/3;duty:10:1/4
	
	//rLCD_CVLS = 0x10;		//For VDD=5V
	
	rLCD_CVLS = 0x1F;		//For VDD=3.3V  //这个没有设置正确会导致屏幕不亮
	rLCD_CTL1 |= 0x80;		//开启LCD电源


	


	
}


#define Verf   (3.3)
#define Amp	 206
#define Res	  3
void DisplayUSB2_A_V(void)
{
       DATA u16 adc,adc1,adc2;
	DATA u8 i;
	DATA float temp;

	adc1=ReadADC(ADC_CH4);	/*电压测试*/
	adc2=ReadADC(ADC_CH5);	/*电压测试*/
	//adc3=ReadADC(ADC_CH6);	/*电压测试*/

	adc=(adc1+adc2)/2;
	
	temp= (float) adc/(float)4096;
	temp=(float)Verf*temp*(float)110/(float)10;

	temp=(float)temp*(float)10;

	i=(u8)temp;
	usb2V=i;

	if(i>100)
		{
			ICON_BC1=1;
			DispNum[0]=i%100/10;
			DispNum[1]=i%100%10;
		}
	else
		{
			ICON_BC1=0;
			DispNum[0]=i/10;
			DispNum[1]=i%10;
		}

	adc=ReadADC(ADC_CH1);	  /*电流测试*/
	temp= (float) adc/(float)4096;
	temp=(float)Verf*temp;
	temp=temp*(float)(1000)/(float)Amp/(float)Res;
	temp=temp*(float)10;
	i=(u8)temp;
	usb2A=i;
	  if(i<10)
		{
			DispNum[4]=0;
			DispNum[5]=i;
		}
		else
		{
			DispNum[4]=i/10;
			DispNum[5]=i%10;
		}
}



void DisplayUSB1_V_A(void)
{
       DATA u16 adc,adc1,adc2;
	DATA u8 i;
	DATA float temp;


	adc1=ReadADC(ADC_CH2);	/*电压测试*/
	adc2=ReadADC(ADC_CH3);	/*电压测试*/
	//adc3=ReadADC(ADC_CH6);	/*电压测试*/

	adc=(adc1+adc2)/2;

	
	temp= (float) adc/(float)4096;
	temp=(float)Verf*temp*(float)147/(float)47;

	temp=(float)temp*(float)10;
	i=(u8)temp;
	usb1V=i;
	if(i>100)
		{
			ICON_BC2=1;
			DispNum[2]=i%10/10;
			DispNum[3]=i%100%10;
		}
	else
		{
			ICON_BC2=0;
			DispNum[2]=i/10;
			DispNum[3]=i%10;
		}

	adc=ReadADC(ADC_CH0);	  /*电流测试*/
	temp= (float) adc/(float)4096;
	temp=(float)Verf*temp;
	temp=temp*(float)(1000)/(float)Amp/(float)Res;


	temp=temp*(float)10;
	i=(u8)temp;
	 usb1A=i;
	if(i<10)
		{
			DispNum[6]=0;
			DispNum[7]=i;
		}
	else
		{
			DispNum[6]=i/10;
			DispNum[7]=i%10;
		}
}



/*
*************************************************************************
设计		liwei
文件		CalW
功能		计算充电效率
基本算法:
设定太阳能的总功率为20 W 
usb1+usb2的功率和=总的输出功率总总功率放大了100倍

*************************************************************************
*/

uint16 code KeycodeArryW[][3] = {

	{0, 	 	0,		   	       0},	   		 
	{11, 	200,		   	       1},	   		 
	{201,  	400, 				2},         
	{401,  	600,	   			3},        
	{601,   	800,	   			4},       
	{801,  	1000, 			5},	  	  
	{1001,	1200, 			6}, 	   
	{1201,	1400, 			7}, 	   
	{1401,	1600, 			8}, 	   
	{1601,	1800, 			9}, 	   
	{1801,	2000, 			10}, 	  
	{2001,	3000, 			10}, 	  
	

};


u8 CalW(void)
{
	u8 i;
	u16 w1,w2,w;
	
	w1=(u16)usb1A*(u16)usb1V;
	w2=(u16)usb2A*(u16)usb2V;

	w=w1+w2;
	//Printf("\r\nPower W=%d ", (WORD)w);

	for (i = 0; i < sizeof(KeycodeArryW); i++)  {
	if ((w >= KeycodeArryW[i][0]) && (w <= KeycodeArryW[i][1]))
	break;
	}	
	if (i >= 11) return	 10;
	else return  KeycodeArryW[i][2];
}


/*
*************************************************************************
设计		liwei
文件		SunPowerGo
功能		动态显示充电的箭头
*************************************************************************
*/
DATA u8 icongo=0;
void SunPowerGo(void)
{
	icongo++;
	if(icongo>3)icongo=0;

	switch(icongo)
		{
			case 0:
				 ICON_T2=0;
				 ICON_T3=0;			
				 ICON_T4=0;

				break;
			case 1:
				 ICON_T2=1;
				 ICON_T3=0;			
				 ICON_T4=0;

				break;
			case 2:
				 ICON_T2=1;
				 ICON_T3=1;			
				 ICON_T4=0;

				break;
			case 3:
				 ICON_T2=1;
				 ICON_T3=1;			
				 ICON_T4=1;
				
				break;
		}
	
	
}

void ShowProcess_bar(u8 n)
{

	switch(n)
		{
			case 0:
		   	 ICON_L10=0; ICON_L9=0; ICON_L8=0; ICON_L7=0; ICON_L6=0; 
		  	 ICON_L5=0; ICON_L4=0; ICON_L3=0;ICON_L2=0; ICON_L1=0;
			break;	
				
			case 1:
		   	 ICON_L10=1; ICON_L9=0; ICON_L8=0; ICON_L7=0; ICON_L6=0; 
		  	 ICON_L5=0; ICON_L4=0; ICON_L3=0;ICON_L2=0; ICON_L1=0;
			break;	
				
			case 2:
		   	 ICON_L10=1; ICON_L9=1; ICON_L8=0; ICON_L7=0; ICON_L6=0; 
		  	 ICON_L5=0; ICON_L4=0; ICON_L3=0;ICON_L2=0; ICON_L1=0;
			break;	
				
			case 3:
		   	 ICON_L10=1; ICON_L9=1; ICON_L8=1; ICON_L7=0; ICON_L6=0; 
		  	 ICON_L5=0; ICON_L4=0; ICON_L3=0;ICON_L2=0; ICON_L1=0;
			break;

			case 4:
		   	 ICON_L10=1; ICON_L9=1; ICON_L8=1; ICON_L7=1; ICON_L6=0; 
		  	 ICON_L5=0; ICON_L4=0; ICON_L3=0;ICON_L2=0; ICON_L1=0;
			break;


			case 5:
		   	 ICON_L10=1; ICON_L9=1; ICON_L8=1; ICON_L7=1; ICON_L6=1; 
		  	 ICON_L5=0; ICON_L4=0; ICON_L3=0;ICON_L2=0; ICON_L1=0;
			break;

			case 6:
		   	 ICON_L10=1; ICON_L9=1; ICON_L8=1; ICON_L7=1; ICON_L6=1; 
		  	 ICON_L5=1; ICON_L4=0; ICON_L3=0;ICON_L2=0; ICON_L1=0;
			break;

			case 7:
		   	 ICON_L10=1; ICON_L9=1; ICON_L8=1; ICON_L7=1; ICON_L6=1; 
		  	 ICON_L5=1; ICON_L4=1; ICON_L3=0;ICON_L2=0; ICON_L1=0;
			break;

			case 8:
		   	 ICON_L10=1; ICON_L9=1; ICON_L8=1; ICON_L7=1; ICON_L6=1; 
		  	 ICON_L5=1; ICON_L4=1; ICON_L3=1;ICON_L2=0; ICON_L1=0;
			break;	

			case 9:
		   	 ICON_L10=1; ICON_L9=1; ICON_L8=1; ICON_L7=1; ICON_L6=1; 
		  	 ICON_L5=1; ICON_L4=1; ICON_L3=1;ICON_L2=1; ICON_L1=0;
			break;

			case 10:
		   	 ICON_L10=1; ICON_L9=1; ICON_L8=1; ICON_L7=1; ICON_L6=1; 
		  	 ICON_L5=1; ICON_L4=1; ICON_L3=1;ICON_L2=1; ICON_L1=1;
			break;		

		}
	
	
}


/*
*************************************************************************
设计		liwei
文件		ShowQCicon
功能		显示QC4.0标志
*************************************************************************
*/
void ShowQCicon(void)
{
	if(usb1V>55)
		{
			ICON_T1=1; // liwei
		}
	else
		{
			ICON_T1=0;// aaaaaaaaaaaaa
		}
}

/*
*************************************************************************
设计		liwei
文件		DisplayAll
功能		在固定定时器的时间内把数据放到LCD 显示驱动
			中去
*************************************************************************
*/

void DisplayAll(void)
{
	DisplayUSB1_V_A();
	DisplayUSB2_A_V();
	SunPowerGo();
	CalW();
	ShowProcess_bar(CalW());


	DisplayNumber();
	DisplayIcon();
}


