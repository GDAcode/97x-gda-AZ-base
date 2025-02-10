#include "StdAfx.h"

CGUSEITEMRECV  pCGUseItemRecv;

void ReadyCGUseItemRecv()
{
	 CGUseItemConfigs();
	 HookThis((DWORD)&CGUseItemRecvEx,0x4012BC);
}

void CGUseItemConfigs()
{
	pCGUseItemRecv.DelaySwitch = GetPrivateProfileIntA ("Pocion","Switch" ,0 ,Aminyuz_Servidor);
	pCGUseItemRecv.PotionDelay = GetPrivateProfileIntA ("Pocion","Tiempo" ,3 ,Aminyuz_Servidor);
}

void CGUseItemRecvEx(PMSG_USEITEM* lpMsg,int aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	CItem* m_Item = &lpObj->pInventory[lpMsg->inventoryPos];

	//=====================================================================
	// SEGURIDAD CONTRA TRAMPAS DE AUTO POCIONES
	//=====================================================================
	if(m_Item->m_Type >= ITEMGET(14,0) && m_Item->m_Type <=ITEMGET(14,6))
	{
		if(pCGUseItemRecv.DelaySwitch != 0 )  
	    {
	    unsigned long  Delay = (GetTickCount()- epObj[aIndex].m_PortionDelay)/1000;
	    if(Delay < pCGUseItemRecv.PotionDelay)
	    {
			return GCReFillSend(aIndex, (WORD)lpObj->Life, 0xFD, 1); 
	    }        
        epObj[aIndex].m_PortionDelay = GetTickCount();
	    }
		
	}

	CGUseItemRecv(lpMsg,aIndex);
}