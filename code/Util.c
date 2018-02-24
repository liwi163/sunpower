#include "gheader.h"


BYTE Asc1Bin(BYTE asc)
{
	if(asc>='0' && asc <='9') return (asc - '0');
	else	if(asc>='a' && asc <='f') return (asc - 'a' + 0x0a);
	else    if(asc>='A' && asc <='F') return (asc - 'A' + 0x0a);
	else return asc;
}


uint32 a2h(BYTE *str)
{
	XDATA	uint32 num=0;
	XDATA	u8 i;
	
	for(i=0; ; i++, str++) {
		if( *str=='\0' || *str==' ' ) break;
		num = num*0x10 + Asc1Bin(*str);
	}
	return num;
}

#ifdef TW88xx
uint32 a2i(BYTE *str)
{
	XDATA	uint32 num=0;
	XDATA	BYTE i;

	for(i=0; ; i++, str++) {
		if( *str=='\0' || *str==' ' ) break;
		num = num*10 + *str - '0';
	}
	return num;
}

#endif

BYTE toupper(BYTE ch)
{
	if( ch>='a' && ch<='z' )
		return (ch - 'a' + 'A');
	else
		return ch;
}

int stricmp(BYTE *ptr1, BYTE *ptr2)
{
	XDATA	int	i, ret;
	
	for(i=0; *ptr1; i++) {
		ret = toupper(*ptr1++) - toupper(*ptr2++);
		if( ret ) return ret;
	}
	ret = toupper(*ptr1) - toupper(*ptr2);
	if( ret ) return ret;

	return 0;
}


