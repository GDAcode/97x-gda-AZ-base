#ifndef COMANDOS_H
#define COMANDOS_H

struct COMANDOS
{
	int  GlobalSwitch;
	int  GlobalColor;
    int  GlobalLevel;
    int  GlobalZen;
    int  GlobalTiempoSwitch;
    int  GlobalTiempo;
	char GlobalSyntax[20];
	char GlobalCMD[20];

	int  WebSwitch;
	char WebText[125];
	char WebCMD[20];

	char HoraCMD[20];

	int  PuntosSwitch;
    int  PuntosLevel;
    int  PuntosZen[2];
    int  PuntosMaxFuerza;
    int  PuntosMaxAgilidad;
    int  PuntosMaxVitalidad;
    int  PuntosMaxEnergia;
	char FuerzaCMD[20];
	char AgilidadCMD[20];
	char VitalidadCMD[20];
	char EnergiaCMD[20];

	int AsesinatosSwitch;
	char Asesinatos[20];

	int  CInvSwitch;
    int  CInvLevel;
	int  CInvVip;
	char ClearInvCMD[20];

	int  ReloadSwitch;
	int  ReloadLevel;
	int  ReloadZen;
	int  ReloadGM;
	int  ReloadGMSystem;
	char ReloadCMD[20];

	int  DropSwitch;
	int  DropNeedLevel;
	int  DropNeedZen;
	int  DropEfect;
	int  DropOnlyGM;
	int  DropGMSystem;
	char DropCMD[20];

	int  GGSwitch;
	int  GGLevel;
	int  GGZen;
	int  GGGM;
	int  GGGMSystem;
	char GGCMD[20];

	int  SkinSwitch;
	int  SkinLevel;
	int  SkinZen;
	int  SkinGM;
	int  SkinGMSystem;
	char SkinCMD[20];

	int  OnlineSwitch;
	int  OnlineGM;
	int  OnlineGMAcceso;
	char OnlineCMD[20];

	int  MoveAllSwitch;
	int  MoveAllLevel;
	int  MoveAllZen;
	int  MoveAllGM;
	int  MoveAllGMAcceso;
	char MoveAllCMD[20];

	int  BlockSwitch;
	int  BlockGM;
	int  BlockGMAcceso;
	char BlockCMD[20];

	int  UnBlockSwitch;
	int  UnBlockGM;
	int  UnBlockGMAcceso; 
	char UnBlockCMD[20];

	int  BanSwitch;
	int  BanGM;
	int  BanGMAcceso;
	char BanCMD[20];

	int  UnBanSwitch;
	int  UnBanGM;
	int  UnBanGMAcceso;
	char UnBanCMD[20];

};
extern COMANDOS  pComandos;

void Comandos();
void ChatDataSend(int aIndex, unsigned char* aRecv);

void ZenComando(DWORD aIndex, LPCSTR IpBuffer);
void GlobalComando(DWORD aIndex,char*msg);
void WebComando(int aIndex);
void HoraComando(int aIndex);
void Puntos(int aIndex, LPCSTR IpBuffer, BYTE Type);
void AsesinatosComando(int aIndex);
void ClearInvComando(int aIndex,LPCSTR IpBuffer);
void ReloadComando(int aIndex);
void DropCommand(int aIndex ,char*msg);
void GGComando(int aIndex,char*msg);
void SkinComando(int aIndex, char* msg);
void OnlineComando(int aIndex);
void MoveAllComando(int aIndex,char* msg);
void BlockComando(int aIndex, char* Msg);
void UnBlockComando(int aIndex, char* Msg);
void BanComando(int aIndex, char* Msg);
void UnBanComando(int aIndex, char* Msg);
#endif