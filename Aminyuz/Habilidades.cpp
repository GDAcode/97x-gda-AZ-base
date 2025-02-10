#include "StdAfx.h"

void Habilidades()
{
	// --------------------------------------------------------------------
	// # MONSTRUOS EN ORBES DE ELF
	// --------------------------------------------------------------------
    *(unsigned char*) (0x00457E40)   = GetPrivateProfileIntA  ("ORBES","Invocacion 1",26,Aminyuz_Habilidades);
    *(unsigned char*) (0x00457E71)   = GetPrivateProfileIntA  ("ORBES","Invocacion 2",32,Aminyuz_Habilidades);
    *(unsigned char*) (0x00457EA2)   = GetPrivateProfileIntA  ("ORBES","Invocacion 3",21,Aminyuz_Habilidades);
    *(unsigned char*) (0x00457ED3)   = GetPrivateProfileIntA  ("ORBES","Invocacion 4",20,Aminyuz_Habilidades); 
    *(unsigned char*) (0x00457F04)   = GetPrivateProfileIntA  ("ORBES","Invocacion 5",10,Aminyuz_Habilidades);
    *(unsigned char*) (0x00457F35)   = GetPrivateProfileIntA  ("ORBES","Invocacion 6",150,Aminyuz_Habilidades);
    *(unsigned char*) (0x00457F66)   = GetPrivateProfileIntA  ("ORBES","Invocacion 7",151,Aminyuz_Habilidades);

	// --------------------------------------------------------------------
	// # CONFIGURACIONES DE LIFE SWELLING
	// --------------------------------------------------------------------
	*(unsigned int*)  (0x004583B0+1) = GetPrivateProfileIntA  ("LIFESWELLING","Vitalidad",80,Aminyuz_Habilidades);
    *(unsigned int*)  (0x004583C4+1) = GetPrivateProfileIntA  ("LIFESWELLING","Energia",50,Aminyuz_Habilidades);
    *(unsigned int*)  (0x004583E2+1) = GetPrivateProfileIntA  ("LIFESWELLING","Duracion",200,Aminyuz_Habilidades);

	// --------------------------------------------------------------------
	// # CONFIGURACIONES DEL MANA SHIELD
	// --------------------------------------------------------------------
	*(unsigned char*) (0x00458794+3) = GetPrivateProfileIntA  ("MANASHIELD","Porcentaje",10   ,Aminyuz_Habilidades);
    *(unsigned int*)  (0x00458779+1) = GetPrivateProfileIntA  ("MANASHIELD","Agilidad",6800,Aminyuz_Habilidades);
    *(unsigned int*)  (0x0045878D+1) = GetPrivateProfileIntA  ("MANASHIELD","Energia",6800,Aminyuz_Habilidades);
    *(unsigned int*)  (0x004587AC+1) = GetPrivateProfileIntA  ("MANASHIELD","ExtraEnergia",6800 ,Aminyuz_Habilidades); 
	*(unsigned char*) (0x004587B3+2) = GetPrivateProfileIntA  ("MANASHIELD","Duracion",60,Aminyuz_Habilidades);
}