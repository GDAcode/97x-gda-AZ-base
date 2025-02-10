#include "StdAfx.h"

ZENWARDEN pZenWarden;

void LoadZenWarden()
{
	pZenWarden.ZenWardenSwitch   = GetPrivateProfileIntA("ZenWarden", "Switch", 0, Aminyuz_ZenWarden);
	pZenWarden.ZenWardenID	     = GetPrivateProfileIntA("ZenWarden", "ID", 222, Aminyuz_ZenWarden);
}

void ZenWardenClick(LPOBJ gObj, LPOBJ gObjNPC, int aIndex)
{
	if(pZenWarden.ZenWardenSwitch != 0)
	{
		ZenWarden(gObj, gObjNPC,aIndex);
	}
	else
	{
		MsgOutput(aIndex,"No estoy de servico, vuelva mas tarde.");
	}
}

void ZenWarden(LPOBJ gObj, LPOBJ NpcObj, int aIndex)
{
	int Cofre500KK_ID			= ITEMGET(14,27);
	int Cofre1B_ID				= ITEMGET(14,28);
	int Cofre22_ID				= ITEMGET(14,29);

	int Cantidad = GetInventoryItemCount(aIndex, Cofre500KK_ID, 0);
	int Cantidad1 = GetInventoryItemCount(aIndex, Cofre1B_ID, 0);
	int Cantidad2 = GetInventoryItemCount(aIndex, Cofre22_ID, 0);

	if (Cantidad + Cantidad2 + Cantidad1 == 0)
    {
        GCServerMsgStringSend("[AVISO] Usted no tiene el cofres en el inventario.",aIndex,1);
        return;
    }

	long long numero = (5000000*Cantidad)*100.00;
	long long numero1 = (10000000*Cantidad1)*100.00;
	long long numero2 = (20000000*Cantidad2)*100.00;

	if(Cantidad > 0)
	{
		gObjDeleteItemsCount(aIndex,Cofre500KK_ID,0,Cantidad);
		Manager.ExecFormat("UPDATE MuOnline.dbo.MEMB_INFO SET banco = banco + (5000000*'%d')*(100.00) Where memb___id = '%s'",Cantidad,gObj->AccountID);
	}
	
	if(Cantidad1 > 0)
	{
		gObjDeleteItemsCount(aIndex,Cofre1B_ID,0,Cantidad1);
		Manager.ExecFormat("UPDATE MuOnline.dbo.MEMB_INFO SET banco = banco + (10000000*'%d')*(100.00) Where memb___id = '%s'",Cantidad1,gObj->AccountID);
	}

	if(Cantidad2 > 0)
	{
		gObjDeleteItemsCount(aIndex,Cofre22_ID,0,Cantidad2);
		Manager.ExecFormat("UPDATE MuOnline.dbo.MEMB_INFO SET banco = banco + (20000000*'%d')*(100.00) Where memb___id = '%s'",Cantidad2,gObj->AccountID);
	}
	MsgOutput(aIndex,"[AVISO] Depositastes %I64d en la web bank.",numero + numero1 + numero2);
}