#ifndef DEFINES_H
#define DEFINES_H

#define DataRecv      ((bool(*) (unsigned char, unsigned char*, int, int, ...)) 0x00414180)
#define DataSend      ((void(*)(DWORD aIndex, PBYTE Packet, DWORD Size)) 0x00440240)
#define GObjExtItemApply	  ((void(*)(LPOBJ obj)) 0x00453C40)
#define gObjSetItemApply  	  ((void(*)(LPOBJ obj)) 0x004810C0)
#define GCServerMsgStringSend ((void(*)(char* message, DWORD aIndex, int Tipo)) 0x0040167C)
#define GCMoneySend                       ((void(*)(DWORD aIndex, DWORD Money)) 0x00402702)
#define gObjTeleport				     ((void(*)(int index, int map, int x, int y)) 0x004786D0)
#define gObjMoveGate                     ((void(*)(int aIndex, int Gate)) 0x00402810)
#define GCItemListSend				     ((void(*)(int aIndex)) 0x00411010)
#define gObjCalCharacter	             ((void(*)(int aIndex)) 0x00451DE0)
#define GCManaSend					     ((void(*)(int aIndex, short Mana, BYTE Ipos, unsigned char flag,  WORD BP)) 0x00429050)
#define gObjSetBP				         ((void(*)(int aIndex)) 0x0045C040)
#define GCReFillSend		             ((void(*)(DWORD, WORD, BYTE, BYTE)) 0x00428FD0)
#define gObjNextExpCal	                 ((void(*)(LPOBJ obj)) 0x00402040)
#define gObjDel						     ((short(*)(int index)) 0x00460640)
#define ItemGetNumberMake				 ((int(*)(int Type, int Index)) 0x00482DE0)
#define ItemSerialCreateSend             ((int(*)(DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD)) 0x004020C7)
#define gObjLifeCheck					 ((void(*)(OBJECTSTRUCT* lpTargetObj, OBJECTSTRUCT* lpObj, int AttackDamage, int DamageSendType, int MSBFlag, int MSBDamage, BYTE Skill, int iShieldDamage))  0x004684A0) //new
#define gObjAttack                       ((int(*)(OBJECTSTRUCT* lpObj, OBJECTSTRUCT* lpTargetObj,void*lpMagic, BOOL magicsend, BYTE MSBFlag, int AttackDamage)) 0x004677A0) //new 
#define gObjAddMonsters				     ((short(*)()) 0x004013B1)
#define gObjSetMonsters				     ((bool(*)(int aIndex, int MobNr)) 0x00402AE0)
#define LogAddFuncColor                  ((void(*)(unsigned char Color,char * message, ...)) 0x00402400)
#define GCLevelUpMsgSend		     	 ((void(*)(int aIndex, WORD Level, WORD LevelUpPoint, WORD MaxLife, WORD MaxMana, WORD MaxBP)) 0x004018B6)
#define NpcTalk                          ((bool(*)(OBJECTSTRUCT* lpNpc, OBJECTSTRUCT* lpObj)) 0x00487A50)
#define GCPkLevelSend                    ((void(*)(DWORD aIndex,BYTE PkLevel)) 0x00401D7F)
#define GCMagicAttackNumberSend          ((void(*)(OBJECTSTRUCT*, unsigned char, int, unsigned char)) 0x00402036)
#define ReadCommonServerInfo             ((void(*)(void)) 0x0048C2E0)
#define GCMagicListMultiSend             ((void(*)(LPOBJ lpObj)) 0x418030)
#define CGRequestQuestInfo              ((void(*)(int aIndex)) 0x0042A7C0)
#define DGGuildMemberInfoRequest        ((void(*)(int aIndex)) 0x0042C460)
#define GCRefillSend			      	((void(*)(WORD, WORD, BYTE, BYTE)) 0x00428FD0)
#define CGWarehouseUseEnd                ((void(*)(int)) 0x00423250)
#define JGCharacterCreateFailSend	     ((void(*)(DWORD, char*)) 0x00410A50)
#define CloseClient                      ((BOOL(*)(int)) 0x00440E90)
#define gObjViewportListProtocolCreate   ((void(*)(LPOBJ lpObj)) 0x00474E40)
#define gObjInventoryDeleteItem          ((void(*)(int,int)) 0x00402383)
#define GCInventoryItemDeleteSend        ((void(*)(int,int,unsigned char)) 0x0040201D)
#define CGUseItemRecv                    ((void(*)(PMSG_USEITEM* lpMsg,int aIndex)) 0x00427A70)

#define gObjMonsterTopHitDamageUser      ((DWORD(*) (BYTE*MonsterAddress)) 0x00404D70)
#define gEventMonsterItemDrop            ((int(*)(BYTE *,BYTE*)) 0x0040A670)

#define gObjJoominCheck					((BOOL(*)(int aIndex, char *szInJN)) 0x460b50)
#define GCWarehouseStateSend            ((void(*)(int aIndex, char state)) 0x004233A0)
#define GCWarehouseRecivePassword       ((void(*)(int aIndex, PMSG_WAREHOUSEPASSSEND *lpMsg)) 0x00423400)

#define BlessLevelUp					((bool(*)(OBJECTSTRUCT *gObj, int slotx, int sloty))	0x00479A60)
#define SoulLevelUp						((bool(*)(OBJECTSTRUCT *gObj, int slotx, int sloty))	0x00479E50)
#define LifeLevelUp						((bool(*)(OBJECTSTRUCT *gObj, int slotx, int sloty))	0x0047A490)

#define gObjMakePreviewCharSet           ((void(*)(DWORD aIndex))	0x0046FE30)

#define GCRequestTrade		((void(*)(PMSG_TRADE_REQUEST*, DWORD)) 0x41D3B0)
#define GCResponseTrade		((void(*)(PMSG_TRADE_RESPONSE*, DWORD)) 0x41D990)
#define GCCancelTrade		((void(*)(DWORD)) 0x41E8A0)

#define OBJECT_MAXRANGE(aIndex) ( ((aIndex) < 0 )?FALSE:( (aIndex) > OBJECT_MAX -1 )?FALSE:TRUE   )

#define ServerExperience		         0x513674
#define ServerDrop				         0x513650
#define OBJECT_BASE	                     0x4CEE778                  
#define OBJECT_SIZE	                     0x0D0C
#define OBJECT_MIN	                     4800
#define OBJECT_MAX		                 5800
#define GET_NUMBERH(x)				((BYTE)((DWORD)(x) >> (DWORD)(8)))
#define GET_NUMBERL(x)				((BYTE)((DWORD)(x) & 0xFF))
#define MAX_ITEM_INFO 7+5
#define SLOT_EMPTY -1
#define ITEMGET(X,Y)((X * 32) + Y)
#define ServerAttackSpeed		         0x5136D8
#define ServerMinimumSpeed		         0x5136E4
#define ServerDecTimeSpeed		         0x5136E0
#define MonsterCount		             0x634D8E4
#define MonsterReads		             0x634453C
#define OBJ_MINMONSTER                   0
#define OBJ_MAXMONSTER                   4200

enum LOG_COLORS
{
	COLOR_BLACK		= 1,
	COLOR_RED		= 2,
	COLOR_GREEN		= 3,
	COLOR_BLUE		= 4,
	COLOR_RED2	    = 5,
	COLOR_BLUE2		= 6,
	COLOR_PINK      = 7,
	COLOR_YELLOW    = 8,
	COLOR_PURPLE    = 9,
	COLOR_ORANGE    = 10,
	COLOR_CYAN      = 11,
	COLOR_GOLD      = 12,

};

namespace ASM
{
	enum T
	{
		JMP			= 0xE9,
		JE			= 0x74,
		JNE			= 0x75,
		JGE			= 0x7D,
		NOP			= 0x90,
		CALL		= 0xE8,
		PUSH		= 0x68,
	};
};

#endif