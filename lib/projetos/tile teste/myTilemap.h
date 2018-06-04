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

private:
	myTile * tiles;
	int totalTiles, tileSize;
};

