#pragma once
#include "myTile.h"
#include <iostream>
#include <fstream>
#include "Monster.h"

class myTilemap
{
public:
	myTilemap();
	~myTilemap();

	void ler(std::string arquivo);
	int getMapId();
	int getPos(int x, int y);
	myTile getTile(int x, int y);
	void desenhar();

	bool getVisited();
	void setVisited(bool v);
	
	bool getFirst();
	void setFirst(bool f);

	void setTile(int x, int y, int id);

	Sprite getBauSprite();

	bool getMonstersDone();
	void setMonstersDone(bool d);

	void setNMonsters(int n);
	int getNMonsters();
	Monster getMonster(int *posArray);

private:
	myTile * tiles;
	int totalTiles, tileSize;
	int map[32][24]; // 32 colunas, 24 linhas
	int mapId, numMonsters;
	bool visited, first, monstersDone;
	Monster *m;
};

