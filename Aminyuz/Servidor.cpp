#include "StdAfx.h"

void Servidor()
{
	// --------------------------------------------------------------------
	// # MAXIMO DE USUARIOS
	// --------------------------------------------------------------------
	*(unsigned int*) (0x005133E8  ) = GetPrivateProfileIntA  ("GENERAL","Maximo de Usuarios",200,Aminyuz_Servidor);

	// --------------------------------------------------------------------
	// # NIVEL MAXIMO DEL PERSONAJE
	// --------------------------------------------------------------------
    *(unsigned int*) (0x00459BA2+3) = GetPrivateProfileIntA  ("GENERAL","Nivel",350,Aminyuz_Servidor);
	*(unsigned int*) (0x00462A33+2) = GetPrivateProfileIntA  ("GENERAL","Nivel",350,Aminyuz_Servidor);
	*(unsigned int*) (0x00496D93+1) = GetPrivateProfileIntA  ("GENERAL","Nivel",350,Aminyuz_Servidor);
	*(unsigned int*) (0x0048A2A7+3) = GetPrivateProfileIntA  ("GENERAL","Nivel",350,Aminyuz_Servidor);

	// --------------------------------------------------------------------
	// # PUNTOS POR NIVEL DE LAS CLASES
	// --------------------------------------------------------------------
	*(unsigned char*) (0x00462B0C+2)   = GetPrivateProfileIntA  ("GENERAL","Puntos por nivel DK/DW/ELF",5,Aminyuz_Servidor);
	*(unsigned char*) (0x00462AF5+2)   = GetPrivateProfileIntA  ("GENERAL","Puntos por nivel MG",7,Aminyuz_Servidor);

	// --------------------------------------------------------------------
	// # TIEMPO DE ARTICULOS EN EL SUELO
	// --------------------------------------------------------------------
	*(unsigned int*) (0x00446C81+1) = GetPrivateProfileIntA  ("GENERAL","Tiempo de articulos en el suelo",120,Aminyuz_Servidor)*1000;
	*(unsigned int*) (0x00446DCA+1) = GetPrivateProfileIntA  ("GENERAL","Tiempo de articulos en el suelo",120,Aminyuz_Servidor)*1000;
	*(unsigned int*) (0x00446F4F+1) = GetPrivateProfileIntA  ("GENERAL","Tiempo de articulos en el suelo",120,Aminyuz_Servidor)*1000;
	*(unsigned int*) (0x00447148+1) = GetPrivateProfileIntA  ("GENERAL","Tiempo de articulos en el suelo",120,Aminyuz_Servidor)*1000;

	// --------------------------------------------------------------------
	// # ANUNCIOS DE LOS GUARDIAS
	// --------------------------------------------------------------------
	unsigned long dwTmp ; 
    char GuardSay[500];
    memset(&GuardSay,0,50);
    DWORD *Offset = (unsigned long*)(0x00509058);
    dwTmp = GetPrivateProfileString("ANUNCIOS","Guardias","Bienvenidos a Mu Aminyuz !",GuardSay,50,Aminyuz_Servidor);
	memset(&Offset[0],0,50);
    memcpy(&Offset[0],GuardSay,strlen(GuardSay));

	// --------------------------------------------------------------------
	// # CARTELES DE LOS GUARDIAS
	// --------------------------------------------------------------------
	int Cartel255 = GetPrivateProfileIntA("CARTELES","Liaman the Barmaid",0,Aminyuz_Servidor);
	if(Cartel255 != 0)
	{
		SetRange((LPVOID)0x00487D00, 5, ASM::NOP);
	}
	int Cartel253 = GetPrivateProfileIntA("CARTELES","Bob the Dealer",0,Aminyuz_Servidor);
	if(Cartel253 != 0)
	{
		SetRange((LPVOID)0x00487B98, 5, ASM::NOP);
	}
	int Cartel251 = GetPrivateProfileIntA("CARTELES","Hans the Blacksmith",0,Aminyuz_Servidor);
	if(Cartel251 != 0)
	{
		SetRange((LPVOID)0x00487D5A, 5, ASM::NOP);
	}

	// --------------------------------------------------------------------
	// # ANILLOS DE TRANSFORMACION
	// --------------------------------------------------------------------
    *(unsigned int*) (0x00458C98+3)  = GetPrivateProfileIntA  ("ANILLOS","Transformacion 1",2,Aminyuz_Servidor);
    *(unsigned int*) (0x00458CA1+3)  = GetPrivateProfileIntA  ("ANILLOS","Transformacion 2",7,Aminyuz_Servidor);
    *(unsigned int*) (0x00458CAA+3)  = GetPrivateProfileIntA  ("ANILLOS","Transformacion 3",14,Aminyuz_Servidor);
    *(unsigned int*) (0x00458CB3+3)  = GetPrivateProfileIntA  ("ANILLOS","Transformacion 4",8,Aminyuz_Servidor);
    *(unsigned int*) (0x00458CBC+3)  = GetPrivateProfileIntA  ("ANILLOS","Transformacion 5",9,Aminyuz_Servidor);
    *(unsigned int*) (0x00458CC5+3)  = GetPrivateProfileIntA  ("ANILLOS","Transformacion 6",41,Aminyuz_Servidor);

	// -------------------------------
	//  APARICIÓN DE DORADOS
	// -------------------------------
	*(unsigned char*) (0x0043621C+3) = GetPrivateProfileIntA  ("DORADOS","Tantalo",8,Aminyuz_Servidor);
}