#include "StdAfx.h"

SEGURIDAD pSeguridad;

void Seguridad()
{
	SeguridadConfigs();
}

void SeguridadConfigs()
{
	pSeguridad.IsWarehouseHacker    = GetPrivateProfileIntA("SEGURIDAD","Vault",0,Aminyuz_Seguridad);
	pSeguridad.IsTradeHacker        = GetPrivateProfileIntA("SEGURIDAD","Trade",0,Aminyuz_Seguridad);
	pSeguridad.IsPaquetesHacker     = GetPrivateProfileIntA("SEGURIDAD","Paquetes",0,Aminyuz_Seguridad);
	pSeguridad.IsGuildMasterUnicode = GetPrivateProfileIntA("SEGURIDAD","Clan",0,Aminyuz_Seguridad);
	pSeguridad.IsNickHacker         = GetPrivateProfileIntA("SEGURIDAD","Nombre",0,Aminyuz_Seguridad);
	pSeguridad.IsChaosBoxHacker     = GetPrivateProfileIntA("SEGURIDAD","ChaosBox",0,Aminyuz_Seguridad);
	pSeguridad.IsArmaHacker			= GetPrivateProfileIntA("SEGURIDAD","Arma",0,Aminyuz_Seguridad);
}
// ----------------------------------------------------------------------------------------------
//	# SEGURIDAD CONTRA TRAMPAS EN EL BAUL
// ----------------------------------------------------------------------------------------------
bool WarehouseHacker(int aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if(lpObj->WarehouseSave >= 1 )
    {
	   LogAddFuncColor(COLOR_RED,"[SEGURIDAD][%s][%s] Fuistes desconectado por usar Hacker!",lpObj->AccountID,lpObj->Name);
	   CGWarehouseUseEnd(aIndex);
	   return TRUE;
    }
	   return FALSE;
}
// ----------------------------------------------------------------------------------------------
//	# SEGURIDAD CONTRA TRAMPAS EN TRADES
// ----------------------------------------------------------------------------------------------
bool TradeHacker(int aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	
	if(lpObj->pTransaction == 1 )
    {
		LogAddFuncColor(COLOR_RED,"[SEGURIDAD][%s][%s] Fuistes desconectado por usar Hacker!",lpObj->AccountID,lpObj->Name);
		CloseClient(aIndex);
		return TRUE;
    }
	return FALSE;
}      
// ----------------------------------------------------------------------------------------------
//	# SEGURIDAD CONTRA TRAMPAS DE GUILD MASTER
// ----------------------------------------------------------------------------------------------
bool GuildMasterHacker(BYTE protoNum,LPBYTE aRecv,DWORD aLen,DWORD aIndex,DWORD Encrypt,int Serial)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	if((lpObj->m_IfState.use == 0) || (lpObj->m_IfState.use == 1 && lpObj->m_IfState.type == 3) || (lpObj->m_IfState.use == 0 && lpObj->m_IfState.type == 15))  
	   {
		   LogAddFuncColor(COLOR_RED,"[SEGURIDAD][%s][%s] Fuistes desconectado por usar Hacker!",lpObj->AccountID,lpObj->Name);
		   CloseClient(aIndex);
		   return TRUE;
	   }
	
	if(pSeguridad.IsGuildMasterUnicode  != 0 )
	{
		if(!DecodeProtocol(aIndex,(char*)aRecv+3))
		{
			LogAddFuncColor(COLOR_RED,"[SEGURIDAD][%s][%s] Fuistes desconectado por usar Hacker!",lpObj->AccountID,lpObj->Name);
			CloseClient(aIndex);
			return TRUE;
		}
	}
	return FALSE;
}
// ----------------------------------------------------------------------------------------------
//	# SEGURIDAD CONTRA NOMBRES MALICIOSOS AL CREAR EL PERSONAJE
// ----------------------------------------------------------------------------------------------
bool CharacterCreate(PMSG_CHARCREATE* lpMsg, int aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	bool bResult = false;

	for(int i = 0; i < sizeof(lpMsg->Name); i++)
	{
		if(!isalnum(lpMsg->Name[i]) && lpMsg->Name[i] != ' ' && lpMsg->Name[i] != NULL && lpMsg->Name[i] != '-' && lpMsg->Name[i] != '_')
		{
			LogAddFuncColor(COLOR_RED,"[SEGURIDAD][%s]Intentastes Nick Hacker [%s]",lpObj->AccountID,lpMsg->Name);
			bResult = true;
		}
	}
	return bResult;
}
// ----------------------------------------------------------------------------------------------
//	# SEGURIDAD CONTRA TRAMPAS DE LA MAQUINA CHAOS
// ----------------------------------------------------------------------------------------------
bool ChaosBoxHacker(int aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	
	if(lpObj->m_IfState.use != 1 && lpObj->m_IfState.type != 7 )
	{
		LogAddFuncColor(COLOR_RED,"[SEGURIDAD][%s][%s] Desconectado por usar Chaos machine Hacker !",lpObj->AccountID,lpObj->Name);
		CloseClient(aIndex);
		return TRUE;
	  }
	  return FALSE;

}
// ----------------------------------------------------------------------------------------------
//	# SEGURIDAD CONTRA BUG DE PETS
// ----------------------------------------------------------------------------------------------
bool ArmaHacker(int aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	
	if(lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT].m_Type == SLOT_EMPTY)
	{
		if(lpObj->Class == CLASS_KNIGHT )
		{
			GCItemListSend(aIndex);  
			gObjMakePreviewCharSet(aIndex);
			LogAddFuncColor(COLOR_RED,"[SEGURIDAD][%s][%s] Intentastes Arma Shadow Hacker!",lpObj->AccountID,lpObj->Name);
			CloseClient(aIndex);
			return TRUE;
		}
	}
	return FALSE;
}