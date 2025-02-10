#include "StdAfx.h"

void ReadyReload()
{
	if( pComandos.ReloadSwitch != 0 )
	{
		HookThis((DWORD)&DataReload,0x0049003D);
	}
}

//===============================================================================================
//-- New DataReload
//===============================================================================================
void APIENTRY DataReload()
{
	ReadCommonServerInfo();
	ReadyAll();
}

//===============================================================================================
//--  Realad All
//===============================================================================================
void ReadyAll()
{
	BalanceFile();
	Servidor();
	ReadGMSystem();
	Comandos();
	MoveReq();
	Fixes();
	Rates();
	Habilidades();
}