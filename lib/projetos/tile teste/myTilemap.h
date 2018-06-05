#pragma once
#include "myTile.h"
#include <iostream>
#include <fstream>

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

private:
	myTile * tiles;
	int totalTiles, tileSize;
	int map[32][24]; // 32 colunas, 24 linhas
	int mapId;
};

