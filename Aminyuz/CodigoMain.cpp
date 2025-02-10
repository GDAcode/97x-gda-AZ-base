#include "StdAfx.h"

void CodigoMain(int aIndex)
{
	LPOBJ lpObj = (LPOBJ)OBJECT_POINTER(aIndex);
	PMSG_CODIGOMAIN Result;
	Result.h.c = 0xC1;
	Result.h.size = sizeof(Result);
	Result.h.head = 0xFE;
	Result.Code = 0x07;
	Result.Seguridad = 251;
	DataSend(lpObj->m_Index, (LPBYTE)(&Result), Result.h.size);
}
