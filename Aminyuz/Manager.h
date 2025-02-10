#pragma once

#include "Database.h"

extern char CharacterEx[5][11];

class CManager : public CDataBase
{
public:
	CManager( void );
	~CManager( void );
	bool Initialize();
	int SkinStaff( char* Character );
	bool InitDatabase( );
	bool load();
	bool CManager::InitConfigurations();
	void OnMessage(const char * szMessage, ...);
	void OnError(const char * szMessage, ...);
	void OnQuery(const char * szMessage, ...);

	int VipCount( char* Account );
	void CharacterCount( char* Account );
	int CountResets(char * Character);
	int CheckAccount(char * Account);
	
private:
	char Host[50];
	char Database[50];
	char Usuario[50];
	char Contraseña[50];
};

extern CManager Manager;