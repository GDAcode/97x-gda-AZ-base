#include "StdAfx.h"

void Fixes()
{
	// --------------------------------------------------------------------
	// # Cambiada la ubicacion del ServerInfo.dat
	// --------------------------------------------------------------------
	memset((char*)0x0050E35E,0,22);                            
	memcpy((char*)0x0050E35E,".\\Data\\ServerInfo.dat",21);

	// --------------------------------------------------------------------
	// # Limite de escudos 32
	// --------------------------------------------------------------------
	BYTE Escudos = GetPrivateProfileIntA("IMPORTANTES","Escudos",0,Aminyuz_Fixes);
	if(Escudos != 0)
	{
		*(BYTE*)(0x00454233+1) = 0xE0;
	}

	// --------------------------------------------------------------------
	// # Fix +28 Item Option
	// --------------------------------------------------------------------
	int Opcion = GetPrivateProfileIntA("IMPORTANTES","Opcion+28",0,Aminyuz_Fixes);
	if(Opcion != 0)
	{
		SetNop(0x004118E3,2);
		SetNop(0x0045BD20,2);
		*(BYTE*)(0x0047A673+2) = 0x07;
		SetNop(0x00482377,2);     
	}

	// --------------------------------------------------------------------
	// # PartyZen
	// --------------------------------------------------------------------
	BYTE PartyZen = GetPrivateProfileIntA ("IMPORTANTES", "PartyZen", 0, Aminyuz_Fixes);
	if ( PartyZen != 0 )
	{
		BYTE btParty[57] =
		{
			0x8B, 0x4D, 0x0C, 0x33,
			0xC0, 0x8A, 0x41, 0x5C,
			0x83, 0xF8, 0x02, 0x75,
			0x20, 0x8B, 0x91, 0x94,
			0x00, 0x00, 0x00, 0x89,
			0x55, 0xF8, 0xDB, 0x45,
			0xF8, 0xD8, 0x0D, 0x74,
			0x36, 0x51, 0x00, 0xE8,
			0x40, 0x54, 0x03, 0x00,
			0x8B, 0x4D, 0x0C, 0x89,
			0x81, 0x94, 0x00, 0x00,
			0x00, 0x5F, 0x5E, 0x5B,
			0x8B, 0xE5, 0x5D, 0xC3
		};
		memcpy((int*)0x4680DC, btParty, sizeof(btParty));
	}

	// --------------------------------------------------------------------
	// # PK Bug
	// --------------------------------------------------------------------
	BYTE PKBug = GetPrivateProfileIntA("IMPORTANTES","PKBug",0,Aminyuz_Fixes);
	if(  PKBug != 0 )
	{
		*(BYTE*)(0x45508A) = 0x90;
		*(BYTE*)(0x45508B) = 0x90;
		*(BYTE*)(0x45508C) = 0x90;
		*(BYTE*)(0x45508D) = 0x90;
		*(BYTE*)(0x45508E) = 0x90;
		*(BYTE*)(0x4550AF) = 0x90;
		*(BYTE*)(0x4550B0) = 0x90;
		*(BYTE*)(0x4550B1) = 0x90;
		*(BYTE*)(0x4550B2) = 0x90;
		*(BYTE*)(0x4550B3) = 0x90;
		*(BYTE*)(0x4642A4) = 0x9C;
		*(BYTE*)(0x4642B0) = 0x9C;
		*(BYTE*)(0x4643C0) = 0x9C;
		*(BYTE*)(0x4643CC) = 0x9C; 
	}

	// --------------------------------------------------------------------
	// # Pk Can Be Killed (KOR FIX)
	// --------------------------------------------------------------------
	memset((BYTE*)0x45509C, 0xEB, 1);
    memset((BYTE*)0x455077, 0xEB, 1);

	// --------------------------------------------------------------------
	// # PK Limit Player Kill
	// --------------------------------------------------------------------
	memset((PBYTE)0x465585, 0x90, 15);

	// --------------------------------------------------------------------
	// # ¡Û Mensaje de invasion de Dorados
	// --------------------------------------------------------------------
	// # [ Mapa, Mensaje ]
	// --------------------------------------------------------------------
	*(BYTE*)(0x0050B060) = 0x20;   //		[ 20 ]
	*(BYTE*)(0x0050B060+1) = 0x5D; //	¡	[ A1 -> 5D ]
	*(BYTE*)(0x0050B060+2) = 0x00; //	Ù	[ D9 -> 00 ] 
	*(BYTE*)(0x0050B060+4) = 0x5B; //	¡	[ A1 -> 5B ]
	*(BYTE*)(0x0050B060+5) = 0x20; //	Ù	[ D9 -> 20 ]
	*(BYTE*)(0x0050B060+6) = 0x00; //		[ 20 -> 00 ]

	//======================================================================
    // Fix Nuevo Chequeo X Y Map
	//======================================================================
    BYTE check[]= {0xE9,0xA2,0x00,0x00,0x00,0x90};
	memcpy((DWORD*)0x461022, check, 6);

	//======================================================================
	//-- Fix Error L2 Index
	//======================================================================
	BYTE ErrorL2 = GetPrivateProfileIntA("IMPORTANTES","ErrorL2",0,Aminyuz_Fixes);
	if(  ErrorL2 != 0 )
	{
	*(BYTE*)(0x44029B) = 0x90;
    *(BYTE*)(0x44029C) = 0x90;
	*(BYTE*)(0x44029D) = 0x90;
	*(BYTE*)(0x44029E) = 0x90;
	*(BYTE*)(0x44029F) = 0x90;
	*(BYTE*)(0x4402A0) = 0x90;
	}
	//======================================================================
	//-- CheckSum 
	//======================================================================
	int  CheckSum = GetPrivateProfileIntA("OPCIONALES","CheckSum",0,Aminyuz_Fixes);
	if(  CheckSum != 0 )
	{
		*(BYTE*)(0x004155EA) = 0xEB;
		*(BYTE*)(0x00415653) = 0xEB;
	}
	else
	{
		*(BYTE*)(0x004155EA) = 0x7E;
		*(BYTE*)(0x00415653) = 0x75;
	}
	//======================================================================
	//-- Fixes Flechas Infinitas [NUEVO]
	//======================================================================
	int  Arrows = GetPrivateProfileIntA("OPCIONALES","FlechasInfinitas",0,Aminyuz_Fixes);
    if(  Arrows != 0)      
    {
	SetNop(0x00454CB3,45);  
    SetNop(0x00454D82,45);  
	}
	//======================================================================
	//-- Fix los pks abren los shops 
	//======================================================================
	BYTE PKShop = GetPrivateProfileIntA("OPCIONALES","PkShopOpem",0,Aminyuz_Fixes);
	if(  PKShop != 0 )
	{
    *(BYTE*)(0x41B797) = 0xEB;  
	}
	//======================================================================
    //-- Fix Los pk pueden entrar a los eventos
	//======================================================================
	BYTE PKEvent = GetPrivateProfileIntA("OPCIONALES","PKEventEnter",0,Aminyuz_Fixes);
	if(  PKEvent != 0 )
	{
	*(BYTE*)(0x42AD19) = 0xEB;  //-- PK Blood Castle Enter 
	*(BYTE*)(0x429455) = 0xEB;  //-- PK Devil Square Enter
	}
	//======================================================================
	//-- Fix Pociones 255
	//======================================================================
	BYTE Potions = GetPrivateProfileIntA("IMPORTANTES","PocionBug",0,Aminyuz_Fixes);
	if(  Potions != 0 )
	{
	SetNop(0x004119FE,10);
	SetNop(0x0045BE0E,7);
	}
	//======================================================================
	//-- Fix Menos Logs [NUEVO]
	//======================================================================
	BYTE Logs = GetPrivateProfileIntA("OPCIONALES","MenosLogs",0,Aminyuz_Fixes);
	if(  Logs != 0 )
    {
	SetNop(0x004128C0, 6); // Monster Item Drop Request           
    SetNop(0x00445545, 6); // Item has Disappeared                
    SetNop(0x00444511, 6); // Can't throw away the item           
    SetNop(0x00462A90, 6); // Experience : Map (0x0x0x0x00)       
    SetNop(0x00462BC4, 6); // Level Up
	SetNop(0x0045E957, 6); // # Desactivar SkyLand Boss Monster Setting!!
	SetNop(0x0045E981, 6); // # Desactivar SkyLand Boss Shield Setting!!
	}
	//======================================================================
	//-- Fix Nick WebZen
	//======================================================================
	BYTE WebZen = GetPrivateProfileIntA("IMPORTANTES","WebZen",0,Aminyuz_Fixes);
	if(  WebZen != 0 )
	{
	*(BYTE*)(0x45D33A) = 0x01;
	*(BYTE*)(0x45D37B) = 0x01;
    *(BYTE*)(0x45D3E3) = 0x01;
	}
	// --------------------------------------------------------------------
	// # GCWarehouseRecivePassword Remove box personal id
	// --------------------------------------------------------------------
	*(BYTE*)(0x0042359E) = 0xEB;
	// --------------------------------------------------------------------
	// # Anti Shadow Bug
	// --------------------------------------------------------------------
	int  Shadow = GetPrivateProfileIntA("IMPORTANTES","ShadowBug",0,Aminyuz_Fixes);
	if(  Shadow != 0 )
	{
		HookThis((DWORD)&AntiShadow, 0x004016E0);
		HookThis((DWORD)&AntiShadow, 0x004015A0);
		HookThis((DWORD)&AntiShadow, 0x00401FAF);
	}
	//======================================================================
     // Eliminar personaje sin id
	 //======================================================================
	 int  _PersonalID = GetPrivateProfileIntA("IMPORTANTES","PersonajeID",0,Aminyuz_Fixes);
	 if(  _PersonalID != 0 )
	 {
		 *(BYTE*)(0x417781) = 0xEB;
		 *(BYTE*)(0x420D2A) = 0x90;
		 *(BYTE*)(0x420D2B) = 0x90;
		 *(BYTE*)(0x420DEB) = 0x90;
		 *(BYTE*)(0x420DEC) = 0x90;
	 }
	 //======================================================================
     // Eliminar guild y salir del guild sin id
	 //======================================================================
	 int  _GuildID = GetPrivateProfileIntA("IMPORTANTES","GuildID",0,Aminyuz_Fixes);
	 if(  _GuildID != 0 )
	 {
		 *(BYTE*)(0x420D2A) = 0x90;
		 *(BYTE*)(0x420D2B) = 0x90;
		 *(BYTE*)(0x420DEB) = 0x90;
		 *(BYTE*)(0x420DEC) = 0x90;
	 }
	 //======================================================================
	 //-- Fix DestroyGIocp
	 //======================================================================
	 BYTE  DestroyGIocp = GetPrivateProfileIntA("IMPORTANTES","DestroyGIocp",0,Aminyuz_Fixes);
	 if(   DestroyGIocp != 0 )
	 {
	 *(BYTE*)(0x40165E) = 0xC3;
	 *(BYTE*)(0x40165F) = 0x90;
	 *(BYTE*)(0x401660) = 0x90;
	 *(BYTE*)(0x401661) = 0x90;
	 *(BYTE*)(0x401652) = 0x90;
	 }
	 //======================================================================
     //-- Erro de 0x00000000 Offset [NUEVO]
	 //======================================================================
	 BYTE  _0x00000000 = GetPrivateProfileIntA("IMPORTANTES","0x00000000",0,Aminyuz_Fixes);
	 if(   _0x00000000 != 0 )
	 {
	 *(BYTE*)(0x0048BB6C) = 0xEB;
	 }
	 //======================================================================
	 //-- Fixes Windons server sp2 [NEW] (GetQueuedCompletionStatus)
	 //======================================================================
	 BYTE  Winsp2 = GetPrivateProfileIntA("IMPORTANTES","Winsp2",0,Aminyuz_Fixes);
	 if(   Winsp2 != 0 )
	 {
	 *(BYTE*)(0x0043EEAE) = 0xEB;
	 }
	 //======================================================================
	 //-- Fix InvalidSocket
	 //======================================================================
	 BYTE  InvalidSocket = GetPrivateProfileIntA("IMPORTANTES","InvalidSocket",0,Aminyuz_Fixes);
	 if(   InvalidSocket != 0 )
	 {
	 *(BYTE*)(0x440EF8) = 0x90; 
	 *(BYTE*)(0x440EF9) = 0x90; 
	 *(BYTE*)(0x440F23) = 0xEB;
	 }
	 //======================================================================
	 //-- Fix Error-L1 : Socket Serial %s %d o_serial:%d serial:%d
	 //======================================================================
     BYTE  ErrorL1 = GetPrivateProfileIntA("IMPORTANTES","ErrorL1Socket",0,Aminyuz_Fixes);
	 if(   ErrorL1 != 0 )
	 {
	 *(BYTE*)(0x00414239) = 0xEB;
	 }
	 //======================================================================
     //-- Speed Hack Desable
	 //======================================================================
	 BYTE  SpeedHackDesactivado = GetPrivateProfileIntA("SEGURIDAD","SpeedHackOff",0,Aminyuz_Fixes);
	 if(   SpeedHackDesactivado != 0 )
	 {
	 *(BYTE*)(0x0042570E) = 0xEB;
	 *(BYTE*)(0x00457574) = 0xEB;
	 }
	 //======================================================================
	 //-- Fix Error L1 cliente Hack check
	 //======================================================================
	 BYTE  ErrorL1Client = GetPrivateProfileIntA("IMPORTANTES","ErrorL1Client",0,Aminyuz_Fixes);
	 if(   ErrorL1Client != 0 )
	 {
	 *(BYTE*)(0x004172E0) = 0xC3;
	 }
	 //======================================================================
	 //-- Speed Hack Warnings Bypass 0x00415140 => Function CGLiveClient
	 //======================================================================
	 BYTE  SpeedHackWarnings = GetPrivateProfileIntA("SEGURIDAD","SpeedHackWarnings",0,Aminyuz_Fixes);
	 if(   SpeedHackWarnings != 0 )
	 {
	 *(BYTE*)(0x0041536C) = 0xEB;
	 *(BYTE*)(0x00415379) = 0xEB;
	 }
	 //======================================================================
	 //-- Speed Hack Log Disable
	 //======================================================================
     BYTE SpeedHackLogs = GetPrivateProfileIntA("SEGURIDAD","SpeedHackLogs",0,Aminyuz_Fixes);
	 if(  SpeedHackLogs != 0 )
     {
	 SetNop (0x41532B,6);	
	 }
	 //======================================================================
     //-- CObjUseSkill::SpeedHackCheck	
	 //======================================================================
     BYTE SpeedHackCheck = GetPrivateProfileIntA("SEGURIDAD","SpeedHackCheck",0,Aminyuz_Fixes);
	 if(  SpeedHackCheck != 0 )
     { 
	 memset((PBYTE)0x004024E6, 0xC3, 1); 	    
     memset((PBYTE)0x004256C4, 0x90, 6);
	 }
	 //======================================================================
     //-- Fix Antihacks Fix 
	 //======================================================================
	 BYTE Antihacks = GetPrivateProfileIntA("SEGURIDAD","Antihacks",0,Aminyuz_Fixes);
	 if(  Antihacks != 0 )
     {
	 *(BYTE*)(0x48107D) = 0x7E;
	 }
	 //--------------------------------------------------------------------
	 // # Invalid Socket
	 //--------------------------------------------------------------------
	SetNop(0x045E514,7);
	SetNop(0x045E51B,3);
	SetNop(0x045E51E,1);
	SetNop(0x045E51F,5);
	SetNop(0x045E524,5);
	SetNop(0x045E529,5);
	SetNop(0x045E52E,6);
	SetNop(0x045E534,1);
	SetNop(0x045E535,6);
	SetNop(0x045E53B,3);
	SetNop(0x045E53E,3);
	SetNop(0x045E541,2);
	SetNop(0x045E543,6);
	SetNop(0x045E549,1);
	SetNop(0x045E54A,3);
	SetNop(0x045E54D,1);
	SetNop(0x045E54E,5);
	SetNop(0x045E553,6);
	SetNop(0x045E559,3);
	SetNop(0x045E55C,2);
}
// --------------------------------------------------------------------
//	# Personal ID ( Baul ) ( 4 Digitos )
// --------------------------------------------------------------------
void GCWarePassSend(int aIndex, PMSG_WAREHOUSEPASSSEND *lpMsg)
{

	switch(lpMsg->Type)
	{
	case 0:
		{
			if(lpMsg->Pass != gObj[aIndex].WarehousePW)
			{
				GCWarehouseStateSend(aIndex, 10);
				return;
			}
			else
			{
				gObj[aIndex].WarehouseLock = 0;
				gObj[aIndex].WarehousePW = 0;
				GCWarehouseStateSend(aIndex,  gObj[aIndex].WarehouseLock);
				GCWarehouseRecivePassword(aIndex,lpMsg);
			}
		}
		break;
	case 1:
		{
			gObj[aIndex].WarehouseLock = 1;
			gObj[aIndex].WarehousePW = lpMsg->Pass;
			GCWarehouseStateSend(aIndex,  gObj[aIndex].WarehouseLock);
		}
		break;
	case 2:
		{
			if(lpMsg->Pass !=  gObj[aIndex].WarehousePW)
			{
				GCWarehouseStateSend(aIndex, 10);
				return;
			}
			else
			{
				GCWarehouseStateSend(aIndex, 0);
				GCWarehouseRecivePassword(aIndex,lpMsg);
			}
		}
		break;
	}

	GCWarehouseRecivePassword(aIndex,lpMsg);
}
// --------------------------------------------------------------------
//	# Anti Shadow Bug
// --------------------------------------------------------------------
bool AntiShadow(OBJECTSTRUCT *gObj, int slotx, int sloty) 
{
	int ItemID     = gObj->pInventory[sloty].m_Type;
	int LevelType  = gObj->pInventory[slotx].m_Type;

	if (ItemID >= 391) 
	{
		return TRUE;
	}
	if (LevelType == 0x1CD) { if (BlessLevelUp(gObj, slotx, sloty)) { return true; } else { return false; }  }
	if (LevelType == 0x1CE) { if (SoulLevelUp(gObj,  slotx, sloty)) { return true; } else { return false; }  }
	if (LevelType == 0x1D0) { if (LifeLevelUp(gObj,  slotx, sloty)) { return true; } else { return false; }  }
	return FALSE;
}