#include "StdAfx.h"

unsigned int Bronze			= GetPrivateProfileIntA("Precios","Bronze",100000000, Aminyuz_Precios);
unsigned int Plata			= GetPrivateProfileIntA("Precios","Plata",100000000, Aminyuz_Precios);
unsigned int Oro			= GetPrivateProfileIntA("Precios","Oro",100000000, Aminyuz_Precios);

void __declspec(naked) Precios()
{
	_asm
	{
		// Jewel of Chaos
		MOV EAX,DWORD PTR SS:[EBP-0x04]
		MOVSX ECX,WORD PTR DS:[EAX+0x06]
		CMP ECX, ITEMGET(12,15)
		JNZ Item1
		MOV DWORD PTR SS:[EBP-0x10], 0xC5C10
		JMP Exit

Item1:  // Cofre de 500M
		MOV EAX,DWORD PTR SS:[EBP-0x04]
		MOVSX ECX,WORD PTR DS:[EAX+0x06]
		CMP ECX, ITEMGET(14,27)
        JNZ Item2
		MOV ECX, Bronze
        MOV DWORD PTR SS:[EBP-0x10], ECX
        JMP Exit 

Item2:  // Cofre de 1B
		MOV EAX,DWORD PTR SS:[EBP-0x04]
		MOVSX ECX,WORD PTR DS:[EAX+0x06]
		CMP ECX, ITEMGET(14,28)
        JNZ Item3
		MOV ECX, Plata
        MOV DWORD PTR SS:[EBP-0x10], ECX
        JMP Exit 

Item3:  // Cofre de 2B
		MOV EAX,DWORD PTR SS:[EBP-0x04]
		MOVSX ECX,WORD PTR DS:[EAX+0x06]
		CMP ECX, ITEMGET(14,29)
        JNZ Continue
		MOV ECX, Oro
        MOV DWORD PTR SS:[EBP-0x10], ECX
        JMP Exit 
Exit:
		mov edx, 0x00480999
		JMP edx
Continue:
		mov edx, 0x0048005F
		jmp edx
	}
}

void LoadPrecios()
{
	*(unsigned int*) (0x00480021) = GetPrivateProfileIntA  ("Precios","Bless",9000000,Aminyuz_Precios);
	*(unsigned int*) (0x0048003B) = GetPrivateProfileIntA  ("Precios","Soul",6000000,Aminyuz_Precios);
	*(unsigned int*) (0x00480071) = GetPrivateProfileIntA  ("Precios","Life",45000000,Aminyuz_Precios);
	*(unsigned int*) (0x0048008B) = GetPrivateProfileIntA  ("Precios","Creation",36000000,Aminyuz_Precios);
	

	SetRange((LPVOID)0x00480044, 27, ASM::NOP);
	SetOp((LPVOID)0x00480044, Precios, ASM::JMP);
}