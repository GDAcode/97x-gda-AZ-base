#ifndef MAPAS_H
#define MAPAS_H

void ReadyNewMaps();

#define MAPS_LIMIT 25

#define MAP_BASE 0x6354C78 //0x7342000 
#define MAP_SIZE 0x4DB68
#define DIR_BASE 0x687DE60

typedef void(*pMapItemInit)(void);
extern pMapItemInit MapItemInit;
typedef void(*pLoadMapAttr)(const char*, int);
extern pLoadMapAttr LoadMapAttr;
typedef const char*(*pGetNewPath)(const char*, int);
extern pGetNewPath GetNewPath;

void LoadMapAttribute(unsigned int index, const char *name);
void LoadMaps();
void MapsFix();

#endif