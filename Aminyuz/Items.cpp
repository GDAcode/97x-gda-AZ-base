#include "StdAfx.h"


bool CItem::IsItem()
{
		if((int)this->m_Type == (-1))
		{
			return false;
		}

		return true;
}

void CItem::PlusSpecial(int* Value, int Special)
{
		if(!this->IsItem())
		{
			return;
		}

		if(this->m_Durability == 0.0f)
		{
			return;
		}

		for(int i = 0; i < this->m_SpecialNum; i++)
		{
			if(this->m_Special[i] == Special)
			{
				switch(Special)
				{
				case 82:
					{
						int Option = this->m_Option3 * 5;
						Option -= (int)(Option * this->m_CurrentDurabilityState);
						*Value += Option;
					}break;
				case 84:
					{
						*Value += 4;
					}break;
				case 81:
				case 80:
				case 83:
					{
						int Option = this->m_Option3 * 4;
						Option -= (int)(Option * this->m_CurrentDurabilityState);
						*Value += Option;
					}break;
				case 100:
				case 101:
					{
						int Option = (*Value + ((this->m_Level * 5) + 50));
						*Value += Option;
					}break;
				case 103:
					{
						*Value += 50;
					}break;
				case 105:
					{
						int Option = (*Value + ((this->m_Level * 5) + 10));
						*Value += Option;
					}break;
				default:
					{
						int Option = (*Value + (this->m_Option3 * 4));
						*Value += Option;
					}break;
				}
			}
		}
}

void CItem::PlusSpecialPercentEx(int* Value, int Source, int Special)
{
		if(!this->IsItem())
		{
			return;
		}

		if(this->m_Durability == 0.0f)
		{
			return;
		}

		for(int i = 0; i < this->m_SpecialNum; i++)
		{
			if(this->m_Special[i] == Special)
			{
				int Option = (Source * this->m_Option3) / 100;
				Option -= (int)(Option * this->m_CurrentDurabilityState);
				*Value += Option;
			}
		}
}

int CItem::ItemDefense()
{
		if(!this->IsItem())
		{
			return 0;
		}
		else
		{
			int Defense = this->m_Defense;

			if(Defense < 0)
			{
				return 0;
			}
			else
			{
				this->PlusSpecial(&Defense, 83);
				return Defense;
			}
		}
}

void CItem::Value()
{
	_asm
	{
		MOV ECX, this;
		MOV EDI, 0x47FD80;
		CALL EDI;
	}
}

bool CItem::IsExtLifeAdd()
{
	if ( (this->m_NewOption & 0x20) == 32 )
	{
		return 4;
	}

	return 0;
}

bool CItem::IsExtManaAdd()
{
	if ( (this->m_NewOption & 0x10) == 16 )
	{
		return 4;
	}

	return 0;
}

bool CItem::IsExtDamageMinus()
{
	if ( (this->m_NewOption & 8) == 8 )
	{
		return 4;
	}

	return 0;
}

bool CItem::IsExtDamageReflect()
{
	if ( (this->m_NewOption & 4) == 4 )
	{
		return 5;
	}

	return 0;
}


bool CItem::IsExtDefenseSuccessfull()
{
	if ( (this->m_NewOption & 2) == 2 )
	{
		return 10;
	}

	return 0;
}