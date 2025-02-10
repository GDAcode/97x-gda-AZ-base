#ifndef FUNCIONES_H
#define FUNCIONES_H

void HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset );
void MsgOutput(DWORD aIndex,char *szMsg ...);
void StringSendAll( char*Text, int type );
void SetNop(DWORD dwOffset, int Size );
void SetNop2(DWORD dwOffset, int Size );
int GetPlayerIndex(char *Name );
int GetPlayerCount();
int GetGMCount();
int MosterAdd(int MobID, int MapID, int CoordX, int CoordY );
void Refresh(DWORD aIndex);
bool DecodeProtocol(short aIndex, char *tpProtocol);

void ItemSerialCreateSendEx(int aIndex, int MapNumber, int x, int y, int Type, int Level, int Dur, int Skill, int Luck, int Option,int LootIndex,int Excellent);

int GenExcOpt(int amount);
int GetNumberByPercent(int Proc, int Min, int Max);
bool IsBadFileLine(char *FileLine, int &Flag);
int GetInventoryItemCount(int aIndex, int Type, int Level);
int gObjDeleteItemsCount(int gObjId, short Type, short Level, int Count);

BOOL GetBoxPosition(int MapNumber, int X, int Y, int W, int H, short& rX, short& rY);

DWORD WriteMemory(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize);
DWORD SetOp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress, BYTE cmd);
DWORD SetRange(const LPVOID dwAddress, const USHORT wCount, const BYTE btValue);

#endif