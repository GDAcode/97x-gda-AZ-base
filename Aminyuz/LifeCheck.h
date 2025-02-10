#ifndef LIFECHECK_H
#define LIFECHECK_H

void ReadLifeCheck();
void gObjLifeCheckHook(OBJECTSTRUCT* mObj, OBJECTSTRUCT* pObj, int AttackDamage, int DamageSendType, int MSBFlag, int MSBDamage, BYTE Skill, int iShieldDamage);

#endif