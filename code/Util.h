#ifndef __UTIL_H__
#define __UTIL_H__

#define _between(x, a, b)	(a<=x && x<=b)
#define _swap(a, b)			{ a^=b; b^=a; a^=b; }

#define Pause(a)	{ Printf("\r\n"); Printf(a); while(!RS_ready()); RS_rx(); }

uint32 a2i(BYTE *str);
uint32 a2h(BYTE *str);

BYTE Asc1Bin(BYTE asc);


BYTE toupper(BYTE ch);
int stricmp(BYTE *ptr1, BYTE *ptr2);

#endif // __UTIL_H__

