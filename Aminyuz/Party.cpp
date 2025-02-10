#include "StdAfx.h"

void Party()
{
	// --------------------------------------------------------------------
	// # DIFERENCIA DE NIVEL PARA FORMAR UN PARTY
	// --------------------------------------------------------------------
    *(unsigned int*) (0x0041ECCC+1) = GetPrivateProfileIntA  ("GENERAL","Nivel",130,Aminyuz_Party);
	*(unsigned int*) (0x0041EDAF+1) = GetPrivateProfileIntA  ("GENERAL","Nivel",130,Aminyuz_Party);
	*(unsigned int*) (0x0041EED7+1) = GetPrivateProfileIntA  ("GENERAL","Nivel",130,Aminyuz_Party);

	// --------------------------------------------------------------------
	// # EXPERIENCIA EN PARTY POR JUGADOR
	// --------------------------------------------------------------------
    *(unsigned int*) (0x00467E3C+3) = GetPrivateProfileIntA  ("GRUPOS","2 Jugadores",120,Aminyuz_Party);
	*(unsigned int*) (0x00467E15+3) = GetPrivateProfileIntA  ("GRUPOS","3 Jugadores",150,Aminyuz_Party);
	*(unsigned int*) (0x00467E24+3) = GetPrivateProfileIntA  ("GRUPOS","4 Jugadores",170,Aminyuz_Party);
	*(unsigned int*) (0x00467E33+3) = GetPrivateProfileIntA  ("GRUPOS","5 Jugadores",190,Aminyuz_Party);

	// --------------------------------------------------------------------
	// # EXPERIENCIA EN PARTY POR GRUPO
	// --------------------------------------------------------------------
    *(unsigned int*) (0x00467E06+3) = GetPrivateProfileIntA  ("GRUPOS","2 Clases",120,Aminyuz_Party);
	*(unsigned int*) (0x00467DDF+3) = GetPrivateProfileIntA  ("GRUPOS","3 Clases",200,Aminyuz_Party);
	*(unsigned int*) (0x00467DEE+3) = GetPrivateProfileIntA  ("GRUPOS","4 Clases",230,Aminyuz_Party);
	*(unsigned int*) (0x00467DFD+3) = GetPrivateProfileIntA  ("GRUPOS","5 Clases",260,Aminyuz_Party);

	// --------------------------------------------------------------------
	// # EXPERIENCIA EN PARTY POR JUGADOR EN EL DEVIL SQUARED
	// --------------------------------------------------------------------
    *(unsigned int*) (0x00430D90+3) = GetPrivateProfileIntA  ("DEVILSQUARE","2 Jugadores",120,Aminyuz_Party);
	*(unsigned int*) (0x00430D69+3) = GetPrivateProfileIntA  ("DEVILSQUARE","3 Jugadores",150,Aminyuz_Party);
	*(unsigned int*) (0x00430D78+3) = GetPrivateProfileIntA  ("DEVILSQUARE","4 Jugadores",170,Aminyuz_Party);
	*(unsigned int*) (0x00430D87+3) = GetPrivateProfileIntA  ("DEVILSQUARE","5 Jugadores",190,Aminyuz_Party);

	// --------------------------------------------------------------------
	// # EXPERIENCIA EN PARTY POR GRUPO EN EL DEVIL SQUARED
	// --------------------------------------------------------------------
    *(unsigned int*) (0x00430D5A+3) = GetPrivateProfileIntA  ("DEVILSQUARE","2 Clases",120,Aminyuz_Party);
	*(unsigned int*) (0x00430D33+3) = GetPrivateProfileIntA  ("DEVILSQUARE","3 Clases",170,Aminyuz_Party);
	*(unsigned int*) (0x00430D42+3) = GetPrivateProfileIntA  ("DEVILSQUARE","4 Clases",190,Aminyuz_Party);
	*(unsigned int*) (0x00430D51+3) = GetPrivateProfileIntA  ("DEVILSQUARE","5 Clases",220,Aminyuz_Party);
}