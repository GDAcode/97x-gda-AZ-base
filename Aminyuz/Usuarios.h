#ifndef USUARIO_H
#define USUARIO_H

enum ClassNumber 
{
  CLASS_WIZARD   = 0x0,
  CLASS_KNIGHT   = 0x1,
  CLASS_ELF      = 0x2,
  CLASS_MAGUMSA  = 0x3,
};

enum OBJECT_TYPE 
{
	OBJECT_EMPTY	 = -1,
	OBJECT_USER		 =  1,
	OBJECT_MONSTER	 =  2,
	OBJECT_NPC		 =  3
};

struct PBMSG_HEAD
{
public:
	BYTE c;
	BYTE size;
	BYTE headcode;
};

struct PBMSG_HEAD2
{
	unsigned char c;
	unsigned char size;
	unsigned char head;
};

struct PMSG_CODIGOMAIN
{
	PBMSG_HEAD2 h;
	BYTE Code;
	BYTE Seguridad;
};

struct PMSG_WAREHOUSEPASSSEND
{
    PBMSG_HEAD h;
    char Type;
    short Pass;
    char LastJoominNumber[10];
};

struct PMSG_DEFAULT2
{
	PBMSG_HEAD h;
	BYTE subcode;
};

struct PMSG_LVPOINTADD
{
	PBMSG_HEAD h;
	BYTE subcode;	
	BYTE Type;	
};

struct PMSG_CHATDATA
{
	PBMSG_HEAD h;
	char chatid[10];
	char chatmsg[60];
};

struct PMSG_INVENTORYITEMMOVE
{
	PBMSG_HEAD h;
	BYTE sFlag;
	BYTE source_item_num;
	BYTE sItemInfo[4];
	BYTE tFlag;
	BYTE target_item_num;
};

struct PMSG_CHARCREATE
{
	PBMSG_HEAD h;
	BYTE subcode;
	char Name[10];
	BYTE ClassSkin;
};

struct PMSG_CHARMAPJOINRESULT
{
	struct PBMSG_HEAD h;
	unsigned char subcode;
	unsigned char MapX;
	unsigned char MapY;
	unsigned char MapNumber;
	unsigned char Dir;
	unsigned long Exp;
	unsigned long NextExp;
	unsigned short LevelUpPoint;
	unsigned short Str;
	unsigned short Dex;
	unsigned short Vit;
	unsigned short Energy;
	unsigned short Life;
	unsigned short MaxLife;
	unsigned short Mana;
	unsigned short MaxMana;
	unsigned short BP;
	unsigned short MaxBP;
	int Money;
	unsigned char PkLevel;
	unsigned char CtlCode;
	short AddPoint;
	short MaxAddPoint;
};

struct PMSG_CHARREGEN
{
	PBMSG_HEAD h;
	char subcode;
	char MapX;
	char MapY;
	char MapNumber;
	char Dir;
	unsigned short Life;
	unsigned short Mana;
	unsigned short BP;
	unsigned int Exp;
	unsigned int Money;
};

struct PMSG_SERVERCMD
{
	PBMSG_HEAD h;
	BYTE subcode;	
	BYTE CmdType;	
	BYTE X;	
	BYTE Y;	
};

struct PMSG_BUYRESULT
{
	PBMSG_HEAD h;
	BYTE Result;
	BYTE ItemInfo[MAX_ITEM_INFO];
};

struct PMSG_SELLRESULT
{
	PBMSG_HEAD h;	
	BYTE Result;	
	DWORD Money;	
};

struct PMSG_BUYREQUEST
{
	PBMSG_HEAD h;
	BYTE Pos;	// 3
};

struct PMSG_SELLREQUEST
{
	PBMSG_HEAD h;
	BYTE Pos;	
};

struct PMSG_USEITEM
{
	PBMSG_HEAD h;
	BYTE inventoryPos;
	BYTE invenrotyTarget;
	BYTE btItemUseType;
};

struct PMSG_CHAOSBOX_RESULT
{
	PBMSG_HEAD	    head;
	unsigned char	info[7];
};

struct PMSG_SENDMESSAGE
{
	PBMSG_HEAD h;
	BYTE Subcode;
	char Msg[80];
};

struct PWMSG_HEAD	// Packet - Word Type
{
public:

	void set( LPBYTE lpBuf, BYTE head, int size)
	{
		lpBuf[0] = 0xC2;
		lpBuf[1] = GET_NUMBERH(size);
		lpBuf[2] = GET_NUMBERL(size);
		lpBuf[3] = head;
	};

	void setE( LPBYTE lpBuf, BYTE head, int size)	// line : 49
	{
		lpBuf[0] = 0xC4;
		lpBuf[1] = GET_NUMBERH(size);
		lpBuf[2] = GET_NUMBERL(size);
		lpBuf[3] = head;
	};

	BYTE c;
	BYTE sizeH;
	BYTE sizeL;
	BYTE headcode;
};

struct PMSG_STATEBLOODCASTLE
{
	PBMSG_HEAD h;	// C1:9B
	BYTE btPlayState;		// 3
	WORD wRemainSec;	// 4
	WORD wMaxKillMonster;	// 6
	WORD wCurKillMonster;	// 8
	WORD wUserHaveWeapon;	// A
	BYTE btWeaponNum;	// C
};


struct PMSG_ATTACKRESULT
{
	PBMSG_HEAD h;	        // C1:DC
	BYTE NumberH;	        // 3
	BYTE NumberL;	        // 4
	BYTE DamageH;	        // 5
	BYTE DamageL;	        // 6
	BYTE DamageType;	    // 7
	BYTE btShieldDamageH;	// 8
	BYTE btShieldDamageL;	// 9
	float Life;             //A //hpbar
	float MaxLife;          //E //hpbar
	float AddLife;          //  //hpbar
};

#define OBJECT_POINTER(aIndex) ((aIndex * OBJECT_SIZE) + OBJECT_BASE)


struct taginterfaceState
{
	BYTE use : 2;
	BYTE state : 2;
	BYTE type : 4;
};

struct tagActionState
{
	DWORD Rest : 1;
	DWORD Attack : 1;
	DWORD Move : 1;
	DWORD Escape : 1;
	DWORD Emotion : 4;
	DWORD EmotionCount : 8;
};

struct VIEWPORT_STRUCT
{
	char state;
	short number;
	BYTE type;
	short index;
	int dis;
};

struct HITDAMAGE_STRUCT
{
	short number;
	int HitDamage;
	DWORD LastHitTime;
};

struct PMSG_SET_DEVILSQUARE
{
	PBMSG_HEAD h;	// C1:92
	BYTE Type;	// 3
};

struct PMSG_CLIENTTIME
{
	PBMSG_HEAD H;
	DWORD Time;
	WORD AttackSpeed;
	WORD MagicSpeed;
};

struct PMSG_TALKRESULT
{
	PBMSG_HEAD h;
	BYTE result;	// 3
	BYTE level1;	// 4
	BYTE level2;	// 5
	BYTE level3;	// 6
};

struct PMSG_TALKREQUEST
{
	PBMSG_HEAD h;
	BYTE NumberH;	// 3
	BYTE NumberL;	// 4
};

struct PMSG_SHOPITEMCOUNT
{
	PWMSG_HEAD h;
	BYTE Type;
	BYTE count;
};

struct PMSG_IDPASS {
  /*<thisrel this+0x0>*/ /*|0x3|*/	struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/	unsigned char subcode;
  /*<thisrel this+0x4>*/ /*|0xa|*/	char Id[10];
  /*<thisrel this+0xe>*/ /*|0xa|*/	char Pass[10];
  /*<thisrel this+0x18>*/ /*|0x4|*/	unsigned long TickCount;
  /*<thisrel this+0x1c>*/ /*|0x5|*/	unsigned char CliVersion[3];
  /*<thisrel this+0x21>*/ /*|0x10|*/unsigned char CliSerial[16];
};

struct PMSG_USE_STAT_FRUIT {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char result;
  /*<thisrel this+0x4>*/ /*|0x1|*/ WORD btStatValue;
  /*<thisrel this+0x5>*/ /*|0x1|*/ unsigned char btFruitType;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};

struct _GUILD_INFO_STRUCT
{
	int Number;
	char Name[9];
	BYTE Mark[32];
	BYTE Count;
	BYTE TotalCount;
	char Names[35][11];
	short Index[35];
	BYTE Use[35];
	char pServer[35];
	char TargetGuildName[9];
	short TargetIndex[35];
	_GUILD_INFO_STRUCT* lpTargetGuildNode;
	BYTE WarDeclareState;
	BYTE WarState;
	BYTE WarType;
	BYTE BattleGroundIndex;
	BYTE BattleTeamCode;
	BYTE PlayScore;
	int TotalScore;
	char Notice[60];
	_GUILD_INFO_STRUCT* back;
	_GUILD_INFO_STRUCT* next;
};


class CMagicInf
{
public:
	BYTE m_Level;
	BYTE m_Skill;
	int m_DamageMin;
	int m_DamageMax;
};

class CItem
{
public:
	DWORD m_Number;
	char m_serial; 
	short m_Type;
	short m_Level;
	BYTE m_Part;
	BYTE m_Class;
	BYTE m_TwoHand;
	BYTE m_AttackSpeed;
	BYTE m_WalkSpeed;
	WORD m_DamageMin;
	WORD m_DamageMax;
	BYTE m_SuccessfulBlocking;
	WORD m_Defense;
	WORD m_MagicDefense;
	BYTE m_Speed; 
	WORD m_DamageMinOrigin;
	WORD m_DefenseOrigin; 
	WORD m_Magic;
	float m_Durability; 
	WORD m_DurabilitySmall;
	float m_BaseDurability;
	BYTE m_SpecialNum; 
	BYTE m_Special[8]; 
	BYTE m_SpecialValue[8]; 
	WORD m_RequireStrength; 
	WORD m_RequireDexterity; 
	WORD m_RequireEnergy;
	WORD m_RequireLevel;
	BYTE m_RequireClass[4];
	BYTE m_Resistance[4];
	int m_Value; 
	DWORD m_SellMoney;
	DWORD m_BuyMoney;
	int m_OldSellMoney;
	int m_OldBuyMoney;
	BYTE m_Option1;
	BYTE m_Option2;
	BYTE m_Option3;
	BYTE m_NewOption;
	float m_DurabilityState[4];
	float m_CurrentDurabilityState;
	bool m_QuestItem;
	BYTE m_SetOption;

   public:

   bool IsItem();
   void Value();
   int ItemDefense();
   bool IsExtLifeAdd();
   bool IsExtManaAdd();
   bool IsExtDamageMinus();
   bool IsExtDefenseSuccessfull();
   bool IsExtDamageReflect();
   void PlusSpecial(int* Value, int Special);
   void PlusSpecialPercentEx(int* Value, int Source, int Special);

   __declspec() void Convert(int type, BYTE Option1, BYTE Option2, BYTE Option3,BYTE Attribute2, BYTE SetOption, BYTE DbVersion);

};

struct OBJECTSTRUCT
{
	int m_Index;
	int Connected;
	char LoginMsgSnd;
	char LoginMsgCount;
	char CloseCount;
	char CloseType;
	struct _PER_SOCKET_CONTEXT* PerSocketContext;
	UINT_PTR m_socket;
	char Ip_addr[16];
	int UserNumber;
	int DBNumber;
	BYTE Magumsa;
	DWORD AutoSaveTime;
	DWORD ConnectCheckTime;
	DWORD CheckTick;
	BYTE CheckSpeedHack;
	DWORD CheckTick2;
	BYTE CheckTickCount;
	int iPingTime;
	BYTE m_TimeCount;
	DWORD m_dwPKTimer;
	short CheckSumTableNum; 
	DWORD CheckSumTime;
	BYTE Type; 
	BYTE Live; 
	char characterPos; 
	char AccountID[11]; 
	char Name[11];
	char LastJoominNumber[14];
	BYTE Class; 
	BYTE DbClass;
	BYTE ChangeUP; 
	short Level; 
	int LevelUpPoints; 
	DWORD Experience; 
	DWORD NextExp; 
	int Money; 
	WORD Strength; 
	WORD Dexterity; 
	WORD Vitality; 
	WORD Energy; 
	float Life; 
	float MaxLife; 
	float FillLife; 
	float FillLifeMax; 
	float Mana; 
	float MaxMana;
	int BP; 
	int MaxBP; 
	int AddBP; 
	float VitalityToLife; 
	float EnergyToMana; 
	char m_PK_Count; 
	char m_PK_Level;
	int m_PK_Time; 
	short X;
	short Y; 
	BYTE Dir;
	BYTE MapNumber; 
	short AddLife; 
	short AddMana; 
	BYTE DamageMinus;
	BYTE DamageReflect; 
	short MonsterDieGetMoney; 
	BYTE MonsterDieGetLife; 
	BYTE MonsterDieGetMana; 
	BYTE StartX;
	BYTE StartY; 
	short m_OldX; 
	short m_OldY; 
	short TX;
	short TY; 
	short MTX; 
	short MTY; 
	int PathCount;
	int PathCur; 
	char PathStartEnd; 
	short PathOri[15]; 
	short PathX[15];
	short PathY[15]; 
	char PathDir[16]; 
	DWORD PathTime;
	char m_MoveGateNumber;
	DWORD Authority; 
	DWORD AuthorityCode;
	DWORD Penalty; 
	BYTE m_cAccountItemBlock;
	struct tagActionState m_ActState;
	BYTE m_ActionNumber; 
	DWORD m_State; 
	char m_StateSub; 
	BYTE m_Rest;
	char m_ViewState;
	BYTE m_ViewSkillState; 
	DWORD m_LastMoveTime;
	DWORD m_LastAttackTime;
	int m_DetectSpeedHackTime; 
	DWORD m_SumLastAttackTime; 
	DWORD m_DetectCount; 
	int m_DetectedHackKickCount;
	int m_SpeedHackPenalty; 
	BYTE m_AttackSpeedHackDetectedCount;
	DWORD m_PacketCheckTime; 
	BYTE m_ShopTime; 
	DWORD m_TotalAttackTime;
	int m_TotalAttackCount; 
	DWORD TeleportTime; 
	char Teleport;
	char KillerType;
	char DieRegen;
	char RegenOk;
	BYTE RegenMapNumber;
	BYTE RegenMapX; 
	BYTE RegenMapY;
	DWORD RegenTime; 
	DWORD MaxRegenTime; 
	short m_PosNum;
	DWORD LifeRefillTimer;
	DWORD CurActionTime;
	DWORD NextActionTime; 
	DWORD DelayActionTime; 
	char DelayLevel; 
	char m_PoisonBeattackCount; 
	char m_ColdBeattackCount;
	OBJECTSTRUCT* lpAttackObj; 
	short m_SkillNumber; 
	DWORD m_SkillTime; 
	char m_ManaFillCount; 
	char m_LifeFillCount;
	int SelfDefense[5]; 
	DWORD SelfDefenseTime[5];
	DWORD MySelfDefenseTime; 
	char m_Drink;
	int m_SkillDefense; 
	char m_SkillDefenseTime;
	int m_SkillAttack;
	char m_SkillAttackTime;
	int m_SkillAttack2;
	char m_SkillAttackTime2;
	int m_SkillAddLife; 
	int m_SkillAddLifeTime;
	int m_SkillHarden; 
	int m_SkillHardenTime; 
	int m_SkillMagumReduceDefense;
	int m_SkillMagumReduceDefenseTime;
	int PartyNumber;
	int PartyTargetUser;
	int GuildNumber;
	_GUILD_INFO_STRUCT* lpGuild; 
	char GuildName[11];
	int m_RecallMon;
	int m_Change; 
	short TargetNumber; 
	short TargetShopNumber; 
	short ShopNumber;
	short LastAttackerID;
	int m_AttackDamageMin;
	int m_AttackDamageMax; 
	int m_MagicDamageMin; 
	int m_MagicDamageMax; 
	int m_AttackDamageLeft;
	int m_AttackDamageRight;
	int m_AttackDamageMaxLeft; 
	int m_AttackDamageMinLeft;
	int m_AttackDamageMaxRight; 
	int m_AttackDamageMinRight;
	int m_AttackRating; 
	int m_AttackSpeed;
	int m_MagicSpeed; 
	int m_Defense; 
	int m_MagicDefense;
	int m_SuccessfulBlocking;
	short m_MoveSpeed;
	short m_MoveRange;
	short m_AttackRange;
	short m_AttackType; 
	short m_ViewRange; 
	short m_Attribute;
	short m_ItemRate;
	short m_MoneyRate;
	int m_CriticalDamage; 
	int m_ExcelentDamage;
	CMagicInf* m_lpMagicBack; 
	CMagicInf* Magic;
	char MagicCount; 
	BYTE UseMagicNumber;
	DWORD UseMagicTime; 
	char UseMagicCount;
	short OSAttackSerial; 
	BYTE SASCount; 
	DWORD SkillAttackTime;
	BYTE CharSet[11];
	BYTE m_Resistance[4];
	int FrustrumX[4];
	int FrustrumY[4];
	VIEWPORT_STRUCT VpPlayer[75]; 
	VIEWPORT_STRUCT VpPlayer2[75];
	int VPCount; 
	int VPCount2;
	HITDAMAGE_STRUCT sHD[40]; 
	short sHDCount; 
	taginterfaceState m_IfState;
	DWORD m_InterfaceTime;
	CItem* pInventory; 
	BYTE* pInventoryMap;
	char* pInventoryCount; 
	char pTransaction;
	CItem* Inventory1;
	BYTE* InventoryMap1;
	char InventoryCount1;
	CItem* Inventory2;
	BYTE* InventoryMap2;
	char InventoryCount2;
	CItem* Trade;
	LPBYTE TradeMap;
	int TradeMoney;
	BYTE TradeOk;
	CItem* pWarehouse; 
	BYTE* pWarehouseMap; 
	char WarehouseCount;
	short WarehousePW; 
	BYTE WarehouseLock; 
	BYTE WarehouseUnfailLock;
	int WarehouseMoney; 
	int WarehouseSave; 
	CItem* pChaosBox; 
	BYTE* pChaosBoxMap; 
	int ChaosMoney; 
	int ChaosSuccessRate; 
	int ChaosLock; 
	DWORD m_Option;
	int m_nEventScore; 
	int m_nEventExp;
	int m_nEventMoney; 
	BYTE m_bDevilSquareIndex;
	BYTE m_bDevilSquareAuth; 
	char m_cBloodCastleIndex;
	char m_cBloodCastleSubIndex;
	int m_iBloodCastleEXP; 
	BYTE IsInBattleGround; 
	BYTE HaveWeaponInHand;
	short EventChipCount; 
	int MutoNumber;
	int UseEventServer; 
	BYTE LoadWareHouseInfo;
	BYTE m_Quest[50];
	BYTE m_SendQuestInfo;
	int m_SkyBossMonSheildLinkIndex;
	int m_SkyBossMonSheild; 
	int m_SkyBossMonSheildTime;
	int m_MaxLifePower;
	int m_WizardSkillDefense;
	int m_WizardSkillDefenseTime;
	int m_PacketChecksumTime;
	int m_CheckLifeTime;
	BYTE m_MoveOtherServer; 
	char m_BossGoldDerconMapNumber; 
	BYTE m_InWebzen; 
	char m_LastTeleportTime; 
	BYTE m_ClientHackLogCount; 
	BYTE m_ReqWarehouseOpen; 
	int NotAttackAreaCount; 
};
typedef OBJECTSTRUCT* LPOBJ;
extern	OBJECTSTRUCT* gObj;

struct PLAYERSTRUCT
{
    int  m_PkCount;
	int  m_PostDelay;
	int  m_VendoDelay;
	int  m_ComproDelay;

	int  m_MoveDelay;

	int  m_TradeDelay;

	int m_UserOff;
	int m_CloseSetCheck;

	int m_PortionDelay;

	int m_DCTick;
	int m_DCCnt;

	int m_GM_Map;
	int m_GM_X;
	int m_GM_Y;
	int m_GM_GO;

	int Hits;
	int BlockAttack;

};
extern PLAYERSTRUCT epObj[OBJECT_MAX];

#endif