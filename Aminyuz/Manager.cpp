#include "StdAfx.h"

CManager Manager = CManager( );

char CharacterEx[5][11] = { 0 };

CManager::CManager( void )
{

}

CManager::~CManager( void )
{

}

bool CManager::Initialize( )
{
	if( !this->InitDatabase ( ) )
	{
		return false;
	}

	return true;
}

bool CManager::InitDatabase()
{
	bool bReturn = false;

	Manager.load();

	if(this->Connect(this->Host , this->Database , this->Usuario , this->Contraseña) == true )
	{	
		bReturn = true;
	}
	else
	{
		MessageBox(NULL,"Verifique el archivo Conexion.ini","[AT] Error de conexión!",MB_OK | MB_ICONSTOP);
		ExitProcess(0);
		
		this->DiagnosticConn();
	}

	return bReturn;
}

bool CManager::load()
{
	GetPrivateProfileString("SQL", "Usuario","sa",this->Usuario,sizeof(this->Usuario),Aminyuz_SQL);
	GetPrivateProfileString("SQL", "Contraseña", "123456",this->Contraseña,sizeof(this->Contraseña),Aminyuz_SQL);
	GetPrivateProfileString("SQL", "Database","MuOnline",this->Database,sizeof(this->Database),Aminyuz_SQL);
	GetPrivateProfileString("SQL", "Host","127.0.0.1",this->Host,sizeof(this->Host),Aminyuz_SQL);

	return true;
}

void CManager::OnError(const char * szMessage, ...)
{
}

void CManager::OnMessage(const char * szMessage, ...)
{
}

void CManager::OnQuery(const char * szMessage, ...)
{
}

int CManager::VipCount( char* Account )
{
	int Vip;

	this->ExecFormat("SELECT vip FROM MEMB_INFO WHERE memb___id = '%s'" , Account );

	this->Fetch( );

	Vip = this->GetInt("vip");

	this->Clear( );

	return Vip;
}

int CManager::CheckAccount( char* Account )
{
	int Find;

	this->Fetch( );

	Find = this->ExecFormat( "SELECT * FROM MEMB_INFO WHERE memb___id = '%s'" , Account );

	this->Clear( );

	return Find;
}

int CManager::CountResets(char * Character)
{
	int Resets;

	this->ExecFormat("SELECT Resets from Character WHERE Name = '%s'",Character);

	this->Fetch( );

	Resets = this->GetInt("Resets");

	this->Clear( );

	return Resets;
}

void CManager::CharacterCount( char* Account )
{
	this->ExecFormat("SELECT * FROM AccountCharacter WHERE Id='%s'" , &Account[0] );
	this->Fetch();
	this->GetStr("GameID1", CharacterEx[0]);
	this->GetStr("GameID2", CharacterEx[1]);
	this->GetStr("GameID3", CharacterEx[2]);
	this->GetStr("GameID4", CharacterEx[3]);
	this->GetStr("GameID5", CharacterEx[4]);
	this->Clear();
}