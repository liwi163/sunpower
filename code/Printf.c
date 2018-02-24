#include "gheader.h"


/*
*******************************************************************************
设计		liwei
文件		Printf.c
功能		输出打印信息


*******************************************************************************

*/

code  BYTE Hex[]="0123456789ABCDEF";


void DoPrint( const char *fmt, va_list ap )
{
		char  ch;
		char  i;
		long  value;
		bit   fl_zero;
		bit   fl_num;
		BYTE  fl_len;
		BYTE  cnt;
		uint32 mask=1;

		char *ptr;

	while(1) {
		
		//----- Find Formatter % -----

		switch( ch = *fmt++ ) {
			case 0:		return;
			case '%':	if( *fmt != '%' ) break;
						fmt++;
			default:	_outchar( ch );
						continue;
		}

		//----- Get Count -------------
		
		fl_zero = 0;
		fl_num = 0;
		cnt = 0;

		ch = *fmt++;

		if( ch=='0' ) {
			fl_zero = 1;
			ch = *fmt++;
			cnt = ch - '0';
			ch = *fmt++;
		}
		else if( ch>='0' && ch<='9' ) {
			cnt = ch - '0';
			ch = *fmt++;
		}

		//----- Get char(B) / int / long(L) ----------------

		fl_len = 2;

		switch(ch) {
		case 'l':
		case 'L':	ch = *fmt++;	fl_len = 4;		break;
		case 'b':
		case 'B':	ch = *fmt++;	fl_len = 1;		break;
		}		

		//----- Get Type Discriptor -----
		
		switch( ch ) {

			case 'd':
			case 'u':

				switch (fl_len) {
				case 1:
					if( ch=='d' ) value = (char)va_arg( ap, char );
					else          value = (BYTE)va_arg( ap, BYTE );
					break;

				case 2:
					if( ch=='d' ) value = (int)va_arg( ap,  int );
					else          value = (uint16)va_arg( ap, uint16 );
					break;

				case 4:
					if( ch=='d' ) value = (long)va_arg( ap, long );
					else          value = (uint32)va_arg( ap, uint32 );
					break;
				}

				if( value<0 ) {
					_outchar('-');
					value = value*(-1);
				}

				if(cnt==0) {
					if( value==0 ) { _outchar('0'); continue; }

					for(cnt=0, mask=1; cnt<10; cnt++) {
						if( (value/mask)==0 ) break;
						mask = mask*10;
					}
				}

				for(i=0, mask=1; i<cnt-1; i++) mask = mask*10;

				while(1) {
					ch = (value / mask) + '0';
					if( ch=='0' && fl_zero==0 && mask!=1 ) ch=' ';
					else fl_zero = 1;
					_outchar(ch);

					value = value % (mask);
					mask = mask / 10;
					
					if( mask==0 )
						break;
				}
				continue;

			case 'x':
			case 'X':

				switch (fl_len) {
				case 1:	value = (BYTE)va_arg( ap, BYTE );		break;
				case 2:	value = (uint16)va_arg( ap, uint16 );		break;
				case 4:	value = (uint32)va_arg( ap, uint32 );		break;
				}

				if(cnt==0) cnt = fl_len*2;

				for(i=0; i<cnt; i++) {
					_outchar( Hex[(value >> (cnt-i-1)*4) & 0x000f] );
				}
				continue;

			case 's':

				ptr = (char *)va_arg( ap, char* );
				while(*ptr!='\0')
					_outchar(*ptr++);
				continue;

			case 'c':
				value = va_arg( ap, char );
					_outchar((BYTE)value);
				continue;

			default:
				value = (WORD)va_arg( ap, int );
				continue;
		}
	}
}

void Printf( const char *fmt, ... )
{
	XDATA	va_list ap;

	_nop_ ();
	va_start(ap, fmt);
	DoPrint( fmt, ap );
	va_end( ap );
}

void Puts( char *ptr )
{
	while(*ptr!='\0')
		RS_tx(*ptr++);
}




#ifdef DEBUG

/*
void dPrintf( const char *fmt, ... )
{
	XDATA	va_list ap;

	if( DebugLevel >= DEBUG_INFO ) {
		va_start(ap, fmt);
		DoPrint( fmt, ap );
		va_end( ap );
	}
}


*/
/*
void wPrintf( const char *fmt, ... )
{
	va_list ap;

	if( DebugLevel >= DEBUG_WARN ) {
		va_start(ap, fmt);
		DoPrint( fmt, ap );
		va_end( ap );
	}
}
*/
/*
void ePrintf( const char *fmt, ... )
{
	va_list ap;

	if( DebugLevel >= DEBUG_ERR ) {
		va_start(ap, fmt);
		DoPrint( fmt, ap );
		va_end( ap );
	}
}
*/
//=============================================================================
//                                                                           
//=============================================================================

/*
void dPuts( char *ptr )
{
	if( DebugLevel >= DEBUG_INFO ) {
		while(*ptr!='\0')
			RS_tx(*ptr++);
	}
}
*/
/*
void wPuts( char *ptr )
{
	if( DebugLevel >= DEBUG_WARN ) {
		while(*ptr!='\0')
			RS_tx(*ptr++);
	}
}
*/
/*
void ePuts( char *ptr )
{
	if( DebugLevel >= DEBUG_ERR ) {
		while(*ptr!='\0')
			RS_tx(*ptr++);
	}
}
*/
#endif // DEBUG

