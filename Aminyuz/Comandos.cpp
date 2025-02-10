#include "StdAfx.h"

COMANDOS  pComandos;

// ----------------------------------------------------------------------------------------------
//	# CHAT DATA SEND VERIFICAR PROTOCOLO
// ----------------------------------------------------------------------------------------------
void ChatDataSend(int aIndex, unsigned char* aRecv)
{
	if(_memicmp(&aRecv[13],pComandos.GlobalCMD,strlen(pComandos.GlobalCMD )) == 0)
	{
	    GlobalComando(aIndex,(char*)aRecv+13+strlen(pComandos.GlobalCMD));
	}
	if(_memicmp(&aRecv[13], pComandos.WebCMD, strlen(pComandos.WebCMD)) == 0)
	{
		WebComando(aIndex);
	}
	if(_memicmp(&aRecv[13],pComandos.HoraCMD,strlen(pComandos.HoraCMD)) == 0)
	{
	    HoraComando(aIndex);
	}
	if(_memicmp(&aRecv[13],pComandos.FuerzaCMD,strlen(pComandos.FuerzaCMD)) == 0)
	{
	    Puntos(aIndex,(char*)aRecv+13+strlen(pComandos.FuerzaCMD),0);
	}
	if(_memicmp(&aRecv[13],pComandos.AgilidadCMD,strlen(pComandos.AgilidadCMD)) == 0)
	{
	    Puntos(aIndex,(char*)aRecv+13+strlen(pComandos.AgilidadCMD),1);
	}
	if(_memicmp(&aRecv[13],pComandos.VitalidadCMD,strlen(pComandos.VitalidadCMD)) == 0)
	{
	    Puntos(aIndex,(char*)aRecv+13+strlen(pComandos.VitalidadCMD),2);
	}
	if(_memicmp(&aRecv[13],pComandos.EnergiaCMD,strlen(pComandos.EnergiaCMD)) == 0)
	{
	    Puntos(aIndex,(char*)aRecv+13+strlen(pComandos.EnergiaCMD),3);
	}
	if(_memicmp(&aRecv[13], pComandos.Asesinatos,strlen(pComandos.Asesinatos)) == 0)
	{
		AsesinatosComando(aIndex);
	}
	if(_memicmp(&aRecv[13], pComandos.ClearInvCMD,strlen(pComandos.ClearInvCMD)) == 0)
	{
		ClearInvComando(aIndex,(char*)aRecv+13+strlen(pComandos.ClearInvCMD));
	}
	if(_memicmp(&aRecv[13],pComandos.ReloadCMD,strlen(pComandos.ReloadCMD)) == 0) 
	{
	    ReloadComando(aIndex);  
	}
	if(_memicmp(&aRecv[13],pComandos.DropCMD,strlen(pComandos.DropCMD)) == 0)
	{
		DropCommand(aIndex,(char*)aRecv+13+strlen(pComandos.DropCMD));
	}
	if(_memicmp(&aRecv[13],pComandos.GGCMD,strlen(pComandos.GGCMD)) == 0) 
	{
		GGComando(aIndex,(char*)aRecv+13+strlen(pComandos.GGCMD));
	}
	if(_memicmp(&aRecv[13],pComandos.SkinCMD,strlen(pComandos.SkinCMD)) == 0)
	{
		SkinComando(aIndex,(char*)aRecv+13+strlen(pComandos.SkinCMD));
	}
	if(_memicmp(&aRecv[13], pComandos.OnlineCMD, strlen(pComandos.OnlineCMD)) == 0)
	{
	    OnlineComando(aIndex);
	}
	if(_memicmp(&aRecv[13], pComandos.MoveAllCMD, strlen(pComandos.MoveAllCMD)) == 0)
	{
		MoveAllComando(aIndex,(char*)aRecv+13+strlen(pComandos.MoveAllCMD));
	}
	if(_memicmp(&aRecv[13],pComandos.BlockCMD,strlen(pComandos.BlockCMD)) == 0)
	{
		BlockComando(aIndex,(char*)aRecv+13+strlen(pComandos.BlockCMD));
	}
	if(_memicmp(&aRecv[13],pComandos.UnBlockCMD,strlen(pComandos.UnBlockCMD)) == 0)
	{
		UnBlockComando(aIndex,(char*)aRecv+13+strlen(pComandos.UnBlockCMD));
	}
	if(_memicmp(&aRecv[13],pComandos.BanCMD,strlen(pComandos.BanCMD)) == 0)
	{
		BanComando(aIndex,(char*)aRecv+13+strlen(pComandos.BanCMD));
	}
	if(_memicmp(&aRecv[13],pComandos.UnBanCMD,strlen(pComandos.UnBanCMD)) == 0)
	{
		UnBanComando(aIndex,(char*)aRecv+13+strlen(pComandos.UnBanCMD));
	} 
	if(_memicmp(&aRecv[13],CReset.Settings.ResetSintax,strlen(CReset.Settings.ResetSintax)) == 0)
	{
		GReset::InitReset(aIndex);
	}

	Move.t_PlayerTeleport(aIndex,(char*)aRecv+14);
}

void Comandos()
{
	pComandos.GlobalSwitch			= GetPrivateProfileIntA ("GLOBAL","Switch"			,0			,Aminyuz_Comandos);
	pComandos.GlobalColor			= GetPrivateProfileIntA ("GLOBAL","Color"			,0			,Aminyuz_Comandos);
	pComandos.GlobalLevel			= GetPrivateProfileIntA ("GLOBAL","Level"			,50			,Aminyuz_Comandos);
	pComandos.GlobalZen				= GetPrivateProfileIntA ("GLOBAL","Zen"				,1000000	,Aminyuz_Comandos);
	pComandos.GlobalTiempoSwitch	= GetPrivateProfileIntA ("GLOBAL","TiempoSwitch"	,1			,Aminyuz_Comandos);
	pComandos.GlobalTiempo			= GetPrivateProfileIntA ("GLOBAL","Tiempo"			,10			,Aminyuz_Comandos);
	GetPrivateProfileStringA		("GLOBAL","Syntax","[GLOBAL]%s"		,pComandos.GlobalSyntax	,20	,Aminyuz_Comandos);
	GetPrivateProfileStringA		("GLOBAL","Comando","/Global"		,pComandos.GlobalCMD    ,8	,Aminyuz_Comandos);

	pComandos.WebSwitch				= GetPrivateProfileIntA ("WEB","Switch"				,0			,Aminyuz_Comandos);
    GetPrivateProfileStringA		("WEB","Link","www.aminyuzmu.com"	,pComandos.WebText		,200,Aminyuz_Comandos);
	GetPrivateProfileStringA		("WEB","Comando","/Web"				,pComandos.WebCMD		,20	,Aminyuz_Comandos);

	GetPrivateProfileStringA		("HORA","Comando","/Hora"			,pComandos.HoraCMD		,20	,Aminyuz_Comandos);

	pComandos.PuntosSwitch			= GetPrivateProfileIntA ("PUNTOS","Switch"			,0			,Aminyuz_Comandos);
	pComandos.PuntosLevel			= GetPrivateProfileIntA ("PUNTOS","Level"			,10			,Aminyuz_Comandos);
	pComandos.PuntosZen[0]			= GetPrivateProfileIntA ("PUNTOS","Zen [Gratuito]"	,1000000	,Aminyuz_Comandos);
	pComandos.PuntosZen[1]			= GetPrivateProfileIntA ("PUNTOS","Zen [Vip]"		,0			,Aminyuz_Comandos);
	pComandos.PuntosMaxFuerza		= GetPrivateProfileIntA ("PUNTOS","MaxFuerza"		,31500		,Aminyuz_Comandos);
	pComandos.PuntosMaxAgilidad		= GetPrivateProfileIntA ("PUNTOS","MaxAgilidad"		,31500		,Aminyuz_Comandos);
	pComandos.PuntosMaxVitalidad	= GetPrivateProfileIntA ("PUNTOS","MaxVitalidad"	,31500		,Aminyuz_Comandos);
	pComandos.PuntosMaxEnergia		= GetPrivateProfileIntA ("PUNTOS","MaxEnergia"		,31500		,Aminyuz_Comandos);
	GetPrivateProfileStringA		("PUNTOS","Fuerza","/Fuerza"		,pComandos.FuerzaCMD	,20	,Aminyuz_Comandos);
	GetPrivateProfileStringA		("PUNTOS","Agilidad","/Agilidad"	,pComandos.AgilidadCMD	,20	,Aminyuz_Comandos);
	GetPrivateProfileStringA		("PUNTOS","Vitalidad","/Vitalidad"	,pComandos.VitalidadCMD	,20	,Aminyuz_Comandos);
	GetPrivateProfileStringA		("PUNTOS","Energia","/Energia"		,pComandos.EnergiaCMD	,20	,Aminyuz_Comandos);

	pComandos.AsesinatosSwitch		= GetPrivateProfileIntA ("ASESINATOS","Switch"       ,0         ,Aminyuz_Comandos);
	GetPrivateProfileStringA        ("ASESINATOS","Comando","/Asesinatos", pComandos.Asesinatos ,20 ,Aminyuz_Comandos);

	pComandos.CInvSwitch			= GetPrivateProfileIntA ("CLEARINVENTORY","Switch"	 ,0          ,Aminyuz_Comandos);
    pComandos.CInvLevel				= GetPrivateProfileIntA ("CLEARINVENTORY","Level"    ,10         ,Aminyuz_Comandos);
	pComandos.CInvVip				= GetPrivateProfileIntA ("CLEARINVENTORY","Vip"      ,0          ,Aminyuz_Comandos);
	GetPrivateProfileStringA		("CLEARINVENTORY","Comando","/ClearInv",pComandos.ClearInvCMD,20,Aminyuz_Comandos);

	pComandos.ReloadSwitch			= GetPrivateProfileIntA ("RELOAD","Switch"			,0           ,Aminyuz_Comandos);
	pComandos.ReloadLevel			= GetPrivateProfileIntA ("RELOAD","Level"			,10          ,Aminyuz_Comandos);
	pComandos.ReloadZen				= GetPrivateProfileIntA ("RELOAD","Zen"				,1000000     ,Aminyuz_Comandos);
	pComandos.ReloadGM				= GetPrivateProfileIntA ("RELOAD","GM"				,0           ,Aminyuz_Comandos);
	pComandos.ReloadGMSystem		= GetPrivateProfileIntA ("RELOAD","GMAccess"		,0           ,Aminyuz_Comandos);
	GetPrivateProfileStringA		("RELOAD","Comando","/Reload"		,pComandos.ReloadCMD	,20	 ,Aminyuz_Comandos); 

	pComandos.DropSwitch         = GetPrivateProfileIntA ("DROP","Switch"  ,0           ,Aminyuz_Comandos);
	pComandos.DropNeedLevel      = GetPrivateProfileIntA ("DROP","Level"      ,10          ,Aminyuz_Comandos);
	pComandos.DropNeedZen        = GetPrivateProfileIntA ("DROP","Zen"        ,1000000     ,Aminyuz_Comandos);
	pComandos.DropEfect          = GetPrivateProfileIntA ("DROP","Efect"          ,1           ,Aminyuz_Comandos);
	pComandos.DropOnlyGM         = GetPrivateProfileIntA ("DROP","GM"         ,0           ,Aminyuz_Comandos);
	pComandos.DropGMSystem       = GetPrivateProfileIntA ("DROP","GMAccess"       ,0           ,Aminyuz_Comandos);
	GetPrivateProfileStringA                             ("DROP","Comando"        ,"/Drop"     ,pComandos.DropCMD,20,Aminyuz_Comandos);

	pComandos.GGSwitch			= GetPrivateProfileIntA ("GG","Switch"			,0           ,Aminyuz_Comandos);
	pComandos.GGLevel			= GetPrivateProfileIntA ("GG","Level"			,10          ,Aminyuz_Comandos);
	pComandos.GGZen				= GetPrivateProfileIntA ("GG","Zen"				,1000000     ,Aminyuz_Comandos);
	pComandos.GGGM				= GetPrivateProfileIntA ("GG","GM"				,0           ,Aminyuz_Comandos);
	pComandos.GGGMSystem		= GetPrivateProfileIntA ("GG","GMAccess"		,0           ,Aminyuz_Comandos);
	GetPrivateProfileStringA		("GG","Comando","/GG"		,pComandos.GGCMD	,20	 ,Aminyuz_Comandos); 

	pComandos.SkinSwitch		= GetPrivateProfileIntA ("SKIN","Switch"		,0           ,Aminyuz_Comandos);
	pComandos.SkinLevel			= GetPrivateProfileIntA ("SKIN","Level"			,10          ,Aminyuz_Comandos);
	pComandos.SkinZen			= GetPrivateProfileIntA ("SKIN","Zen"			,1000000     ,Aminyuz_Comandos);
	pComandos.SkinGM			= GetPrivateProfileIntA ("SKIN","GM"			,0           ,Aminyuz_Comandos);
	pComandos.SkinGMSystem		= GetPrivateProfileIntA ("SKIN","GMAccess"		,0           ,Aminyuz_Comandos);
	GetPrivateProfileStringA                            ("SKIN","Comando"		,"/Skin"     ,pComandos.SkinCMD,20,Aminyuz_Comandos);

	pComandos.OnlineSwitch		= GetPrivateProfileIntA ("ONLINE","Switch"		,0           ,Aminyuz_Comandos);
	pComandos.OnlineGM			= GetPrivateProfileIntA ("ONLINE","GM"			,0           ,Aminyuz_Comandos);
	pComandos.OnlineGMAcceso	= GetPrivateProfileIntA ("ONLINE","GMAcceso"	,0           ,Aminyuz_Comandos);
	GetPrivateProfileStringA                            ("ONLINE","Comando"		,"/Online"     ,pComandos.OnlineCMD,20,Aminyuz_Comandos);

	pComandos.MoveAllSwitch		= GetPrivateProfileIntA ("MOVEALL","Switch"		,0           ,Aminyuz_Comandos);
	pComandos.MoveAllGM			= GetPrivateProfileIntA ("MOVEALL","GM"			,0           ,Aminyuz_Comandos);
	pComandos.MoveAllGMAcceso	= GetPrivateProfileIntA ("MOVEALL","GMAcceso"	,0           ,Aminyuz_Comandos);
	GetPrivateProfileStringA                            ("MOVEALL","Comando"	,"/MoveAll"  ,pComandos.MoveAllCMD,20,Aminyuz_Comandos); 

	pComandos.BlockSwitch        = GetPrivateProfileIntA ("BLOCK","Switch"      ,0           ,Aminyuz_Comandos);
	pComandos.BlockGM			 = GetPrivateProfileIntA ("BLOCK","GM"          ,0           ,Aminyuz_Comandos);
	pComandos.BlockGMAcceso      = GetPrivateProfileIntA ("BLOCK","GMAcceso"    ,0           ,Aminyuz_Comandos);
    GetPrivateProfileStringA                             ("BLOCK","Comando"     ,"/Block"    ,pComandos.BlockCMD,20,Aminyuz_Comandos);

	pComandos.UnBlockSwitch      = GetPrivateProfileIntA ("UNBLOCK","Switch"    ,0           ,Aminyuz_Comandos);
	pComandos.UnBlockGM			 = GetPrivateProfileIntA ("UNBLOCK","GM"        ,0           ,Aminyuz_Comandos);
	pComandos.UnBlockGMAcceso    = GetPrivateProfileIntA ("UNBLOCK","GMAcceso"  ,0           ,Aminyuz_Comandos);
	GetPrivateProfileStringA                             ("UNBLOCK","Comando"   ,"/UnBlock"  ,pComandos.UnBlockCMD,20,Aminyuz_Comandos);
	
	pComandos.BanSwitch          = GetPrivateProfileIntA ("BAN","Switch"        ,0           ,Aminyuz_Comandos);
	pComandos.BanGM				 = GetPrivateProfileIntA ("BAN","GM"            ,0           ,Aminyuz_Comandos);
	pComandos.BanGMAcceso        = GetPrivateProfileIntA ("BAN","GMAcceso"      ,0           ,Aminyuz_Comandos);
	GetPrivateProfileStringA                             ("BAN","Comando"       ,"/Ban"      ,pComandos.BanCMD,20,Aminyuz_Comandos);
	
	pComandos.UnBanSwitch        = GetPrivateProfileIntA ("UNBAN","Switch"       ,0          ,Aminyuz_Comandos);
	pComandos.UnBanGM			 = GetPrivateProfileIntA ("UNBAN","GM"           ,0          ,Aminyuz_Comandos);
	pComandos.UnBanGMAcceso      = GetPrivateProfileIntA ("UNBAN","GMAcceso"     ,0          ,Aminyuz_Comandos);
	GetPrivateProfileStringA                             ("UNBAN","Comando"      ,"/UnBan"   ,pComandos.UnBanCMD,20,Aminyuz_Comandos);

	GetPrivateProfileStringA		("RESET","Comando","/Reset"	,CReset.Settings.ResetSintax	,50	 ,Aminyuz_Reset);
}

// ----------------------------------------------------------------------------------------------
//	# COMANDO GLOBAL
// ----------------------------------------------------------------------------------------------
void GlobalComando(DWORD aIndex,char*msg)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if (!strcmpi("/Global",msg))
	{
		GCServerMsgStringSend("Sintaxis:/Global <mensaje>",aIndex,1);
		return;
	}

	if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("Sintaxis:/Global <mensaje>",aIndex,1);
		return;
	}

	if (pComandos.GlobalSwitch <= 0)
	{
		MsgOutput(aIndex,"[AVISO] Comando desactivado!");		
		return;
	}

	if (pComandos.GlobalTiempoSwitch != 0)
	{
		unsigned long  Delay = (GetTickCount()- epObj[aIndex].m_PostDelay)/1000;

		if (Delay < pComandos.GlobalTiempo)
		{
			MsgOutput(aIndex,"[AVISO] Espera %d segundos para postear nuevamente!",(pComandos.GlobalTiempo - Delay),aIndex);
			return;
		}
		epObj[aIndex].m_PostDelay = GetTickCount();
	}

	if (lpObj->Level < pComandos.GlobalLevel)
	{
		MsgOutput(aIndex,"[AVISO] No tenes el nivel suficiente! Requerido: %d",pComandos.GlobalLevel);				
		return;
	}

	if (lpObj->Money < pComandos.GlobalZen)
	{
		MsgOutput(aIndex,"[AVISO] No tenes el zen suficiente! Requerido: %d",pComandos.GlobalZen);				
		return;
	}
	GCMoneySend(aIndex,lpObj->Money -= pComandos.GlobalZen);

	char Text[220];
	sprintf(Text,pComandos.GlobalSyntax,msg);

	switch (pComandos.GlobalColor)
	{  
		//-----------------------------------
		// # COLOR AMARILLO
		//-----------------------------------
	case 0:
		{
			for(int i=OBJECT_MIN;i<OBJECT_MAX;i++)
			{
				BYTE Buffer[0xFF] = {0};
				BYTE Len=strlen(Text);
				Buffer[0]=0xC1;
				Buffer[1]=Len+14;
				Buffer[2]=0x02;
				strncpy((char*)&Buffer[3],lpObj->Name,10);
				strncpy((char*)&Buffer[13],Text,Len);
				DataSend(i,(unsigned char*)Buffer,Buffer[1]);
			}
		}
		break;
		//-----------------------------------
		// # COLOR AZUL
		//-----------------------------------
	case 1:
		{
			for(int i=OBJECT_MIN;i<OBJECT_MAX;i++)
			{
				BYTE Buffer[0xFF] = {0};
				BYTE Len=strlen(Text);
				Buffer[0]=0xC1;
				Buffer[1]=Len+15;
				Buffer[2]=0x00;
				strncpy((char*)&Buffer[3],lpObj->Name,10);
				Buffer[13]=0x7E;
				strncpy((char*)&Buffer[14],Text,Len);
				DataSend(i,(unsigned char*)Buffer,Buffer[1]);
			}
		}
		break;
		//-----------------------------------
		// # COLOR VERDE
		//-----------------------------------
	case 2:
		{
			for(int i=OBJECT_MIN;i<OBJECT_MAX;i++)
			{
				BYTE Buffer[0xFF] = {0};
				BYTE Len=strlen(Text);
				Buffer[0]=0xC1;
				Buffer[1]=Len+15;
				Buffer[2]=0x00;
				strncpy((char*)&Buffer[3],lpObj->Name,10);
				Buffer[13]=0x40;
				strncpy((char*)&Buffer[14],Text,Len);
				DataSend(i,(unsigned char*)Buffer,Buffer[1]);
			}
		}
		break; 
	}
}
// ----------------------------------------------------------------------------------------------
//	# COMANDO WEB
// ----------------------------------------------------------------------------------------------
void WebComando(int aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if(pComandos.WebSwitch == 0)
	{
		MsgOutput(aIndex,"[AVISO] Comando desactivado!");
		return;
	}
	GCServerMsgStringSend(pComandos.WebText, aIndex, 1);	
}
// ----------------------------------------------------------------------------------------------
//	# COMANDO HORA
// ----------------------------------------------------------------------------------------------
void HoraComando(int aIndex)
{
	 OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

     time_t tim=time(NULL);
     tm *now=localtime(&tim);

     char dateStr [11];
     char timeStr [9];
     char WeekStr [30];

     sprintf_s(dateStr, "%02d/%02d/%04d", now->tm_mday, now->tm_mon+1, now->tm_year+1900);
     sprintf_s(timeStr, "%02d:%02d", now->tm_hour, now->tm_min);

     int iDWeek = now->tm_wday;

     if(iDWeek == 0) 
	 {
		 sprintf(WeekStr, "Domingo");
     } 
	 else if(iDWeek == 1) 
	 {
		 sprintf(WeekStr, "Lunes");
     } 
	 else if(iDWeek == 2) 
	 {
		 sprintf(WeekStr, "Martes");
     } 
	 else if(iDWeek == 3) 
	 {
		 sprintf(WeekStr, "Miercoles");
     } 
	 else if(iDWeek == 4) 
	 {
		 sprintf(WeekStr, "Jueves");
     } 
	 else if(iDWeek == 5) 
	 {
		 sprintf(WeekStr, "Viernes");
     }
	 else if(iDWeek == 6) 
	 {
		 sprintf(WeekStr, "Sábado");
     }
    char OutputSuccess[200];
    sprintf_s(OutputSuccess, "La hora es %s - %s, %s!", timeStr, dateStr, WeekStr); 
    GCServerMsgStringSend(OutputSuccess, aIndex,0);
}
// ----------------------------------------------------------------------------------------------
//	# COMANDO PUNTOS
// ----------------------------------------------------------------------------------------------
void Puntos(int aIndex, LPCSTR IpBuffer, BYTE Type)
{
	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	int VipIndex = Manager.VipCount(lpObj->AccountID);
	int Points = atoi(IpBuffer);

	if( pComandos.PuntosSwitch <= 0 )
	{
		MsgOutput(aIndex,"[AVISO] Comando desactivado!");
		return;
	}

	if(Points <= 0 || IpBuffer[0] != ' ' )
	{
	    LogAddFuncColor(COLOR_RED,"[Anti-Hacker][%s][%s] Uso incorrecto del comando puntos!",lpObj->AccountID,lpObj->Name);
		return;
	}

	//-----------------------------------
	// # FIX ADD POINTS
	//-----------------------------------
	if( lpObj->DieRegen      != 0  || 
	    lpObj->pTransaction  != 0  || 
		lpObj->WarehouseSave != 0  ||
		lpObj->m_IfState.use == 1 && lpObj->m_IfState.type == 7 )
	{
		MsgOutput(aIndex,"[AVISO] Cierre el Baul,Trade o Npc para usar el comando!");		
		LogAddFuncColor(COLOR_RED,"[Anti-Hacker][%s][%s]Intento bugear el comando puntos!",lpObj->AccountID,lpObj->Name);
		return;
	}

	if( lpObj->Level < pComandos.PuntosLevel )
	{
		MsgOutput(aIndex,"[AVISO] No tenes el nivel suficiente! Requerido: %d",pComandos.PuntosLevel);
		return;
	}
	if( lpObj->Money < pComandos.PuntosZen[VipIndex] )
	{
		MsgOutput(aIndex,"[AVISO] No tenes el zen suficiente! Requerido: %d",pComandos.PuntosZen[VipIndex]);
		return;
	}
    if(lpObj->LevelUpPoints < Points)
    {
		MsgOutput(aIndex,"[AVISO] No tenes puntos suficientes! Requeridos: %d",Points);
		return;
	}

	if(Type == 0) 
    {
		if( Points + lpObj->Strength > pComandos.PuntosMaxFuerza || lpObj->Strength >= pComandos.PuntosMaxFuerza)
		{
			MsgOutput(aIndex,"[AVISO] No podes sobrepasar %d puntos en Fuerza ",pComandos.PuntosMaxFuerza );
			return;
		}
		lpObj->LevelUpPoints -= Points;
		lpObj->Strength += Points;
		MsgOutput(aIndex,"[AVISO] Reconectate para ver tus puntos!");
	}

	if(Type == 1) 
    {
		if( Points + lpObj->Dexterity > pComandos.PuntosMaxAgilidad || lpObj->Dexterity >= pComandos.PuntosMaxAgilidad)
		{
			MsgOutput(aIndex,"[AVISO] No podes sobrepasar %d puntos en Agilidad ",pComandos.PuntosMaxAgilidad);
			return;
		}
		lpObj->LevelUpPoints -= Points;
		lpObj->Dexterity += Points;
		MsgOutput(aIndex,"[AVISO] Reconectate para ver tus puntos!");
	}

	if(Type == 2) 
    {
		if( Points + lpObj->Vitality > pComandos.PuntosMaxVitalidad || lpObj->Vitality >= pComandos.PuntosMaxVitalidad)
		{
			MsgOutput(aIndex,"[AVISO] No podes sobrepasar %d puntos en Vitalidad ",pComandos.PuntosMaxVitalidad);
			return;
		}
		lpObj->LevelUpPoints -= Points;
		lpObj->Vitality += Points;
		lpObj->MaxLife += lpObj->VitalityToLife * Points;
		MsgOutput(aIndex,"[AVISO] Reconectate para ver tus puntos!");
	}
	
	if(Type == 3) 
    {
		if( Points + lpObj->Energy > pComandos.PuntosMaxEnergia || lpObj->Energy >= pComandos.PuntosMaxEnergia)
		{
			MsgOutput(aIndex,"[AVISO] No podes sobrepasar %d puntos en Energia ",pComandos.PuntosMaxEnergia);
			return;
		}
		lpObj->LevelUpPoints -= Points;
		lpObj->Energy += Points;
		lpObj->MaxMana += lpObj->EnergyToMana * Points;
		MsgOutput(aIndex,"[AVISO] Reconectate para ver tus puntos!");
	}
    GCMoneySend(aIndex,lpObj->Money -= pComandos.PuntosZen[VipIndex]);

	//-- Balance Status 
    gObjCalCharacterEX(lpObj->m_Index);
	GCReFillSend(lpObj->m_Index,(WORD)lpObj->MaxLife + lpObj->AddLife,0xFE,0);  
	gObjSetBP(aIndex);
	GCManaSend(lpObj->m_Index,(short)lpObj->MaxMana + lpObj->AddMana,0xFE,0,lpObj->MaxBP + lpObj->AddBP);
}
// ----------------------------------------------------------------------------------------------
//	# COMANDO ASESINATOS
// ----------------------------------------------------------------------------------------------
void AsesinatosComando(int aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if(pComandos.AsesinatosSwitch == 0)
	{
		MsgOutput(aIndex,"[AVISO] Comando desactivado!");
		return;
	}
	MsgOutput(aIndex,"[AVISO] Tienes %d asesinatos", lpObj->m_PK_Count);	
}
// ----------------------------------------------------------------------------------------------
//	# COMANDO LIMPIAR INVENTARIO
// ----------------------------------------------------------------------------------------------
void ClearInvComando(int aIndex,LPCSTR IpBuffer)
{
	int VipIndex = Manager.VipCount(gObj->AccountID);
    int ClrInvCode = atoi(IpBuffer);
    
	if(ClrInvCode > 2 && ClrInvCode < 0)
	{
		GCServerMsgStringSend("El Sistema va desde el nº 0 hasta el 2.              ",aIndex,1);
		GCServerMsgStringSend("nº 1 Limpia la parte de abajo del inventário.",aIndex,1);
		GCServerMsgStringSend("nº 2 Limpia el zen del inventário.             ",aIndex,1);
		return;
	}

	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if(pComandos.CInvSwitch <= 0)
    {
		MsgOutput(aIndex,"[AVISO] Comando desactivado!");
		return;
    }
    if( gObj->Level < pComandos.CInvLevel )
	{
		MsgOutput(aIndex,"[AVISO] No tenes el nivel suficiente! Requerido: %d",pComandos.CInvLevel);
		return;
	}
	if(VipIndex < pComandos.CInvVip)
	{
		GCServerMsgStringSend("[AVISO] Comando solo para usuarios Vip!",aIndex,1);
		return;
	}

    switch(ClrInvCode)
	    {
	    //==============================================================
	    //-- Borrar parte de abajo del inventario
	    //==============================================================
		case 1:
		{
			for (int i=12; i<76; i++)
			{
				gObjInventoryDeleteItem(aIndex, i);
				GCInventoryItemDeleteSend(aIndex, i, 1);
			}
			GCServerMsgStringSend("Ha borrado la parte inferior del inventario",aIndex,1);
			return;
		}
		break;
		//==============================================================
	    //-- Limpia todo el zen del inventario
	    //==============================================================
        case 2:
		gObj->Money = 0;
        GCMoneySend(aIndex,gObj->Money);
		GCServerMsgStringSend("Usted ha borrado todo el Zen",aIndex,1);
        break;
        }
}
// ----------------------------------------------------------------------------------------------
//	# COMANDO RELOAD
// ----------------------------------------------------------------------------------------------
void ReloadComando(int aIndex)       
{		
	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if( pComandos.ReloadSwitch <= 0 )
	{
	MsgOutput(aIndex,"[AVISO] Comando desactivado!");		
	return;
	}
	if( lpObj->Level < pComandos.ReloadLevel )
	{
	MsgOutput(aIndex,"[AVISO] No tenes el nivel suficiente! Requerido: %d",pComandos.ReloadLevel);				
    return;
	}
	if( lpObj->Money < pComandos.ReloadZen )
	{
	MsgOutput(aIndex,"[AVISO] No tenes el zen suficiente! Requerido: %d",pComandos.ReloadZen);				
	return;
	}
	if(lpObj->Authority < 2  && pComandos.ReloadGM != 0 )
	{
	GCServerMsgStringSend("[AVISO] Comando solo para GameMasters!" ,aIndex,1);
	return;
	}   
	
	//-----------------------------------
	// # GM SYSTEM
	//-----------------------------------
	if(pComandos.ReloadGMSystem != 0)
	{
	int CanReload = 0;
	for(int x=1;x < GMSystemCount;x++)
	{
	if(!strcmp(GMSystemInfo[x].Name,lpObj->Name))
	{
	CanReload = GMSystemInfo[x].GMReload;
	}
	}
	if(CanReload == 0)
	{
	GCServerMsgStringSend("Este [GM] No puede usar el comando!",aIndex,1);
	return;
	}
	}  
    GCMoneySend(aIndex,lpObj->Money -= pComandos.ReloadZen );

	ReadyAll();
    GCServerMsgStringSend("[AVISO] Reiniciastes las configuraciones!",aIndex,1);
}
//===============================================================================================
//-- Drop Command
//===============================================================================================
void DropCommand(int aIndex ,char*msg)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	unsigned char spaces = 0;

	if( pComandos.DropSwitch <= 0 )
	{
	MsgOutput(aIndex,"[AVISO] Comando desactivado!");
	return;
	}
	for(int i=0; i< strlen(msg);i++)
	{
	if(msg[i]==' ')
	spaces++;
	}
	if(spaces > 10)
	{
		GCServerMsgStringSend("El comando no puede contener mas de 9 espacios!",aIndex,1);
		return;
	}
	if(strlen(msg) == 1)
	{
		MsgOutput(aIndex,"Modo: <SEC><TYP><LVL><DUR><LUK><SKL><OPT><EXC><CANTIDAD>");
		return;
	} 
	if( lpObj->Level < pComandos.DropNeedLevel )
	{
	MsgOutput(aIndex,"[AVISO] No tenes el nivel suficiente! Requerido: %d",pComandos.DropNeedLevel);				
    return;
	}
	if( lpObj->Money < pComandos.DropNeedZen )
	{
	MsgOutput(aIndex,"[AVISO] No tenes el zen suficiente! Requerido: %d",pComandos.DropNeedZen);				
	return;
	}
	if(lpObj->Authority < 2  && pComandos.DropOnlyGM != 0 )
	{
    GCServerMsgStringSend("[AVISO] Comando solo para GameMasters!" ,aIndex,1);
	return;
	}   

	//=====================================================
	// -- GM Systgem :)
	//=====================================================
	if(pComandos.DropGMSystem != 0)
	{
	int CanDrop = 0;
	for(int x=1;x < GMSystemCount;x++)
	{
	if(!strcmp(GMSystemInfo[x].Name,lpObj->Name))
	{
	CanDrop = GMSystemInfo[x].GMDrop;
	}
	}
	if(CanDrop == 0)
	{
	GCServerMsgStringSend("Este [GM] No puede usar el comando!",aIndex,1);
	return;
	}
	}  

    GCMoneySend(aIndex,lpObj->Money -= pComandos.DropNeedZen);

    int ItemType,ItemNr,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,ItemExc,DropQuantity;
	sscanf(msg,"%d %d %d %d %d %d %d %d %d ",&ItemType,&ItemNr,&ItemLevel,&ItemDur,&ItemSkill,&ItemLuck,&ItemOpt,&ItemExc,&DropQuantity);
	LogAddFuncColor(COLOR_BLUE,"[Drop.Items]:[%s][%s] Created Item - [%d][%d][%d][%d][%d][%d][%d][%d][%d][%d].",lpObj->AccountID,lpObj->Name,ItemType,ItemNr,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,ItemExc,DropQuantity); 

	if(DropQuantity > 10)
	{
		DropQuantity = 10;
	}
	for(int x = 0; x < DropQuantity; x++)
	{
		int Item = ItemType*32+ItemNr;
		ItemSerialCreateSendEx(aIndex,lpObj->MapNumber,lpObj->X,lpObj->Y,Item,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,aIndex,ItemExc);
	}
	
	GCServerMsgStringSend("[AVISO] Item creado con exito!",aIndex,1);
}
// ----------------------------------------------------------------------------------------------
//	# COMANDO GG
// ----------------------------------------------------------------------------------------------
void GGComando(int aIndex,char*msg)       
{		
	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if( pComandos.GGSwitch <= 0 )
	{
		MsgOutput(aIndex,"[AVISO] Comando desactivado!");
		return;
	}
	if( lpObj->Level < pComandos.GGLevel )
	{
		MsgOutput(aIndex,"[AVISO] No tenes el nivel suficiente! Requerido: %d",pComandos.GGLevel);
		return;
	}
	if( lpObj->Money < pComandos.GGZen )
	{
		MsgOutput(aIndex,"[AVISO] No tenes el zen suficiente! Requerido: %d",pComandos.GGZen);
		return;
	}
	if(lpObj->Authority < 2  && pComandos.GGGM != 0 )
	{
		GCServerMsgStringSend("[AVISO] Comando solo para GameMasters!" ,aIndex,1);
		return;
	}   
	
	//-----------------------------------
	// # GM SYSTEM
	//-----------------------------------
	if(pComandos.GGGMSystem != 0)
	{
		int CanGG = 0;
		for(int x=1;x < GMSystemCount;x++)
		{
			if(!strcmp(GMSystemInfo[x].Name,lpObj->Name))
			{
				CanGG = GMSystemInfo[x].GMGG;
			}
		}
		if(CanGG == 0)
		{
			GCServerMsgStringSend("Este [GM] No puede usar el comando!",aIndex,1);
			return;
		}
	}
	GCMoneySend(aIndex,lpObj->Money -= pComandos.GGZen );

	char GMensaje[255];
	sprintf_s(GMensaje,"%s: %s",lpObj->Name,msg);
	StringSendAll(GMensaje,0);
}
// ----------------------------------------------------------------------------------------------
//	# COMANDO SKIN
// ----------------------------------------------------------------------------------------------
void SkinComando(int aIndex, char* msg)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	int skin = atoi(msg);

	if( pComandos.SkinSwitch <= 0 )
	{
		MsgOutput(aIndex,"[AVISO] Comando desactivado!");
		return;
	}
	if( lpObj->Level < pComandos.SkinLevel )
	{
		MsgOutput(aIndex,"[AVISO] No tenes el nivel suficiente! Requerido: %d",pComandos.SkinLevel);
		return;
	}
	if( lpObj->Money < pComandos.SkinZen )
	{
		MsgOutput(aIndex,"[AVISO] No tenes el zen suficiente! Requerido: %d",pComandos.SkinZen);
		return;
	}

	if( skin == 34  || skin == 55 || skin == 56 ||skin == 68 || skin == 100 || skin == 101 || 
	    skin == 103 || skin == 239 )
	{
		GCServerMsgStringSend("[AVISO] Transformación Prohibida!",aIndex,1);
		return;
	} 

	if(lpObj->Authority < 2  && pComandos.SkinGM != 0 )
	{
		GCServerMsgStringSend("[AVISO] Comando solo para GameMasters!" ,aIndex,1);
		return;
	}   

	//-----------------------------------
	// # GM SYSTEM
	//-----------------------------------
	if(pComandos.SkinGMSystem != 0)
	{
		int CanSkin = 0;
		for(int x=1;x < GMSystemCount;x++)
		{
			if(!strcmp(GMSystemInfo[x].Name,lpObj->Name))
			{
				CanSkin = GMSystemInfo[x].GMSkin;
			}
		}
		if(CanSkin == 0)
		{
			GCServerMsgStringSend("Este [GM] No puede usar el comando!",aIndex,1);
			return;
		}
	}

    GCMoneySend(aIndex,lpObj->Money -= pComandos.SkinZen);

	lpObj->m_Change = skin;
	gObjViewportListProtocolCreate(lpObj);
    GCServerMsgStringSend("Usted se transformo en un mounstro!",aIndex,1);
}
// ----------------------------------------------------------------------------------------------
//	# COMANDO ONLINE
// ----------------------------------------------------------------------------------------------
void OnlineComando(int aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if(pComandos.OnlineSwitch == 0)
	{
		MsgOutput(aIndex,"[AVISO] Comando desactivado!");
		return;
	}

	if(lpObj->Authority < 2  && pComandos.OnlineGMAcceso != 0 )
	{
		GCServerMsgStringSend("[AVISO] Comando solo para GameMasters!" ,aIndex,1);
		return;
	} 

	//-----------------------------------
	// # SISTEMA DE GAMEMASTERS
	//-----------------------------------
	if(pComandos.OnlineGM != 0)
	{
		int CanOnline = 0;
		for(int x=1;x < GMSystemCount;x++)
		{
			if(!strcmp(GMSystemInfo[x].Name,lpObj->Name))
			{
				CanOnline = GMSystemInfo[x].GMOnline;
			}
		}
		if(CanOnline == 0)
		{
			GCServerMsgStringSend("Este [GM] No puede usar el comando!",aIndex,1);
			return;
		}
	}

    int GMs      = GetGMCount();
    int Players  = GetPlayerCount() - GMs;
    int Geral    = Players + GMs;
    char msg[200];
    sprintf_s(msg, "Usuarios = %d | Administradores = %d  | Total = %d ", Players, GMs, Geral); 
    GCServerMsgStringSend(msg, aIndex, 1);
}
// ----------------------------------------------------------------------------------------------
//	# COMANDO MOVE ALL
// ----------------------------------------------------------------------------------------------
void MoveAllComando(int aIndex,char* msg)
{
    OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	
	if( pComandos.MoveAllSwitch <= 0 )
	{
		MsgOutput(aIndex,"[AVISO] Comando desactivado!");
		return;
	}
	if(lpObj->Authority < 2  && pComandos.MoveAllGMAcceso != 0 )
	{
		GCServerMsgStringSend("[AVISO] Comando solo para GameMasters!" ,aIndex,1);
		return;
	}

	//=====================================================
	// -- GM System :)
	//=====================================================
	if(pComandos.MoveAllGM != 0)
	{
		int CanMoveAll = 0;
		for(int x=1;x < GMSystemCount;x++)
		{
			if(!strcmp(GMSystemInfo[x].Name,lpObj->Name))
			{
				CanMoveAll = GMSystemInfo[x].GMMoveAll;
			}
		}
		if(CanMoveAll == 0)
		{
			GCServerMsgStringSend("Este [GM] No puede usar el comando!",aIndex,1);
			return;
		}
	}

    int TargetMap, TargetX, TargetY = 0;
    sscanf((char*)msg,"%d %d %d",&TargetMap, &TargetX, &TargetY);

    for(int i=OBJECT_MIN;i<OBJECT_MAX;i++)
    {
       gObjTeleport(i,TargetMap,TargetX,TargetY);
    }

	MsgOutput(aIndex,"[AVISO] Todos los personajes fueron movidos con exito!");
	LogAddFuncColor(COLOR_RED,"[GM-LOG][%s][%s] Movio a todos los personajes.",lpObj->AccountID,lpObj->Name);
}
// ----------------------------------------------------------------------------------------------
//	# COMANDO BLOQUEAR JUGADOR
// ----------------------------------------------------------------------------------------------
void BlockComando(int aIndex, char* Msg)  
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if( pComandos.BlockSwitch <= 0 )
	{
		MsgOutput(aIndex,"[AVISO] Comando desactivado!");
		return;
	}
	if(lpObj->Authority < 2  && pComandos.BlockGMAcceso != 0 )
	{
		GCServerMsgStringSend("[AVISO] Comando solo para GameMasters!" ,aIndex,1);
		return;
	} 

	//=====================================================
	// -- GM System :)
	//=====================================================
	if(pComandos.BlockGM != 0)
	{
		int CanBlock = 0;
		for(int x=1;x < GMSystemCount;x++)
		{
			if(!strcmp(GMSystemInfo[x].Name,lpObj->Name))
			{
				CanBlock = GMSystemInfo[x].GMBlock;
			}
		}
		if(CanBlock == 0)
		{
			GCServerMsgStringSend("Este [GM] No puede usar el comando!",aIndex,1);
			return;
		}
	}

	char Target[11] = {0}; 
	sscanf(Msg,"%s",&Target);
	int Index = GetPlayerIndex(Target); 

	OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);  

	Manager.ExecFormat("UPDATE Character SET CtlCode='1' WHERE Name='%s'",Target);

	CloseClient(Index);

	char AllMsg[125];
	sprintf(AllMsg,"%s está Bloqueado !!",Target);
	StringSendAll(AllMsg,0);

}
// ----------------------------------------------------------------------------------------------
//	# COMANDO DESBLOQUEAR JUGADOR
// ----------------------------------------------------------------------------------------------
void UnBlockComando(int aIndex, char* Msg)  
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if( pComandos.UnBlockSwitch <= 0 )
	{
		MsgOutput(aIndex,"[AVISO] Comando desactivado!");
		return;
	}
	if(lpObj->Authority < 2  && pComandos.UnBlockGMAcceso != 0 )
	{
		GCServerMsgStringSend("[AVISO] Comando solo para GameMasters!" ,aIndex,1);
		return;
	}

	//=====================================================
	// -- GM System :)
	//=====================================================
	if(pComandos.UnBlockGM != 0)
	{
		int CanUnBlock = 0;
		for(int x=1;x < GMSystemCount;x++)
		{
			if(!strcmp(GMSystemInfo[x].Name,lpObj->Name))
			{
				CanUnBlock = GMSystemInfo[x].GMUnBlock;
			}
		}
		if(CanUnBlock == 0)
		{
			GCServerMsgStringSend("Este [GM] No puede usar el comando!",aIndex,1);
			return;
		}
	}

	char Target[11] = {0}; 

	sscanf(Msg,"%s",&Target);
	int Index = GetPlayerIndex(Target); 
	OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);  
	
	Manager.ExecFormat("UPDATE Character SET CtlCode='0' WHERE Name='%s'",Target);

	char AllMsg[125];
	sprintf(AllMsg,"%s está Desbloqueado !",Target);
	StringSendAll(AllMsg,0);
}
// ----------------------------------------------------------------------------------------------
//	# COMANDO BANEAR JUGADOR
// ----------------------------------------------------------------------------------------------
void BanComando(int aIndex, char* Msg)  
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if( pComandos.BanSwitch <= 0 )
	{
		MsgOutput(aIndex,"[AVISO] Comando desactivado!");
		return;
	}
	if(lpObj->Authority < 2  && pComandos.BanGMAcceso != 0 )
	{
		GCServerMsgStringSend("[AVISO] Comando solo para GameMasters!" ,aIndex,1);
		return;
	}

	//=====================================================
	// -- GM System :)
	//=====================================================
	if(pComandos.BanGM != 0)
	{
		int CanBan = 0;
		for(int x=1;x < GMSystemCount;x++)
		{
			if(!strcmp(GMSystemInfo[x].Name,lpObj->Name))
			{
				CanBan = GMSystemInfo[x].GMBan;
			}
		}
		if(CanBan == 0)
		{
			GCServerMsgStringSend("Este [GM] No puede usar el comando!",aIndex,1);
			return;
		}
	}

	char Target[11] = {0}; 

	sscanf(Msg,"%s",&Target);
	int Index = GetPlayerIndex(Target); 
	OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index); // Player OK !!

	Manager.ExecFormat("UPDATE MEMB_INFO SET bloc_code='1' WHERE memb___id='%s'",Target);

	CloseClient(Index);

	char AllMsg[125];
	sprintf(AllMsg,"%s Su cuenta fue baneada !!",Target);
	StringSendAll(AllMsg,0);

}
// ----------------------------------------------------------------------------------------------
//	# COMANDO DESBANEAR JUGADOR
// ----------------------------------------------------------------------------------------------
void UnBanComando(int aIndex, char* Msg)  
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if( pComandos.UnBanSwitch <= 0 )
	{
		MsgOutput(aIndex,"[AVISO] Comando desactivado!");
		return;
	}
	if(lpObj->Authority < 2  && pComandos.UnBanGMAcceso != 0 )
	{
		GCServerMsgStringSend("[AVISO] Comando solo para GameMasters!" ,aIndex,1);
		return;
	}

	//=====================================================
	// -- GM System :)
	//=====================================================
	if(pComandos.UnBanGM != 0)
	{
		int CanUnBan = 0;
		for(int x=1;x < GMSystemCount;x++)
		{
			if(!strcmp(GMSystemInfo[x].Name,lpObj->Name))
			{
				CanUnBan = GMSystemInfo[x].GMUnBan;
			}
		}
		if(CanUnBan == 0)
		{
			GCServerMsgStringSend("Este [GM] No puede usar el comando!",aIndex,1);
			return;
		}
	}

	char Target[11] = {0}; 

	sscanf(Msg,"%s",&Target);
	int Index = GetPlayerIndex(Target); 
	OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index); // Player OK !! 
	
	Manager.ExecFormat("UPDATE MEMB_INFO SET bloc_code='0' WHERE memb___id='%s'",Target);

    char AllMsg[125];
    sprintf(AllMsg,"%s Su cuenta fue desbaneada !!",Target);
    StringSendAll(AllMsg,0);

}