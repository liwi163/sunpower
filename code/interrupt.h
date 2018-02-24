#ifndef INTERRUPT_H
#define INTERRUPT_H
//=====================================================================================

#define Get_rIF3_IRQ15       GetBit(rIF3_IRQH,7)
#define Get_rIF3_IRQ14       GetBit(rIF3_IRQH,6)
#define Get_rIF3_IRQ13        GetBit(rIF3_IRQH,5)
#define Get_rIF3_IRQ12        GetBit(rIF3_IRQH,4)
#define Get_rIF3_IRQ11        GetBit(rIF3_IRQH,3)
#define Get_rIF3_IRQ10        GetBit(rIF3_IRQH,2)
#define Get_rIF3_IRQ9        GetBit(rIF3_IRQH,1)
#define Get_rIF3_IRQ8        GetBit(rIF3_IRQH,0)

#define Get_rIF3_IRQ7        GetBit(rIF3_IRQL,7)
#define Get_rIF3_IRQ6        GetBit(rIF3_IRQL,6)
#define Get_rIF3_IRQ5        GetBit(rIF3_IRQL,5)
#define Get_rIF3_IRQ4       GetBit(rIF3_IRQL,4)
#define Get_rIF3_IRQ3        GetBit(rIF3_IRQL,3)
#define Get_rIF3_IRQ2        GetBit(rIF3_IRQL,2)
#define Get_rIF3_IRQ1        GetBit(rIF3_IRQL,1)
#define Get_rIF3_IRQ0        GetBit(rIF3_IRQL,0)



//---------------------------------------------------------
#define IE0_SPI_EN		DefineBit(rIE0_CTL, bit7)
#define IE0_MI2C_EN		DefineBit(rIE0_CTL, bit6)
#define IE0_ADC_EN		DefineBit(rIE0_CTL, bit5)
#define IE0_ACOMP_EN	DefineBit(rIE0_CTL, bit4)
#define IE0_LVD_EN		DefineBit(rIE0_CTL, bit3)
#define IE0_WTMR_EN		DefineBit(rIE0_CTL, bit2)
#define IE0_ETMR_EN		DefineBit(rIE0_CTL, bit1)
#define IE0_INTOG_EN		DefineBit(rIE0_CTL, bit0)

#define IE1_SPI_EN		DefineBit(rIE1_CTL, bit7)
#define IE1_MI2C_EN		DefineBit(rIE1_CTL, bit6)
#define IE1_ADC_EN		DefineBit(rIE1_CTL, bit5)
#define IE1_ACOMP_EN	DefineBit(rIE1_CTL, bit4)
#define IE1_LVD_EN		DefineBit(rIE1_CTL, bit3)
#define IE1_WTMR_EN		DefineBit(rIE1_CTL, bit2)
#define IE1_ETMR_EN		DefineBit(rIE1_CTL, bit1)
#define IE1_INTOG_EN		DefineBit(rIE1_CTL, bit0)

#define IE2_SPI_EN		DefineBit(rIE2_CTL, bit7)
#define IE2_MI2C_EN		DefineBit(rIE2_CTL, bit6)
#define IE2_ADC_EN		DefineBit(rIE2_CTL, bit5)
#define IE2_ACOMP_EN	DefineBit(rIE2_CTL, bit4)
#define IE2_LVD_EN		DefineBit(rIE2_CTL, bit3)
#define IE2_WTMR_EN		DefineBit(rIE2_CTL, bit2)
#define IE2_ETMR_EN		DefineBit(rIE2_CTL, bit1)
#define IE2_INTOG_EN		DefineBit(rIE2_CTL, bit0)

#define IE3_IRQ15_EN		DefineBit(rIE3_IRQH, bit7)
#define IE3_IRQ14_EN		DefineBit(rIE3_IRQH, bit6)
#define IE3_IRQ13_EN		DefineBit(rIE3_IRQH, bit5)
#define IE3_IRQ12_EN		DefineBit(rIE3_IRQH, bit4)
#define IE3_IRQ11_EN		DefineBit(rIE3_IRQH, bit3)
#define IE3_IRQ10_EN		DefineBit(rIE3_IRQH, bit2)
#define IE3_IRQ9_EN		DefineBit(rIE3_IRQH, bit1)
#define IE3_IRQ8_EN		DefineBit(rIE3_IRQH, bit0)
#define IE3_IRQ7_EN		DefineBit(rIE3_IRQL, bit7)
#define IE3_IRQ6_EN		DefineBit(rIE3_IRQL, bit6)
#define IE3_IRQ5_EN		DefineBit(rIE3_IRQL, bit5)
#define IE3_IRQ4_EN		DefineBit(rIE3_IRQL, bit4)
#define IE3_IRQ3_EN		DefineBit(rIE3_IRQL, bit3)
#define IE3_IRQ2_EN		DefineBit(rIE3_IRQL, bit2)
#define IE3_IRQ1_EN		DefineBit(rIE3_IRQL, bit1)
#define IE3_IRQ0_EN		DefineBit(rIE3_IRQL, bit0)

//--------------------------------
//	External IRQ Interrupt  --------- XFR_0x40 ~ XFR_0x49
//
//--------------------------------
//<1>:enable Ext_IRQxx
#define EXT_IRQ15_EN		DefineBit(rEN_IRQH, bit7)
#define EXT_IRQ14_EN		DefineBit(rEN_IRQH, bit6)
#define EXT_IRQ13_EN		DefineBit(rEN_IRQH, bit5)
#define EXT_IRQ12_EN		DefineBit(rEN_IRQH, bit4)
#define EXT_IRQ11_EN		DefineBit(rEN_IRQH, bit3)
#define EXT_IRQ10_EN		DefineBit(rEN_IRQH, bit2)
#define EXT_IRQ9_EN		DefineBit(rEN_IRQH, bit1)
#define EXT_IRQ8_EN		DefineBit(rEN_IRQH, bit0)
#define EXT_IRQ7_EN		DefineBit(rEN_IRQL, bit7)
#define EXT_IRQ6_EN		DefineBit(rEN_IRQL, bit6)
#define EXT_IRQ5_EN		DefineBit(rEN_IRQL, bit5)
#define EXT_IRQ4_EN		DefineBit(rEN_IRQL, bit4)
#define EXT_IRQ3_EN		DefineBit(rEN_IRQL, bit3)
#define EXT_IRQ2_EN		DefineBit(rEN_IRQL, bit2)
#define EXT_IRQ1_EN		DefineBit(rEN_IRQL, bit1)
#define EXT_IRQ0_EN		DefineBit(rEN_IRQL, bit0)

//<1>:IRQxx_Flag
#define EVT_IRQ15_EN		DefineBit(rEVT_IRQH, bit7)
#define EVT_IRQ14_EN		DefineBit(rEVT_IRQH, bit6)
#define EVT_IRQ13_EN		DefineBit(rEVT_IRQH, bit5)
#define EVT_IRQ12_EN		DefineBit(rEVT_IRQH, bit4)
#define EVT_IRQ11_EN		DefineBit(rEVT_IRQH, bit3)
#define EVT_IRQ10_EN		DefineBit(rEVT_IRQH, bit2)
#define EVT_IRQ9_EN		DefineBit(rEVT_IRQH, bit1)
#define EVT_IRQ8_EN		DefineBit(rEVT_IRQH, bit0)
#define EVT_IRQ7_EN		DefineBit(rEVT_IRQL, bit7)
#define EVT_IRQ6_EN		DefineBit(rEVT_IRQL, bit6)
#define EVT_IRQ5_EN		DefineBit(rEVT_IRQL, bit5)
#define EVT_IRQ4_EN		DefineBit(rEVT_IRQL, bit4)
#define EVT_IRQ3_EN		DefineBit(rEVT_IRQL, bit3)
#define EVT_IRQ2_EN		DefineBit(rEVT_IRQL, bit2)
#define EVT_IRQ1_EN		DefineBit(rEVT_IRQL, bit1)
#define EVT_IRQ0_EN		DefineBit(rEVT_IRQL, bit0)

//<1>:clear IRQxx_Flag
#define CLR_IRQ15_EN	DefineBit(rCLR_IRQH, bit7)
#define CLR_IRQ14_EN	DefineBit(rCLR_IRQH, bit6)
#define CLR_IRQ13_EN	DefineBit(rCLR_IRQH, bit5)
#define CLR_IRQ12_EN	DefineBit(rCLR_IRQH, bit4)
#define CLR_IRQ11_EN	DefineBit(rCLR_IRQH, bit3)
#define CLR_IRQ10_EN	DefineBit(rCLR_IRQH, bit2)
#define CLR_IRQ9_EN		DefineBit(rCLR_IRQH, bit1)
#define CLR_IRQ8_EN		DefineBit(rCLR_IRQH, bit0)
#define CLR_IRQ7_EN		DefineBit(rCLR_IRQL, bit7)
#define CLR_IRQ6_EN		DefineBit(rCLR_IRQL, bit6)
#define CLR_IRQ5_EN		DefineBit(rCLR_IRQL, bit5)
#define CLR_IRQ4_EN		DefineBit(rCLR_IRQL, bit4)
#define CLR_IRQ3_EN		DefineBit(rCLR_IRQL, bit3)
#define CLR_IRQ2_EN		DefineBit(rCLR_IRQL, bit2)
#define CLR_IRQ1_EN		DefineBit(rCLR_IRQL, bit1)
#define CLR_IRQ0_EN		DefineBit(rCLR_IRQL, bit0)

//<0/1>:BOTH/SINGLE -EDGE TRIGGER
#define EDGE0_IRQ15_EN		DefineBit(rIRQ_CHGH, bit7)
#define EDGE0_IRQ14_EN		DefineBit(rIRQ_CHGH, bit6)
#define EDGE0_IRQ13_EN		DefineBit(rIRQ_CHGH, bit5)
#define EDGE0_IRQ12_EN		DefineBit(rIRQ_CHGH, bit4)
#define EDGE0_IRQ11_EN		DefineBit(rIRQ_CHGH, bit3)
#define EDGE0_IRQ10_EN		DefineBit(rIRQ_CHGH, bit2)
#define EDGE0_IRQ9_EN		DefineBit(rIRQ_CHGH, bit1)
#define EDGE0_IRQ8_EN		DefineBit(rIRQ_CHGH, bit0)
#define EDGE0_IRQ7_EN		DefineBit(rIRQ_CHGL, bit7)
#define EDGE0_IRQ6_EN		DefineBit(rIRQ_CHGL, bit6)
#define EDGE0_IRQ5_EN		DefineBit(rIRQ_CHGL, bit5)
#define EDGE0_IRQ4_EN		DefineBit(rIRQ_CHGL, bit4)
#define EDGE0_IRQ3_EN		DefineBit(rIRQ_CHGL, bit3)
#define EDGE0_IRQ2_EN		DefineBit(rIRQ_CHGL, bit2)
#define EDGE0_IRQ1_EN		DefineBit(rIRQ_CHGL, bit1)
#define EDGE0_IRQ0_EN		DefineBit(rIRQ_CHGL, bit0)

//<0/1>:RISING/FALLING -EDGE TRIGGER, IF EDGE0 =1
#define EDGE1_IRQ15_EN		DefineBit(rIRQ_EDGEH, bit7)
#define EDGE1_IRQ14_EN		DefineBit(rIRQ_EDGEH, bit6)
#define EDGE1_IRQ13_EN		DefineBit(rIRQ_EDGEH, bit5)
#define EDGE1_IRQ12_EN		DefineBit(rIRQ_EDGEH, bit4)
#define EDGE1_IRQ11_EN		DefineBit(rIRQ_EDGEH, bit3)
#define EDGE1_IRQ10_EN		DefineBit(rIRQ_EDGEH, bit2)
#define EDGE1_IRQ9_EN		DefineBit(rIRQ_EDGEH, bit1)
#define EDGE1_IRQ8_EN		DefineBit(rIRQ_EDGEH, bit0)
#define EDGE1_IRQ7_EN		DefineBit(rIRQ_EDGEL, bit7)
#define EDGE1_IRQ6_EN		DefineBit(rIRQ_EDGEL, bit6)
#define EDGE1_IRQ5_EN		DefineBit(rIRQ_EDGEL, bit5)
#define EDGE1_IRQ4_EN		DefineBit(rIRQ_EDGEL, bit4)
#define EDGE1_IRQ3_EN		DefineBit(rIRQ_EDGEL, bit3)
#define EDGE1_IRQ2_EN		DefineBit(rIRQ_EDGEL, bit2)
#define EDGE1_IRQ1_EN		DefineBit(rIRQ_EDGEL, bit1)
#define EDGE1_IRQ0_EN		DefineBit(rIRQ_EDGEL, bit0)
//=====================================================================================

void INT3_ISR_12_int(void);



#endif
