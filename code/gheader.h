//=====================================================================================
#include <math.h>
#include <stdarg.h>
#include <intrins.h>
#include <math.h>
#include <absacc.h>
#include "Typedef.h"
#include "option.h"
//=====================================================================================


#define USE_COMQUEUE	    	1	// (0)表示禁止，(1)表示允许。使用命令队列
#define PDATA_FOR_XFR         0
#define XDATA_FOR_XFR         1
#define PDATA_FOR_PBYTE     2

#define XFR_USEING      		PDATA_FOR_PBYTE//PDATA_FOR_XFR//XDATA_FOR_XFR 
#define WT56F216			2
#define DEBUG

#include "SFR_WT56F216.h"
#include "REG_WT56F216_MemAlloc.h"
#include "global.h"
#include "gpio.h"
#include "option.h"
#include "main.h"
#include "Interrupt.h"
#include "mcu.h"
#include "printf.h"
#include "key.h"
#include "ctrl.h"
#include "lcd.h"
//=====================================================================================
