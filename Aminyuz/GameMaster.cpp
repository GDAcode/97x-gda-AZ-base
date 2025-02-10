#include "StdAfx.h"

GMSYSTEM GMSystemInfo[255];

int GMSystemCount;

void ReadGMSystem()
{
	FILE *fp;
	BOOL bRead = FALSE;
	DWORD dwArgv = 0;
	char sLineTxt[255] = {0};
	GMSystemCount = 1;

	fp = fopen(Aminyuz_GM,"r");

	if(!fp)
	{
		MessageBoxA(NULL, "GameMaster.ini - Archivo no encontrado.", "Erro Critico.", MB_OK);
		::ExitProcess(0);
	}

	rewind(fp);
	
	while(fgets(sLineTxt, 255, fp) != NULL)
	{
		if(sLineTxt[0] == '/')continue;
		if(sLineTxt[0] == ';')continue;

		int n[11];
		char GetGMName[11];

		sscanf(sLineTxt, "%s %d %d %d %d %d %d %d %d %d %d ", &GetGMName,&n[1],&n[2],&n[3],&n[4],&n[5],&n[6],&n[7],&n[8],&n[9],&n[10]);
		sprintf(GMSystemInfo[GMSystemCount].Name,"%s",GetGMName);

		GMSystemInfo[GMSystemCount].GMReload  	 = n[1];
		GMSystemInfo[GMSystemCount].GMDrop		 = n[2];
		GMSystemInfo[GMSystemCount].GMGG		 = n[3];
		GMSystemInfo[GMSystemCount].GMSkin		 = n[4];
		GMSystemInfo[GMSystemCount].GMOnline	 = n[5];
		GMSystemInfo[GMSystemCount].GMMoveAll	 = n[6];
		GMSystemInfo[GMSystemCount].GMBlock		 = n[7];
		GMSystemInfo[GMSystemCount].GMUnBlock	 = n[8];
		GMSystemInfo[GMSystemCount].GMBan		 = n[9];
		GMSystemInfo[GMSystemCount].GMUnBan		 = n[10];
		GMSystemCount++;
	}

	rewind(fp);
	fclose(fp);
}