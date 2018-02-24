#ifndef __LCD_H__
#define __LCD_H__

#define SEG_A			0x01
#define SEG_B			0x02
#define SEG_C			0x04
#define SEG_D			0x08
#define SEG_E			0x10
#define SEG_F			0x20
#define SEG_G			0x40

/*以下的段位没有定义*/

#define SEG_H			0x0080
#define SEG_I			0x0100
#define SEG_J			0x0200
#define SEG_K			0x0400
#define SEG_L			0x0800
#define SEG_M			0x1000
#define SEG_N			0x2000



union FlageGrup{
  unsigned char Bb;
    struct {
        unsigned char B0:1;
        unsigned char B1:1;
        unsigned char B2:1;
        unsigned char B3:1;
        unsigned char B4:1;
        unsigned char B5:1;
        unsigned char B6:1;
        unsigned char B7:1;
    }Bi;
};




#define px(a,b)   			( (a<<3)|b)   // a表示地址偏移量; b表示com1~com4

#define NOT_SHOW   		px(6,0)

extern u8  DispNum[8];

/*

#define ICON_KHz          	Uicon[0].Bi.B0
#define ICON_MHz          	Uicon[0].Bi.B1
#define ICON_SW         	Uicon[0].Bi.B2
#define ICON_WET     		Uicon[0].Bi.B3
#define ICON_Dot100        Uicon[0].Bi.B4
#define ICON_Dot10          Uicon[0].Bi.B5
#define ICON_COL           	Uicon[0].Bi.B6
#define ICON_PM            	Uicon[0].Bi.B7
*/

#define ICON_T          	Uicon[0].Bi.B0
#define ICON_T1          	Uicon[0].Bi.B1
#define ICON_T2         	Uicon[0].Bi.B2
#define ICON_T3     		Uicon[0].Bi.B3
#define ICON_T4      		Uicon[0].Bi.B4
 #define ICON_BC1         	Uicon[0].Bi.B5
#define ICON_BC2           	Uicon[0].Bi.B6
#define ICON_L1            	Uicon[0].Bi.B7

#define ICON_L2          	Uicon[1].Bi.B0
#define ICON_L3          	Uicon[1].Bi.B1
#define ICON_L4      	  	Uicon[1].Bi.B2
#define ICON_L5     		Uicon[1].Bi.B3
#define ICON_L6       		Uicon[1].Bi.B4
#define ICON_L7         	Uicon[1].Bi.B5
#define ICON_L8           	Uicon[1].Bi.B6
#define ICON_L9            	Uicon[1].Bi.B7

#define ICON_L10          	Uicon[2].Bi.B0
#define ICON_L17          	Uicon[2].Bi.B1
#define ICON_L11         	Uicon[2].Bi.B2
#define ICON_L12     		Uicon[2].Bi.B3
#define ICON_L13       	Uicon[2].Bi.B4
#define ICON_L14         	Uicon[2].Bi.B5
#define ICON_L15           	Uicon[2].Bi.B6
#define ICON_L16            	Uicon[2].Bi.B7

#define CLEAR_ALL		    	0
#define CLEAR_ICON	    		1
#define CLEAR_NUM_ALL 		2	// 0-8(8-digit)

#define STR_MAX         3


//LCD_String 对应
#define STR_OFF        0
#define STR_ON         1
#define STR_SCAN     2



void LCDInit(void);
void DisplayNumber(void);
void DisplayIcon(void);
void DisplayClear(u8 mode);
void DisplayAll(void);
void DisplayUSB1_V_A(void);
void DisplayUSB2_A_V(void);
void SunPowerGo(void);
void ShowQCicon(void);
void ShowProcess_bar(u8 n);
u8 CalW(void);


#endif

