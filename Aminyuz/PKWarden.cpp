#include "StdAfx.h"

PKWARDEN pPKWarden;

void LoadPKWarden()
{
	pPKWarden.PKWardenSwitch    = GetPrivateProfileIntA("PKWARDEN", "Switch", 0, Aminyuz_PKWarden);
	pPKWarden.PKWardenID		= GetPrivateProfileIntA("PKWARDEN", "ID", 223, Aminyuz_PKWarden);
	pPKWarden.PKWardenSistema	= GetPrivateProfileIntA("PKWARDEN", "Sistema", 1, Aminyuz_PKWarden);
	pPKWarden.PKWardenZen1		= GetPrivateProfileIntA("PKWARDEN", "Zen1", 10000000, Aminyuz_PKWarden);
	pPKWarden.PKWardenZen2      = GetPrivateProfileIntA("PKWARDEN", "Zen2", 20000000, Aminyuz_PKWarden);
	pPKWarden.PKWardenLevel		= GetPrivateProfileIntA("PKWARDEN", "Level", 1, Aminyuz_PKWarden);
	GetPrivateProfileString("PK UPDATE","UPDATE PK","UPDATE MuOnline.dbo.Character SET PkPunto = PkPunto + 1 WHERE Name = '%s'",pPKWarden.PQuery1,100,Aminyuz_PKWarden);
}

void PKWardenClick(LPOBJ gObj, LPOBJ gObjNPC, int aIndex)
{
	if(pPKWarden.PKWardenSwitch != 0)
	{
		PKWarden(gObj, gObjNPC,aIndex);
	}
	else
	{
		MsgOutput(aIndex,"No estoy de servico, vuelva mas tarde.");
	}
}

void PKWarden(LPOBJ gObj, LPOBJ NpcObj, int aIndex)
{
    if(gObj->m_PK_Level < 4)
    {
		MsgOutput(aIndex,"[AVISO] No sos pk!");
        return;
    }

    int PKWardenZen;

    switch(pPKWarden.PKWardenSistema)
    {
	case 0:
        PKWardenZen = 0;
        break;
    case 1:
        PKWardenZen = (pPKWarden.PKWardenZen1 * gObj->m_PK_Count);
        break;
    case 2:
         PKWardenZen = pPKWarden.PKWardenZen2;
        break;
    }

	if(gObj->Level < pPKWarden.PKWardenLevel )
	{
		MsgOutput(aIndex,"[AVISO] No tenes el nivel suficiente! Requerido: %d",pPKWarden.PKWardenLevel);
		return;
	}

    if(gObj->Money < PKWardenZen)
    {
		MsgOutput(aIndex,"[AVISO] No tenes el zen suficiente! Requerido: %d", PKWardenZen - gObj->Money);
        return;
    }

	if (gObj->m_PK_Count == 100)
	{
		Manager.ExecFormat(pPKWarden.PQuery1,gObj->Name);
		MsgOutput(aIndex,"[AVISO] Lograstes un Punto PK");
	}

    if (PKWardenZen > 0)
    {
        gObj->Money -= PKWardenZen;
        GCMoneySend (gObj->m_Index, gObj->Money);
		MsgOutput(aIndex,"[AVISO] Pagaste %d de Zen", PKWardenZen);
    }
	MsgOutput(aIndex,"[AVISO] Tus pecados fueron perdonados!", gObj->m_PK_Count);

    gObj->m_PK_Level = 3;
    gObj->m_PK_Count = 0;

    GCPkLevelSend (gObj->m_Index,3);
}