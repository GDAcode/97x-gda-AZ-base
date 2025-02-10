#include "StdAfx.h"

//===========================================================================================
// HookThis
//===========================================================================================
void HookThis( DWORD dwMyFuncOffset, DWORD dwJmpOffset )
{
	*(DWORD*)(dwJmpOffset+1)=dwMyFuncOffset-(dwJmpOffset+5);
}
//===========================================================================================
// MsgOutput
//===========================================================================================
void MsgOutput(DWORD aIndex,char *szMsg ...)
{
	char Buffer[250];
	va_list pArgs;
	va_start(pArgs, szMsg);
	vsprintf(Buffer,szMsg,pArgs);
	va_end(pArgs);
	GCServerMsgStringSend(Buffer, aIndex, 0x01);
}
//===========================================================================================
// MsgSendAll
//===========================================================================================
void StringSendAll( char*Text, int type )
{
	for(int i=OBJECT_MIN;i<OBJECT_MAX;i++)
	{
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
		
		if(gObj->Connected == 3)
		{
		  GCServerMsgStringSend(Text,i,type);
		}
	}
}
//===========================================================================================
// SetNop
//===========================================================================================
void SetNop( DWORD dwOffset, int Size )
{
	for(int n=0;n < Size;n++)
	{
		*(BYTE*)(dwOffset+n)=0x90;
	}
}
void SetNop2( DWORD dwOffset, int Size )
{
	for(int n=1;n < Size;n++)
	{
		*(BYTE*)(dwOffset+n)=0x90;
	}
}
//===========================================================================================
// Chequeo de personaje GM   
//===========================================================================================
int GetGMCount() 
{
      int GMCount = 0;
      for(int i = OBJECT_MIN; i <= OBJECT_MAX; i++)
      {
       OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
         if(gObj->Connected == 3)
           {
            if(gObj->Authority > 1 )
            {
            GMCount++;
            }
         }
     }
     return GMCount;
     
}
//===========================================================================================
//-- GetPlayerIndex
//===========================================================================================
int GetPlayerIndex( char *Name )
{			 
	for(int i = OBJECT_MIN; i <= OBJECT_MAX; i++)
	{  	 
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);	 
	  //if(gObj->Connected < 3) continue;  
		if(!strcmp(gObj->Name, Name)) return i;
	}
	return -1;
}
//===========================================================================================
// Chequeo de Personaje
//===========================================================================================
int GetPlayerCount()
{
    int PlayerCount = 0;
    for(int i = OBJECT_MIN; i <= OBJECT_MAX; i++)
    {
       OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
       if(gObj->Connected == 3)
       {
          PlayerCount++;
       }
    }
    return PlayerCount;
}
//===========================================================================================
// MosterAdd 
//===========================================================================================
int MosterAdd( int MobID, int MapID, int CoordX, int CoordY )
{
    int mIndex = gObjAddMonsters();

	if(mIndex >= 0)
	{
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(mIndex);

		gObj->Class = MobID;
		gObj->MapNumber = MapID;
		gObj->X = CoordX;
		gObj->Y = CoordY; 
		gObjSetMonsters(mIndex, MobID);
	}   
	return mIndex;
}
//------------------------------------------------------------
// CHAR MAP JOIN - SEND [CREATE]
//------------------------------------------------------------
void Refresh(DWORD aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	PMSG_CHARMAPJOINRESULT lpMsg;
	lpMsg.h.c = 0xC3;
	lpMsg.h.headcode = 0xF3;
	lpMsg.h.size = sizeof(PMSG_CHARMAPJOINRESULT);
	lpMsg.subcode = 0x03;
	lpMsg.MapX = lpObj->X;
	lpMsg.MapY = lpObj->Y;
	lpMsg.MapNumber = lpObj->MapNumber;
	lpMsg.Dir = lpObj->Dir;
	lpMsg.Exp = lpObj->Experience;
	lpMsg.NextExp = lpObj->NextExp;
	lpMsg.LevelUpPoint = lpObj->LevelUpPoints;
	lpMsg.Str = lpObj->Strength;
	lpMsg.Dex = lpObj->Dexterity;
	lpMsg.Vit = lpObj->Vitality;
	lpMsg.Energy = lpObj->Energy;
	lpMsg.Money = lpObj->Money;
	lpMsg.PkLevel = lpObj->m_PK_Level;
	lpMsg.Life = (short)lpObj->Life;
	lpMsg.MaxLife = (short)((double)lpObj->AddLife + lpObj->MaxLife);
	lpMsg.Mana = (short)lpObj->Mana;
	lpMsg.MaxMana = (short)((double)lpObj->AddMana + lpObj->MaxMana);
	lpMsg.CtlCode = (short)lpObj->Authority;
	lpMsg.BP = lpObj->BP;
	lpMsg.MaxBP = lpObj->AddBP + lpObj->MaxBP;
	DataSend(aIndex, &lpMsg.h.c, (DWORD)lpMsg.h.size);

	//------------------------------------------------------------
	// CHAR REGEN - SEND [DESTROY]
	//------------------------------------------------------------
	PMSG_CHARREGEN pMsg; 
	pMsg.h.c = 0xC1;
	pMsg.h.headcode = 0xF3;
	pMsg.h.size = sizeof(PMSG_CHARREGEN);
	pMsg.subcode = 0x04;
	pMsg.Dir = lpObj->Dir;
	pMsg.MapX = LOBYTE(lpObj->X);
	pMsg.MapY = LOBYTE(lpObj->Y);
	pMsg.Life = (float)lpObj->Life;
	pMsg.Mana = (float)lpObj->Mana;
	pMsg.Exp = lpObj->Experience;
	pMsg.MapNumber = lpObj->MapNumber;
	pMsg.Money = lpObj->Money;
	pMsg.BP = LOWORD(lpObj->BP);
	lpObj->PathCount = 0;
	DataSend(aIndex, &pMsg.h.c, (DWORD)pMsg.h.size);

	gObjTeleport(aIndex,lpObj->MapNumber,lpObj->X,lpObj->Y);
	GCItemListSend(aIndex);
	GCMagicListMultiSend(lpObj);
	CGRequestQuestInfo(aIndex);
	DGGuildMemberInfoRequest(aIndex);
	gObjCalCharacter(aIndex);
}
//===========================================================================================
// DecodeProtocol
//===========================================================================================
bool DecodeProtocol(short aIndex, char *tpProtocol)
{
	int count = 0;
	for(int i=0; i < 8;i++)
	{
		if(tpProtocol[i] >= 'a' && tpProtocol[i] <= 'z' || tpProtocol[i] >= 'A' && tpProtocol[i] <= 'Z' || tpProtocol[i] >= '0' && tpProtocol[i] <= '9' || tpProtocol[i] == NULL)
		{
			return true;
		}
		else
		{
			count++;
		}
	}

	if(count > 0)
	{
		return false;
	}
	return true;
}

//===========================================================================================
//--  Function ItemSerialCreateSend Extra   
//===========================================================================================
void ItemSerialCreateSendEx(int aIndex, int MapNumber, int x, int y, int Type, int Level, int Dur, int Skill, int Luck, int Option,int LootIndex,int Excellent)
{

	int Buff = {0};

	if(MapNumber == 235 )
	{

	  for(int i = 12; i < 76; i++)
	  {
		  OBJECTSTRUCT *ItObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

		  if(ItObj->pInventory[i].m_Type == SLOT_EMPTY )
		  {
			   Buff++; 
		       if(Buff == 1) /* FIX MAX BUFFER OVER */
		       {
               ItObj->pInventory[i].m_Type      = Type; 
			   ItObj->pInventory[i].m_Level     = Level;
			   ItObj->pInventory[i].m_Option1   = Skill;
			   ItObj->pInventory[i].m_Option2   = Dur;
			   ItObj->pInventory[i].m_Option3   = Luck;
			   ItObj->pInventory[i].m_NewOption = Option;
			   ItObj->pInventory[i].m_SetOption = Excellent;
			   GCItemListSend(aIndex);
			   //Log
	           LogAddFuncColor(COLOR_GREEN,"[%s][%s] InventoryCreateSend: %d %d %d %d %d %d %d",ItObj->AccountID,ItObj->Name,Type,Level,Dur,Skill,Luck,Option,Excellent);
			   break;
		       } 
		  }
	  }
	
	}
	else
	{
	    ItemSerialCreateSend(aIndex,MapNumber,x,y,Type,Level,Dur,Skill,Luck,Option,aIndex,Excellent);  //Original Function 
	}

}

int GenExcOpt(int amount)
{
    // User input errors
    if (amount > 6) amount = 6;
    if (amount < 1) amount = 1;

    int opt_db[6]  = {1, 2, 4, 8, 16, 32};
    int exc = 0;

    std::random_shuffle(opt_db, opt_db + 6);

    for(int n=0; n < amount; n++)
    {
        exc += opt_db[n];
    }

    return exc;
}

int GetNumberByPercent(int Proc, int Min, int Max)
{
    int Random = rand()%100;

    if(Proc == 0 || Max == Min)
    {
        return Min;
    }

    if(Random <= Proc)
    {
        return Max;
    }
    if(Proc > 50)
    {
        return GetNumberByPercent(Proc/2, Min, Max-1);
    }
    else if(Proc < 30)
    {
        return GetNumberByPercent(Proc*3/2, Min, Max-1);
    }
    else
    {
        return GetNumberByPercent(Proc, Min, Max-1);
    }
}

bool IsBadFileLine(char *FileLine, int &Flag)
{
	if(Flag == 0)
	{
		if(isdigit(FileLine[0]))
		{
			Flag = FileLine[0] - 48;

			return true;
		}
	}
	else if(Flag < 0 || Flag > 9)
	{
		Flag = 0;
	}

	if(!strncmp(FileLine,"end", 3))
	{
		Flag = 0;

		return true;
	}

	if(FileLine[0] == '/' || FileLine[0] == '\n')
	{
		return true;
	}

	size_t lengthfile = strlen(FileLine);

	for(UINT i = 0; i < lengthfile; i++)
	{
		if(isalnum(FileLine[i]))
		{
			return false;
		}
	}

	return true;
}

//===========================================================================================
//-- GetInventoryItemCount
//===========================================================================================
int GetInventoryItemCount(int aIndex, int Type, int Level)
{
    OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

    int count = 0;
    for(unsigned i = 12; i < 76; i++)
    {
        if(gObj->pInventory[i].m_Type == Type)
        {
            if(Level != -1)
            {
                if(!gObj->pInventory[i].m_Level == Level)
                {
                    continue;
                }
            }
            count++;
        }
    }
    return count;
}

//===========================================================================================
//-- gObjDeleteItemsCount
//===========================================================================================
int gObjDeleteItemsCount(int gObjId, short Type, short Level, int Count)
{
	int count = 0;
	for(int i = 12; i < 76; i++)
	{
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);
		if(gObj->pInventory[i].m_Type == Type && gObj->pInventory[i].m_Level == Level)
		{
			gObjInventoryDeleteItem(gObjId, i);
			GCInventoryItemDeleteSend(gObjId, i, 1);
			count++;

			if(Count == count)
			break;
		}
	}
	return count;
}

BOOL GetBoxPosition(int MapNumber, int X, int Y, int W, int H, short& rX, short& rY)
{
	BOOL Result = FALSE;

	__asm
	{
		PUSH rY;
		PUSH rX;
		PUSH H;
		PUSH W;
		PUSH Y;
		PUSH X;
		PUSH MapNumber;
		MOV ECX, 0x6344538;
		MOV EDI, 0x40277F;
		CALL EDI;
		MOV Result, EAX;
	}

	return Result;
}

DWORD WriteMemory(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize)
{
    DWORD dwErrorCode   = 0;
    DWORD dwOldProtect  = 0;
	// ----
    int iRes = VirtualProtect(lpAddress, uSize, PAGE_EXECUTE_READWRITE, & dwOldProtect);
	// ----
    if( iRes == 0 )
    {
        dwErrorCode = GetLastError();
        return dwErrorCode;
    }
	// ----
    memcpy(lpAddress, lpBuf, uSize);
	// ----
    DWORD dwBytes   = 0;
	// ----
    iRes = VirtualProtect(lpAddress, uSize, dwOldProtect, & dwBytes);
	// ----
    if ( iRes == 0 )
    {
        dwErrorCode = GetLastError();
        return dwErrorCode;
    }
	// ----
    return 0x00;
}
//---------------------------------------------------------------------------

DWORD SetOp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress, const BYTE cmd)
{
	BYTE btBuf[5];
	DWORD dwShift	= (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 5;
	// ----
	btBuf[0]		= cmd;
	memcpy( (LPVOID) & btBuf[1], (LPVOID) & dwShift, sizeof(ULONG_PTR));
	// ----
	return WriteMemory(dwEnterFunction, (LPVOID) btBuf, sizeof(btBuf));
}
//---------------------------------------------------------------------------

DWORD SetRange(const LPVOID dwAddress, const USHORT wCount, const BYTE btValue)
{
	BYTE * lpBuf	= new BYTE[wCount];
	// ----
	memset(lpBuf, btValue, wCount);
	// ----
	return WriteMemory( dwAddress, (LPVOID) lpBuf, wCount);
}
//---------------------------------------------------------------------------