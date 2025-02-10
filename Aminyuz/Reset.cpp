#include "StdAfx.h"

StructReset CReset;

bool GReset::LoadSettings()
{
	CReset.Settings.Switch				= GetPrivateProfileIntA("RESET","Switch",1,Aminyuz_Reset);
	CReset.Settings.Type				= GetPrivateProfileIntA("RESET","Sistema",2,Aminyuz_Reset);
	CReset.Settings.ResetsMax			= GetPrivateProfileIntA("RESET","Maximo",360,Aminyuz_Reset);

	CReset.Acumulativo.Level[0]			= GetPrivateProfileIntA("ACUMULATIVO","Level [Gratuito]",1,Aminyuz_Reset);
	CReset.Acumulativo.Level[1]			= GetPrivateProfileIntA("ACUMULATIVO","Level [Vip]",1,Aminyuz_Reset);
	CReset.Acumulativo.RemoveItems[0]	= GetPrivateProfileIntA("ACUMULATIVO","Remover Items [Gratuito]",1,Aminyuz_Reset);
	CReset.Acumulativo.RemoveItems[1]	= GetPrivateProfileIntA("ACUMULATIVO","Remover Items [Vip]",1,Aminyuz_Reset);
	CReset.Acumulativo.Money[0]			= GetPrivateProfileIntA("ACUMULATIVO","Zen [Gratuito]",1,Aminyuz_Reset);
	CReset.Acumulativo.Money[1]			= GetPrivateProfileIntA("ACUMULATIVO","Zen [Vip]",1,Aminyuz_Reset);
	CReset.Acumulativo.NextLevel		= GetPrivateProfileIntA("ACUMULATIVO","Level despues del reset",1,Aminyuz_Reset);

	CReset.Pontuativo.Level[0]		    = GetPrivateProfileIntA("PUNTUATIVO","Level [Gratuito]",400,Aminyuz_Reset);
	CReset.Pontuativo.Level[1]		    = GetPrivateProfileIntA("PUNTUATIVO","Level [Vip]",380,Aminyuz_Reset);
	CReset.Pontuativo.RemoveItems[0]	= GetPrivateProfileIntA("PUNTUATIVO","Remover Items [Gratuito]",1,Aminyuz_Reset);
	CReset.Pontuativo.RemoveItems[1]	= GetPrivateProfileIntA("PUNTUATIVO","Remover Items [Vip]",1,Aminyuz_Reset);
	CReset.Pontuativo.Money[0]			= GetPrivateProfileIntA("PUNTUATIVO","Zen [Gratuito]",1,Aminyuz_Reset);
	CReset.Pontuativo.Money[1]			= GetPrivateProfileIntA("PUNTUATIVO","Zen [Vip]",1,Aminyuz_Reset);
	CReset.Pontuativo.NextLevel		    = GetPrivateProfileIntA("PUNTUATIVO","Level despues del reset",1,Aminyuz_Reset); 
	CReset.Pontuativo.NextFor		    = GetPrivateProfileIntA("PUNTUATIVO","Puntos despues del reset en fuerza",25,Aminyuz_Reset);
	CReset.Pontuativo.NextAgi		    = GetPrivateProfileIntA("PUNTUATIVO","Puntos despues del reset en agilidad",25,Aminyuz_Reset);
	CReset.Pontuativo.NextVit		    = GetPrivateProfileIntA("PUNTUATIVO","Puntos despues del reset en vitalidad",25,Aminyuz_Reset);
	CReset.Pontuativo.NextEne		    = GetPrivateProfileIntA("PUNTUATIVO","Puntos despues del reset en energia",25,Aminyuz_Reset);
	CReset.Pontuativo.PointsAdd[0]	    = GetPrivateProfileIntA("PUNTUATIVO","Puntos por reset [Gratuito]",300,Aminyuz_Reset); 
	CReset.Pontuativo.PointsAdd[1]	    = GetPrivateProfileIntA("PUNTUATIVO","Puntos por reset [Vip]",600,Aminyuz_Reset);

	GetPrivateProfileString("RESET UPDATE","UPDATE RESET","UPDATE MuOnline.dbo.Character SET Resets = Resets + 1 WHERE Name = '%s'",CReset.Settings.RQuery1,100,Aminyuz_Reset);

	return true;
}

bool GReset::CheckItems(DWORD aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	for(int i = 0; i < 11; i++)
	{
		if(lpObj->pInventory[i].m_Type > 0)
		{
			return false;
		}
	}
	return true;
}

void GReset::InitReset(DWORD aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	int VipIndex = Manager.VipCount(lpObj->AccountID);
	int Resets = Manager.CountResets(lpObj->Name);

	DWORD Type = CReset.Settings.Type;

	if(CReset.Settings.Switch != 1)
	{
		GCServerMsgStringSend("[AVISO] Comando desactivado!",aIndex,1);
		return;
	}
	else if(Resets >= CReset.Settings.ResetsMax)
	{
		MsgOutput(aIndex,"[AVISO] Reset Maximo Alcanzado!");
		return;
	}
	else
	{
		switch(Type)
		{
		case 1: // Acumulativo
			{
				if(CReset.Acumulativo.Level[VipIndex] > lpObj->Level)
				{
					GCServerMsgStringSend("[AVISO] No tenes el nivel necesario",aIndex,1);
					return;
				}
				else if(CReset.Acumulativo.Money[VipIndex] > lpObj->Money)
				{
					GCServerMsgStringSend("[AVISO] No tenes el zen suficiente!",aIndex,1);
					return;
				}
				else if(CReset.Acumulativo.RemoveItems[VipIndex] != 0 && GReset::CheckItems(aIndex) == false)
				{
					GCServerMsgStringSend("[AVISO] Remueva todos los items para resetear!",aIndex,1);
					return;
				}
				else
				{
					Resets		             += 1;
					lpObj->Money			 -= CReset.Acumulativo.Money[VipIndex];
					lpObj->NextExp           = 1;
					lpObj->Experience        = 1;
					lpObj->BP                = 1;
					lpObj->MaxBP             = 1;
					lpObj->MaxLife		     = lpObj->VitalityToLife * lpObj->Vitality;  
		            lpObj->MaxMana		     = lpObj->EnergyToMana * lpObj->Energy;
					lpObj->Level			 = CReset.Acumulativo.NextLevel;
					GCMoneySend(aIndex,lpObj->Money);

					Manager.ExecFormat(CReset.Settings.RQuery1,lpObj->Name);

					if(lpObj->DbClass == 0 || lpObj->DbClass == 1 || lpObj->DbClass == 16 || lpObj->DbClass == 17 || lpObj->DbClass == 48 || lpObj->DbClass == 64)
					{
						gObjTeleport(lpObj->m_Index,0,134,128);
					}
					else if(lpObj->DbClass == 32 || lpObj->DbClass == 33)
					{
						gObjTeleport(lpObj->m_Index,3,174,114);
					}


					Refresh(aIndex);
					GCServerMsgStringSend("[AVISO] Reseteo con exito!",aIndex,1);
					GCRefillSend(aIndex,(WORD)lpObj->MaxLife + lpObj->AddLife,0xFE,0);
					gObjSetBP(aIndex);
					GCManaSend(aIndex,(short)lpObj->MaxMana + lpObj->AddMana,0xFE,0,lpObj->MaxBP + lpObj->AddBP);
					GCLevelUpMsgSend(aIndex,lpObj->Level,lpObj->LevelUpPoints,(WORD)(lpObj->MaxLife+lpObj->AddLife),(WORD)(lpObj->MaxMana+lpObj->AddMana),(WORD)(lpObj->MaxBP+lpObj->AddBP));

				}

			}
			break;

		case 2: // Pontuativo
			{
				if(CReset.Pontuativo.Level[VipIndex] > lpObj->Level)
				{
					GCServerMsgStringSend("[AVISO] No tenes el nivel necesario",aIndex,1);
					return;
				}
				else if(CReset.Pontuativo.Money[VipIndex] > lpObj->Money)
				{
					GCServerMsgStringSend("[AVISO] No tenes el zen suficiente!",aIndex,1);
					return;
				}
				else if(CReset.Pontuativo.RemoveItems[VipIndex] != 0 && GReset::CheckItems(aIndex) == false)
				{
					GCServerMsgStringSend("[AVISO] Remueva todos los items para resetear!",aIndex,1);
					return;
				}
				else
				{
					lpObj->LevelUpPoints      = 0;

					Resets		                    += 1;
					lpObj->Money			    -= CReset.Pontuativo.Money[VipIndex];
					lpObj->LevelUpPoints	    += Resets * CReset.Pontuativo.PointsAdd[VipIndex];
					lpObj->NextExp            = 1;
					lpObj->Experience         = 1;
					lpObj->BP                 = 1;
					lpObj->MaxBP              = 1;
					lpObj->Level			    = CReset.Pontuativo.NextLevel;
					lpObj->MaxLife			= lpObj->VitalityToLife * CReset.Pontuativo.NextVit;  
					lpObj->MaxMana			= lpObj->EnergyToMana * CReset.Pontuativo.NextEne;  
					lpObj->Strength			= CReset.Pontuativo.NextFor;
					lpObj->Dexterity			= CReset.Pontuativo.NextAgi;
					lpObj->Vitality			= CReset.Pontuativo.NextVit;
					lpObj->Energy			    = CReset.Pontuativo.NextEne;
					GCMoneySend(aIndex,lpObj->Money);

					Manager.ExecFormat(CReset.Settings.RQuery1,lpObj->Name);

					if(lpObj->DbClass == 0 || lpObj->DbClass == 1 || lpObj->DbClass == 16 || lpObj->DbClass == 17 || lpObj->DbClass == 48 || lpObj->DbClass == 64)
					{
						gObjTeleport(lpObj->m_Index,0,134,128);
					}
					else if(lpObj->DbClass == 32 || lpObj->DbClass == 33)
					{
						gObjTeleport(lpObj->m_Index,3,174,114);
					}


					Refresh(aIndex);
					GCServerMsgStringSend("[AVISO] Reseteo con exito!",aIndex,1);
					GCRefillSend(aIndex,(WORD)lpObj->MaxLife + lpObj->AddLife,0xFE,0);  
					gObjSetBP(aIndex);
					GCManaSend(aIndex,(short)lpObj->MaxMana + lpObj->AddMana,0xFE,0,lpObj->MaxBP + lpObj->AddBP);
					GCLevelUpMsgSend(aIndex,lpObj->Level,lpObj->LevelUpPoints,(WORD)(lpObj->MaxLife+lpObj->AddLife),(WORD)(lpObj->MaxMana+lpObj->AddMana),(WORD)(lpObj->MaxBP+lpObj->AddBP));

				}
			}
			break;

		}
	}
}