#ifndef SEGURIDAD_H
#define SEGURIDAD_H

struct SEGURIDAD
{
	int IsWarehouseHacker;
	int IsTradeHacker;
	int IsPaquetesHacker;
	int IsGuildMasterUnicode;
	int IsNickHacker;
	int IsChaosBoxHacker;
	int IsArmaHacker;
};
extern SEGURIDAD pSeguridad;

void Seguridad();
void SeguridadConfigs();

bool WarehouseHacker(int aIndex);
bool TradeHacker(int aIndex);
bool GuildMasterHacker(BYTE protoNum,LPBYTE aRecv,DWORD aLen,DWORD aIndex,DWORD Encrypt,int Serial);
bool CharacterCreate(PMSG_CHARCREATE* lpMsg, int aIndex);
bool ChaosBoxHacker(int aIndex);
bool ArmaHacker(int aIndex);

#endif