//=====================================================================================
#include "gheader.h"
//=====================================================================================
//
//=====================================================================================
#define		IF_IRQ15		0x80
#define		IF_IRQ14		0x40
#define		IF_IRQ13		0x20
#define		IF_IRQ12		0x10
#define		IF_IRQ11		0x08
#define		IF_IRQ10		0x04
#define		IF_IRQ9		0x02
#define		IF_IRQ8		0x01
#define		IF_IRQ7		0x80
#define		IF_IRQ6		0x40
#define		IF_IRQ5		0x20
#define		IF_IRQ4		0x10
#define		IF_IRQ3		0x08
#define		IF_IRQ2		0x04
#define		IF_IRQ1		0x02
#define		IF_IRQ0		0x01 
//--------------------------------
#define		IF_SPI		0x80
#define		IF_MI2C		0x40
#define		IF_ADC		0x20
#define		IF_ACOMP	0x10
#define		IF_LVD		0x08
#define		IF_WTMR	0x04
#define		IF_ETMR		0x02
#define		IF_IN_TOG	0x01
//---------------------------------------------------------
//				Interrupt  Function
// Interrupt 			      vector    Num   Location
//=======================================
//External Interrupt-0	       03H		0   (highest)	IE.0	TCON.0
//Timer/Counter-0	       0BH		1	  IE.1	--
//External Interrrupt-1	       13H		2	  IE.2	TCON.2
//Timer/Counter-1	       1BH		3	  IE.3	--
//Serial Port	              	23H		4	  IE.4	--
//Timer/Counter-2	       2BH		5	  IE.5 	--
//Serial Port-1	              33H		6 	  IE.6	--
//External Interrupt-2	       3BH		7	  XICON.2	XICON.0
//External Interrupt-3	       43H		8   (lowest)	XICON.6	XICON.4
//---------------------------------------------------------
void INT0_ISR_Entry(void) interrupt 0 
{	



}
//======================================================
//
//======================================================
void INT1_ISR_Entry(void) interrupt 2 
{ 


}
//======================================================
//
//======================================================
void INT2_ISR_Entry(void) interrupt 7 
{ 

}
//======================================================
//	only for IRQ[15:0]
//======================================================
void INT3_ISR_Entry(void) interrupt 8 
{

}

