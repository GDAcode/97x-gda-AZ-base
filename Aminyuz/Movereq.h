#ifndef MOVEREQ_H
#define MOVEREQ_H

void MoveReq();

#define MAX_TELEPORT_NUMBER 100	
#define MAX_MAPS_NUMBER 50

struct S_Teleport
{
	char t_Name[30];
	unsigned short MinLevel;
	unsigned int Money;
	unsigned short PK;
	unsigned int Vip;
	unsigned short x1;
	unsigned short y1;
	unsigned short x2;
	unsigned short y2;
	unsigned short map;
};

class C_Teleport
{
    public:
	S_Teleport t_struct[MAX_TELEPORT_NUMBER];
	unsigned short t_num;
	void t_LoadTeleports();
	void t_PlayerTeleport(DWORD aIndex,char * map);
};
extern C_Teleport Move;


#endif
