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
	int getPos(int &x, int &y);
	myTile getTile(int x, int y);
	void desenhar();

	bool getVisited();
	void setVisited(bool v);

	void setTile(int x, int y, int id);

	Sprite getBauSprite();

	bool getMonstersDone();
	void setMonstersDone(bool d);

	void setNMonsters(int n);
	int getNMonsters();
	void inicializaMonstro(int i, int id, int def, int hp, std::string nome, std::string caminho);
	Monster& getMonster(int &i);

	void readMonster();

	void setChests();

	void setOpenChest(int x, int y);

	int getNumBaus();

	int getrx(int i);
	int getry(int i);

	bool isEnd();
	void setEnd(bool b);

private:
	myTile * tiles;
	int totalTiles, tileSize;
	int map[32][24]; // 32 colunas, 24 linhas
	int mapId, numMonsters; // total de monstros no mapa
	bool visited, first, monstersDone;
	int idporta[2];
	int aux, numBaus;
	Monster *m;

	// array dos monstros
	int *m_id, *m_def, *m_hp;
	std::string *m_nome;
	std::string *m_sheet;
	int nMonstros; // tipos
	int *rx, *ry;

	bool end;
};

