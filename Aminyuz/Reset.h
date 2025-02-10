#pragma once

struct Reset_Acumulativo
{
	int Level[2];
	int RemoveItems[2];
	int NextLevel;
	int Money[2];
};

struct Reset_Pontuativo
{
	int Level[2];
	int Money[2];
	int NextLevel;
	int RemoveItems[2];
	int NextFor;
	int NextAgi;
	int NextVit;
	int NextEne;
	int PointsAdd[4];
};

struct Reset_Settings
{
	int Switch;
	int Type;
	int ResetsMax;
	char ResetSintax[50];
	char RQuery1[100];
};

struct StructReset
{
	Reset_Acumulativo Acumulativo;
	Reset_Pontuativo Pontuativo;
	Reset_Settings Settings;
};

class GReset
{
public:
	static void InitReset(DWORD aIndex);
	static bool CheckItems(DWORD aIndex);
	static bool LoadSettings();
};

extern StructReset CReset;