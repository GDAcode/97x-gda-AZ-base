#include "StdAfx.h"

KUNDUN eKundun;

void ReadKundun()
{   
	KundunConfigs();
	if(eKundun.IsKundun != 0 )
	{
		_beginthread(Kundun,0,NULL);
	}
}

void KundunConfigs()
{
	eKundun.IsKundun        = GetPrivateProfileInt("GENERAL","Switch",1,Aminyuz_Kundun);
	eKundun.Start_Time      = GetPrivateProfileInt("GENERAL","Inicio",2,Aminyuz_Kundun)* 60000;
	eKundun.Duration_Time   = GetPrivateProfileInt("GENERAL","Duracion",10,Aminyuz_Kundun)* 60000;

	eKundun.Mapa1           = GetPrivateProfileInt("Mapas","Mapa1",0,Aminyuz_Kundun);
    GetPrivateProfileStringA("Mapas","Anuncio1","[ Las Fuerzas de Kundun Invaden Lorencia ]",eKundun.Anuncio1,200,Aminyuz_Kundun);

	eKundun.Mapa2           = GetPrivateProfileInt("Mapas","Mapa2",2,Aminyuz_Kundun);    
    GetPrivateProfileStringA("Mapas","Anuncio2","[ Las Fuerzas de Kundun Invaden Davias ]",eKundun.Anuncio2,200,Aminyuz_Kundun);

	eKundun.Mapa3           = GetPrivateProfileInt("Mapas","Mapa3",3,Aminyuz_Kundun);    
    GetPrivateProfileStringA("Mapas","Anuncio3","[ Las Fuerzas de Kundun Invaden Noria ]",eKundun.Anuncio3,200,Aminyuz_Kundun);
	
	eKundun.Mapa4           = GetPrivateProfileInt("Mapas","Mapa4",24,Aminyuz_Kundun);    
    GetPrivateProfileStringA("Mapas","Anuncio4","[ Las Fuerzas de Kundun Invaden Kanturu ]",eKundun.Anuncio4,200,Aminyuz_Kundun);
	
	eKundun.Mapa5           = GetPrivateProfileInt("Mapas","Mapa5",5,Aminyuz_Kundun);    
    GetPrivateProfileStringA("Mapas","Anuncio5","[ Las Fuerzas de Kundun Invaden Land of Trials ]",eKundun.Anuncio5,200,Aminyuz_Kundun);

for(int i(0);i < 255; i++)
	{
		eKundun.Itema[i].Index      = 0;
		eKundun.Itema[i].Type       = 0;
		eKundun.Itema[i].RateItem   = 0;

		eKundun.Itema[i].MinLevel   = 0;
		eKundun.Itema[i].MaxLevel   = 0;
		eKundun.Itema[i].RateLevel  = 0;

		eKundun.Itema[i].Skill      = 0;
		eKundun.Itema[i].RateSkill  = 0;

		eKundun.Itema[i].Luck       = 0;
		eKundun.Itema[i].RateLuck   = 0;

		eKundun.Itema[i].MinOpt     = 0;
		eKundun.Itema[i].MaxOpt     = 0;
		eKundun.Itema[i].RateOpt    = 0;

		eKundun.Itema[i].MinExl     = 0;
		eKundun.Itema[i].MaxExl     = 0;
		eKundun.Itema[i].RateExl    = 0;
	}

FILE *file = fopen(Aminyuz_Kundun,"r");

	if(file == NULL)
	{
		MessageBoxA(0,"Error al cargar el archivo Kundun.ini !!","ERROR",0);
		ExitProcess(1);
		return;
	}

	char Buff[256];
	int Flag = 0;

	eKundun.Count = 0;

	while(!feof(file)) // Check whether there is a line in the document
	{
		fgets(Buff,256,file);//This function reads the current line
		if(IsBadFileLine(Buff, Flag)) //auxiliary function
			continue;
		if(Flag == 1)
		{
			int n[20];
			sscanf(Buff, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4], &n[5], &n[6], &n[7], &n[8], &n[9], &n[10], &n[11], &n[12], &n[13], &n[14], &n[15]);

			eKundun.Itema[eKundun.Count].Type        = n[0];
			eKundun.Itema[eKundun.Count].Index       = n[1];
			eKundun.Itema[eKundun.Count].RateItem    = n[2];
			eKundun.Itema[eKundun.Count].MinLevel    = n[3];
			eKundun.Itema[eKundun.Count].MaxLevel    = n[4];
			eKundun.Itema[eKundun.Count].RateLevel   = n[5];
			eKundun.Itema[eKundun.Count].Skill       = n[6];
			eKundun.Itema[eKundun.Count].RateSkill   = n[7];
			eKundun.Itema[eKundun.Count].Luck        = n[8];
			eKundun.Itema[eKundun.Count].RateLuck    = n[9];
			eKundun.Itema[eKundun.Count].MinOpt      = n[10];
			eKundun.Itema[eKundun.Count].MaxOpt      = n[11];
			eKundun.Itema[eKundun.Count].RateOpt     = n[12];
			eKundun.Itema[eKundun.Count].MinExl      = n[13];
			eKundun.Itema[eKundun.Count].MaxExl      = n[14];
			eKundun.Itema[eKundun.Count].RateExl     = n[15];
			eKundun.Count++;
		}

	}
	fclose(file);
}

void Kundun(void * lpParam)
{
	while(true)
	{
		Sleep(eKundun.Start_Time);

		StringSendAll("[ El Ataque de Kundun Comenzara en 1 minuto ]",0);
		Sleep(60000);

		srand(static_cast<int>(time(NULL)));

		int MapRand = rand() % 5;

		if(MapRand == 0)
		{
			StringSendAll(eKundun.Anuncio1,0);
			GetBoxPosition(eKundun.Mapa1, 50, 50, 200, 200, gObj->X, gObj->Y);
			MosterAdd(157,eKundun.Mapa1,gObj->X,gObj->Y);
			LogAddFuncColor(COLOR_RED,"Make Kundun : %d, %d,%d",eKundun.Mapa1, gObj->X, gObj->Y);
		}
		else if(MapRand == 1)
		{
			StringSendAll(eKundun.Anuncio2,0);
			GetBoxPosition(eKundun.Mapa2, 50, 50, 200, 200, gObj->X, gObj->Y);
			MosterAdd(157,eKundun.Mapa2,gObj->X,gObj->Y);
			LogAddFuncColor(COLOR_RED,"Make Kundun : %d, %d,%d",eKundun.Mapa2, gObj->X, gObj->Y);
		}
		else if(MapRand == 2)
		{
			StringSendAll(eKundun.Anuncio3,0);
			GetBoxPosition(eKundun.Mapa3, 50, 50, 200, 200, gObj->X, gObj->Y);
			MosterAdd(157,eKundun.Mapa3,gObj->X,gObj->Y);
			LogAddFuncColor(COLOR_RED,"Make Kundun : %d, %d,%d",eKundun.Mapa3, gObj->X, gObj->Y);
		}
		else if(MapRand == 3)
		{
			StringSendAll(eKundun.Anuncio4,0);
			GetBoxPosition(eKundun.Mapa4, 50, 50, 200, 200, gObj->X, gObj->Y);
			MosterAdd(157,eKundun.Mapa4,gObj->X,gObj->Y);
			LogAddFuncColor(COLOR_RED,"Make Kundun : %d, %d,%d",eKundun.Mapa4, gObj->X, gObj->Y);
		}
		else if(MapRand == 4)
		{
			StringSendAll(eKundun.Anuncio5,0);
			GetBoxPosition(eKundun.Mapa5, 50, 50, 200, 200, gObj->X, gObj->Y);
			MosterAdd(157,eKundun.Mapa5,gObj->X,gObj->Y);
			LogAddFuncColor(COLOR_RED,"Make Kundun : %d, %d,%d",eKundun.Mapa5, gObj->X, gObj->Y);
		}
		Sleep(eKundun.Duration_Time);
		Kundun_DisappearMonster();
	}

}

void Kundun_DisappearMonster()
{
	for(int iIndex = 0; iIndex < OBJ_MAXMONSTER; iIndex++)
	{
		OBJECTSTRUCT *mObj = (OBJECTSTRUCT*)OBJECT_POINTER(iIndex);

		if(mObj->Class == 157 )
		{
			gObjDel(iIndex); 
		}
	}
	int MobCount = *(DWORD *)(MonsterCount);
	MobCount--;
}

void DropitemBoss(int aIndex)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	char msg[150];

	sprintf(msg,"[%s] ha derrotado a Kundun",gObj->Name);
	StringSendAll(msg,0);

	int Level=0, Skill=0, Luck=0, Opt=0,Exc=0, ExcNum=0;

	srand(static_cast<int>(time(NULL)));

	int Ran = rand()%eKundun.Count;
	int DropItem = ITEMGET(eKundun.Itema[Ran].Type,eKundun.Itema[Ran].Index);

	Level	= GetNumberByPercent(eKundun.Itema[Ran].RateLevel,eKundun.Itema[Ran].MinLevel,eKundun.Itema[Ran].MaxLevel);
    Opt		= GetNumberByPercent(eKundun.Itema[Ran].RateOpt,eKundun.Itema[Ran].MinOpt,eKundun.Itema[Ran].MaxOpt);
    Skill	= GetNumberByPercent(eKundun.Itema[Ran].RateSkill,0,eKundun.Itema[Ran].Skill);
    Luck	= GetNumberByPercent(eKundun.Itema[Ran].RateLuck,0,eKundun.Itema[Ran].Luck);

	if(eKundun.Itema[Ran].RateExl > 0)
    {
        ExcNum	= GetNumberByPercent(eKundun.Itema[Ran].RateExl,eKundun.Itema[Ran].MinExl,eKundun.Itema[Ran].MaxExl);
        Exc		= GenExcOpt(ExcNum);
    }
	ItemSerialCreateSend(aIndex, gObj->MapNumber, gObj->X, gObj->Y,DropItem,Level,0,Skill,Luck,Opt,aIndex,Exc);
}