
#include "gheader.h"

//Version: 1.00 >>@2012-0-25, Add XFR 0xDD
//---------------------------------------
// XFR ---- using xdata
//---------------------------------------
#if(XFR_USEING==XDATA_FOR_XFR)
// System Level Register
xdata BYTE rCHIP_ID			_at_ 0x0000;  // R
xdata BYTE rSYS_CTL      	_at_ 0x0001;  // RW
xdata BYTE rLVD_CTL      	_at_ 0x0002;  // RW
xdata BYTE rRESET_FLG     	_at_ 0x0003;  // RW

// power saving
xdata BYTE rISP_CHG_CTL		_at_ 0x0004;  // RW
xdata BYTE rSOURCE_CLK_SLT	_at_ 0x0005;  // RW
xdata BYTE rCLOCK_SW_CTL	_at_ 0x0006;  // RW
xdata BYTE rIRC_12M_PD		_at_ 0x0007;  // RW
xdata BYTE rCRY_12M_DR      _at_ 0x0008;  // RW

xdata BYTE rCSTM_ID1       	_at_ 0x000D;  // RW
xdata BYTE rCSTM_ID2       	_at_ 0x000E;  // RW
xdata BYTE rCSTM_ID3       	_at_ 0x000F;  // RW

// GPIO
xdata BYTE rGPIOA_OEN     	_at_ 0x0010;  // RW
xdata BYTE rGPIOB_OEN     	_at_ 0x0011;  // RW
xdata BYTE rGPIOC_OEN     	_at_ 0x0012;  // RW 
xdata BYTE rGPIOD_OEN     	_at_ 0x0013;  // RW 
xdata BYTE rGPIOE_OEN     	_at_ 0x0014;  // RW 
xdata BYTE rGPIOF_OEN     	_at_ 0x0015;  // RW 

xdata BYTE rGPIOA_DAT     	_at_ 0x0016;  // RW
xdata BYTE rGPIOB_DAT     	_at_ 0x0017;  // RW
xdata BYTE rGPIOC_DAT     	_at_ 0x0018;  // RW 
xdata BYTE rGPIOD_DAT     	_at_ 0x0019;  // RW 
xdata BYTE rGPIOE_DAT     	_at_ 0x001A;  // RW 
xdata BYTE rGPIOF_DAT    	_at_ 0x001B;  // RW 

xdata BYTE rGPIOA_PHN     	_at_ 0x001C;  // RW
xdata BYTE rGPIOB_PHN     	_at_ 0x001D;  // RW
xdata BYTE rGPIOC_PHN     	_at_ 0x001E;  // RW
xdata BYTE rGPIOD_PHN     	_at_ 0x001F;  // RW
xdata BYTE rGPIOE_PHN     	_at_ 0x0020;  // RW
xdata BYTE rGPIOF_PHN     	_at_ 0x0021;  // RW

xdata BYTE rGPIOA_TYP     	_at_ 0x0022;  // RW
xdata BYTE rGPIOE_TYP     	_at_ 0x0023;  // RW
xdata BYTE rGPIOF_TYP		_at_ 0x0024;  // RW

xdata BYTE rGPIOA_FUN1		_at_ 0x0025;  // RW 
xdata BYTE rGPIOA_FUN2     	_at_ 0x0026;  // RW		ADC 0~7 enable io pad 
xdata BYTE rGPIOB_FUN1      _at_ 0x0027;  // RW		SCAN 0~7 enable io pad
xdata BYTE rGPIOB_FUN2      _at_ 0x0028;  // RW
xdata BYTE rGPIOC_FUN1      _at_ 0x0029;  // RW
xdata BYTE rGPIOC_FUN2      _at_ 0x002A;  // RW
xdata BYTE rGPIOD_FUN1     	_at_ 0x002B;  // RW
xdata BYTE rGPIOD_FUN2     	_at_ 0x002C;  // RW
xdata BYTE rGPIOE_FUN1      _at_ 0x002D;  // RW
xdata BYTE rGPIOE_FUN2      _at_ 0x002E;  // RW
xdata BYTE rGPIOF_FUN1      _at_ 0x002F;  // RW
      
         

// 8051 Int-0/1/2/3
xdata BYTE rIE0_CTL     	_at_ 0x0030;  // RW
xdata BYTE rIE1_CTL     	_at_ 0x0031;  // RW
xdata BYTE rIE2_CTL     	_at_ 0x0032;  // RW
xdata BYTE rIE3_IRQH    	_at_ 0x0033;  // RW
xdata BYTE rIE3_IRQL    	_at_ 0x0034;  // RW
xdata BYTE rIF0_FLAG    	_at_ 0x0035;  // RW
xdata BYTE rIF1_FLAG    	_at_ 0x0036;  // RW
xdata BYTE rIF2_FLAG    	_at_ 0x0037;  // RW
xdata BYTE rIF3_IRQH    	_at_ 0x0038;  // RW
xdata BYTE rIF3_IRQL		_at_ 0x0039;  // RW

// IRQ
xdata BYTE rEN_IRQH	    	_at_ 0x0040;  // RW
xdata BYTE rEN_IRQL	 		_at_ 0x0041;  // RW
xdata BYTE rEVT_IRQH     	_at_ 0x0042;  // RW
xdata BYTE rEVT_IRQL    	_at_ 0x0043;  // RW
xdata BYTE rCLR_IRQH		_at_ 0x0044;  // RW
xdata BYTE rCLR_IRQL     	_at_ 0x0045;  // RW
xdata BYTE rIRQ_CHGH     	_at_ 0x0046;  // RW
xdata BYTE rIRQ_CHGL     	_at_ 0x0047;  // RW
xdata BYTE rIRQ_EDGEH    	_at_ 0x0048;  // RW
xdata BYTE rIRQ_EDGEL    	_at_ 0x0049;  // RW

// PWM
xdata BYTE rPWM_CTL         _at_ 0x0050;  // RW
xdata BYTE rPWM0_PRDH       _at_ 0x0051;  // RW 
xdata BYTE rPWM0_PRDL       _at_ 0x0052;  // RW
xdata BYTE rPWM0_DUTYH     	_at_ 0x0053;  // RW 
xdata BYTE rPWM0_DUTYL      _at_ 0x0054;  // RW
xdata BYTE rPWM1_PRDH       _at_ 0x0055;  // RW 
xdata BYTE rPWM1_PRDL       _at_ 0x0056;  // RW
xdata BYTE rPWM1_DUTYH     	_at_ 0x0057;  // RW 
xdata BYTE rPWM1_DUTYL      _at_ 0x0058;  // RW


// wakeup & Toggle
xdata BYTE rGPIOA_WK        _at_ 0x0060;  // RW
xdata BYTE rGPIOB_WK        _at_ 0x0061;  // RW
xdata BYTE rGPIOE_WK        _at_ 0x0062;  // RW
xdata BYTE rGPIOF_WK        _at_ 0x0063;  // RW
xdata BYTE rPERIPHERAL_WK	_at_ 0x0064;  // RW
xdata BYTE rGPIOA_TOG       _at_ 0x0065;  // R
xdata BYTE rGPIOB_TOG       _at_ 0x0066;  // R
xdata BYTE rGPIOE_TOG       _at_ 0x0067;  // R
xdata BYTE rGPIOF_TOG       _at_ 0x0068;  // R
xdata BYTE rPERIPHERAL_TOG  _at_ 0x0069;  // R
xdata BYTE rCLR_IN_TOG      _at_ 0x006A;  // RW

// IRC calibration
xdata BYTE rRC_LADJ			_at_ 0x0070;  // RW
xdata BYTE rRC12M_CNTH		_at_ 0x0071;  // RW
xdata BYTE rRC12M_CNTL		_at_ 0x0072;  // RW
xdata BYTE rRC_CALIB_EN		_at_ 0x0073;  // RW

// WDT
xdata BYTE rWDT_CTL			_at_ 0x0078;  // RW

// WATCH Timer
xdata BYTE rWTMR_CTL		_at_ 0x007C;  // RW
xdata BYTE rWTMR_SLT		_at_ 0x007D;  // RW

//LCD Driver
xdata BYTE rLCD_DAT0    	_at_ 0x0080;  // RW
xdata BYTE rLCD_DAT1   		_at_ 0x0081;  // RW
xdata BYTE rLCD_DAT2    	_at_ 0x0082;  // RW
xdata BYTE rLCD_DAT3    	_at_ 0x0083;  // RW
xdata BYTE rLCD_DAT4    	_at_ 0x0084;  // RW
xdata BYTE rLCD_DAT5    	_at_ 0x0085;  // RW
xdata BYTE rLCD_DAT6    	_at_ 0x0086;  // RW
xdata BYTE rLCD_DAT7    	_at_ 0x0087;  // RW
xdata BYTE rLCD_DAT8    	_at_ 0x0088;  // RW
xdata BYTE rLCD_DAT9    	_at_ 0x0089;  // RW
xdata BYTE rLCD_DAT10   	_at_ 0x008A;  // RW
xdata BYTE rLCD_DAT11   	_at_ 0x008B;  // RW
xdata BYTE rLCD_DAT12   	_at_ 0x008C;  // RW
xdata BYTE rLCD_DAT13   	_at_ 0x008D;  // RW
xdata BYTE rLCD_DAT14   	_at_ 0x008E;  // RW
xdata BYTE rLCD_DAT15   	_at_ 0x008F;  // RW
xdata BYTE rLCD_DAT16   	_at_ 0x0090;  // RW
xdata BYTE rLCD_DAT17   	_at_ 0x0091;  // RW
xdata BYTE rLCD_DAT18   	_at_ 0x0092;  // RW
xdata BYTE rLCD_DAT19		_at_ 0x0093;  // RW


// LCD Control Register 1 
xdata BYTE rLCD_CTL1		_at_ 0x0098;  // W
xdata BYTE rLCD_CTL2   		_at_ 0x0099;  // R
xdata BYTE rLCD_CVLS		_at_ 0x009A;  // R
xdata BYTE rLCD_PSC    		_at_ 0x009B;  // RW
xdata BYTE rSEG_EN0    		_at_ 0x009C;  // RW
xdata BYTE rSEG_EN1   	 	_at_ 0x009D;  // RW
xdata BYTE rSEG_EN2    		_at_ 0x009E;  // RW


// Master/Slave I2C Interface
xdata BYTE rMI2C_CTL       _at_ 0x00A0;  // RW
xdata BYTE rMI2C_STA       _at_ 0x00A1;  // RW
xdata BYTE rMI2C_DSLV      _at_ 0x00A2;  // RW
xdata BYTE rMI2C_DTRX      _at_ 0x00A3;  // R
xdata BYTE rMI2C_SADR      _at_ 0x00A4;  // RW
xdata BYTE rMI2C_EXTEND    _at_ 0x00A5;  // RW

// enhance Timer
xdata BYTE rETM_CTL1       _at_ 0x00B0;  // RW
xdata BYTE rETM_CTL2       _at_ 0x00B1;  // RW
xdata BYTE rETM_INT        _at_ 0x00B2;  // RW
xdata BYTE rETM_BUFL       _at_ 0x00B3;  // RW
xdata BYTE rETM_BUFH       _at_ 0x00B4;  // RW


// SPI
xdata BYTE rSPI_CTL1       	_at_ 0x00C0;  // RW
xdata BYTE rSPI_CTL2       	_at_ 0x00C1;  // RW
xdata BYTE rSPI_INT       	_at_ 0x00C2;  // RW
xdata BYTE rSPI_CLR      	_at_ 0x00C3;  // RW
xdata BYTE rSPI_FLG      	_at_ 0x00C4;  // RW
xdata BYTE rSPI_BRS     	_at_ 0x00C5;  // RW
xdata BYTE rSPI_TXBUF      	_at_ 0x00C6;  // RW
xdata BYTE rSPI_RXBUF     	_at_ 0x00C7;  // RW
	
// Low Speed ADC (for key scan)
xdata BYTE rADC_CTL       	_at_ 0x00D0;  // RW
xdata BYTE rADC_SEL     	_at_ 0x00D1;  // R
xdata BYTE rADC_INT      	_at_ 0x00D2;  // RW
xdata BYTE rADC_ENCH       	_at_ 0x00D3;  // RW
xdata BYTE rADC_CMP_VH     	_at_ 0x00D4;  // R
xdata BYTE rADC_CMP_VL      _at_ 0x00D5;  // RW
xdata BYTE rADC_DATAH      	_at_ 0x00D6;  // RW
xdata BYTE rADC_DATAL      	_at_ 0x00D7;  // RW

// Ananlog Comparator
xdata BYTE rACOMP_CTL      	_at_ 0x00DA;  // RW 
xdata BYTE rACOMP_FLG      	_at_ 0x00DB;  // RW 
xdata BYTE rACOMP_VREF      _at_ 0x00DC;  // RW 
xdata BYTE rACOMP_IOCTL     _at_ 0x00DD;  // RW
//simulation EEPROM
xdata BYTE rEER_EN1       	_at_ 0x00E0;  // W
xdata BYTE rEER_EN2       	_at_ 0x00E1;  // W
xdata BYTE rEER_ADDRL     	_at_ 0x00E2;  //RW		//bit 7-0
xdata BYTE rEER_ADDRH     	_at_ 0x00E3;  //RW		//bit 11-8
xdata BYTE rEER_TCTL     	_at_ 0x00E4;	//W
xdata BYTE rEER_DATA     	_at_ 0x00E8;  // W


xdata BYTE rFLASH_CTL	    _at_ 0x00F0;  // R/W
xdata BYTE rIRC_CTL		 	_at_ 0x00F2;  // R/W

#endif


//---------------------------------------
// XFR ---- using pdata
//---------------------------------------
#if(XFR_USEING==PDATA_FOR_XFR)
// System Level Register
pdata BYTE rCHIP_ID       	_at_ 0x0000;  // R
pdata BYTE rSYS_CTL      	_at_ 0x0001;  // RW
pdata BYTE rLVD_CTL      	_at_ 0x0002;  // RW
pdata BYTE rRESET_FLG      	_at_ 0x0003;  // RW

// power saving
pdata BYTE rISP_CHG_CTL		_at_ 0x0004;  // RW
pdata BYTE rSOURCE_CLK_SLT	_at_ 0x0005;  // RW
pdata BYTE rCLOCK_SW_CTL	_at_ 0x0006;  // RW
pdata BYTE rIRC_12M_PD		_at_ 0x0007;  // RW
pdata BYTE rCRY_12M_DR      _at_ 0x0008;  // RW

pdata BYTE rCSTM_ID1       	_at_ 0x000D;  // RW
pdata BYTE rCSTM_ID2       	_at_ 0x000E;  // RW
pdata BYTE rCSTM_ID3       	_at_ 0x000F;  // RW

// GPIO
pdata BYTE rGPIOA_OEN     	_at_ 0x0010;  // RW
pdata BYTE rGPIOB_OEN     	_at_ 0x0011;  // RW
pdata BYTE rGPIOC_OEN     	_at_ 0x0012;  // RW 
pdata BYTE rGPIOD_OEN     	_at_ 0x0013;  // RW 
pdata BYTE rGPIOE_OEN     	_at_ 0x0014;  // RW 
pdata BYTE rGPIOF_OEN     	_at_ 0x0015;  // RW 

pdata BYTE rGPIOA_DAT     	_at_ 0x0016;  // RW
pdata BYTE rGPIOB_DAT     	_at_ 0x0017;  // RW
pdata BYTE rGPIOC_DAT     	_at_ 0x0018;  // RW 
pdata BYTE rGPIOD_DAT     	_at_ 0x0019;  // RW 
pdata BYTE rGPIOE_DAT     	_at_ 0x001A;  // RW 
pdata BYTE rGPIOF_DAT     	_at_ 0x001B;  // RW 

pdata BYTE rGPIOA_PHN     	_at_ 0x001C;  // RW
pdata BYTE rGPIOB_PHN     	_at_ 0x001D;  // RW
pdata BYTE rGPIOC_PHN     	_at_ 0x001E;  // RW
pdata BYTE rGPIOD_PHN     	_at_ 0x001F;  // RW
pdata BYTE rGPIOE_PHN    	_at_ 0x0020;  // RW
pdata BYTE rGPIOF_PHN    	_at_ 0x0021;  // RW

pdata BYTE rGPIOA_TYP     	_at_ 0x0022;  // RW
pdata BYTE rGPIOE_TYP     	_at_ 0x0023;  // RW
pdata BYTE rGPIOF_TYP     	_at_ 0x0024;  // RW

pdata BYTE rGPIOA_FUN1      _at_ 0x0025;  // RW 
pdata BYTE rGPIOA_FUN2     	_at_ 0x0026;  // RW		ADC 0~7 enable io pad 
pdata BYTE rGPIOB_FUN1      _at_ 0x0027;  // RW		SCAN 0~7 enable io pad
pdata BYTE rGPIOB_FUN2      _at_ 0x0028;  // RW
pdata BYTE rGPIOC_FUN1      _at_ 0x0029;  // RW
pdata BYTE rGPIOC_FUN2      _at_ 0x002A;  // RW
pdata BYTE rGPIOD_FUN1     	_at_ 0x002B;  // RW
pdata BYTE rGPIOD_FUN2     	_at_ 0x002C;  // RW
pdata BYTE rGPIOE_FUN1      _at_ 0x002D;  // RW
pdata BYTE rGPIOE_FUN2      _at_ 0x002E;  // RW
pdata BYTE rGPIOF_FUN1      _at_ 0x002F;  // RW
         

// 8051 Int-0/1/2/3
pdata BYTE rIE0_CTL     	_at_ 0x0030;  // RW
pdata BYTE rIE1_CTL     	_at_ 0x0031;  // RW
pdata BYTE rIE2_CTL     	_at_ 0x0032;  // RW
pdata BYTE rIE3_IRQH    	_at_ 0x0033;  // RW
pdata BYTE rIE3_IRQL    	_at_ 0x0034;  // RW
pdata BYTE rIF0_FLAG    	_at_ 0x0035;  // RW
pdata BYTE rIF1_FLAG    	_at_ 0x0036;  // RW
pdata BYTE rIF2_FLAG    	_at_ 0x0037;  // RW
pdata BYTE rIF3_IRQH    	_at_ 0x0038;  // RW
pdata BYTE rIF3_IRQL		_at_ 0x0039;  // RW

// IRQ
pdata BYTE rEN_IRQH	      	_at_ 0x0040;  // RW
pdata BYTE rEN_IRQL	 		_at_ 0x0041;  // RW
pdata BYTE rEVT_IRQH     	_at_ 0x0042;  // RW
pdata BYTE rEVT_IRQL    	_at_ 0x0043;  // RW
pdata BYTE rCLR_IRQH		_at_ 0x0044;  // RW
pdata BYTE rCLR_IRQL     	_at_ 0x0045;  // RW
pdata BYTE rIRQ_CHGH     	_at_ 0x0046;  // RW
pdata BYTE rIRQ_CHGL     	_at_ 0x0047;  // RW
pdata BYTE rIRQ_EDGEH     	_at_ 0x0048;  // RW
pdata BYTE rIRQ_EDGEL     	_at_ 0x0049;  // RW

// PWM
pdata BYTE rPWM_CTL         _at_ 0x0050;  // RW
pdata BYTE rPWM0_PRDH       _at_ 0x0051;  // RW 
pdata BYTE rPWM0_PRDL       _at_ 0x0052;  // RW
pdata BYTE rPWM0_DUTYH      _at_ 0x0053;  // RW 
pdata BYTE rPWM0_DUTYL      _at_ 0x0054;  // RW
pdata BYTE rPWM1_PRDH       _at_ 0x0055;  // RW 
pdata BYTE rPWM1_PRDL       _at_ 0x0056;  // RW
pdata BYTE rPWM1_DUTYH      _at_ 0x0057;  // RW 
pdata BYTE rPWM1_DUTYL      _at_ 0x0058;  // RW


// wakeup & Toggle
pdata BYTE rGPIOA_WK        _at_ 0x0060;  // RW
pdata BYTE rGPIOB_WK        _at_ 0x0061;  // RW
pdata BYTE rGPIOE_WK        _at_ 0x0062;  // RW
pdata BYTE rGPIOF_WK        _at_ 0x0063;  // RW
pdata BYTE rPERIPHERAL_WK   _at_ 0x0064;  // RW
pdata BYTE rGPIOA_TOG       _at_ 0x0065;  // R
pdata BYTE rGPIOB_TOG       _at_ 0x0066;  // R
pdata BYTE rGPIOE_TOG       _at_ 0x0067;  // R
pdata BYTE rGPIOF_TOG       _at_ 0x0068;  // R
pdata BYTE rPERIPHERAL_TOG  _at_ 0x0069;  // R
pdata BYTE rCLR_IN_TOG      _at_ 0x006A;  // RW

// IRC calibration
pdata BYTE rRC_LADJ			_at_ 0x0070;  // RW
pdata BYTE rRC12M_CNTH		_at_ 0x0071;  // RW
pdata BYTE rRC12M_CNTL		_at_ 0x0072;  // RW
pdata BYTE rRC_CALIB_EN		_at_ 0x0073;  // RW

// WDT
pdata BYTE rWDT_CTL			_at_ 0x0078;  // RW

// WATCH Timer
pdata BYTE rWTMR_CTL		_at_ 0x007C;  // RW
pdata BYTE rWTMR_SLT		_at_ 0x007D;  // RW

//LCD Driver
//LCD顯示資料暫存器 0-19
pdata BYTE rLCD_DAT0    	_at_ 0x0080;  // RW
pdata BYTE rLCD_DAT1    	_at_ 0x0081;  // RW
pdata BYTE rLCD_DAT2    	_at_ 0x0082;  // RW
pdata BYTE rLCD_DAT3    	_at_ 0x0083;  // RW
pdata BYTE rLCD_DAT4    	_at_ 0x0084;  // RW
pdata BYTE rLCD_DAT5    	_at_ 0x0085;  // RW
pdata BYTE rLCD_DAT6    	_at_ 0x0086;  // RW
pdata BYTE rLCD_DAT7    	_at_ 0x0087;  // RW
pdata BYTE rLCD_DAT8    	_at_ 0x0088;  // RW
pdata BYTE rLCD_DAT9    	_at_ 0x0089;  // RW
pdata BYTE rLCD_DAT10   	_at_ 0x008A;  // RW
pdata BYTE rLCD_DAT11   	_at_ 0x008B;  // RW
pdata BYTE rLCD_DAT12   	_at_ 0x008C;  // RW
pdata BYTE rLCD_DAT13   	_at_ 0x008D;  // RW
pdata BYTE rLCD_DAT14   	_at_ 0x008E;  // RW
pdata BYTE rLCD_DAT15   	_at_ 0x008F;  // RW
pdata BYTE rLCD_DAT16   	_at_ 0x0090;  // RW
pdata BYTE rLCD_DAT17  		_at_ 0x0091;  // RW
pdata BYTE rLCD_DAT18   	_at_ 0x0092;  // RW
pdata BYTE rLCD_DAT19		_at_ 0x0093;  // RW

// LCD Control Register 1 
pdata BYTE rLCD_CTL1		_at_ 0x0098;  // W
pdata BYTE rLCD_CTL2   		_at_ 0x0099;  // R
pdata BYTE rLCD_CVLS		_at_ 0x009A;  // R
pdata BYTE rLCD_PSC    		_at_ 0x009B;  // RW
pdata BYTE rSEG_EN0    		_at_ 0x009C;  // RW
pdata BYTE rSEG_EN1    		_at_ 0x009D;  // RW
pdata BYTE rSEG_EN2    		_at_ 0x009E;  // RW


// Master/Slave I2C Interface
pdata BYTE rMI2C_CTL       	_at_ 0x00A0;  // RW
pdata BYTE rMI2C_STA       	_at_ 0x00A1;  // RW
pdata BYTE rMI2C_DSLV       _at_ 0x00A2;  // RW
pdata BYTE rMI2C_DTRX       _at_ 0x00A3;  // R
pdata BYTE rMI2C_SADR      	_at_ 0x00A4;  // RW
pdata BYTE rMI2C_EXTEND     _at_ 0x00A5;  // RW

// enhance Timer
pdata BYTE rETM_CTL1       	_at_ 0x00B0;  // RW
pdata BYTE rETM_CTL2       	_at_ 0x00B1;  // RW
pdata BYTE rETM_INT       	_at_ 0x00B2;  // RW
pdata BYTE rETM_BUFL        _at_ 0x00B3;  // RW
pdata BYTE rETM_BUFH        _at_ 0x00B4;  // RW


// SPI
pdata BYTE rSPI_CTL1       	_at_ 0x00C0;  // RW
pdata BYTE rSPI_CTL2       	_at_ 0x00C1;  // RW
pdata BYTE rSPI_INT       	_at_ 0x00C2;  // RW
pdata BYTE rSPI_CLR      	_at_ 0x00C3;  // RW
pdata BYTE rSPI_FLG      	_at_ 0x00C4;  // RW
pdata BYTE rSPI_BRS     	_at_ 0x00C5;  // RW
pdata BYTE rSPI_TXBUF      	_at_ 0x00C6;  // RW
pdata BYTE rSPI_RXBUF     	_at_ 0x00C7;  // RW

// Low Speed ADC (for key scan)
pdata BYTE rADC_CTL       	_at_ 0x00D0;  // RW
pdata BYTE rADC_SEL     	_at_ 0x00D1;  // R
pdata BYTE rADC_INT      	_at_ 0x00D2;  // RW
pdata BYTE rADC_ENCH       	_at_ 0x00D3;  // RW
pdata BYTE rADC_CMP_VH     	_at_ 0x00D4;  // R
pdata BYTE rADC_CMP_VL      _at_ 0x00D5;  // RW
pdata BYTE rADC_DATAH      	_at_ 0x00D6;  // RW
pdata BYTE rADC_DATAL      	_at_ 0x00D7;  // RW

// Ananlog Comparator
pdata BYTE rACOMP_CTL      	_at_ 0x00DA;  // RW 
pdata BYTE rACOMP_FLG      	_at_ 0x00DB;  // RW 
pdata BYTE rACOMP_VREF      _at_ 0x00DC;  // RW 
pdata BYTE rACOMP_IOCTL     _at_ 0x00DD;  // RW 
//simulation EEPROM
pdata BYTE rEER_EN1       	_at_ 0x00E0;  // W
pdata BYTE rEER_EN2       	_at_ 0x00E1;  // W
pdata BYTE rEER_ADDRL     	_at_ 0x00E2;  //RW		//bit 7-0
pdata BYTE rEER_ADDRH     	_at_ 0x00E3;  //RW		//bit 11-8
pdata BYTE rEER_TCTL     	_at_ 0x00E4;	//W
pdata BYTE rEER_DATA     	_at_ 0x00E8;  // W

#endif


#if(XFR_USEING==PDATA_FOR_PBYTE)

#endif

//Define information

//=====================================================================================
