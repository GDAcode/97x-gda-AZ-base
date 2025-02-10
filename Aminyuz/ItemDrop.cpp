#include  "StdAfx.h"

C_DropSystem Drop;

void ReadyDropSystem()
{
	int DPSystem = GetPrivateProfileIntA ("ITEMDROP","Sistema",0,Aminyuz_ItemDrop);
	if( DPSystem != 0 )
	{
	Drop.t_LoadSystem();                                 // Drop System 
	HookThis((DWORD)&MonsterDropCall,0x00401AC8);        // Drop System
	}

}
//================================================================================================
//-- Drop System Load
//================================================================================================
void C_DropSystem::t_LoadSystem()
{
	this->t_num = 0;
	FILE * hFile;
	fopen_s(&hFile,Aminyuz_ItemDrop,"r");
	char Linha[1024];
	int type,index,lvl,opt,luck,skill,dur,rate,minlvl,maxlvl,exc;

	if(hFile == 0)
	{
		MessageBox(0, "..\\Aminyuz\\ItemDrop.txt - Archivo no encontrado.", "Error Critico.", MB_OK | MB_ICONSTOP);
		::ExitProcess(0);
		return;
	}

    while(!feof(hFile))
    {
        fgets(Linha, 1024, hFile);
		if(!strcmp(Linha, "end"))
			break;

		if(Linha[strlen(Linha) - 1] == '\n' || Linha[strlen(Linha) - 1] == '\r')
		{
			if(Linha[0] != '/' || Linha[1] != '/')
			{
				if(t_num > MAX_DROP_NUMBER)
				{
					MessageBoxA(NULL,"Error al leer el ItemDrop.txt, numero /n\maximo de items excedido.!","Fatal Error",NULL);
				 
					::ExitThread(0);
				}
				sscanf_s(Linha, "%d %d %d %d %d %d %d %d %d %d %d ", &type, &index, &lvl, &opt, &luck, &skill, &dur, &rate, &minlvl, &maxlvl, &exc);
				t_struct[this->t_num].Type		= type;
				t_struct[this->t_num].Index		= index;
				t_struct[this->t_num].Level		= lvl;	
				t_struct[this->t_num].Opt		= opt;	
				t_struct[this->t_num].Luck		= luck;	
				t_struct[this->t_num].Skill		= skill;
				t_struct[this->t_num].Dur		= dur;	
				t_struct[this->t_num].Rate		= rate;	
				t_struct[this->t_num].Minlvl	= minlvl;	
				t_struct[this->t_num].Maxlvl	= maxlvl;
				t_struct[this->t_num].Exc		= exc;
				t_num++;
			}
		}
	}
	fclose(hFile);
}
int C_DropSystem::MygEventMonsterItemDrop(BYTE * b_MonsterDataAddr,BYTE * a_gObjAddr)
{
	for(int i = 0; i < t_num; i++)
	{	
		
		WORD wMonsterLv =0;
		WORD wMonsterId =0;
		WORD Player;
		BYTE cMapID,cX,cY;
		PBYTE bDataAddr =0;
		bDataAddr = (PBYTE)b_MonsterDataAddr;

	    memcpy(&Player,bDataAddr+0x6A,sizeof(WORD));		//gObj->Name
		memcpy(&wMonsterLv,bDataAddr+0x86,sizeof(WORD));	//gObj->Level
		memcpy(&wMonsterId,bDataAddr+0x83,sizeof(WORD));	//gObj->Class
		memcpy(&cMapID,bDataAddr+0xD9,sizeof(BYTE));		//gObj->MapId
		memcpy(&cX,bDataAddr+0xD4,sizeof(BYTE));			//gObj-X
		memcpy(&cY,bDataAddr+0xD6,sizeof(BYTE));			//gObj->Y

		DWORD Item = t_struct[i].Type * 32 + t_struct[i].Index;

		DWORD dwTopHitUser = gObjMonsterTopHitDamageUser(b_MonsterDataAddr);

		 DWORD dwRand = rand();

		if(wMonsterLv >= t_struct[i].Minlvl)
		{
			if(wMonsterLv <= t_struct[i].Maxlvl)
			{
				if(rand() % 10000 < t_struct[i].Rate)
				{
				ItemSerialCreateSend(b_MonsterDataAddr[0],cMapID,cX,cY,Item,t_struct[i].Level,t_struct[i].Dur,t_struct[i].Skill,t_struct[i].Luck,t_struct[i].Opt,dwTopHitUser,t_struct[i].Exc);
				return 1;
				}
			}
		}
	}
	int rValue = gEventMonsterItemDrop(b_MonsterDataAddr, a_gObjAddr);
	return rValue;
}

void MonsterDropCall(BYTE * b_MonsterDataAddr,BYTE * a_gObjAddr)
{
	Drop.MygEventMonsterItemDrop(b_MonsterDataAddr,a_gObjAddr);
}