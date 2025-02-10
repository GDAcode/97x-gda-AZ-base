#ifndef PKWARDEN_H
#define PKWARDEN_H

struct PKWARDEN
{
	int PKWardenSwitch;
	int PKWardenID;
	int PKWardenSistema;
	DWORD PKWardenZen1;
	DWORD PKWardenZen2;
	int PKWardenLevel;

	char PQuery1[100];
};
extern PKWARDEN pPKWarden;

void LoadPKWarden();
void PKWardenClick(LPOBJ gObj, LPOBJ gObjNPC, int aIndex);
void PKWarden(LPOBJ gObj, LPOBJ NpcObj, int aIndex);

#endif