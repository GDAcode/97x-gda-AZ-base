#include "StdAfx.h"

void Rates()
{
	// --------------------------------------------------------------------
	// # FIJAR ARTICULOS EXCELENTES
	// --------------------------------------------------------------------
    *(unsigned char*) (0x004814CC+1) = GetPrivateProfileIntA  ("EXCELENTES","Exito al Defender",10,Aminyuz_Rates);
	*(unsigned char*) (0x004815EC+1) = GetPrivateProfileIntA  ("EXCELENTES","Aumento de Ataque",2,Aminyuz_Rates);
	*(unsigned char*) (0x0048162C+1) = GetPrivateProfileIntA  ("EXCELENTES","Velocidad de Ataque",7,Aminyuz_Rates);
	*(unsigned char*) (0x0048156D+1) = GetPrivateProfileIntA  ("EXCELENTES","Exito al Atacar",10 ,Aminyuz_Rates);
	*(unsigned char*) (0x0048148C+1) = GetPrivateProfileIntA  ("EXCELENTES","Reflejo de Ataque",5,Aminyuz_Rates);

	// --------------------------------------------------------------------
	// # PORCENTAJE DE LA CAIDA DE ARTICULOS
	// --------------------------------------------------------------------
    *(unsigned int*)  (0x00409E36+3) = GetPrivateProfileIntA  ("ARTICULOS","Habilidad",80 ,Aminyuz_Rates);
    *(unsigned int*)  (0x00409E3D+3) = GetPrivateProfileIntA  ("ARTICULOS","Suerte",80 ,Aminyuz_Rates);
	*(unsigned int*)  (0x00409C25+1) = GetPrivateProfileIntA  ("EXCELENTES","Taza de caida",200,Aminyuz_Rates);
    *(unsigned int*)  (0x00409DE3+3) = GetPrivateProfileIntA  ("EXCELENTES","Habilidad",100,Aminyuz_Rates);
    *(unsigned int*)  (0x00409DEA+3) = GetPrivateProfileIntA  ("EXCELENTES","Suerte",80 ,Aminyuz_Rates);

	// --------------------------------------------------------------------
	// # PORCENTAJE DE JOYAS EN ITEMS
	// --------------------------------------------------------------------
	*(unsigned char*) (0x0047A678+3) = 100 - GetPrivateProfileIntA ("JOYAS","Life",75,Aminyuz_Rates);

	// --------------------------------------------------------------------
	// # PORCENTAJE DE EXITO EN LA MAQUINA CHAOS
	// --------------------------------------------------------------------
	*(unsigned char*)  (0x0044926D)  = GetPrivateProfileIntA  ("CHAOSMACHINE","ChaosMix10Rate",90 ,Aminyuz_Rates);
    *(unsigned char*)  (0x0044927C)  = GetPrivateProfileIntA  ("CHAOSMACHINE","ChaosMix11Rate",90 ,Aminyuz_Rates);
}