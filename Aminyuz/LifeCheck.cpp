#include "StdAfx.h"

void ReadLifeCheck()
{
  HookThis((DWORD)&gObjLifeCheckHook,0x00402996);  
}

void gObjLifeCheckHook(OBJECTSTRUCT* mObj, OBJECTSTRUCT* pObj, int AttackDamage, int DamageSendType, int MSBFlag, int MSBDamage, BYTE Skill, int iShieldDamage)
{	
	// -------------------------------------
	// # Lord of Kundun
	// -------------------------------------
	if(eKundun.IsKundun != 0 )
	{
		if(mObj->Life <= 0 && mObj->Live != 0 )
		{
			if(mObj->Type == OBJECT_MONSTER && mObj->Class == 157)
			{
				DropitemBoss(pObj->m_Index);
			}
		}
	}
    gObjLifeCheck(mObj,pObj,AttackDamage,DamageSendType,MSBFlag,MSBDamage,Skill,iShieldDamage); 

}