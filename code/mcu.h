#ifndef _MCU_H_
#define _MCU_H_

extern u8 ResetStatus;

extern bdata bit m_b10ms;
extern bdata bit m_b100ms;
extern bdata bit m_b500ms;
extern bdata bit m_b1000ms;


#define RS_BUF_MAX		4  /*没有用到*/
extern u8 RS_buf[];
extern data u8 RS_in,RS_out;
extern bit RS_Xbusy;



void InitMcuReg(void);
void InitMcuPort(void);
void InitSysTimer(void);
void SelectUart0Baudrate(BYTE BitRateIndex);
void InitUartPort(void);
BYTE RS_ready(void);
BYTE RS_rx(void);
void RS_tx(BYTE tx_buf);
void RS_ungetch(BYTE ch);
void SysTimer(void);



#endif
