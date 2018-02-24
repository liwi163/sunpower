#ifndef __PRINTF_H__
#define __PRINTF_H__

#define _outchar(c) while(1) { if( !RS_Xbusy ) { ES=0; SBUF0 = c; RS_Xbusy=1; ES=1; break; } }

#define Putch(c) _outchar(c)

void Printf ( const char *fmt, ... );
void Puts ( char *ptr );

//========= Debugging String Display Functions =================
// 'nullFn' has to be defined in Compiler Option as nullFn="//" 
// to prevent compile error in No DEBUG option
//==============================================================
#ifdef DEBUG
 //void dPrintf( const char *fmt, ... );
 //void dPuts( char *ptr );

 #ifdef DEBUG_PC
 #define pcPrintf	dPrintf
 #else 
 #define pcPrintf	nullFn
 #endif

 #ifdef DEBUG_OSD
 #define osdPrintf	dPrintf
 #else 
 #define osdPrintf	nullFn
 #endif
 
 #ifdef DEBUG_TW
 #define twPrintf	dPrintf
 #else 
 #define twPrintf	nullFn
 #endif

#else
 #define dPrintf	nullFn
 #define dPuts		nullFn
 #define pcPrintf	nullFn
 #define osdPrintf	nullFn
 #define twPrintf	nullFn
#endif	// DEBUG

BYTE Getch(void);
BYTE Getche(void);


#endif	//__PRINTF_H__

