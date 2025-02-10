#include "StdAfx.h"

void LoadTrade()
{
	HookThis((DWORD)&GCTradeRequest, 0x402216);
	HookThis((DWORD)&GCTradeResponse, 0x4018E3);
	HookThis((DWORD)&GCTradeCancel, 0x401ED8);
}

int TradeTiempo			= GetPrivateProfileIntA("TRADE","Tiempo"			,10	,Aminyuz_Comandos);

void GCTradeRequest(PMSG_TRADE_REQUEST* objMsg, DWORD aIndex)
{
	unsigned long  Delay = (GetTickCount()- epObj[aIndex].m_TradeDelay)/1000;

	if (Delay < TradeTiempo)
	{
		MsgOutput(aIndex,"[AVISO] Espera %d segundos para Tradear nuevamente!",(TradeTiempo - Delay),aIndex);
		return;
	}
	epObj[aIndex].m_TradeDelay = GetTickCount();

	if(gObj[aIndex].Live == 1)
	{
		WORD szTarget = (WORD)gObj[aIndex].TargetNumber;

		if(gObj[aIndex].m_IfState.use == 1 && gObj[aIndex].m_IfState.type == 1 && gObj[aIndex].pTransaction == 1)
		{
			if(gObj[szTarget].Type == 1)
			{
				GCCancelTrade(aIndex);
				return;
			}
		}
		else
		{
			GCRequestTrade(objMsg,aIndex);
		}
	}
}

void GCTradeResponse(PMSG_TRADE_RESPONSE* objMsg, DWORD aIndex)
{
	if(gObj[aIndex].Live == 1)
	{
		WORD szTarget = (WORD)gObj[aIndex].TargetNumber;

		if(gObj[aIndex].m_IfState.use == 1 && gObj[aIndex].m_IfState.type == 1 && gObj[aIndex].pTransaction == 1)
		{
			if(gObj[szTarget].Type == 1)
			{
				GCCancelTrade(aIndex);
				return;
			}
		}
		else
		{
			GCResponseTrade(objMsg,aIndex);
		}
	}
}

void GCTradeCancel(DWORD aIndex)
{
	if(gObj[aIndex].Live == 1)
	{
		GCCancelTrade(aIndex);
		GCServerMsgStringSend("[AVISO] Cancelaste el Trade",aIndex,1);
	}
}