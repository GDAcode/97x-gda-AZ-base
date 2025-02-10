#ifndef PROTOCOLO_H
#define PROTOCOLO_H

void Protocolo();
void ProtocoloConfigs();

struct PROTOCOLO
{
	char Bienvenida[200];
	char GMAnuncio[200];
};
extern PROTOCOLO  pProtocolo;

void CharacterLogin(int aIndex);
void ProtocolCore(BYTE protoNum, BYTE *aRecv, int aLen, int aIndex, BOOL Encrypt=0, int serial=-1);

#endif