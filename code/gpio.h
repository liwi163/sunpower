#ifndef GPIO_H
#define GPIO_H
// GPIO.h 
//Version: 1.02 >>@2012-05-21, Delete GPIO Reserved function.
//Version: 1.01 >>@2012-05-18, Delete GPIOE7 define I2C SCL function, only enable GPIOA3 as SDA
								// I2C Slave : Set GPIOA3 and GPIOE7 input
								// I2C Master : Set GPIOA3 input, GPIOE7 output
//Version: 1.00 >>@2012-04-25, corrected EN adn MP chip Compatible issue

//=====================================================================================
#define GPIO_OUTPUT_MODE      	1
#define GPIO_INPUT_MODE       	0
#define GPIO_PULL_LOW         		1
#define GPIO_PULL_HIGH        		0

//=====================================================================================
//GPIOA7
#define GPA7_FUN_SLT_GPIO()		{rGPIOA_FUN1 &=~0xC0;}
#define GPA7_FUN_SLT_PWM1()		{rGPIOA_FUN1 |=0x40;}
#define GPA7_FUN_SLT_ETMO()		{rGPIOA_FUN1 |=0x80;}
#define GPA7_FUN_SLT_ADC0()		{rGPIOA_FUN1 |=0xC0;}
//GPIOA6
#define GPA6_FUN_SLT_GPIO()		{rGPIOA_FUN1 &=~0x20;}
#define GPA6_FUN_SLT_STBB()		{rGPIOA_FUN1 |=0x20;}
//GPIOA5
#define GPA5_FUN_SLT_GPIO()		{rGPIOA_FUN1 |=~0x08;}	 //GPIOA4 as GPIO
#define GPA5_FUN_SLT_XSOUT()	{rGPIOA_FUN1 |=0x08;}	 //副晶振輸出 GPIOA4 As XSIN
//GPIOA4
//GPIOA4 follow GPIOA5 setting

//GPIOA3
#define GPA3_FUN_SLT_GPIO()		{rGPIOA_FUN2 &=~0xC0;}
#define GPA3_FUN_SLT_SDA()		{rGPIOA_FUN2 |=0x40;}
#define GPA3_FUN_SLT_MISO()		{rGPIOA_FUN2 |=0x80;}
#define GPA3_FUN_SLT_P03()		{rGPIOA_FUN2 |=0xC0;}
//GPIOA2
#define GPA2_FUN_SLT_GPIO()		{rGPIOA_FUN2 &=~0x20;}
#define GPA2_FUN_SLT_XMIN()		{rGPIOA_FUN2 |=0x20;}	//主晶振輸入，將制GPIOA1D為XMOUT
//GPIOA0
#define GPA0_FUN_SLT_GPIO()		{rGPIOA_FUN2 |=~0x01;}
#define GPA0_FUN_SLT_MOSIB()	{rGPIOA_FUN2 |=0x01;}	//SPI MOSIB
//-------------------------------------------------------------------------------------
//GPIOB7
#define GPB7_FUN_SLT_GPIO()		{rGPIOB_FUN1 &=~0xC0;}
#define GPB7_FUN_SLT_RX0B()		{rGPIOB_FUN1 |=0x40;}
#define GPB7_FUN_SLT_BSEG7()	{rGPIOB_FUN1 |=0x80;}
#define GPB7_FUN_SLT_ADC7()		{rGPIOB_FUN1 |=0xC0;}
//GPIOB6
#define GPB6_FUN_SLT_GPIO()		{rGPIOB_FUN1 &=~0x30;}
#define GPB6_FUN_SLT_BUZOB()	{rGPIOB_FUN1 |=0x10;}
#define GPB6_FUN_SLT_BSEG6()	{rGPIOB_FUN1 |=0x20;}
#define GPB6_FUN_SLT_ADC6()		{rGPIOB_FUN1 |=0x30;}
//GPIOB5
//MP chip add PWM0B
#define GPB5_FUN_SLT_GPIO()		{rGPIOB_FUN1 &=~0x0C;}
#define GPB5_FUN_SLT_PWM0B)		{rGPIOB_FUN1 |=0x04;}	// For MP chip
#define GPB5_FUN_SLT_BSEG5()	{rGPIOB_FUN1 |=0x08;}
#define GPB5_FUN_SLT_ADC5()		{rGPIOB_FUN1 |=0x0C;}
//GPIOB4
#define GPB4_FUN_SLT_GPIO()		{rGPIOB_FUN1 &=~0x03;}
#define GPB4_FUN_SLT_ACOM4()	{rGPIOB_FUN1 |=0x01;}
#define GPB4_FUN_SLT_BSEG4()	{rGPIOB_FUN1 |=0x02;}
#define GPB4_FUN_SLT_ADC4()		{rGPIOB_FUN1 |=0x03;}
//GPIOB3
#define GPB3_FUN_SLT_GPIO()		{rGPIOB_FUN2 &=~0xC0;}
#define GPB3_FUN_SLT_ACOM5()	{rGPIOB_FUN2 |=0x40;}
#define GPB3_FUN_SLT_BSEG3()	{rGPIOB_FUN2 |=0x80;}
#define GPB3_FUN_SLT_ADC3()		{rGPIOB_FUN2 |=0xC0;}
//GPIOB2
#define GPB2_FUN_SLT_GPIO()		{rGPIOB_FUN2 &=~0x30;}
#define GPB2_FUN_SLT_ACOM6()	{rGPIOB_FUN2 |=0x10;}
#define GPB2_FUN_SLT_BSEG2()	{rGPIOB_FUN2 |=0x20;}
#define GPB2_FUN_SLT_ADC2()		{rGPIOB_FUN2 |=0x30;}
//GPIOB1
#define GPB1_FUN_SLT_GPIO()		{rGPIOB_FUN2 &=~0x0C;}
#define GPB1_FUN_SLT_TX0A()		{rGPIOB_FUN2 |=0x04;}
#define GPB1_FUN_SLT_BSEG1()	{rGPIOB_FUN2 |=0x08;}
#define GPB1_FUN_SLT_VREF()		{rGPIOB_FUN2 |=0x0C;}
//GPIOB0
#define GPB0_FUN_SLT_GPIO()		{rGPIOB_FUN2 &=~0x03;}
#define GPB0_FUN_SLT_ACOM7()	{rGPIOB_FUN2 |=0x01;}
#define GPB0_FUN_SLT_BSEG0()	{rGPIOB_FUN2 |=0x02;}
#define GPB0_FUN_SLT_ADC1()		{rGPIOB_FUN2 |=0x03;}
//-------------------------------------------------------------------------------------
//GPIOC7
//GPIOC7~GPIOC4 : GPDx_FUN_SLT[1:0] = 11: reserved
//GPIOC3~GPIOC1 : GPDx_FUN_SLT[1:0] = 11: reserved
//		 GPIOC0 : GPDx_FUN_SLT[1:0] = 01: reserved
#define GPC7_FUN_SLT_GPIO()		{rGPIOC_FUN1 &=~0xC0;}
#define GPC7_FUN_SLT_ASEG2()	{rGPIOC_FUN1 |=0x40;}
#define GPC7_FUN_SLT_BSEG15()	{rGPIOC_FUN1 |=0x80;}
//11:MP chip reserved this function
//GPIOC6
#define GPC6_FUN_SLT_GPIO()		{rGPIOC_FUN1 &=~0x30;}
#define GPC6_FUN_SLT_ASEG1()	{rGPIOC_FUN1 |=0x10;}
#define GPC6_FUN_SLT_BSEG14()	{rGPIOC_FUN1 |=0x20;}
//11:MP chip reserved this function
//GPIOC5
#define GPC5_FUN_SLT_GPIO()		{rGPIOC_FUN1 &=~0x0C;}
#define GPC5_FUN_SLT_ASEG0()	{rGPIOC_FUN1 |=0x04;}
#define GPC5_FUN_SLT_BSEG13()	{rGPIOC_FUN1 |=0x08;}
//11:MP chip reserved this function
//GPIOC4
#define GPC4_FUN_SLT_GPIO()		{rGPIOC_FUN1 &=~0x03;}
#define GPC4_FUN_SLT_ACOM0()	{rGPIOC_FUN1 |=0x01;}
#define GPC4_FUN_SLT_BSEG12()	{rGPIOC_FUN1 |=0x02;}
//11:MP chip reserved this function
//GPIOC3
#define GPC3_FUN_SLT_GPIO()		{rGPIOC_FUN2 &=~0xC0;}
#define GPC3_FUN_SLT_ACOM1()	{rGPIOC_FUN2 |=0x40;}
#define GPC3_FUN_SLT_BSEG11()	{rGPIOC_FUN2 |=0x80;}
//11:MP chip reserved this function
//GPIOC2
#define GPC2_FUN_SLT_GPIO()		{rGPIOC_FUN2 &=~0x30;}
#define GPC2_FUN_SLT_ACOM2()	{rGPIOC_FUN2 |=0x10;}
#define GPC2_FUN_SLT_BSEG10()	{rGPIOC_FUN2 |=0x20;}
//11:MP chip reserved this function
//GPIOC1
#define GPC1_FUN_SLT_GPIO()		{rGPIOC_FUN2 &=~0x0C;}
#define GPC1_FUN_SLT_ACOM3()	{rGPIOC_FUN2 |=0x04;}
#define GPC1_FUN_SLT_BSEG9()	{rGPIOC_FUN2 |=0x08;}
//11:MP chip reserved this function
//GPIOC0
#define GPC0_FUN_SLT_GPIO()		{rGPIOC_FUN2 &=~0x03;}
//01:MP chip reserved this function
#define GPC0_FUN_SLT_BSEG8()	{rGPIOC_FUN2 |=0x02;}
#define GPC0_FUN_SLT_ADC8()		{rGPIOC_FUN2 |=0x03;}
//-------------------------------------------------------------------------------------
//GPIOD7
//GPIOD7~GPIOD4 : GPDx_FUN_SLT[1:0] = 10: reserved
#define GPD7_FUN_SLT_GPIO()		{rGPIOD_FUN1 &=~0xC0;}
#define GPD7_FUN_SLT_ASEG10()	{rGPIOD_FUN1 |=0x40;}
//10:MP chip reserved this function
#define GPD7_FUN_SLT_BCOM0()	{rGPIOD_FUN1 |=0xC0;}
//GPIOD6
#define GPD6_FUN_SLT_GPIO()		{rGPIOD_FUN1 &=~0x30;}
#define GPD6_FUN_SLT_ASEG9()	{rGPIOD_FUN1 |=0x10;}
//10:MP chip reserved this function
#define GPD6_FUN_SLT_BCOM1()	{rGPIOD_FUN1 |=0x30;}
//GPIOD5
#define GPD5_FUN_SLT_GPIO()		{rGPIOD_FUN1 &=~0x0C;}
#define GPD5_FUN_SLT_ASEG8()	{rGPIOD_FUN1 |=0x04;}
//10:MP chip reserved this function
#define GPD5_FUN_SLT_BCOM2()	{rGPIOD_FUN1 |=0x0C;}
//GPIOD4
#define GPD4_FUN_SLT_GPIO()		{rGPIOD_FUN1 &=~0x03;}
#define GPD4_FUN_SLT_ASEG7()	{rGPIOD_FUN1 |=0x01;}
//10:MP chip reserved this function
#define GPD4_FUN_SLT_BCOM3()	{rGPIOD_FUN1 |=0x03;}
//GPIOD3
#define GPD3_FUN_SLT_GPIO()		{rGPIOD_FUN2 &=~0xC0;}
#define GPD3_FUN_SLT_ASEG6()	{rGPIOD_FUN2 |=0x40;}
#define GPD3_FUN_SLT_BSEG19()	{rGPIOD_FUN2 |=0x80;}
#define GPD3_FUN_SLT_BCOM4()	{rGPIOD_FUN2 |=0xC0;}
//GPIOD2
#define GPD2_FUN_SLT_GPIO()		{rGPIOD_FUN2 &=~0x30;}
#define GPD2_FUN_SLT_ASEG5()	{rGPIOD_FUN2 |=0x10;}
#define GPD2_FUN_SLT_BSEG18()	{rGPIOD_FUN2 |=0x20;}
#define GPD2_FUN_SLT_BCOM5()	{rGPIOD_FUN2 |=0x30;}
//GPIOD1
#define GPD1_FUN_SLT_GPIO()		{rGPIOD_FUN2 &=~0x0C;}
#define GPD1_FUN_SLT_ASEG4()	{rGPIOD_FUN2 |=0x04;}
#define GPD1_FUN_SLT_BSEG17()	{rGPIOD_FUN2 |=0x08;}
#define GPC1_FUN_SLT_BCOM6()	{rGPIOD_FUN2 |=0x0C;}
//GPIOD0
#define GPD0_FUN_SLT_GPIO()		{rGPIOD_FUN2 &=~0x03;}
#define GPD0_FUN_SLT_ASEG3()	{rGPIOD_FUN2 |=0x01;}
#define GPD0_FUN_SLT_BSEG16()	{rGPIOD_FUN2 |=0x02;}
#define GPD0_FUN_SLT_BCOM7()	{rGPIOD_FUN2 |=0x03;}
//-------------------------------------------------------------------------------------
//GPIOE7
#define GPE7_FUN_SLT_GPIO()		{rGPIOE_FUN1 &=~0xC0;}
#define GPE7_FUN_SLT_ASEG18()	{rGPIOE_FUN1 |=0x40;}
#define GPE7_FUN_SLT_SCK()		{rGPIOE_FUN1 |=0x80;}
//I2C funcation only enable GPIOA3 as SDA
#define GPE7_FUN_SLT_P00()		{rGPIOE_FUN1 |=0xC0;}
//GPIOE6
#define GPE6_FUN_SLT_GPIO()		{rGPIOE_FUN1 &=~0x30;}
#define GPE6_FUN_SLT_ASEG17()	{rGPIOE_FUN1 |=0x10;}
#define GPE6_FUN_SLT_ETMI()		{rGPIOE_FUN1 |=0x20;}
#define GPE6_FUN_SLT_ADC15()	{rGPIOE_FUN1 |=0x30;}
//GPIOE5
#define GPE5_FUN_SLT_GPIO()		{rGPIOE_FUN1 &=~0x0C;}
#define GPE5_FUN_SLT_ASEG16()	{rGPIOE_FUN1 |=0x04;}
#define GPE5_FUN_SLT_RX1()		{rGPIOE_FUN1 |=0x08;}
#define GPE5_FUN_SLT_ADC14()	{rGPIOE_FUN1 |=0x0C;}
//GPIOE4
#define GPE4_FUN_SLT_GPIO()		{rGPIOE_FUN1 &=~0x03;}
#define GPE4_FUN_SLT_ASEG15()	{rGPIOE_FUN1 |=0x01;}
//10:MP chip reserved this function
#define GPE4_FUN_SLT_ADC13()	{rGPIOE_FUN1 |=0x03;}
//GPIOE3
#define GPE3_FUN_SLT_GPIO()		{rGPIOE_FUN2 &=~0xC0;}
#define GPE3_FUN_SLT_ASEG14()	{rGPIOE_FUN2 |=0x40;}
#define GPE3_FUN_SLT_BUZOC()	{rGPIOE_FUN2 |=0x80;}	//BUZZER C PATH
#define GPE3_FUN_SLT_ADC12()	{rGPIOE_FUN2 |=0xC0;}
//GPIOE2
#define GPE2_FUN_SLT_GPIO()		{rGPIOE_FUN2 &=~0x30;}
#define GPE2_FUN_SLT_ASEG13()	{rGPIOE_FUN2 |=0x10;}
//10:MP chip reserved this function
#define GPE2_FUN_SLT_ADC11()	{rGPIOE_FUN2 |=0x30;}
//GPIOE1
#define GPE1_FUN_SLT_GPIO()		{rGPIOE_FUN2 &=~0x0C;}
#define GPE1_FUN_SLT_ASEG12()	{rGPIOE_FUN2 |=0x04;}
//10:/MP chip reserved this function
#define GPE1_FUN_SLT_ADC10()	{rGPIOE_FUN2 |=0x0C;}   
//GPIOE0
#define GPE0_FUN_SLT_GPIO()		{rGPIOE_FUN2 &=~0x03;}
#define GPE0_FUN_SLT_ASEG11()	{rGPIOE_FUN2 |=0x01;}
//10:MP chip reserved this function
#define GPE0_FUN_SLT_ADC9()		{rGPIOE_FUN2 |=0x03;} 
//-------------------------------------------------------------------------------------
//GPIOF3
//This GPIO is SWUT(ISP programming PIN) do not external pull high
#define GPF3_FUN_SLT_GPIO()		{rGPIOF_FUN1 &=~0x80;}
#define GPF3_FUN_SLT_NRST()		{rGPIOF_FUN1 |=0x80;}
//GPIOF2
#define GPF2_FUN_SLT_GPIO()		{rGPIOF_FUN1 &=~0x30;}
#define GPF2_FUN_SLT_CMPO()		{rGPIOF_FUN1 |=0x10;}
#define GPF2_FUN_SLT_T2CAP()	{rGPIOF_FUN1 |=0x20;}
#define GPF2_FUN_SLT_P02()		{rGPIOF_FUN1 |=0x30;}
//GPIOF1
#define GPF1_FUN_SLT_GPIO()		{rGPIOF_FUN1 &=~0x0C;}
#define GPF1_FUN_SLT_T2()		{rGPIOF_FUN1 |=0x04;}
#define GPF1_FUN_SLT_MOSIA()	{rGPIOF_FUN1 |=0x08;}
#define GPF1_FUN_SLT_P01()		{rGPIOF_FUN1 |=0x0C;}
//GPIOF0
#define GPF0_FUN_SLT_GPIO()		{rGPIOF_FUN1 &=~0x03;}
#define GPF0_FUN_SLT_PWM0()		{rGPIOF_FUN1 |=0x01;}
#define GPF0_FUN_SLT_PWM0A()	{rGPIOF_FUN1 |=0x01;}	//For MP chip
#define GPF0_FUN_SLT_T2O()		{rGPIOF_FUN1 |=0x02;}
#define GPF0_FUN_SLT_BUZOA()	{rGPIOF_FUN1 |=0x03;}
//=====================================================================================
#endif
