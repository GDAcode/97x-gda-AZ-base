#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <rpc.h>
#include <strsafe.h>
#include <rpcdce.h>
#include <process.h>
#include <fstream>
#include <algorithm>
#include <SQL.h>
#include <SqlExt.h>
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"rpcrt4.lib")
#pragma comment(lib,"user32.lib")
#pragma warning(disable: 4018 4101 4129 4244 4305 4309 4390 4715 4800 4996 4805 4995 )

#include "Protocolo.h"
#include "Defines.h"
#include "Funciones.h"
#include "Comandos.h"
#include "Database.h"
#include "Manager.h"
#include "Usuarios.h"
#include "Movereq.h"
#include "Items.h"
#include "Fixes.h"
#include "Servidor.h"
#include "Balance.h"
#include "LifeCheck.h"
#include "Noticias.h"
#include "PKWarden.h"
#include "NPCTalkEx.h"
#include "Reload.h"
#include "GameMaster.h"
#include "Reset.h"
#include "Seguridad.h"
#include "Rates.h"
#include "Habilidades.h"
#include "Party.h"
#include "Kundun.h"
#include "Mapas.h"
#include "ItemDrop.h"
#include "Precios.h"
#include "ZenWarden.h"
#include "CGUseItemRecv.h"
#include "CodigoMain.h"
#include "Trade.h"
#include "ObjAttack.h"

#define Alpha_Balance           "..\\Aminyuz\\Balance.ini"

#define Aminyuz_Comandos		"..\\Aminyuz\\Comandos.ini"
#define Aminyuz_Seguridad		"..\\Aminyuz\\Seguridad.ini"
#define Aminyuz_GM              "..\\Aminyuz\\GameMaster.ini"
#define Aminyuz_SQL             "..\\Aminyuz\\Conexion.ini"
#define Aminyuz_Noticias        "..\\Aminyuz\\Noticias.ini"

#define Aminyuz_Fixes           "..\\Aminyuz\\Fixes.ini"
#define Aminyuz_Servidor		"..\\Aminyuz\\Servidor.ini"
#define Aminyuz_Rates	        "..\\Aminyuz\\Rates.ini"
#define Aminyuz_Habilidades		"..\\Aminyuz\\Habilidades.ini"
#define Aminyuz_Party			"..\\Aminyuz\\Party.ini"
#define Aminyuz_Reset           "..\\Aminyuz\\Reset.ini"
#define Aminyuz_Movereq         "..\\Aminyuz\\Movereq.ini"
#define Aminyuz_Kundun          "..\\Aminyuz\\Eventos\\Kundun.ini"
#define Aminyuz_ItemDrop        "..\\Aminyuz\\ItemDrop.txt"
#define Aminyuz_Precios			"..\\Aminyuz\\Precios.ini"

#define Aminyuz_PKWarden        "..\\Aminyuz\\NPC\\PKWarden.ini"
#define Aminyuz_ZenWarden       "..\\Aminyuz\\NPC\\ZenWarden.ini"