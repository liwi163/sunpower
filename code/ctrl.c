#include "gheader.h"

bit Flg_Power = 1;

#define  downset    0
#define  upset        70
u8 Pwmset=downset;


#if ENABLE_PWM_MODE 
WORD PwmDutyTotal;


WORD Pwm0Counter=0;



void API_AdjustPwm0Duty(BYTE DutyPercent)
{
	float DutyTotal;
	BYTE Pwm0DutyHi,Pwm0DutyLo;
	//Pwm0Counter = 1199;
	DutyTotal = (float)DutyPercent / 100;
	DutyTotal = Pwm0Counter * DutyTotal;
	PwmDutyTotal = DutyTotal;

	
	Pwm0DutyHi = (BYTE)(PwmDutyTotal/256);
	Pwm0DutyLo = (BYTE)(PwmDutyTotal%256);
	rPWM0_DUTYH = Pwm0DutyHi;
	rPWM0_DUTYL = Pwm0DutyLo; 
}



void DRV_InitialPWM(void)
{
	PWM0_PIN_OE = GPIO_OUTPUT_MODE;
	GPF0_FUN_SLT_PWM0();

	//PWM1_PIN_OE = GPIO_OUTPUT_MODE;
	//GPA7_FUN_SLT_PWM1();
	
			
	//PWM0 = GPIOF0
	//rPWM0_PRDH = PWM_PRE_1KHZ / 256;      
 	//rPWM0_PRDL = PWM_PRE_1KHZ % 256;      

    //PWM1 = GPIOA7
	//rPWM1_PRDH = PWM_PRE_5KHZ / 256;       
	//rPWM1_PRDL = PWM_PRE_5KHZ % 256;  
	//Pwm0Duty = 50;  
	Pwm0Counter = PWM_PRE_30KHZ;
	rPWM0_PRDH = Pwm0Counter / 256;      
 	rPWM0_PRDL = Pwm0Counter % 256;      

     
	//Pwm0Counter = Pwm0Counter - Pwm0Counter;
	rPWM0_DUTYH = (WORD)((Pwm0Counter/2) / 256);
	rPWM0_DUTYL = (WORD)((Pwm0Counter/2) % 256); 
	API_AdjustPwm0Duty(Pwmset);
 

	//PWM1 = GPIOA7
	//rPWM1_PRDH = 2048 / 256;       
	//rPWM1_PRDL = 2048 % 256;   
	//rPWM1_DUTYH = PWM_DUTY_50 / 256; 
	//rPWM1_DUTYL = PWM_DUTY_50 % 256;





	rPWM_CTL = 0;
	rPWM_CTL = ENABLE_PWM0;


		//Enabel PWM0 & PWM1
	//rPWM_CTL = (ENABLE_PWM1+ENABLE_PWM0);
}





#endif	



/*
********************************************************************************
* 	函 数 名: CtrKeyProc
* 	功能描述: 完成按键的解码处理
* 	输    入: 无
* 	返    回: 无
********************************************************************************
*/
void CtrKeyProc(void)
{
	uint8 keycode;
	
#if defined(EN_IRUSERCODE_MSG)
			MenuShowIRUserCode();
			return;
#endif
	if (!KeyHit())  return;
	keycode = KeyGetKey();
	
	//Printf("\r\nKeyIn ADC Value is: %bd", keycode );



	switch(keycode)
		{
		case KEYCODE_POWER:
			if ( Flg_KeyOnePress)		break;			// 不允许连击
			Flg_KeyOnePress = 1;
			
			break;				
		}

	
	//if(!CtrlIsPowerOn())	return;

	switch (keycode)  
		{
		
	
		
			case KEYCODE_VOLUP:
				if ( Flg_KeyOnePress)		break;			
				Flg_KeyOnePress = 0;//允许连击


				//SysPar.Brightness=SysPar.Brightness+1;
				//ActiveSave_Brightness();

				if(Pwmset<upset)Pwmset++;
				if(Pwmset>upset)Pwmset=upset;
				Printf("\r\nKeyIn Pwm =%d",(u16)Pwmset);
				
				 API_AdjustPwm0Duty(Pwmset);
				 Puts("\nPASS KEYCODE_VOLUP");
				
				break;
			case KEYCODE_VOLDOWN:
				if ( Flg_KeyOnePress)		break;			
				Flg_KeyOnePress = 0;// 允许连击

				if(Pwmset>downset) Pwmset--;
				Printf("\r\nKeyIn Pwm =%d",(u16)Pwmset);
					
				 API_AdjustPwm0Duty(Pwmset);


				Puts("\nPASS KEYCODE_VOLDOWN");
				break;
			case KEYCODE_MUTE:
				if ( Flg_KeyOnePress)		break;			// 不允许连击
				Flg_KeyOnePress = 1;
				
				
				Puts("\nPASS KEYCODE_MUTE");
				break;
	
	
		}
 }


 
 
 
 /*
 ********************************************************************************
 *	 函 数 名: CtrKeyProc
 *	 功能描述: 完成按键的解码处理
 *	 输    入: 无
 *	 返    回: 无
 ********************************************************************************
 */

 bit CtrlIsPowerOn(void)
 {

	 if (Flg_Power)  return 1;
	 else return 0;
 }

 /*
 ********************************************************************************
 *	 函 数 名: CtrKeyProc
 *	 功能描述: 完成按键的解码处理
 *	 输    入: 无
 *	 返    回: 无
 ********************************************************************************
 */

 void CtrlPowerOnOff(void)
 {
	 Flg_Power = ~Flg_Power;
 
 }

/*
********************************************************************************
* 	函 数 名: CtrKeyProc
* 	功能描述: 完成按键的解码处理
* 	输    入: 无
* 	返    回: 无
********************************************************************************
*/

void PowerOn(void)
{
	;
}

u16 ReadADC(u8 ch)
{
 DATA u16 key_in;
// DATA u32 temp;

	
	key_in=API_AverageADCData(ch);
	//Printf("\r\ key_in=%d ", (WORD)key_in);

	//v=5000;
	//j=4096;

	//temp=((u32)v)*((u32)key_in);
	//temp=temp/(u32)j;
	//Printf("\r\nKeyIn ADC [%bx]=   %d  Vl=%4x ", ch,(WORD)key_in, (u16)(temp>>8));

	#if 0
	Printf("\r\nKeyIn ADC [%bx]=%d ", ch,(WORD)key_in);
	#endif
	
	return key_in;
}




void SetUSB1_Output(bit sw)
{
	if(sw)
		USB_PowerSW=1;
	else
		USB_PowerSW=0;

}
