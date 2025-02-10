#include "StdAfx.h"

bool NPCTalkEx(LPOBJ gObj,int NpcId)
{
    bool bResult = false;

    if(OBJECT_MAXRANGE(NpcId) == FALSE)
	{
        return false;
	}

    if(OBJECT_MAXRANGE(gObj->m_Index) == FALSE)
	{
        return false;
	}

    OBJECTSTRUCT *gObjNPC = (OBJECTSTRUCT*)OBJECT_POINTER(NpcId);

	//====================================
	// NPC PKWarden
	//====================================
    if (gObjNPC->Class == pPKWarden.PKWardenID)
    {
		PKWardenClick(gObj, gObjNPC,gObj->m_Index);

		bResult = true;
    }

	//====================================
	// NPC ZenWarden
	//====================================
	if (gObjNPC->Class == pZenWarden.ZenWardenID)
    {
		ZenWardenClick(gObj, gObjNPC,gObj->m_Index);

		bResult = true;
    }
	
    return bResult;
}