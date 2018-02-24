//#include <REG52.H>
//=====================================================================================   

/*  BYTE Registers  */
sfr B     = 0xF0;
sfr ACC   = 0xE0;
//SFR 0xD8 ~ 0xDF
sfr rSCON1	= 0xD8;
sfr SBUF1 	= 0xD9;
sfr rSBRG1H = 0xDA;
sfr rSBRG1L = 0xDB;

//SFR 0xD0 ~ 0xD7
sfr PSW    = 0xD0;

//SFR 0xC0 ~ 0xCF
sfr rXICON	= 0xC0;
sfr T2CON   = 0xC8;
sfr T2MOD  	= 0xC9;
sfr RCAP2L 	= 0xCA;
sfr RCAP2H	= 0xCB;
sfr TL2   	= 0xCC;
sfr TH2   	= 0xCD;

//SFR 0xB8 ~ 0xBF
sfr IP    = 0xB8;
//SFR 0xA8 ~ 0xAF
sfr IE    = 0xA8;

//SFR 0x98 ~ 0x9F
sfr SCON0   = 0x98;
sfr SBUF0 	= 0x99;
sfr rSBRG0H = 0x9A;
sfr rSBRG0L = 0x9B;

//SFR 0x88 ~ 0x8F
sfr TCON  = 0x88;
sfr TMOD  	= 0x89;
sfr TL0   	= 0x8A;
sfr TL1   	= 0x8B;
sfr TH0   	= 0x8C;
sfr TH1   	= 0x8D;




//SFR 0x80 ~ 0x87
sfr P0    	= 0x80;
sfr SP    	= 0x81;
sfr DPL   	= 0x82;		/* Data Pointer Low Byte */
sfr DPH   	= 0x83;		/* Data Pointer High Byte */
sfr DPL1  	= 0x84;		/* Data Pointer 1 Low Byte */
sfr DPH1  	= 0x85;		/* Data Pointer 1 High Byte */
sfr DPS   	= 0x86;
sfr PCON  	= 0x87;



/*
================================================================================
=	特殊功能寄存器区的可位寻址的位定义
================================================================================
*/

// 8051 GPIO
sbit P07   	= P0^7;
sbit P06   	= P0^6;
sbit P05    	= P0^5;
sbit P04		= P0^4;
sbit P03   	= P0^3;
sbit P02   	= P0^2;
sbit P01    	= P0^1;
sbit P00		= P0^0;



/*  TCON  */
sbit TF1   = TCON^7;
sbit TR1   = TCON^6;
sbit TF0   = TCON^5;
sbit TR0   = TCON^4;
sbit IE1   = TCON^3;
sbit IT1   = TCON^2;
sbit IE0   = TCON^1;
sbit IT0   = TCON^0;

/*  SCON  */
sbit SM0   = SCON0^7;
sbit SM1   = SCON0^6;
sbit SM2   = SCON0^5;
sbit REN   = SCON0^4;
sbit TB8   = SCON0^3;
sbit RB8   = SCON0^2;
sbit TI    = SCON0^1;
sbit RI    = SCON0^0;

/*  IE  */
sbit EA    = IE^7;
sbit ES1   = IE^6;
sbit ET2   = IE^5; //8052 only
sbit ES    = IE^4;
sbit ET1   = IE^3;
sbit EX1   = IE^2;
sbit ET0   = IE^1;
sbit EX0   = IE^0;

/*  IP  */
sbit PS1 	= IP^6;
sbit PT2   = IP^5;
sbit PS    = IP^4;
sbit PT1   = IP^3;
sbit PX1   = IP^2;
sbit PT0   = IP^1;
sbit PX0   = IP^0;

/*  rT2CON  */
sbit TF2   = T2CON^7;
sbit EXF2  = T2CON^6;
sbit RCLK  = T2CON^5;
sbit TCLK  = T2CON^4;
sbit EXEN2 = T2CON^3;
sbit TR2   = T2CON^2;
sbit CT2   = T2CON^1;
sbit CPRL2 = T2CON^0;



/*  BIT Registers  */
/*  PSW  */
sbit CY		= PSW^7;
sbit AC  	= PSW^6;
sbit F0    	= PSW^5;
sbit RS1   	= PSW^4;
sbit RS0   	= PSW^3;
sbit OV    	= PSW^2;
sbit P     	= PSW^0; //8052 only


/*  rSCON1  */
sbit SM0_1	= rSCON1^7;
sbit SM1_1  = rSCON1^6;
sbit SM2_1  = rSCON1^5;
sbit REN_1  = rSCON1^4;
sbit TB8_1  = rSCON1^3;
sbit RB8_1  = rSCON1^2;
sbit TI_1   = rSCON1^1;
sbit RI_1   = rSCON1^0;



/*  rXICON  */
sbit PX3   = rXICON^7;
sbit EX3   = rXICON^6;
sbit IE3   = rXICON^5;
sbit IT3   = rXICON^4;
sbit PX2   = rXICON^3;
sbit EX2   = rXICON^2;
sbit IE2    = rXICON^1;
sbit IT2    = rXICON^0;
		











