#ifndef FIXES_H
#define FIXES_H

void Fixes();
void GCWarePassSend(int aIndex, PMSG_WAREHOUSEPASSSEND *lpMsg);
bool AntiShadow(OBJECTSTRUCT *gObj, int slotx, int sloty);

#endif