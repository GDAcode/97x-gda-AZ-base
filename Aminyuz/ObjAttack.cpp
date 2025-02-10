#include "StdAfx.h"

void ReadygObjAttack()
{
   HookThis((DWORD)&gObjAttackEX,0x004026F3); 
}

bool gObjAttackEX(OBJECTSTRUCT* lpObj, OBJECTSTRUCT* lpTargetObj, void * lpMagic, BOOL magicsend, BYTE MSBFlag, int AttackDamage)
{
	if(lpObj->Type == OBJECT_USER && lpTargetObj->Type == OBJECT_USER)
	{
		short Type = lpObj->pInventory[EQUIPMENT_HELPER].m_Type;

	    if(!((Type >= ITEMGET(13,0) && Type <= ITEMGET(13, 3))))
	    {
		   GCInventoryItemDeleteSend(lpObj->m_Index, 8, 0);
	    }

	    //=========================================================
	    //-- Fix Pets Bug
	    //=========================================================
		/*if(lpObj->pInventory[EQUIPMENT_HELPER].m_Type == SLOT_EMPTY)
	    {
			GCItemListSend(lpObj->m_Index);  
	    }
		else
		{

		}*/
	}
	
	gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage);
	
	return false;
}