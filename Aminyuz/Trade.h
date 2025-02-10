#pragma once

struct PMSG_TRADE_REQUEST
{
	PBMSG_HEAD h;
	unsigned char NumberH;
	unsigned char NumberL;
};

struct PMSG_TRADE_RESPONSE
{
	PBMSG_HEAD h;
	unsigned char Response;
	unsigned char Id[10];
	unsigned short Level;
	int GuildNumber;
};

void LoadTrade();
void GCTradeRequest(PMSG_TRADE_REQUEST* objMsg, DWORD aIndex);
void GCTradeResponse(PMSG_TRADE_RESPONSE* objMsg, DWORD aIndex);
void GCTradeCancel(DWORD aIndex);