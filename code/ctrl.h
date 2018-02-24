#ifndef __CTRL_H__
#define __CTRL_H__

void CtrKeyProc(void);
bit CtrlIsPowerOn(void);
void CtrlPowerOnOff(void);
void PowerOn(void);
void PowerOff(void);
u16 ReadADC(u8 ch);

#define Vref				5030	/*毫伏*/

#define SHOWONLY		0x80
#define SHOW			0x40
#define HIDE				0x00
#define INC				0x20
#define DEC				0x00



/*
================================================================================
=	该枚举类型主要用于说明输入信号源的定义7
================================================================================
*/
typedef enum {
	TVI_1=0,		
	TVI_2,		
	TVI_3,		
	TVI_4,	
}INPUT_SOURCE;




#define up     1
#define down 0

#define ENABLE_PWM_MODE    1

#if ENABLE_PWM_MODE 

#define PWM0_PIN_OE       DefineBit(rGPIOF_OEN, bit0)
#define PWM0_PIN          DefineBit(rGPIOF_DAT, bit0)
#define PWM0_PIN_PHN      DefineBit(rGPIOF_PHN, bit0)

#define PWM1_PIN_OE       DefineBit(rGPIOA_OEN, bit7)
#define PWM1_PIN          DefineBit(rGPIOA_DAT, bit7)
#define PWM1_PIN_PHN      DefineBit(rGPIOA_PHN, bit7)




#define SOURCE_CLOCK	12000000


#define ENABLE_PWM0	0x01
#define ENABLE_PWM1	0x02

#define PWM_PRE_1KHZ	(WORD)((SOURCE_CLOCK/1000)-1)
#define PWM_PRE_2KHZ	(WORD)((SOURCE_CLOCK/2000)-1)
#define PWM_PRE_3KHZ	(WORD)((SOURCE_CLOCK/3000)-1)
#define PWM_PRE_4KHZ	(WORD)((SOURCE_CLOCK/4000)-1)
#define PWM_PRE_5KHZ	(WORD)((SOURCE_CLOCK/5000)-1)
#define PWM_PRE_6KHZ	(WORD)((SOURCE_CLOCK/6000)-1)
#define PWM_PRE_7KHZ	(WORD)((SOURCE_CLOCK/7000)-1)
#define PWM_PRE_8KHZ	(WORD)((SOURCE_CLOCK/8000)-1)
#define PWM_PRE_9KHZ	(WORD)((SOURCE_CLOCK/9000)-1)
#define PWM_PRE_10KHZ	(WORD)((SOURCE_CLOCK/10000)-1)
#define PWM_PRE_20KHZ	(WORD)((SOURCE_CLOCK/20000)-1)
#define PWM_PRE_30KHZ	(WORD)((SOURCE_CLOCK/30000)-1)
#define PWM_PRE_40KHZ	(WORD)((SOURCE_CLOCK/40000)-1)
#define PWM_PRE_50KHZ	(WORD)((SOURCE_CLOCK/50000)-1)
#define PWM_PRE_60KHZ	(WORD)((SOURCE_CLOCK/60000)-1)
#define PWM_PRE_70KHZ	(WORD)((SOURCE_CLOCK/70000)-1)
#define PWM_PRE_80KHZ	(WORD)((SOURCE_CLOCK/80000)-1)
#define PWM_PRE_90KHZ	(WORD)((SOURCE_CLOCK/90000)-1)
#define PWM_PRE_100KHZ	(WORD)((SOURCE_CLOCK/100000)-1)
#define PWM_PRE_200KHZ	(WORD)((SOURCE_CLOCK/200000)-1)
#define PWM_PRE_300KHZ	(WORD)((SOURCE_CLOCK/300000)-1)
#define PWM_PRE_400KHZ	(WORD)((SOURCE_CLOCK/400000)-1)
#define PWM_PRE_500KHZ	(WORD)((SOURCE_CLOCK/500000)-1)
#define PWM_PRE_600KHZ	(WORD)((SOURCE_CLOCK/600000)-1)
#define PWM_PRE_700KHZ	(WORD)((SOURCE_CLOCK/700000)-1)
#define PWM_PRE_800KHZ	(WORD)((SOURCE_CLOCK/800000)-1)
#define PWM_PRE_900KHZ	(WORD)((SOURCE_CLOCK/900000)-1)
#define PWM_PRE_1MHZ	(WORD)((SOURCE_CLOCK/1000000)-1)
#define PWM_PRE_2MHZ	(WORD)((SOURCE_CLOCK/2000000)-1)
#define PWM_PRE_3MHZ	(WORD)((SOURCE_CLOCK/3000000)-1)
#define PWM_PRE_4MHZ	(WORD)((SOURCE_CLOCK/4000000)-1)
#define PWM_PRE_5MHZ	(WORD)((SOURCE_CLOCK/5000000)-1)
#define PWM_PRE_6MHZ	(WORD)((SOURCE_CLOCK/6000000)-1)



extern u8 Pwmset;
extern WORD PwmDutyTotal;
extern WORD Pwm0Counter;

void DRV_InitialPWM(void);
void API_AdjustPwm0Duty(BYTE DutyPercent);
void SetUSB1_Output(bit sw);










































#endif


#endif
