#ifndef CGUSEITEMRECV_H
#define CGUSEITEMRECV_H


struct CGUSEITEMRECV
{
	int DelaySwitch; 
	int PotionDelay;
};

extern CGUSEITEMRECV  pCGUseItemRecv;

void ReadyCGUseItemRecv();
void CGUseItemConfigs();
#define GS_GOBJPOINTER(aIndex)((aIndex * OBJECT_SIZE) + OBJECT_BASE)
void CGUseItemRecvEx(PMSG_USEITEM* lpMsg,int aIndex);

#endif