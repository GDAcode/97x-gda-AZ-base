#include "StdAfx.h"

PROTOCOLO  pProtocolo;

void Protocolo()
{ 
	ProtocoloConfigs();
	HookThis((DWORD)&ProtocolCore,0x00401D5C);
}

void ProtocoloConfigs()
{
   GetPrivateProfileStringA("ANUNCIOS","Usuarios","BIENVENIDO A MU AMINYUZ",pProtocolo.Bienvenida,200,Aminyuz_Servidor);
   GetPrivateProfileStringA("ANUNCIOS","Administradores"," %s: Online ",pProtocolo.GMAnuncio,200,Aminyuz_Servidor);
}

void ProtocolCore(BYTE protoNum, BYTE *aRecv, int aLen, int aIndex, BOOL Encrypt, int serial)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	switch(BYTE(protoNum))
	{
	    case 0x00:
			{
		        ChatDataSend(aIndex, aRecv);
			}
		    break;
		case 0x03:
			{
				CharacterLogin(aIndex);
			}
            break;
		case 0x1D: // Arma shadow bug bk
		   if(pSeguridad.IsArmaHacker != 0  )
	       {
			     if(ArmaHacker(aIndex) == TRUE)
				 {
					  return;
				 }
	       }
		case 0x30: // Click NPC
			{
				if(NPCTalkEx(lpObj,(aRecv[4] + aRecv[3] * 256)))
				{
					return;
				}
				break;
			}
		case 0x31: // Baul
		   {
		       if(pSeguridad.IsWarehouseHacker != 0  )
	           {
			       if(WarehouseHacker(aIndex) == TRUE)
				   {
					    return;
				   }
	           }
		   }
		   break;
		case 0x37: // Trade
		   {
		       if(pSeguridad.IsTradeHacker != 0  )
	           {
			       if(TradeHacker(aIndex) == TRUE)
				   {
					    return;
				   }
	           }
		   }
		   break;
		case 0x55: // Guild
		   {
		       if(pSeguridad.IsPaquetesHacker  != 0  )
	           {
			       if(GuildMasterHacker(protoNum,aRecv,aLen,aIndex,Encrypt,serial) == TRUE)
				   {
					    return;
				   }
	           }
		   } 
		   break;
		case 0xF3:  // Personaje
		   {	 	

			   PMSG_DEFAULT2 * lpDef = (PMSG_DEFAULT2 *)aRecv;

			   switch ( lpDef->subcode )
			    {
			        case 0x01:
				    {
					if(pSeguridad.IsNickHacker != 0 )
					{
					if(CharacterCreate((PMSG_CHARCREATE *)aRecv, aIndex)== TRUE )
					{
						JGCharacterCreateFailSend(aIndex, lpObj->Name);
						return;
					}
				    }
					}
			    }
		   }
		   break;
		   case 0x87:  // CGChaosBoxUseEnd
		    {
		       if(pSeguridad.IsChaosBoxHacker != 0  )
	           {
			       if(ChaosBoxHacker(aIndex) == TRUE)
				   {
					    return;
				   }
	           }
		   } 
		   break;
	}
	DataRecv(protoNum,aRecv,aLen,aIndex,Encrypt,serial);
}

void CharacterLogin(int aIndex)
{
	 LPOBJ pObj = (LPOBJ)OBJECT_POINTER(aIndex);

	 int VipIndex = Manager.VipCount(pObj->AccountID);

	 //====================================================
	 //-- Check Player Map  
	 //====================================================
	 if(pObj->MapNumber == 17  || pObj->MapNumber > 25 )
	 {
	    gObjMoveGate(pObj->m_Index,17); 
	 }

	 //====================================================
	 // Anuncio de GameMaster
	 //====================================================
	 if(pObj->Authority > 1 )
     {
	     char GMAnuncio[220];
         sprintf_s(GMAnuncio,pProtocolo.GMAnuncio,pObj->Name);
         StringSendAll(GMAnuncio,0);
	 }

	 //====================================================
	 // Mensaje de Bienvenida 
	 //====================================================
	 if(pObj->Connected)
     {
		 char Bienvenida[200];
		 sprintf_s(Bienvenida,pProtocolo.Bienvenida);
		 GCServerMsgStringSend(Bienvenida,aIndex,0);
	 }
}