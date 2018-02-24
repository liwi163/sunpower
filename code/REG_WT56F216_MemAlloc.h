//#include <absacc.h>


#if(XFR_USEING==PDATA_FOR_PBYTE)
#define rCHIP_ID			PBYTE[0X0000]
#define rSYS_CTL			PBYTE[0x0001]
#define rLVD_CTL			PBYTE[0X0002]
#define rRESET_FLG		PBYTE[0x0003]

// power saving
#define rISP_CHG_CTL		PBYTE[0x0004]
#define rSOURCE_CLK_SLT	PBYTE[0x0005]



#define rIRC_12M_PD		PBYTE[0x0006]
#define rPOWER_SAVE_CTL rIRC_12M_PD  
#define rCLOCK_SW_CTL	PBYTE[0x0007]


#define rCRY_12M_DR		PBYTE[0x0008]

#define rCSTM_ID1		PBYTE[0x000D]
#define rCSTM_ID2		PBYTE[0x000E]
#define rCSTM_ID3		PBYTE[0x000F]


/*
================================================================================
=	¼Ä´æÆ÷µØÖ·: 0010H - 002FH
=	Í¨ÓÃI/O¶Ë¿Ú¼Ä´æÆ÷ºÍ¸´ºÏ¹¦ÄÜ¼Ä´æÆ÷
================================================================================
*/
#define rGPIOA_OEN			PBYTE[0x0010]  // RW
#define rGPIOB_OEN			PBYTE[0x0011]  // RW
#define rGPIOC_OEN			PBYTE[0x0012]  // RW 
#define rGPIOD_OEN			PBYTE[0x0013]  // RW 
#define rGPIOE_OEN			PBYTE[0x0014]  // RW 
#define rGPIOF_OEN			PBYTE[0x0015]  // RW 

#define rGPIOA_DAT			PBYTE[0x0016]  // RW
#define rGPIOB_DAT			PBYTE[0x0017]  // RW
#define rGPIOC_DAT			PBYTE[0x0018]  // RW 
#define rGPIOD_DAT			PBYTE[0x0019]  // RW 
#define rGPIOE_DAT			PBYTE[0x001A]  // RW 
#define rGPIOF_DAT			PBYTE[0x001B]  // RW 

#define rGPIOA_PHN			PBYTE[0x001C]  // RW
#define rGPIOB_PHN			PBYTE[0x001D]  // RW
#define rGPIOC_PHN			PBYTE[0x001E]  // RW
#define rGPIOD_PHN			PBYTE[0x001F]  // RW
#define rGPIOE_PHN			PBYTE[0x0020]  // RW
#define rGPIOF_PHN			PBYTE[0x0021]  // RW

#define rGPIOA_TYP			PBYTE[0x0022]  // RW
#define rGPIOE_TYP			PBYTE[0x0023]  // RW
#define rGPIOF_TYP			PBYTE[0x0024]  // RW

#define rGPIOA_FUN1		PBYTE[0x0025]  // RW 
#define rGPIOA_FUN2		PBYTE[0x0026]  // RW		ADC 0~7 enable io pad 
#define rGPIOB_FUN1		PBYTE[0x0027]  // RW		SCAN 0~7 enable io pad
#define rGPIOB_FUN2		PBYTE[0x0028]  // RW
#define rGPIOC_FUN1		PBYTE[0x0029]  // RW
#define rGPIOC_FUN2		PBYTE[0x002A]  // RW
#define rGPIOD_FUN1		PBYTE[0x002B]  // RW
#define rGPIOD_FUN2		PBYTE[0x002C]  // RW
#define rGPIOE_FUN1		PBYTE[0x002D]  // RW
#define rGPIOE_FUN2		PBYTE[0x002E]  // RW
#define rGPIOF_FUN1		PBYTE[0x002F]  // RW

/*
================================================================================
=	¼Ä´æÆ÷µØÖ·: 0030H - 003FH
=	ÖÐ¶ÏÊ¹ÄÜ¼Ä´æÆ÷
================================================================================
*/
#define rIE0_CTL			PBYTE[0x0030]  // RW
#define rIE1_CTL			PBYTE[0x0031]  // RW
#define rIE2_CTL			PBYTE[0x0032]  // RW
#define rIE3_IRQH			PBYTE[0x0033]  // RW
#define rIE3_IRQL			PBYTE[0x0034]  // RW
#define rIF0_FLAG			PBYTE[0x0035]  // RW
#define rIF1_FLAG			PBYTE[0x0036]  // RW
#define rIF2_FLAG			PBYTE[0x0037]  // RW
#define rIF3_IRQH			PBYTE[0x0038]  // RW
#define rIF3_IRQL			PBYTE[0x0039]  // RW


/*
================================================================================
=	¼Ä´æÆ÷µØÖ·: 0040H - 004FH
=	Íâ²¿ÖÐ¶ÏÇëÇó¼Ä´æÆ÷
================================================================================
*/
#define rEN_IRQH				PBYTE[0x0040]  // RW
#define rEN_IRQL				PBYTE[0x0041]  // RW
#define rEVT_IRQH			PBYTE[0x0042]  // RW
#define rEVT_IRQL			PBYTE[0x0043]  // RW
#define rCLR_IRQH			PBYTE[0x0044]  // RW
#define rCLR_IRQL			PBYTE[0x0045]  // RW
#define rIRQ_CHGH			PBYTE[0x0046]  // RW
#define rIRQ_CHGL			PBYTE[0x0047]  // RW
#define rIRQ_EDGEH			PBYTE[0x0048]  // RW
#define rIRQ_EDGEL			PBYTE[0x0049]  // RW


/*
================================================================================
=	¼Ä´æÆ÷µØÖ·: 0050H - 005FH
=	PWM¼Ä´æÆ÷
================================================================================
*/
#define rPWM_CTL			PBYTE[0x0050]  // RW
#define rPWM0_PRDH			PBYTE[0x0051]  // RW 
#define rPWM0_PRDL			PBYTE[0x0052]  // RW
#define rPWM0_DUTYH		PBYTE[0x0053]  // RW 
#define rPWM0_DUTYL		PBYTE[0x0054]  // RW
#define rPWM1_PRDH			PBYTE[0x0055]  // RW 
#define rPWM1_PRDL			PBYTE[0x0056]  // RW
#define rPWM1_DUTYH		PBYTE[0x0057]  // RW 
#define rPWM1_DUTYL		PBYTE[0x0058]  // RW


/*
================================================================================
=	¼Ä´æÆ÷µØÖ·: 0060H - 006FH
=	»½ÐÑ¼Ä´æÆ÷
================================================================================
*/
#define rGPIOA_WK			PBYTE[0x0060]  // RW
#define rGPIOB_WK			PBYTE[0x0061]  // RW
#define rGPIOE_WK			PBYTE[0x0062]  // RW
#define rGPIOF_WK			PBYTE[0x0063]  // RW
#define rPERIPHERAL_WK		PBYTE[0x0064]  // RW
#define rGPIOA_TOG			PBYTE[0x0065]  // R
#define rGPIOB_TOG			PBYTE[0x0066]  // R
#define rGPIOE_TOG			PBYTE[0x0067]  // R
#define rGPIOF_TOG			PBYTE[0x0068]  // R
#define rPERIPHERAL_TOG	PBYTE[0x0069]  // R
#define rCLR_IN_TOG		PBYTE[0x006A]  // RW


/*
================================================================================
=	¼Ä´æÆ÷µØÖ·: 0070H - 007FH
=	ÄÚ²¿Õñµ´Ð£Õý¼Ä´æÆ÷£¬¿´ÃÅ¹·¼Ä´æÆ÷ºÍÊµÊ±¶¨Ê±Æ÷¼Ä´æÆ÷
================================================================================
*/
// IRC calibration
#define rRC_LADJ			PBYTE[0x0070]  // RW
#define rRC12M_CNTH	PBYTE[0x0071]  // RW
#define rRC12M_CNTL		PBYTE[0x0072]  // RW
#define rRC_CALIB_EN		PBYTE[0x0073]  // RW

// WDT
#define rWDT_CTL		PBYTE[0x0078]  // RW

// WATCH Timer
#define rWTMR_CTL		PBYTE[0x007C]  // RW
#define rWTMR_SLT		PBYTE[0x007D]  // RW


/*
================================================================================
=	¼Ä´æÆ÷µØÖ·: 0080H - 009FH
=	LCDÏÔÊ¾»º³åÇøÒÔ¼°¿ØÖÆ¼Ä´æÆ÷
================================================================================
*/
#define rLCD_DAT0			PBYTE[0x0080]  // RW
#define rLCD_DAT1			PBYTE[0x0081]  // RW
#define rLCD_DAT2			PBYTE[0x0082]  // RW
#define rLCD_DAT3			PBYTE[0x0083]  // RW
#define rLCD_DAT4			PBYTE[0x0084]  // RW
#define rLCD_DAT5			PBYTE[0x0085]  // RW
#define rLCD_DAT6			PBYTE[0x0086]  // RW
#define rLCD_DAT7			PBYTE[0x0087]  // RW
#define rLCD_DAT8			PBYTE[0x0088]  // RW
#define rLCD_DAT9			PBYTE[0x0089]  // RW
#define rLCD_DAT10			PBYTE[0x008A]  // RW
#define rLCD_DAT11			PBYTE[0x008B]  // RW
#define rLCD_DAT12			PBYTE[0x008C]  // RW
#define rLCD_DAT13			PBYTE[0x008D]  // RW
#define rLCD_DAT14			PBYTE[0x008E]  // RW
#define rLCD_DAT15			PBYTE[0x008F]  // RW
#define rLCD_DAT16			PBYTE[0x0090]  // RW
#define rLCD_DAT17			PBYTE[0x0091]  // RW
#define rLCD_DAT18			PBYTE[0x0092]  // RW
#define rLCD_DAT19			PBYTE[0x0093]  // RW

// LCD Control Register 1 
#define rLCD_CTL1			PBYTE[0x0098]  // W
#define rLCD_CTL2			PBYTE[0x0099]  // R
#define rLCD_CVLS			PBYTE[0x009A]  // R
#define rLCD_PSC			PBYTE[0x009B]  // RW
#define rSEG_EN0			PBYTE[0x009C]  // RW
#define rSEG_EN1			PBYTE[0x009D]  // RW
#define rSEG_EN2			PBYTE[0x009E]  // RW


/*
================================================================================
=	¼Ä´æÆ÷µØÖ·: 00A0H - 00AFH
=	I2C´®ÐÐ½Ó¿Ú¼Ä´æÆ÷
================================================================================
*/
#define rMI2C_CTL			PBYTE[0x00A0]  // RW
#define rMI2C_STA			PBYTE[0x00A1]  // RW
#define rMI2C_DSLV			PBYTE[0x00A2]  // RW
#define rMI2C_DTRX			PBYTE[0x00A3]  // RW
#define rMI2C_SADR			PBYTE[0x00A4]  // RW
#define rMI2C_EXTEND		PBYTE[0x00A5]  // RW


/*
================================================================================
=	¼Ä´æÆ÷µØÖ·: 00B0H - 00BFH
=	ÔöÇ¿ÐÍ¶¨Ê±Æ÷/¼ÆÊýÆ÷¼Ä´æÆ÷
================================================================================
*/
#define rETM_CTL1			PBYTE[0x00B0]  // RW
#define rETM_CTL2			PBYTE[0x00B1]  // RW
#define rETM_INT			PBYTE[0x00B2]  // RW
#define rETM_BUFL			PBYTE[0x00B3]  // RW
#define rETM_BUFH			PBYTE[0x00B4]  // RW


/*
================================================================================
=	¼Ä´æÆ÷µØÖ·: 00C0H - 00CFH
=	SPI´®ÐÐ½Ó¿Ú¼Ä´æÆ÷
================================================================================
*/
#define rSPI_CTL1			PBYTE[0x00C0]  // RW
#define rSPI_CTL2			PBYTE[0x00C1]  // RW
#define rSPI_INT			PBYTE[0x00C2]  // RW
#define rSPI_CLR			PBYTE[0x00C3]  // RW
#define rSPI_FLG			PBYTE[0x00C4]  // RW
#define rSPI_BRS			PBYTE[0x00C5]  // RW
#define rSPI_TXBUF			PBYTE[0x00C6]  // RW
#define rSPI_RXBUF			PBYTE[0x00C7]  // RW


/*
================================================================================
=	¼Ä´æÆ÷µØÖ·: 00D0H - 00D7H
=	10bit ADC¼Ä´æÆ÷
================================================================================
*/
#define rADC_CTL			PBYTE[0x00D0]  // RW
#define rADC_SEL			PBYTE[0x00D1]  // R
#define rADC_INT			PBYTE[0x00D2]  // RW
#define rADC_ENCH			PBYTE[0x00D3]  // RW
#define rADC_CMP_VH		PBYTE[0x00D4]  // R
#define rADC_CMP_VL		PBYTE[0x00D5]  // RW
#define rADC_DATAH			PBYTE[0x00D6]  // RW
#define rADC_DATAL			PBYTE[0x00D7]  // RW


/*
================================================================================
=	¼Ä´æÆ÷µØÖ·: 00DAH - 00DFH
=	±È½ÏÆ÷¼Ä´æÆ÷
================================================================================
*/
#define rACOMP_CTL			PBYTE[0x00DA]  // RW 
#define rACOMP_FLG			PBYTE[0x00DB]  // RW 
#define rACOMP_VREF		PBYTE[0x00DC]  // RW 


/*
================================================================================
=	¼Ä´æÆ÷µØÖ·: 00E0H - 00EFH
=	·ÂÕæEEPROM¼Ä´æÆ÷
================================================================================
*/
#define rEER_EN1			PBYTE[0x00E0]  // W
#define rEER_EN2			PBYTE[0x00E1]  // W
#define rEER_ADDRL			PBYTE[0x00E2]  //RW		//bit 7-0
#define rEER_ADDRH			PBYTE[0x00E3]  //RW		//bit 11-8
#define rEER_TCTL			PBYTE[0x00E4]	//W
#define rEER_DATA			PBYTE[0x00E8]  // W


/*
================================================================================
=	WT56F216ÓÃÓÚ²âÊÔµÈÄ¿µÄµÄÒþ²Ø¼Ä´æÆ÷
================================================================================
*/
#define rFLASH_CTL					PBYTE[0x00F0]  // R/W
#define rIRC_CTL						PBYTE[0x00F2]  // R/W

#define rCUSTOMER_ID				XBYTE[0x0E00]
#define rINITIAL_DATA				XBYTE[0x0E01]

#define rLDO_CALIBRATION_DATA		XBYTE[0x0E02]
#define rRC_CALIBRATION_DATA		XBYTE[0x0E03]

#endif


