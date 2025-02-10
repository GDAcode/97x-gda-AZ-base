#include "StdAfx.h"

void MoveReq()
{
   Move.t_LoadTeleports();     
}

C_Teleport Move;

int IsPkMove			= GetPrivateProfileIntA("MOVE","PKMove"			,0	,Aminyuz_Comandos);
int MoveTiempoSwitch	= GetPrivateProfileIntA("MOVE","TiempoSwitch"	,1	,Aminyuz_Comandos);
int MoveTiempo			= GetPrivateProfileIntA("MOVE","Tiempo"			,10	,Aminyuz_Comandos);

void C_Teleport::t_LoadTeleports()
{
	this->t_num = 0;
	FILE* mFile;
	fopen_s(&mFile,Aminyuz_Movereq,"r"); 
	char Linha[1024];
	int map,x1,x2,y1,y2,lvl,zen,Vip;

	if(mFile == 0)
	{
		MessageBox(0, "Movereq.ini - Archivo no encontrado.", "Erro Critico.", MB_OK | MB_ICONSTOP);
		ExitThread(0);
		return;
	}

    while(!feof(mFile))
    {
        fgets(Linha, 1024, mFile);
		if(!strcmp(Linha, "end"))
			break;

        if(Linha[strlen(Linha) - 1] == '\n' || Linha[strlen(Linha) - 1] == '\r')
        {
            if(Linha[0] != '/' || Linha[1] != '/')
            {
				if(t_num > MAX_TELEPORT_NUMBER)
				{
					MessageBoxA(NULL,"Error reading teleport file, max /n\number of moves overflowed!","Fatal Error",NULL);				 
					ExitThread(0);
				}
				char *rest;
				strcpy_s(t_struct[this->t_num].t_Name, 30, strtok_s(Linha,	"\"%50[^\"]\"", &rest));
				sscanf_s(rest, "%d %d %d %d %d %d %d %d ",&map,&x1,&y1,&x2,&y2,&lvl,&zen,&Vip);
				t_struct[this->t_num].map = map;
				t_struct[this->t_num].x1 = x1;
				t_struct[this->t_num].x2 = x2;
				t_struct[this->t_num].y1 = y1;
				t_struct[this->t_num].y2 = y2;
				t_struct[this->t_num].Vip = Vip;
				t_struct[this->t_num].Money = zen;
				t_struct[this->t_num].MinLevel = lvl;
				t_num++;
            }
        }
    }
    fclose(mFile);
}
void C_Teleport::t_PlayerTeleport(DWORD aIndex, char *cmd)
{
	for(int i = 0; i < t_num; i++)
	{
		char Message[200];
		if(!_strcmpi(cmd,t_struct[i].t_Name))
		{
			 OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

			 unsigned char  WarpMoney    = t_struct[i].Money;
			 unsigned short RequireLevel = t_struct[i].MinLevel;
			 unsigned char  RequireVip   = t_struct[i].Vip; //Nuevo

			 int ViP = Manager.VipCount(gObj->AccountID);
			 
			 if (MoveTiempoSwitch != 0)
			 {
				 unsigned long  Delay = (GetTickCount()- epObj[aIndex].m_MoveDelay)/1000;
				 
				 if (Delay < MoveTiempo)
				 {
					 MsgOutput(aIndex,"[AVISO] Espera %d segundos para moverte nuevamente!",(MoveTiempo - Delay),aIndex);
					 return;
				 }
				 epObj[aIndex].m_MoveDelay = GetTickCount();
			 }

			 if( ViP < RequireVip )
			 {
				GCServerMsgStringSend("[AVISO] Move solo para usuarios Vip!",aIndex,1);
				return;
			 }

			 if( gObj->Level < RequireLevel )
			 {
				MsgOutput(aIndex,"[AVISO] No tenes el nivel suficiente! Requerido: %d",RequireLevel);
				return;
			 }

			 if( gObj->m_PK_Level > 5 && IsPkMove <= 0 )
			 {
				MsgOutput(aIndex,"[AVISO] Los PK no pueden moverse!");
				return;
			 }
			 else if(gObj->Money < WarpMoney)
			 {
				MsgOutput(aIndex,"[AVISO] No tenes el zen suficiente! Requerido: %d",WarpMoney);
				return;
			 }
			 else if(t_struct[i].map == 10 && gObj->pInventory[EQUIPMENT_WING].m_Type == SLOT_EMPTY && gObj->pInventory[EQUIPMENT_HELPER].m_Type != 0x1A3)
			 {
				GCServerMsgStringSend("[AVISO] Necesitas alas para moverte a Icarus!",aIndex,1);
				return;
			 }
			 else if(t_struct[i].map == 7 && gObj->pInventory[EQUIPMENT_HELPER].m_Type == 0x1A2 || t_struct[i].map == 7 && gObj->pInventory[EQUIPMENT_HELPER].m_Type == 0x1A3)
			 {
				GCServerMsgStringSend("[AVISO] Montado en un Unuria no podes ir a Atlans!",aIndex,1);
				return;
			 }
			 else
			 {
				int FinalX;
				int FinalY;

				if((t_struct[i].x2 - t_struct[i].x1) > 0)
				{
					FinalX = min(t_struct[i].x1, t_struct[i].x2) + rand()% (max(t_struct[i].x1, t_struct[i].x2) - min(t_struct[i].x1, t_struct[i].x2));
				}
				else
				{
					FinalX = t_struct[i].x1;
				}

				if((t_struct[i].y2 - t_struct[i].y1) > 0)
				{
					FinalY = min(t_struct[i].y1, t_struct[i].y2) + rand()% (max(t_struct[i].y1, t_struct[i].y2) - min(t_struct[i].y1, t_struct[i].y2));
				}
				else 
				{
					FinalY =  t_struct[i].y1;
				}
				
				gObj->X = FinalX;
				gObj->Y = FinalY;

				gObj->Money -= t_struct[i].Money;
				GCMoneySend(aIndex,gObj->Money);

				GCItemListSend(aIndex); //Fix Shadow Item
				gObjTeleport(aIndex, t_struct[i].map, gObj->X, gObj->Y);

			 }
		 }
	 }
}