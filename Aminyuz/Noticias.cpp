#include "StdAfx.h"

void Noticias()
{    
	int IsNews  = GetPrivateProfileIntA("GENERAL","Switch",0,Aminyuz_Noticias);
	if( IsNews != 0 )
	{
	   _beginthread(&SNoticias,0,0);
	}
}

 void SNoticias(void * lpParam)
{
	FILE *fp;
	fp=fopen(Aminyuz_Noticias,"r");
	if(!fp)
	{
		MessageBox(NULL,"Noticias.ini no encontrado","Error",MB_OK);
		::ExitProcess(0);
	}
	fclose(fp);

	while(true)
	{
		int Sections      = GetPrivateProfileIntA("GENERAL","Secciones"   ,5 ,Aminyuz_Noticias);
		int time          = GetPrivateProfileIntA("GENERAL","Tiempo"       ,10,Aminyuz_Noticias)*60000;
		if(Sections <= 0 || GetPrivateProfileIntA("GENERAL","Switch"   ,0 ,Aminyuz_Noticias) > 0)
		{
			char MSG1[100],MSG2[100],MSG3[100];
			char Getter1[11],Getter2[11],Getter3[11];

			for(int x=0;x<Sections;x++)
			{
				Sleep(time);
				sprintf(Getter1,"Noticia%02d",((x*3)+1));
				sprintf(Getter2,"Noticia%02d",((x*3)+2));
				sprintf(Getter3,"Noticia%02d",((x*3)+3));
				GetPrivateProfileString("NOTICIAS",Getter1,"Proyecto Aminyuz",MSG1,100,Aminyuz_Noticias);
				GetPrivateProfileString("NOTICIAS",Getter2,"Por Jose Hernandez",MSG2,100,Aminyuz_Noticias);
				GetPrivateProfileString("NOTICIAS",Getter3,"Saludos",MSG3,100,Aminyuz_Noticias);
				StringSendAll(MSG1,0);
				StringSendAll(MSG2,0);
				StringSendAll(MSG3,0);
			}
		}
		else
		{
			Sleep(60000);
		}
	}
	_endthread();
}
