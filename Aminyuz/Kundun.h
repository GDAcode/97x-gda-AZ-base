#ifndef KUNDUN_H
#define KUNDUN_H

struct KUNDUN
{
	int IsKundun;
	int Start_Time;
	int Duration_Time;

	int Mapa1;
	char Anuncio1[200];

	int Mapa2;
	char Anuncio2[200];

	int Mapa3;
	char Anuncio3[200];

	int Mapa4;
	char Anuncio4[200];

	int Mapa5;
	char Anuncio5[200];

	int Count;

	struct
	{
		int Index;
		int Type;
		int RateItem;
		int MinLevel;
		int MaxLevel;
		int RateLevel;
		int Skill;
		int RateSkill;
		int Luck;
		int RateLuck;
		int MinOpt;
		int MaxOpt;
		int RateOpt;
		int MinExl;
		int MaxExl;
		int RateExl;

	}Itema[255];
};

extern KUNDUN eKundun;

void ReadKundun();
void Kundun(void * lpParam);
void KundunConfigs();
void Kundun_DisappearMonster();
void DropitemBoss(int aIndex);

#endif