#include "gheader.h"


/*
*************************************************************************
设计		liwei
文件		main
功能		全局变量定义区
*************************************************************************
*/

u32 tic_pc=0;
u32 tic_01=0;




/*
*************************************************************************
设计		liwei
文件		main
功能		主函数入口李伟
*************************************************************************
*/

void main(void)
{
	InitMcuReg(); 
	InitMcuPort();
	InitSysTimer();
	InitUartPort();
	Printf("\n\n\n");
	Printf("\n********************************************************");
	Printf("\nSi475x Microdigital Board - %s (%s)", __TIME__, __DATE__);
	Printf("\n********************************************************");
	Delay(1);

	ADC_Init();
	
	KeyInit();

	LCDInit();

	EepInit();
	EepLoadAllPar();

	DRV_InitialPWM();
	SetUSB1_Output(ON);
	while(1)
	{
		SysTimer();		
		CtrKeyProc();
	}
	
}








/*
*************************************************************************
设计		liwei
文件		Delay
功能		1ms延时
*************************************************************************
*/

void Delay(WORD  ms)		                                                  
{                                                                                         
  WORD i, j;                                                                             
                                                                                          
  for(i = 0; i < ms; i++)                                                           
  {  
	for(j = 0; j < 0x96; j++)	                        
    {                                                                                     
      	_nop_();  			                                                                         
      	_nop_();                                                                            
      	_nop_();                                                                            
      	_nop_();                                                                            
      	_nop_();                                                                            
	_nop_();                                                          
      	_nop_();                                                                            
	_nop_();                                                          
      	_nop_();                                                                            
	_nop_();                                                          
      	_nop_();                                                                            
	_nop_();                                                          
      	_nop_(); 									                                                                         
    }                                                                                     
  }                                                                                       
} 
/*
*************************************************************************
设计		liwei
文件		Delay
功能		1ms延时
*************************************************************************
*/

void wait_us(u16 us)
{
	while(us--){
      	_nop_();                                                                            
      	_nop_();                                                                            
   //   	_nop_();                                                                            
    //  	_nop_();                                                                            
	}
}


/*
*************************************************************************
设计		liwei
文件		Delay
功能		1ms延时
*************************************************************************
*/

void Delayms(uint16 Time)
{
	tic_pc=0;
	do{;}while(tic_pc<Time);
}

#ifdef ENABLE_FLASH_MODE 


SYSPAR  data SysPar;

uint8 bdata ParAdjStateH;
uint8 bdata ParAdjStateL;

sbit sF_Bit15 = ParAdjStateH ^ 7;
sbit sF_Bit14 = ParAdjStateH ^ 6;
sbit sF_Bit13 = ParAdjStateH ^ 5;
sbit sF_Bit12 = ParAdjStateH ^ 4;
sbit sF_Bit11 = ParAdjStateH ^ 3;
sbit sF_Bit10 = ParAdjStateH ^ 2;
sbit sF_Bit09 = ParAdjStateH ^ 1;
sbit sF_Bit08 = ParAdjStateH ^ 0;

sbit sF_Bit07 = ParAdjStateL ^ 7;
sbit sF_Bit06 = ParAdjStateL ^ 6;
sbit sF_Bit05 = ParAdjStateL ^ 5;
sbit sF_Bit04 = ParAdjStateL ^ 4;
sbit sF_Bit03 = ParAdjStateL ^ 3;
sbit sF_Bit02 = ParAdjStateL ^ 2;
sbit sF_Bit01 = ParAdjStateL ^ 1;
sbit sF_Bit00 = ParAdjStateL ^ 0;




SYSPAR code DEF_SYSPAR={
32,
32,
32,
0x00,
32,
8,
2,
0,

};



//=====================================================================================
/*
1 bank = 256Bytes
Flash Address Range : 0x3000 ~ 0x3EFF = 3840 Bytes
Flash size : 256
EEPROM BYTE : 8
Group size (FlashIndex): 256 / 8 = 16
Write Total Time : 16 * 1000 = 16K
*/

//The WT56F216 flash last 4K can simulator EEPROM
//The WT56F216 total flash is 16K Bytes 0x0000 ~ 0x3FFF
//Simulator EEPROM Range :  0x3000 ~ 0x3EFF
/*
Using Flash function, please follow this step:
1. Eeprom size = FLASH_DEFAULT_SIZE
2. define flash start address = FLASH_DEFAULT_ADDRESS
3. define flash size = FLASH_SIZE
4. modify erase area = DRV_EraseFlash(x)
*/


void Eep_Write(u16 Addr,u16 Num,u8 *buf)
{

//	wait_us(10);		
	while(Num)
	{
		
		rEER_EN1 = 0x0A;								//EEPROM enable data1: 0x0A
		rEER_EN2 = 0x05;								//EEPROM enable data2: 0x05

		
		rEER_ADDRL = Addr;					//set EEPROM address	
		rEER_ADDRH = (Addr>>8)&0x0f;

		rEER_DATA=*buf;
		

		rEER_TCTL = (ENABLE_PROGRAM | PROGRAM_TIMING);

		rEER_EN1=0x00;		//;EEPROM disable data1: 0x00
		rEER_EN2=0x00;		//EEPROM disable data2: 0x00

		Addr++;
		Num--;
		buf++;
		
		}
}


/*
*******************************************************************************
设计		liwei
文件		RS_rx
功能		

//=========================================================
//This ReadFlashData routine for Encryp and no Encryp
//Eeprom Address = 0x3000 ~ 0x3FFF mapping XFR 0xE80 ~ 0xEFF
// (rEER_ADDRH,rEER_ADDRL) = 0x0000 = Eeprom Addres 0x3000 ~ 0x307F mapping XFR 0xE80 ~ 0xEFF 
// (rEER_ADDRH,rEER_ADDRL) = 0x0080 = Eeprom Addres 0x3080 ~ 0x30FF mapping XFR 0xE80 ~ 0xEFF 

// (rEER_ADDRH,rEER_ADDRL) = 0x0F00 = Eeprom Addres 0x3F00 ~ 0x307F mapping XFR 0xE80 ~ 0xEFF 
// (rEER_ADDRH,rEER_ADDRL) = 0x0F80 = Eeprom Addres 0x3F80 ~ 0x3FFF mapping XFR 0xE80 ~ 0xEFF
//=========================================================


*******************************************************************************

*/

void Eep_Read(u16 Addr,u16 Num,u8 *buf)
{

BYTE	R5=0;
WORD	wReadAddress;

BYTE	bReadHiByteAddress;
BYTE	bReadLowByteAddress;
wReadAddress =Addr;


	for(R5=0;R5<Num;R5++)
	{	
			//Address 0x3000 ~ 0x3FFF
			bReadLowByteAddress = wReadAddress;
			bReadHiByteAddress = (wReadAddress/256) & 0x0F;

			rEER_ADDRL = bReadLowByteAddress;								//set EEPROM address	
			rEER_ADDRH = bReadHiByteAddress;
			*buf++ = FLASH_BASE[bReadLowByteAddress+R5];
		
				
	}



	
}

#define Bank14ADDRESS		0x3E00
#define Bank14AddressLow		Bank14ADDRESS%256				
#define Bank14AddressHigh		Bank14ADDRESS>>8

void EraseFlash(void)
{
	
	rEER_EN1=0x0A; 				//;EEPROM enable data1: 0x0A
	rEER_EN2=0x05; 				//EEPROM enable data2: 0x05

	rEER_ADDRL = Bank14AddressLow;
	rEER_ADDRH = Bank14AddressHigh; 									

	rEER_TCTL = ENABLE_ERASE + ERASE_TIMING;;
	rEER_EN1 = 0x00;											//;EEPROM disable data1: 0x00
	rEER_EN2 = 0x00;											//EEPROM disable data2: 0x00

	
}



uint8 code StrUserName[]	= UserName; //UserName;
uint8 code StrVersion[] 	= FWVersion;
uint8 code StrRelease[] 	= ReleaseDate;

uint8 GetLenStrUserName(void)
{
	return sizeof(StrUserName);
}

//	软件版本
uint8 GetLenStrVersion(void)
{
	return sizeof(StrVersion);
}

//	发行的日期
uint8 GetLenStrRelease(void)
{
	return sizeof(StrRelease);
}




static uint8 EepCheckInitFlag(void)
{
	uint8  i,j,tmp,len;
	uint16 RomIdCheckSum,EepIdCheckSum;

	//	计算ROM中标记的校验码
	RomIdCheckSum = 0;
	len  = GetLenStrUserName();
	for (i = 0; i < len; i++) RomIdCheckSum += StrUserName[i];
	tmp = len;

	len   = GetLenStrVersion();
	for (i = 0; i < len; i++) RomIdCheckSum += StrVersion[i];
	tmp += len;

	len   = GetLenStrRelease();
	for (i = 0; i < len; i++) RomIdCheckSum += StrRelease[i];
	len = tmp + len;


	//	计算EEPROM中标记的校验码并和ROM中的校验码进行比较
	for (j = 0; j< 2; j++)  {							// 进行20次比较
		EepIdCheckSum = 0;								// 开始计算EEPROM中的校验码
		for (i = 0; i< len; i++) {
			Eep_Read(eepAdd_PRODUCTID + i, 1, &tmp);
			EepIdCheckSum += tmp;
			}
		
		if (RomIdCheckSum == EepIdCheckSum)  
			{
					Puts("\n\r EEPROM CHECK OK");
					return 1;	// 标志已建立
			}
		}

	return  0;		//	如果20次比较都失效，那么确认标志未建立
}

static void EepSaveProductID(void)
{
	uint16 Addr;
	uint8 len;

	Addr = eepAdd_PRODUCTID;
	len  = GetLenStrUserName();
	Eep_Write(Addr, len, StrUserName);

	Addr += len;
	len   = GetLenStrVersion();
	Eep_Write(Addr, len, StrVersion);

	Addr += len;
	len   = GetLenStrRelease();
	Eep_Write(Addr, len, StrRelease);
}


void EepInit(void)
{
	ClearParAdjState();

	if (EepCheckInitFlag())  return;						// 标志已建立则退出
		
	// 初始化与显示模式无关的参数
	Eep_Write(eepAdd_SYSPAR, SIZE_SYSPAR, (uint8 *)&DEF_SYSPAR);
	Puts("\n\r EEPROM Data Over");
	// 初始化产品标示，每一次重新开机就会检查产品标示，如果成功就不会重新初始化eeprom
	EepSaveProductID();

}


void EepLoadAllPar(void)
{
	
	Eep_Read(eepAdd_SYSPAR, SIZE_SYSPAR, (uint8 *)&SysPar);	
#ifdef Debug_Eeprom
	Printf("SysPar.Brightness= %02bx\r\n",SysPar.Brightness);
	Printf("SysPar.Contrast= %02bx\r\n",SysPar.Contrast);
	Printf("SysPar.Backlight= %02bx\r\n",SysPar.Backlight);
	Printf("SysPar.Backlight= %02bx\r\n",SysPar.Flag);
	Printf("SysPar.Color= %02bx\r\n",SysPar.Color);
	Printf("SysPar.Sharp= %02bx\r\n",SysPar.Sharp);
	Printf("SysPar.Volume= %02bx\r\n",SysPar.Volume);
#endif
}

void EepSavePar(void)
{
	if(GetState_Brightness())
	{

		EraseFlash();
		Eep_Write(eepAdd_SYSPAR, SIZE_SYSPAR, (uint8 *)&SysPar);
		EepSaveProductID();
	
		Puts("\r\n save ok");
	
	}
	ClearParAdjState();
}

#endif
