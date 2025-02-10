#ifndef ITEMDROP_H
#define ITEMDROP_H

#define MAX_DROP_NUMBER 1000

void MonsterDropCall(BYTE * b_MonsterDataAddr,BYTE * a_gObjAddr);
void ReadyDropSystem();


struct S_DropSystem
{
	unsigned char Type;
	unsigned int  Index;
	unsigned char Level;
	unsigned char Opt;
	unsigned int  Luck;
	unsigned char Skill;
	unsigned char Dur;
	unsigned int  Rate;
	unsigned int  Minlvl;
	unsigned int  Maxlvl;
	unsigned char Exc;
};

class C_DropSystem
{
public:
	S_DropSystem t_struct[MAX_DROP_NUMBER];
	unsigned short t_num;
	void t_LoadSystem();
	int MygEventMonsterItemDrop(BYTE * b_MonsterDataAddr,BYTE * a_gObjAddr);
private:
	S_DropSystem		Item[120];
	unsigned char		ItemCount;
};
extern C_DropSystem Drop;


#endif