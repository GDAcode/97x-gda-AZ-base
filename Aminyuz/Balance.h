#ifndef BALANCE_H
#define BALANCE_H

struct BALANCE
{
	int Enabeld;

	int DW_AtackMinRight;
	int DW_AtackMaxRight;
	int DW_AtackMinLeft;
	int DW_AtackMaxLeft;
	int DW_AtackSpeed;
	int DW_MagicSpeed;
	int DW_SuccessfulBlocking;
	int DW_Defense;
	int DW_MagicDMGMin;
	int DW_MagicDMGMax;

	int DK_AtackMinRight;
	int DK_AtackMaxRight;
	int DK_AtackMinLeft;
	int DK_AtackMaxLeft;
	int DK_AtackSpeed;
	int DK_MagicSpeed;
	int DK_SuccessfulBlocking;
	int DK_Defense;
	int DK_MagicDMGMin;
	int DK_MagicDMGMax;

	int ELF_AtackMinRight_Bow;
	int ELF_AtackMaxRight_Bow;
	int ELF_AtackMinLeft_Bow;
	int ELF_AtackMaxLeft_Bow;
	int ELF_AtackMinRight_NoBow;
	int ELF_AtackMaxRight_NoBow;
	int ELF_AtackMinLeft_NoBow;
	int ELF_AtackMaxLeft_NoBow;
	int ELF_AtackSpeed;
	int ELF_MagicSpeed;
	int ELF_SuccessfulBlocking;
	int ELF_Defense;
	int ELF_MagicDMGMin;
	int ELF_MagicDMGMax;
	
	int MG_AtackStrMinRight;
	int MG_AtackStrMaxRight;
	int MG_AtackStrMinLeft;
	int MG_AtackStrMaxLeft;
	int MG_AtackEneMinRight;
	int MG_AtackEneMaxRight;
	int MG_AtackEneMinLeft;
	int MG_AtackEneMaxLeft;
	int MG_AtackSpeed;
	int MG_MagicSpeed;
	int MG_SuccessfulBlocking;
	int MG_Defense;
	int MG_MagicDMGMin;
	int MG_MagicDMGMax;

};
extern BALANCE pCalcharacter;

void Balance();
void BalanceFile();
void gObjCalCharacterEX(int aIndex);

#endif