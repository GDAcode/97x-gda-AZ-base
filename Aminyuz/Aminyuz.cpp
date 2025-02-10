#include "StdAfx.h"

extern "C" _declspec(dllexport) void Aminyuz()
{
	DWORD OldProtect;
	if (VirtualProtect(LPVOID(0x00401000),1347710,PAGE_EXECUTE_READWRITE,&OldProtect))
	{
		Manager.Initialize();	// BASE DE DATOS
		Comandos();				// COMANDOS
		Protocolo();			// PROTOCOLO
		Fixes();				// CORRECCIONES DEL JUEGO
		Servidor();				// CONFIGURACIONES DEL SERVIDOR EN GENERAL
		Balance();				// SISTEMA DE BALANCE
		ReadLifeCheck();		// CHEQUEO DE LOS MOUNSTROS DE LOS EVENTOS PERSONALIZADOS
		LoadPKWarden();
		LoadZenWarden();
		ReadGMSystem();
		ReadyReload();
		GReset::LoadSettings();
		Seguridad();			// SEGURIDAD DEL SERVIDOR
		Rates();				// RATES DEL SERVIDOR
		Habilidades();			// HABILIDADES DEL SERVIDOR
		ReadyNewMaps();
		// -------------------------------------------------
		//	# Codigos de Seguridad Personaje / Guild / Baul
		// -------------------------------------------------
		HookThis((DWORD)&GCWarePassSend,0x004029C3);
		// -------------------------------------------------
		//	# Sistemas del Servidor
		// -------------------------------------------------
		MoveReq();				// SISTEMA DE MOVES
		Noticias();				// SISTEMA DE NOTICIAS AUTOMATICAS
		Party();				// PARTY BONUS
		ReadyDropSystem();		// DROPEO DE ITEMS
		LoadTrade();
		ReadygObjAttack();
		// -------------------------------------------------
		//	# Eventos del Servidor
		// -------------------------------------------------
		ReadKundun();
		LoadPrecios();
		ReadyCGUseItemRecv();
	}
}