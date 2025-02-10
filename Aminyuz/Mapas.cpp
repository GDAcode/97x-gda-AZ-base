#include "StdAfx.h"

void ReadyNewMaps()
{       
    MapsFix();
	memset((DWORD*)0x0048A6B6, 0x90, 10); 
	memset((DWORD*)0x0048A6B6, 0xE8, 1); 
	*(DWORD*)(0x0048A6B6+1) = (DWORD)&LoadMaps-(0x0048A6B6+5);
}


pMapItemInit	MapItemInit		= (pMapItemInit)0x00402225;
pLoadMapAttr	LoadMapAttr		= (pLoadMapAttr)0x00401FC3;
pGetNewPath		GetNewPath		= (pGetNewPath)0x00401A7D;

void MapsFix() 
{
	memset((BYTE*)0x00489424, MAPS_LIMIT, 1);
	memset((BYTE*)0x0048948F, MAPS_LIMIT, 1);
	memset((BYTE*)0x0047C7D4, MAPS_LIMIT, 1);
	memset((BYTE*)0x0047C7FE, MAPS_LIMIT, 1);
	memset((BYTE*)0x0047334E, MAPS_LIMIT, 1);
	memset((BYTE*)0x0047C499, MAPS_LIMIT, 1);
	memset((BYTE*)0x004122FC, MAPS_LIMIT, 1); // ItemSerialCreateRecv
	memset((BYTE*)0x0045D153, MAPS_LIMIT, 1); //
	memset((BYTE*)0x00443782, MAPS_LIMIT-1, 1);
	memset((BYTE*)0x0045C620, MAPS_LIMIT-1, 1);
	memset((BYTE*)0x0045BA63, MAPS_LIMIT-1, 1);
	//memset((BYTE*)0x0045C77B, MAPS_LIMIT-1, 1);
	memset((BYTE*)0x00406B47, MAPS_LIMIT-1, 1);
	memset((BYTE*)0x00463FF1, MAPS_LIMIT-1, 1);
	memset((BYTE*)0x004188DD, MAPS_LIMIT-1, 1);
	memset((BYTE*)0x00497B30, MAPS_LIMIT-1, 1);
	memset((BYTE*)0x00497C00, MAPS_LIMIT-1, 1);
}

void LoadMaps() 
{
	LoadMapAttribute(17, "Terrain18.att");
	LoadMapAttribute(18, "Terrain19.att");
	LoadMapAttribute(19, "Terrain20.att");
	LoadMapAttribute(20, "Terrain21.att");
	LoadMapAttribute(21, "Terrain22.att");
	LoadMapAttribute(22, "Terrain23.att");
	LoadMapAttribute(23, "Terrain24.att");
	LoadMapAttribute(24, "Terrain25.att");
	_asm 
	{
		mov ecx, 06342BC0h;
		mov edi, 00401145h
		call edi;
	}
}

void LoadMapAttribute(unsigned int index, const char *name) 
{
	if(index > MAPS_LIMIT)
	{
	//	logs.ConsoleHora(1,"Fez merda nos mapas. %s %d",__FILE__,__LINE__);
		return;
	}

	unsigned int thismap = (index * MAP_SIZE) + MAP_BASE;

	__asm 
	{
		xor ecx, ecx;
		mov ecx, thismap;
		call MapItemInit;

		push index;
		push name;
		xor ecx, ecx;
		mov ecx, DIR_BASE;
		call GetNewPath;

		push eax;
		mov ecx, thismap;
		call LoadMapAttr;
	}
}