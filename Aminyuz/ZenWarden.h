#pragma once

struct ZENWARDEN
{
	int ZenWardenSwitch;
	int ZenWardenID;
};
extern ZENWARDEN pZenWarden;

void LoadZenWarden();
void ZenWardenClick(LPOBJ gObj, LPOBJ gObjNPC, int aIndex);
void ZenWarden(LPOBJ gObj, LPOBJ NpcObj, int aIndex);