#include "StdAfx.h"

BALANCE pCalcharacter;


void Balance()
{
     BalanceFile();
	 HookThis((DWORD)&gObjCalCharacterEX,0x004015AF);    
}

void BalanceFile()
{
    pCalcharacter.Enabeld = GetPrivateProfileIntA("Balance","CalCharater",0 ,Alpha_Balance);

	pCalcharacter.DW_AtackMinRight        = GetPrivateProfileIntA("MAGO","MinAtackStrRight",8,Alpha_Balance);
	pCalcharacter.DW_AtackMaxRight        = GetPrivateProfileIntA("MAGO","MaxAtackStrRight",4,Alpha_Balance);
	pCalcharacter.DW_AtackMinLeft         = GetPrivateProfileIntA("MAGO","MinAtackStrLeft",8,Alpha_Balance);
	pCalcharacter.DW_AtackMaxLeft         = GetPrivateProfileIntA("MAGO","MaxAtackStrLeft",4,Alpha_Balance);
    pCalcharacter.DW_AtackSpeed           = GetPrivateProfileIntA("MAGO","AtackSpeed",20,Alpha_Balance);
	pCalcharacter.DW_MagicSpeed           = GetPrivateProfileIntA("MAGO","MagicSpeed",10 ,Alpha_Balance);
	pCalcharacter.DW_SuccessfulBlocking   = GetPrivateProfileIntA("MAGO","SucessFullBlock",3,Alpha_Balance);
	pCalcharacter.DW_Defense              = GetPrivateProfileIntA("MAGO","Defense",4,Alpha_Balance);
	pCalcharacter.DW_MagicDMGMin          = GetPrivateProfileIntA("MAGO","MagicDmgMin",9,Alpha_Balance);
	pCalcharacter.DW_MagicDMGMax          = GetPrivateProfileIntA("MAGO","MagicDmgMax",4,Alpha_Balance);

	pCalcharacter.DK_AtackMinRight        = GetPrivateProfileIntA("GUERRERO","MinAtackStrRight",6,Alpha_Balance);
	pCalcharacter.DK_AtackMaxRight        = GetPrivateProfileIntA("GUERRERO","MaxAtackStrRight",4,Alpha_Balance);
	pCalcharacter.DK_AtackMinLeft         = GetPrivateProfileIntA("GUERRERO","MinAtackStrLeft",6,Alpha_Balance);
	pCalcharacter.DK_AtackMaxLeft         = GetPrivateProfileIntA("GUERRERO","MaxAtackStrLeft",4,Alpha_Balance);
	pCalcharacter.DK_AtackSpeed           = GetPrivateProfileIntA("GUERRERO","AtackSpeed",15 ,Alpha_Balance);
	pCalcharacter.DK_MagicSpeed           = GetPrivateProfileIntA("GUERRERO","MagicSpeed",20 ,Alpha_Balance);
	pCalcharacter.DK_SuccessfulBlocking   = GetPrivateProfileIntA("GUERRERO","SucessFullBlock",3,Alpha_Balance);
	pCalcharacter.DK_Defense              = GetPrivateProfileIntA("GUERRERO","Defense",3,Alpha_Balance);
	pCalcharacter.DK_MagicDMGMin          = GetPrivateProfileIntA("GUERRERO","MagicDmgMin",9,Alpha_Balance);
	pCalcharacter.DK_MagicDMGMax          = GetPrivateProfileIntA("GUERRERO","MagicDmgMax",4,Alpha_Balance);

	pCalcharacter.ELF_AtackMinRight_Bow   = GetPrivateProfileIntA("ELFA","MinStrRight_Bow",7,Alpha_Balance);
	pCalcharacter.ELF_AtackMaxRight_Bow   = GetPrivateProfileIntA("ELFA","MaxStrRight_Bow",4,Alpha_Balance);
	pCalcharacter.ELF_AtackMinLeft_Bow    = GetPrivateProfileIntA("ELFA","MinStrLeft_Bow",7,Alpha_Balance);
	pCalcharacter.ELF_AtackMaxLeft_Bow    = GetPrivateProfileIntA("ELFA","MaxStrLeft_Bow",4,Alpha_Balance);
	pCalcharacter.ELF_AtackMinRight_NoBow = GetPrivateProfileIntA("ELFA","MinStrRight_NoBow",14,Alpha_Balance);
	pCalcharacter.ELF_AtackMaxRight_NoBow = GetPrivateProfileIntA("ELFA","MaxStrRight_NoBow",8 ,Alpha_Balance);
	pCalcharacter.ELF_AtackMinLeft_NoBow  = GetPrivateProfileIntA("ELFA","MinStrLeft_NoBow",14,Alpha_Balance);
	pCalcharacter.ELF_AtackMaxLeft_NoBow  = GetPrivateProfileIntA("ELFA","MaxStrLeft_NoBow",8 ,Alpha_Balance);
	pCalcharacter.ELF_AtackSpeed          = GetPrivateProfileIntA("ELFA","AtackSpeed",50,Alpha_Balance);
	pCalcharacter.ELF_MagicSpeed          = GetPrivateProfileIntA("ELFA","MagicSpeed",50,Alpha_Balance);
	pCalcharacter.ELF_SuccessfulBlocking  = GetPrivateProfileIntA("ELFA","SucessFullBlock",4 ,Alpha_Balance);
	pCalcharacter.ELF_Defense             = GetPrivateProfileIntA("ELFA","Defense",10 ,Alpha_Balance);
	pCalcharacter.ELF_MagicDMGMin         = GetPrivateProfileIntA("ELFA","MagicDmgMin",9,Alpha_Balance);
	pCalcharacter.ELF_MagicDMGMax         = GetPrivateProfileIntA("ELFA","MagicDmgMax",4 ,Alpha_Balance);

	pCalcharacter.MG_AtackStrMinRight     = GetPrivateProfileIntA("GLADIADOR","MinAtackStrRight",6,Alpha_Balance);
	pCalcharacter.MG_AtackStrMaxRight     = GetPrivateProfileIntA("GLADIADOR","MaxAtackStrRight",4 ,Alpha_Balance);
	pCalcharacter.MG_AtackStrMinLeft      = GetPrivateProfileIntA("GLADIADOR","MinAtackStrLeft",6 ,Alpha_Balance);
	pCalcharacter.MG_AtackStrMaxLeft      = GetPrivateProfileIntA("GLADIADOR","MaxAtackStrLeft",4,Alpha_Balance);
	pCalcharacter.MG_AtackEneMinRight     = GetPrivateProfileIntA("GLADIADOR","MinAtackEneRight",12,Alpha_Balance);
	pCalcharacter.MG_AtackEneMaxRight     = GetPrivateProfileIntA("GLADIADOR","MaxAtackEneRight",8,Alpha_Balance);
	pCalcharacter.MG_AtackEneMinLeft      = GetPrivateProfileIntA("GLADIADOR","MinAtackEneLeft",12,Alpha_Balance);
	pCalcharacter.MG_AtackEneMaxLeft      = GetPrivateProfileIntA("GLADIADOR","MaxAtackEneLeft",8,Alpha_Balance);
	pCalcharacter.MG_AtackSpeed           = GetPrivateProfileIntA("GLADIADOR","AtackSpeed",15,Alpha_Balance);
	pCalcharacter.MG_MagicSpeed           = GetPrivateProfileIntA("GLADIADOR","MagicSpeed",20,Alpha_Balance);
	pCalcharacter.MG_SuccessfulBlocking   = GetPrivateProfileIntA("GLADIADOR","SucessFullBlock",3,Alpha_Balance);
	pCalcharacter.MG_Defense              = GetPrivateProfileIntA("GLADIADOR","Defense",4 ,Alpha_Balance);
	pCalcharacter.MG_MagicDMGMin          = GetPrivateProfileIntA("GLADIADOR","MagicDmgMin",9,Alpha_Balance);
	pCalcharacter.MG_MagicDMGMax          = GetPrivateProfileIntA("GLADIADOR","MagicDmgMax",4 ,Alpha_Balance);
}

void gObjCalCharacterEX(int aIndex)
{
	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);

    CItem * Right  = &lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT];
	CItem * Left   = &lpObj->pInventory[EQUIPMENT_WEAPON_LEFT];
	CItem * Helm   = &lpObj->pInventory[EQUIPMENT_HELM];
	CItem * Armor  = &lpObj->pInventory[EQUIPMENT_ARMOR];
	CItem * Pants  = &lpObj->pInventory[EQUIPMENT_PANTS];
	CItem * Gloves = &lpObj->pInventory[EQUIPMENT_GLOVES];
	CItem * Boots  = &lpObj->pInventory[EQUIPMENT_BOOTS];
	CItem * Wings  = &lpObj->pInventory[EQUIPMENT_WING];
	CItem * Helper = &lpObj->pInventory[EQUIPMENT_HELPER];

	CItem * Amulet = &lpObj->pInventory[EQUIPMENT_AMULET];
	CItem * Ring01 = &lpObj->pInventory[EQUIPMENT_RING_RIGHT];
	CItem * Ring02 = &lpObj->pInventory[EQUIPMENT_RING_LEFT];

    if( pCalcharacter.Enabeld != 0)
	{
	    if(!Right->IsItem() && !Left->IsItem())
		{
			lpObj->HaveWeaponInHand = FALSE;
		}
		else if(!Left->IsItem() && Right->m_Type == ITEMGET(4, 15))
		{
			lpObj->HaveWeaponInHand = FALSE;
		}
		else if(!Right->IsItem())
		{
			if(Left->m_Type == ITEMGET(4, 7))
			{
				lpObj->HaveWeaponInHand = FALSE;
			}
			else if((Left->m_Type / 32) == 6)
			{
				lpObj->HaveWeaponInHand = FALSE;
			}
		}

		lpObj->AddLife = 0;
		lpObj->AddMana = 0;
		lpObj->MonsterDieGetMoney = 0;
		lpObj->MonsterDieGetLife = 0;
		lpObj->MonsterDieGetMana = 0;
		lpObj->DamageReflect = 0;
		lpObj->DamageMinus = 0;


		switch(lpObj->Class)
		{
		case CLASS_WIZARD:
			{
				lpObj->m_AttackDamageMinRight = (lpObj->Strength / pCalcharacter.DW_AtackMinRight);
				lpObj->m_AttackDamageMaxRight = (lpObj->Strength / pCalcharacter.DW_AtackMaxRight);
				lpObj->m_AttackDamageMinLeft = (lpObj->Strength /  pCalcharacter.DW_AtackMinLeft);
				lpObj->m_AttackDamageMaxLeft = (lpObj->Strength /  pCalcharacter.DW_AtackMaxLeft);
			}
			break;
		case CLASS_KNIGHT:
			{
				lpObj->m_AttackDamageMinRight = (lpObj->Strength / pCalcharacter.DK_AtackMinRight);
				lpObj->m_AttackDamageMaxRight = (lpObj->Strength / pCalcharacter.DK_AtackMaxRight);
				lpObj->m_AttackDamageMinLeft = (lpObj->Strength /  pCalcharacter.DK_AtackMinLeft);
				lpObj->m_AttackDamageMaxLeft = (lpObj->Strength /  pCalcharacter.DK_AtackMaxLeft);
			}
			break;
		case CLASS_ELF:
			{
				if((Right->m_Type >= ITEMGET(4,8) && Right->m_Type < ITEMGET(4,15) ) || (Left->m_Type >= ITEMGET(4,0) && Left->m_Type < ITEMGET(4,7))   ||
			         Right->m_Type == ITEMGET(4,16) || Left->m_Type == ITEMGET(4,20) ||  Left->m_Type == ITEMGET(4,21) || Right->m_Type == ITEMGET(4,18)||
			         Right->m_Type == ITEMGET(4,19) ||  Left->m_Type == ITEMGET(4,17))
				{
				lpObj->m_AttackDamageMinRight = (lpObj->Dexterity / pCalcharacter.ELF_AtackMinRight_NoBow) + (lpObj->Strength / pCalcharacter.ELF_AtackMinRight_Bow);
				lpObj->m_AttackDamageMaxRight = (lpObj->Dexterity / pCalcharacter.ELF_AtackMaxRight_NoBow) + (lpObj->Strength / pCalcharacter.ELF_AtackMaxRight_Bow );
				lpObj->m_AttackDamageMinLeft = (lpObj->Dexterity /  pCalcharacter.ELF_AtackMinLeft_NoBow) + (lpObj->Strength /  pCalcharacter.ELF_AtackMinLeft_Bow);
				lpObj->m_AttackDamageMaxLeft = (lpObj->Dexterity /  pCalcharacter.ELF_AtackMaxLeft_NoBow) + (lpObj->Strength /  pCalcharacter.ELF_AtackMaxLeft_Bow );
				}
				else
		        {
			    lpObj->m_AttackDamageMinRight = (lpObj->Dexterity + lpObj->Strength) / pCalcharacter.ELF_AtackMinRight_NoBow;
			    lpObj->m_AttackDamageMaxRight = (lpObj->Dexterity + lpObj->Strength) / pCalcharacter.ELF_AtackMaxRight_NoBow;
			    lpObj->m_AttackDamageMinLeft = (lpObj->Dexterity + lpObj->Strength) /  pCalcharacter.ELF_AtackMinLeft_NoBow;
			    lpObj->m_AttackDamageMaxLeft = (lpObj->Dexterity + lpObj->Strength) /  pCalcharacter.ELF_AtackMaxLeft_NoBow;
		        }
			}
			break;
		case CLASS_MAGUMSA:
			{
				lpObj->m_AttackDamageMinRight = (lpObj->Strength / pCalcharacter.MG_AtackStrMinRight) + (lpObj->Energy / pCalcharacter.MG_AtackEneMinRight);
				lpObj->m_AttackDamageMaxRight = (lpObj->Strength / pCalcharacter.MG_AtackStrMaxRight) + (lpObj->Energy / pCalcharacter.MG_AtackEneMaxRight);
				lpObj->m_AttackDamageMinLeft = (lpObj->Strength /  pCalcharacter.MG_AtackStrMinLeft) + (lpObj->Energy / pCalcharacter.MG_AtackEneMinLeft);
				lpObj->m_AttackDamageMaxLeft = (lpObj->Strength /  pCalcharacter.MG_AtackStrMaxLeft) + (lpObj->Energy / pCalcharacter.MG_AtackEneMaxLeft);
			}
			break;
		}

		lpObj->pInventory[EQUIPMENT_WING].PlusSpecial(&lpObj->m_AttackDamageMinRight, 80);
		lpObj->pInventory[EQUIPMENT_WING].PlusSpecial(&lpObj->m_AttackDamageMaxRight, 80);
		lpObj->pInventory[EQUIPMENT_WING].PlusSpecial(&lpObj->m_AttackDamageMinLeft, 80);
		lpObj->pInventory[EQUIPMENT_WING].PlusSpecial(&lpObj->m_AttackDamageMaxLeft, 80);
		
		if(Right->IsItem())
		{
			if(Right->m_Type >= ITEMGET(5, 0) && Right->m_Type <= ITEMGET(6, 0))
			{
				lpObj->m_AttackDamageMinRight += Right->m_DamageMin / 2;
				lpObj->m_AttackDamageMaxRight += Right->m_DamageMax / 2;
			}
			else
			{
				lpObj->m_AttackDamageMinRight += Right->m_DamageMin;
				lpObj->m_AttackDamageMaxRight += Right->m_DamageMax;
			}

			lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT].PlusSpecial(&lpObj->m_AttackDamageMinRight, 80);
			lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT].PlusSpecial(&lpObj->m_AttackDamageMaxRight, 80);
		}
		
		if(Left->IsItem())
		{
			lpObj->m_AttackDamageMinLeft += Left->m_DamageMin;
			lpObj->m_AttackDamageMaxLeft += Left->m_DamageMax;

			lpObj->pInventory[EQUIPMENT_WEAPON_LEFT].PlusSpecial(&lpObj->m_AttackDamageMinLeft, 80);
			lpObj->pInventory[EQUIPMENT_WEAPON_LEFT].PlusSpecial(&lpObj->m_AttackDamageMaxLeft, 80);
		}

		lpObj->m_CriticalDamage = 0;
		lpObj->m_ExcelentDamage = 0;
		lpObj->m_MagicDamageMin = lpObj->Energy / 9;
		lpObj->m_MagicDamageMax = lpObj->Energy / 4;

		lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT].PlusSpecial(&lpObj->m_CriticalDamage, 84);
		lpObj->pInventory[EQUIPMENT_WEAPON_LEFT].PlusSpecial(&lpObj->m_CriticalDamage, 84);
		lpObj->pInventory[EQUIPMENT_HELM].PlusSpecial(&lpObj->m_CriticalDamage, 84);
		lpObj->pInventory[EQUIPMENT_ARMOR].PlusSpecial(&lpObj->m_CriticalDamage, 84);
		lpObj->pInventory[EQUIPMENT_PANTS].PlusSpecial(&lpObj->m_CriticalDamage, 84);
		lpObj->pInventory[EQUIPMENT_GLOVES].PlusSpecial(&lpObj->m_CriticalDamage, 84);
		lpObj->pInventory[EQUIPMENT_BOOTS].PlusSpecial(&lpObj->m_CriticalDamage, 84);
		lpObj->pInventory[EQUIPMENT_WING].PlusSpecial(&lpObj->m_CriticalDamage, 84);
		lpObj->pInventory[EQUIPMENT_WING].PlusSpecial(&lpObj->m_MagicDamageMin, 81);
		lpObj->pInventory[EQUIPMENT_WING].PlusSpecial(&lpObj->m_MagicDamageMax, 81);

		//------------------------------------------------------------------------
		// Magic Damage
	    //------------------------------------------------------------------------
		switch(lpObj->Class)
		{
		case CLASS_WIZARD:
			{
			lpObj->m_MagicDamageMin = lpObj->Energy/pCalcharacter.DW_MagicDMGMin;
	        lpObj->m_MagicDamageMax = lpObj->Energy/pCalcharacter.DW_MagicDMGMax;   	
			}break;
		case CLASS_KNIGHT:
			{
			lpObj->m_MagicDamageMin = lpObj->Energy/pCalcharacter.DK_MagicDMGMin;
	        lpObj->m_MagicDamageMax = lpObj->Energy/pCalcharacter.DK_MagicDMGMax;	
			}break;
		case CLASS_ELF:
			{
			lpObj->m_MagicDamageMin = lpObj->Energy/pCalcharacter.ELF_MagicDMGMin;
	        lpObj->m_MagicDamageMax = lpObj->Energy/pCalcharacter.ELF_MagicDMGMax;	
			}break;
		case CLASS_MAGUMSA:
			{
			lpObj->m_MagicDamageMin = lpObj->Energy/pCalcharacter.MG_MagicDMGMin;
	        lpObj->m_MagicDamageMax = lpObj->Energy/pCalcharacter.MG_MagicDMGMax;	
			}break;
		}
		if(Right->IsItem())
		{
			if(lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT].m_Type == ITEMGET(0, 31) || lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT].m_Type == ITEMGET(0, 21) || 
			   lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT].m_Type == ITEMGET(0, 23) || lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT].m_Type == ITEMGET(0, 25))
			{
				lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT].PlusSpecial(&lpObj->m_MagicDamageMin, 80);
				lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT].PlusSpecial(&lpObj->m_MagicDamageMax, 80);
			}
			else
			{
				lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT].PlusSpecial(&lpObj->m_MagicDamageMin, 81);
				lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT].PlusSpecial(&lpObj->m_MagicDamageMax, 81);
			}
		}

		lpObj->m_AttackRating = (lpObj->Strength + lpObj->Dexterity) / 2;
		lpObj->m_AttackRating += lpObj->pInventory[5].ItemDefense();

		switch(lpObj->Class)
		{
		case CLASS_WIZARD:
			{
				lpObj->m_AttackSpeed = lpObj->Dexterity / pCalcharacter.DW_AtackSpeed;
				lpObj->m_MagicSpeed = lpObj->Dexterity /  pCalcharacter.DW_MagicSpeed;
			}break;
		case CLASS_KNIGHT:
			{
				lpObj->m_AttackSpeed = lpObj->Dexterity / pCalcharacter.DK_AtackSpeed;
				lpObj->m_MagicSpeed = lpObj->Dexterity / pCalcharacter.DK_MagicSpeed;
			}break;
		case CLASS_ELF:
			{
				lpObj->m_AttackSpeed = lpObj->Dexterity / pCalcharacter.ELF_AtackSpeed;
				lpObj->m_MagicSpeed = lpObj->Dexterity / pCalcharacter.ELF_MagicSpeed;	
			}break;
		case CLASS_MAGUMSA:
			{
				lpObj->m_AttackSpeed = lpObj->Dexterity / pCalcharacter.MG_AtackSpeed;
				lpObj->m_MagicSpeed = lpObj->Dexterity / pCalcharacter.MG_MagicSpeed;	
			}break;
		}

		bool RightBoolean = false, LeftBoolean = false;

		if(Right->m_Type != ITEMGET(4, 7) && Right->m_Type != ITEMGET(4, 15) && Right->m_Type >= ITEMGET(0, 0) && Right->m_Type < ITEMGET(6, 0))
		{
			if(Right->IsItem())
			{
				RightBoolean = true;
			}
		}

		if(Left->m_Type != ITEMGET(4, 7) && Left->m_Type != ITEMGET(4, 15) && Left->m_Type >= ITEMGET(0, 0) && Left->m_Type < ITEMGET(6, 0))
		{
			if(Left->IsItem())
			{
				LeftBoolean = true;
			}
		}

		if(RightBoolean && LeftBoolean)
		{
			lpObj->m_AttackSpeed += (Right->m_AttackSpeed + Left->m_AttackSpeed) / 2;
			lpObj->m_MagicSpeed += (Right->m_AttackSpeed + Left->m_AttackSpeed) / 2;
		}
		else if(RightBoolean)
		{
			lpObj->m_AttackSpeed += Right->m_AttackSpeed;
			lpObj->m_MagicSpeed += Right->m_AttackSpeed;
		}
		else if(LeftBoolean)
		{
			lpObj->m_AttackSpeed += Left->m_AttackSpeed;
			lpObj->m_MagicSpeed += Left->m_AttackSpeed;
		}

		if(Gloves->IsItem())
		{
			lpObj->m_AttackSpeed += Gloves->m_AttackSpeed;
			lpObj->m_MagicSpeed += Gloves->m_AttackSpeed;
		}

		if(Helper->IsItem())
		{
			lpObj->m_AttackSpeed += Helper->m_AttackSpeed;
			lpObj->m_MagicSpeed += Helper->m_AttackSpeed;
		}

		if(Amulet->IsItem())
		{
			lpObj->m_AttackSpeed += Amulet->m_AttackSpeed;
			lpObj->m_MagicSpeed += Amulet->m_AttackSpeed;
		}

		DWORD dwAttackSpeed   = *(DWORD*)(ServerAttackSpeed);
		int szMinimumSpeed    = *(int*)(ServerMinimumSpeed);
		float szDecTimeAttack = *(float*)(ServerDecTimeSpeed);

		if(lpObj->Class == CLASS_WIZARD)
		{
			lpObj->m_DetectSpeedHackTime = (int)(dwAttackSpeed - ((lpObj->m_MagicSpeed * 2) * szDecTimeAttack));
		}
		else
		{
			lpObj->m_DetectSpeedHackTime = (int)(dwAttackSpeed - (lpObj->m_AttackSpeed * szDecTimeAttack));
		}

		if(lpObj->m_DetectSpeedHackTime < szMinimumSpeed)
		{
			lpObj->m_DetectSpeedHackTime = szMinimumSpeed;
		}
		
		switch(lpObj->Class)
		{
		case CLASS_WIZARD:
			{
				lpObj->m_SuccessfulBlocking = lpObj->Dexterity / pCalcharacter.DW_SuccessfulBlocking;
			}break;
		case CLASS_KNIGHT:
			{
				lpObj->m_SuccessfulBlocking = lpObj->Dexterity / pCalcharacter.DK_SuccessfulBlocking;
			}break;
		case CLASS_ELF:
			{
				lpObj->m_SuccessfulBlocking = lpObj->Dexterity / pCalcharacter.ELF_SuccessfulBlocking;
			}break;
		case CLASS_MAGUMSA:
			{
				lpObj->m_SuccessfulBlocking = lpObj->Dexterity / pCalcharacter.MG_SuccessfulBlocking;
			}break;
		}

		if(Left->IsItem())
		{
			lpObj->m_SuccessfulBlocking += Left->m_SuccessfulBlocking;
			lpObj->pInventory[EQUIPMENT_WEAPON_RIGHT].PlusSpecial(&lpObj->m_SuccessfulBlocking, 82);
		}

		bool Success = true;

		switch(lpObj->Class)
		{
		case 3:
			{
				for(int i = 3; i <= 6; i++)
				{
					if(!lpObj->pInventory[i].IsItem())
					{
						Success = false;
						break;
					}
				}
			}break;
		default:
			{
				for(int i = 2; i <= 6; i++)
				{
					if(!lpObj->pInventory[i].IsItem())
					{
						Success = false;
						break;
					}
				}
			}break;
		}

	    int Level11Count = 0; // Fix Itens + 10
	    int Level10Count = 0; // Fix Itens + 11
	    int Level12Count = 0; // Fix Itens + 12
	    int Level13Count = 0; // Fix Itens + 13
	    int Level14Count = 0; // Fix Itens + 14
	    int Level15Count = 0; // Fix Itens + 15

		if ( Success != false )
	       {
		   int in;
		     if ( lpObj->Class == CLASS_MAGUMSA ) // Magic Gladiator (No Helmet)
				{
					in = lpObj->pInventory[EQUIPMENT_ARMOR].m_Type % 32;

					if(in != ITEMGET(0, 15) && in != ITEMGET(0, 20) && in != ITEMGET(0, 23) && in != ITEMGET(0, 33) && in != ITEMGET(0, 32) && in != ITEMGET(0, 37))
					{
						Success = false;
					}
					else
			        {
				    Level15Count++;

				    for (int m=3;m<=6;m++)
				    {
					if ( in != ( lpObj->pInventory[m].m_Type % 32) )
					{
						Success = false;
					}
					if ( lpObj->pInventory[m].m_Level > 14 )
					{
						Level15Count++;
					}
					else if ( lpObj->pInventory[m].m_Level > 13 )
					{
						Level14Count++;
					}
					else if ( lpObj->pInventory[m].m_Level > 12 )
					{
						Level13Count++;
					}
					else if ( lpObj->pInventory[m].m_Level > 11 )
					{
						Level12Count++;
					}
					else if ( lpObj->pInventory[m].m_Level > 10 )
					{
						Level11Count++;
					}
					else if ( lpObj->pInventory[m].m_Level > 9 )
					{
						Level10Count++;
					}
				}
			}
		}
		else // Dark Knight, Dark Wizard, Elf, (All Set)
		{
			in = lpObj->pInventory[2].m_Type % 32;

			for (int m=2;m<=6;m++)
			{
				if ( in !=  ( lpObj->pInventory[m].m_Type % 32) )
				{
					Success = false;
				}
				if ( lpObj->pInventory[m].m_Level > 14 )   // Fix Itens + 15
				{
					Level15Count++;
				}
				else if ( lpObj->pInventory[m].m_Level > 13 )
				{
					Level14Count++;
				}
				else if ( lpObj->pInventory[m].m_Level > 12 )
				{
					Level13Count++;
				}
				else if ( lpObj->pInventory[m].m_Level > 11 )
				{
					Level12Count++;
				}
				else if ( lpObj->pInventory[m].m_Level > 10 )
				{
					Level11Count++;
				}
				else if ( lpObj->pInventory[m].m_Level > 9 )
				{
					Level10Count++;
				}
			    }
		        }
		     if ( Success != false )
		        {
			     lpObj->m_SuccessfulBlocking += lpObj->m_SuccessfulBlocking / 10;
		        }
	            }  

		switch(lpObj->Class)
		{
		case CLASS_WIZARD:
			{
				lpObj->m_Defense = lpObj->Dexterity / pCalcharacter.DW_Defense;
			}break;
		case CLASS_KNIGHT:
			{
				lpObj->m_Defense = lpObj->Dexterity /  pCalcharacter.DK_Defense;
			}break;
		case CLASS_ELF:
			{
				lpObj->m_Defense = lpObj->Dexterity / pCalcharacter.ELF_Defense;
			}break;
		case CLASS_MAGUMSA:
			{
				lpObj->m_Defense = lpObj->Dexterity /  pCalcharacter.MG_Defense;
			}break;
		}
		
		lpObj->m_Defense += lpObj->pInventory[EQUIPMENT_HELM].ItemDefense();
		lpObj->m_Defense += lpObj->pInventory[EQUIPMENT_ARMOR].ItemDefense();
		lpObj->m_Defense += lpObj->pInventory[EQUIPMENT_PANTS].ItemDefense();
		lpObj->m_Defense += lpObj->pInventory[EQUIPMENT_GLOVES].ItemDefense();
		lpObj->m_Defense += lpObj->pInventory[EQUIPMENT_BOOTS].ItemDefense();
		lpObj->m_Defense += lpObj->pInventory[EQUIPMENT_WEAPON_LEFT].ItemDefense();
		lpObj->m_Defense += lpObj->pInventory[EQUIPMENT_WING].ItemDefense();
		
		if ( (Level15Count + Level14Count + Level13Count + Level12Count + Level11Count + Level10Count) >= 5 )  
	    {
		if ( Success != false )
		{
			if ( Level15Count == 5 )
			{
				lpObj->m_Defense += lpObj->m_Defense * 30 / 100;               
			}
			else if ( Level14Count == 5 || (Level14Count + Level15Count) == 5 )
			{
				lpObj->m_Defense += lpObj->m_Defense * 25 / 100;              
			}
			else if ( Level13Count == 5 || (Level13Count + Level14Count + Level15Count) == 5 )
			{
				lpObj->m_Defense += lpObj->m_Defense * 20 / 100;
			}
			else if ( Level12Count == 5 || (Level12Count + Level13Count + Level14Count + Level15Count) == 5 )
			{
				lpObj->m_Defense += lpObj->m_Defense * 15 / 100;
			}
			else if ( Level11Count == 5 || (Level11Count + Level12Count + Level13Count + Level14Count + Level15Count) == 5 )
			{
				lpObj->m_Defense += lpObj->m_Defense * 10 / 100;
			}
			else if ( Level10Count == 5 || (Level10Count + Level11Count + Level12Count + Level13Count + Level14Count + Level15Count) == 5)
			{
				lpObj->m_Defense += lpObj->m_Defense * 5 / 100;
			}
		 }
	   }
       
		lpObj->m_Defense = (lpObj->m_Defense * 10) / 20;

		//----------------------------------------------
		// Guardian Angel
		//----------------------------------------------
		if(lpObj->pInventory[EQUIPMENT_HELPER].m_Type == ITEMGET(13, 0))
		{
			// Maximo de vida aumentada +50
			lpObj->AddLife += 50;

			// Absorbe 20% de daño
			lpObj->m_Defense += lpObj->m_Defense * (20 / 100);
		}
		//----------------------------------------------
		// Satan
		//----------------------------------------------
		if(lpObj->pInventory[EQUIPMENT_HELPER].m_Type == ITEMGET(13, 1))
		{
			// Aumenta 30% los ataques
			lpObj->m_AttackDamageMinRight += lpObj->m_AttackDamageMinRight * 30 / 100;
			lpObj->m_AttackDamageMaxRight += lpObj->m_AttackDamageMaxRight * 30 / 100;
			lpObj->m_AttackDamageMinLeft += lpObj->m_AttackDamageMinLeft * 30 / 100;
			lpObj->m_AttackDamageMaxLeft += lpObj->m_AttackDamageMaxLeft * 30 / 100;

			// Aumenta 30% los ataques magicos
			lpObj->m_MagicDamageMin += lpObj->m_MagicDamageMin * 30 / 100;
			lpObj->m_MagicDamageMax += lpObj->m_MagicDamageMax * 30 / 100;
		}

		int AddLife = 0;
	    int AddMana = 0;

		if(lpObj->pInventory[EQUIPMENT_WING].m_Type >= ITEMGET(12, 0) && lpObj->pInventory[EQUIPMENT_WING].m_Type <= ITEMGET(12, 6) || lpObj->pInventory[EQUIPMENT_WING].m_Type == ITEMGET(13, 30))
		{
			lpObj->pInventory[EQUIPMENT_WING].PlusSpecial(&AddLife, 100);
			lpObj->pInventory[EQUIPMENT_WING].PlusSpecial(&AddMana, 101);
			lpObj->AddLife += AddLife;
			lpObj->AddMana += AddMana;
		}

		if(lpObj->pInventory[EQUIPMENT_HELPER].m_Type == ITEMGET(13, 3))
		{
			lpObj->pInventory[EQUIPMENT_HELPER].PlusSpecial(&lpObj->AddBP, 103);
		}

		lpObj->pInventory[EQUIPMENT_AMULET].PlusSpecialPercentEx(&lpObj->AddBP, lpObj->MaxBP, 173);
		lpObj->pInventory[EQUIPMENT_RING_RIGHT].PlusSpecialPercentEx((int*)&lpObj->AddMana, (int)lpObj->MaxMana, 172);
		lpObj->pInventory[EQUIPMENT_RING_LEFT].PlusSpecialPercentEx((int*)&lpObj->AddMana, (int)lpObj->MaxMana, 172);

		CItem * rItem[3];
	    int comparecount = 0;
	
	    rItem[0] = &lpObj->pInventory[EQUIPMENT_RING_RIGHT];
	    rItem[1] = &lpObj->pInventory[EQUIPMENT_RING_LEFT];
	    rItem[2] = &lpObj->pInventory[EQUIPMENT_AMULET];

	    #define GET_MAX_RESISTANCE(x,y,z) ( ( ( ( (x) > (y) ) ? (x) : (y) ) > (z) ) ? ( ( (x) > (y) ) ? (x) : (y) ) : (z) )	

	    lpObj->m_Resistance[1] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[1], rItem[1]->m_Resistance[1], rItem[2]->m_Resistance[1]);
	    lpObj->m_Resistance[0] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[0], rItem[1]->m_Resistance[0], rItem[2]->m_Resistance[0]);
	    lpObj->m_Resistance[2] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[2], rItem[1]->m_Resistance[2], rItem[2]->m_Resistance[2]);
	    lpObj->m_Resistance[3] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[3], rItem[1]->m_Resistance[3], rItem[2]->m_Resistance[3]);
	    lpObj->m_Resistance[4] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[4], rItem[1]->m_Resistance[4], rItem[2]->m_Resistance[4]);
	    lpObj->m_Resistance[5] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[5], rItem[1]->m_Resistance[5], rItem[2]->m_Resistance[5]);
	    lpObj->m_Resistance[6] = GET_MAX_RESISTANCE(rItem[0]->m_Resistance[6], rItem[1]->m_Resistance[6], rItem[2]->m_Resistance[6]);

		GObjExtItemApply(lpObj);  
        gObjSetItemApply(lpObj);  
	    gObjNextExpCal(lpObj);      

		if(Left->m_Type >= ITEMGET(4, 0) && Left->m_Type < ITEMGET(4, 7) || Left->m_Type == ITEMGET(4, 17) || Left->m_Type == ITEMGET(4, 20) || Left->m_Type == ITEMGET(4, 21) || Left->m_Type == ITEMGET(4, 22))
		{
			if(Right->m_Type == ITEMGET(4, 15) && Right->m_Level == 1)
			{
				lpObj->m_AttackDamageMinLeft += (WORD)((lpObj->m_AttackDamageMinLeft * 0.03f) + 1.0f);
				lpObj->m_AttackDamageMaxLeft += (WORD)((lpObj->m_AttackDamageMaxLeft * 0.03f) + 1.0f);
			}
			else if(Right->m_Type == ITEMGET(4, 15) && Right->m_Level == 2)
			{
				lpObj->m_AttackDamageMinLeft += (WORD)((lpObj->m_AttackDamageMinLeft * 0.05f) + 1.0f);
				lpObj->m_AttackDamageMaxLeft += (WORD)((lpObj->m_AttackDamageMaxLeft * 0.05f) + 1.0f);
			}
		}
		else if(Right->m_Type >= ITEMGET(4, 8) && Right->m_Type < ITEMGET(4, 15) || Right->m_Type >= ITEMGET(4, 16) && Right->m_Type < ITEMGET(5, 0))
		{
			if(Left->m_Type == ITEMGET(4, 7) && Left->m_Level == 1)
			{
				lpObj->m_AttackDamageMinRight += (WORD)((lpObj->m_AttackDamageMinRight * 0.03f) + 1.0f);
				lpObj->m_AttackDamageMaxRight += (WORD)((lpObj->m_AttackDamageMaxRight * 0.03f) + 1.0f);
			}
			else if(Left->m_Type == ITEMGET(4, 7) && Left->m_Level == 2)
			{
				lpObj->m_AttackDamageMinRight += (WORD)((lpObj->m_AttackDamageMinRight * 0.05f) + 1.0f);
				lpObj->m_AttackDamageMaxRight += (WORD)((lpObj->m_AttackDamageMaxRight * 0.05f) + 1.0f);
			}
		}

	     GCReFillSend(aIndex,(WORD)lpObj->MaxLife + lpObj->AddLife,0xFE,0);  
	     gObjSetBP(aIndex);
	     GCManaSend(aIndex,(short)lpObj->MaxMana + lpObj->AddMana,0xFE,0,lpObj->MaxBP + lpObj->AddBP);
       }
	   else
	   {
		    gObjCalCharacter(aIndex);  // gObjCalCharacter Funcion Original  
       }
	   CodigoMain(aIndex);
}