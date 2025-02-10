#ifndef GAMEMASTER_H
#define GAMEMASTER_H

void ReadGMSystem();
 
typedef struct GMSystem
{
	char Name[11];

	int GMReload;
	int GMDrop;
	int GMGG;
	int GMSkin;
	int GMOnline;
	int GMMoveAll;
	int GMBlock;
	int GMUnBlock;
	int GMBan;
	int GMUnBan;

}GMSYSTEM;

extern GMSYSTEM GMSystemInfo[255];

extern int GMSystemCount;

#endif
