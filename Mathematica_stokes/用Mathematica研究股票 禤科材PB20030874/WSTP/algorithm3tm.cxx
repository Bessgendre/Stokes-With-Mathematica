/*
 * This file automatically produced by /Users/royalty/Desktop/MATHEMATICA/stokes_prediction/WSTP/algorithm/../CompilerAdditions/wsprep from:
 *	algorithm3.tm
 * wsprep Revision 19 Copyright (c) Wolfram Research, Inc. 1990-2022
 */

#define WSPREP_REVISION 19

#include "wstp.h"

int WSAbort = 0;
int WSDone  = 0;
long WSSpecialCharacter = '\0';

WSLINK stdlink = 0;
WSEnvironment stdenv = 0;
WSYieldFunctionObject stdyielder = (WSYieldFunctionObject)0;
WSMessageHandlerObject stdhandler = (WSMessageHandlerObject)0;

extern int WSDoCallPacket(WSLINK);
extern int WSEvaluate( WSLINK, char *);
extern int WSEvaluateString( WSLINK, char *);

/********************************* end header *********************************/


void algorithm3 ( double * _tp1, long _tpl1, double * _tp2, long _tpl2, double * _tp3, long _tpl3, double * _tp4, long _tpl4, double * _tp5, long _tpl5, int _tp6, double _tp7, double _tp8, double _tp9, double _tp10);

static int _tr0( WSLINK wslp)
{
	int	res = 0;
	double * _tp1;
	long _tpl1;
	double * _tp2;
	long _tpl2;
	double * _tp3;
	long _tpl3;
	double * _tp4;
	long _tpl4;
	double * _tp5;
	long _tpl5;
	int _tp6;
	double _tp7;
	double _tp8;
	double _tp9;
	double _tp10;
	if ( ! WSGetRealList( wslp, &_tp1, &_tpl1) ) goto L0;
	if ( ! WSGetRealList( wslp, &_tp2, &_tpl2) ) goto L1;
	if ( ! WSGetRealList( wslp, &_tp3, &_tpl3) ) goto L2;
	if ( ! WSGetRealList( wslp, &_tp4, &_tpl4) ) goto L3;
	if ( ! WSGetRealList( wslp, &_tp5, &_tpl5) ) goto L4;
	if ( ! WSGetInteger( wslp, &_tp6) ) goto L5;
	if ( ! WSGetReal( wslp, &_tp7) ) goto L6;
	if ( ! WSGetReal( wslp, &_tp8) ) goto L7;
	if ( ! WSGetReal( wslp, &_tp9) ) goto L8;
	if ( ! WSGetReal( wslp, &_tp10) ) goto L9;
	if ( ! WSNewPacket(wslp) ) goto L10;

	algorithm3(_tp1, _tpl1, _tp2, _tpl2, _tp3, _tpl3, _tp4, _tpl4, _tp5, _tpl5, _tp6, _tp7, _tp8, _tp9, _tp10);

	res = 1;
L10: L9: L8: L7: L6: L5:	WSReleaseReal64List(wslp, _tp5, _tpl5);
L4:	WSReleaseReal64List(wslp, _tp4, _tpl4);
L3:	WSReleaseReal64List(wslp, _tp3, _tpl3);
L2:	WSReleaseReal64List(wslp, _tp2, _tpl2);
L1:	WSReleaseReal64List(wslp, _tp1, _tpl1);

L0:	return res;
} /* _tr0 */


static struct func {
	int   f_nargs;
	int   manual;
	int   (*f_func)(WSLINK);
	const char  *f_name;
	} _tramps[1] = {
		{10, 0, _tr0, "algorithm3" }
		};

#define CARDOF_EVALSTRS 0

static int _definepattern( WSLINK, char*, char*, int);

int  _WSDoCallPacket( WSLINK, struct func[], int);


int WSInstall( WSLINK wslp)
{
	int _res;
	_res = WSConnect(wslp);
	if (_res) _res = _definepattern(wslp, (char *)"Algorithm3[b_List, h_List,l_List,e_List,huan_List,time_Integer,ratio1_Real,ratio2_Real,ratio3_Real,ratio4_Real]", (char *)"{b,h,l,e,huan,time,ratio1,ratio2,ratio3,ratio4}", 0);
	if (_res) _res = WSPutSymbol( wslp, "End");
	if (_res) _res = WSFlush( wslp);
	return _res;
} /* WSInstall */


int WSDoCallPacket( WSLINK wslp)
{
	return _WSDoCallPacket( wslp, _tramps, 1);
} /* WSDoCallPacket */

/******************************* begin trailer ********************************/

#ifndef EVALSTRS_AS_BYTESTRINGS
#	define EVALSTRS_AS_BYTESTRINGS 1
#endif


#if CARDOF_EVALSTRS
static int  _doevalstr( WSLINK wslp, int n)
{
	long bytesleft, charsleft, bytesnow;
#if !EVALSTRS_AS_BYTESTRINGS
	long charsnow;
#endif
	char **s, **p;
	char *t;

	s = (char **)evalstrs;
	while( n-- > 0){
		if( *s == 0) break;
		while( *s++ != 0){}
	}
	if( *s == 0) return 0;
	bytesleft = 0;
	charsleft = 0;
	p = s;
	while( *p){
		t = *p; while( *t) ++t;
		bytesnow = t - *p;
		bytesleft += bytesnow;
		charsleft += bytesnow;
#if !EVALSTRS_AS_BYTESTRINGS
		t = *p;
		charsleft -= WSCharacterOffset( &t, t + bytesnow, bytesnow);
		/* assert( t == *p + bytesnow); */
#endif
		++p;
	}


	WSPutNext( wslp, WSTKSTR);
#if EVALSTRS_AS_BYTESTRINGS
	p = s;
	while( *p){
		t = *p; while( *t) ++t;
		bytesnow = t - *p;
		bytesleft -= bytesnow;
		WSPut8BitCharacters( wslp, bytesleft, (unsigned char*)*p, bytesnow);
		++p;
	}
#else
	WSPut7BitCount( wslp, charsleft, bytesleft);
	p = s;
	while( *p){
		t = *p; while( *t) ++t;
		bytesnow = t - *p;
		bytesleft -= bytesnow;
		t = *p;
		charsnow = bytesnow - WSCharacterOffset( &t, t + bytesnow, bytesnow);
		/* assert( t == *p + bytesnow); */
		charsleft -= charsnow;
		WSPut7BitCharacters(  wslp, charsleft, *p, bytesnow, charsnow);
		++p;
	}
#endif
	return WSError( wslp) == WSEOK;
}
#endif /* CARDOF_EVALSTRS */


static int  _definepattern( WSLINK wslp, char *patt, char *args, int func_n)
{
	WSPutFunction( wslp, "DefineExternal", (long)3);
	  WSPutString( wslp, patt);
	  WSPutString( wslp, args);
	  WSPutInteger( wslp, func_n);
	return !WSError(wslp);
} /* _definepattern */


int _WSDoCallPacket( WSLINK wslp, struct func functable[], int nfuncs)
{
	int len;
	int n, res = 0;
	struct func* funcp;

	if( ! WSGetInteger( wslp, &n) ||  n < 0 ||  n >= nfuncs) goto L0;
	funcp = &functable[n];

	if( funcp->f_nargs >= 0
	&& ( ! WSTestHead(wslp, "List", &len)
	     || ( !funcp->manual && (len != funcp->f_nargs))
	     || (  funcp->manual && (len <  funcp->f_nargs))
	   )
	) goto L0;

	stdlink = wslp;
	res = (*funcp->f_func)( wslp);

L0:	if( res == 0)
		res = WSClearError( wslp) && WSPutSymbol( wslp, "$Failed");
	return res && WSEndPacket( wslp) && WSNewPacket( wslp);
} /* _WSDoCallPacket */


wsapi_packet WSAnswer( WSLINK wslp)
{
	wsapi_packet pkt = 0;
	int waitResult;

	while( ! WSDone && ! WSError(wslp)
		&& (waitResult = WSWaitForLinkActivity(wslp),waitResult) &&
		waitResult == WSWAITSUCCESS && (pkt = WSNextPacket(wslp), pkt) &&
		pkt == CALLPKT)
	{
		WSAbort = 0;
		if(! WSDoCallPacket(wslp))
			pkt = 0;
	}
	WSAbort = 0;
	return pkt;
} /* WSAnswer */



/*
	Module[ { me = $ParentLink},
		$ParentLink = contents of RESUMEPKT;
		Message[ MessageName[$ParentLink, "notfe"], me];
		me]
*/


static int refuse_to_be_a_frontend( WSLINK wslp)
{
	int pkt;

	WSPutFunction( wslp, "EvaluatePacket", 1);
	  WSPutFunction( wslp, "Module", 2);
	    WSPutFunction( wslp, "List", 1);
		  WSPutFunction( wslp, "Set", 2);
		    WSPutSymbol( wslp, "me");
	        WSPutSymbol( wslp, "$ParentLink");
	  WSPutFunction( wslp, "CompoundExpression", 3);
	    WSPutFunction( wslp, "Set", 2);
	      WSPutSymbol( wslp, "$ParentLink");
	      WSTransferExpression( wslp, wslp);
	    WSPutFunction( wslp, "Message", 2);
	      WSPutFunction( wslp, "MessageName", 2);
	        WSPutSymbol( wslp, "$ParentLink");
	        WSPutString( wslp, "notfe");
	      WSPutSymbol( wslp, "me");
	    WSPutSymbol( wslp, "me");
	WSEndPacket( wslp);

	while( (pkt = WSNextPacket( wslp), pkt) && pkt != SUSPENDPKT)
		WSNewPacket( wslp);
	WSNewPacket( wslp);
	return WSError( wslp) == WSEOK;
}


int WSEvaluate( WSLINK wslp, char *s)
{
	if( WSAbort) return 0;
	return WSPutFunction( wslp, "EvaluatePacket", 1L)
		&& WSPutFunction( wslp, "ToExpression", 1L)
		&& WSPutString( wslp, s)
		&& WSEndPacket( wslp);
} /* WSEvaluate */


int WSEvaluateString( WSLINK wslp, char *s)
{
	int pkt;
	if( WSAbort) return 0;
	if( WSEvaluate( wslp, s)){
		while( (pkt = WSAnswer( wslp), pkt) && pkt != RETURNPKT)
			WSNewPacket( wslp);
		WSNewPacket( wslp);
	}
	return WSError( wslp) == WSEOK;
} /* WSEvaluateString */


WSMDEFN( void, WSDefaultHandler, ( WSLINK wslp, int message, int n))
{
	switch (message){
	case WSTerminateMessage:
		WSDone = 1;
	case WSInterruptMessage:
	case WSAbortMessage:
		WSAbort = 1;
	default:
		return;
	}
}


static int _WSMain( char **argv, char **argv_end, char *commandline)
{
	WSLINK wslp;
	int err;

	if( !stdenv)
		stdenv = WSInitialize( (WSEnvironmentParameter)0);

	if( stdenv == (WSEnvironment)0) goto R0;

	if( !stdhandler)
		stdhandler = (WSMessageHandlerObject)WSDefaultHandler;


	wslp = commandline
		? WSOpenString( stdenv, commandline, &err)
		: WSOpenArgcArgv( stdenv, (int)(argv_end - argv), argv, &err);
	if( wslp == (WSLINK)0){
		WSAlert( stdenv, WSErrorString( stdenv, err));
		goto R1;
	}

	if( stdyielder) WSSetYieldFunction( wslp, stdyielder);
	if( stdhandler) WSSetMessageHandler( wslp, stdhandler);

	if( WSInstall( wslp))
		while( WSAnswer( wslp) == RESUMEPKT){
			if( ! refuse_to_be_a_frontend( wslp)) break;
		}

	WSClose( wslp);
R1:	WSDeinitialize( stdenv);
	stdenv = (WSEnvironment)0;
R0:	return !WSDone;
} /* _WSMain */


int WSMainString( char *commandline)
{
	return _WSMain( (charpp_ct)0, (charpp_ct)0, commandline);
}

int WSMainArgv( char** argv, char** argv_end) /* note not FAR pointers */
{   
	static char * far_argv[128];
	int count = 0;
	
	while(argv < argv_end)
		far_argv[count++] = *argv++;
		 
	return _WSMain( far_argv, far_argv + count, (charp_ct)0);

}


int WSMain( int argc, char **argv)
{
 	return _WSMain( argv, argv + argc, (char *)0);
}
 
