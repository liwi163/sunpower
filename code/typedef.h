#ifndef TYPEDEF_H
#define TYPEDEF_H
//====================================================

#define	uCHAR	unsigned char
#define	sCHAR	signed   char
#define	uINT	unsigned short
#define	sINT	signed   short
#define	uLONG	unsigned long
#define	sLONG	signed long
#define	npage	xdata
#define	zpage	data

#define PBYTE ((unsigned char volatile pdata *) 0)

typedef unsigned char ;
typedef unsigned char uint8;
typedef char i8;
typedef unsigned char u8 ,U8,BYTE;
typedef unsigned int  U16,WORD,u16;
typedef unsigned long U32,u32;
typedef unsigned int  uint16;
typedef unsigned long uint32;

#define DATA				data
#define PDATA			pdata
#define IDATA			idata
#define XDATA			xdata
#define CODE			code
#define CONST			code
#define CODE_P
#define FAR



//====================================================

//		TYPEDEFS													
//====================================================

typedef enum {FALSE = 0, TRUE = !FALSE} BoolStatus;

//====================================================
typedef struct
{
  BYTE  bit0 : 1;
  BYTE  bit1 : 1;
  BYTE  bit2 : 1;
  BYTE  bit3 : 1;
  BYTE  bit4 : 1;
  BYTE  bit5 : 1;
  BYTE  bit6 : 1;
  BYTE  bit7 : 1;
} tpBIT;


#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80

//====================================================
#define ON        1
#define OFF       0

#ifndef NULL
 #define NULL ((void *) 0)
#endif
//(void *)


//====================================================
#define SetBit(var, bit_no)     {var |= (1 << bit_no);}
#define ClrBit(var, bit_no)     {var &= ~(1 << bit_no);}
#define GetBit(var, bit_def)    ((var&(1 << bit_def))?1:0)
#define DefineBit(var, bitno)   (((tpBIT *)&var)->bitno)
//====================================================
#endif
