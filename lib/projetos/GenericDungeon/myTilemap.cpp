#include "myTilemap.h"



myTilemap::myTilemap()
{
	visited = false;
	first = false;
	monstersDone = false;
	numMonsters = 0;
	aux = 0;
	end = false;
}


myTilemap::~myTilemap()
{

}

void myTilemap::ler(std::string arquivo)
{
	int id, idmapa;
	int solido;
	std::string nome;
	std::string caminho;


	ifstream tilemap(arquivo);
	if (tilemap) {
		tilemap >> totalTiles;
		tilemap >> tileSize;

		tiles = new myTile[totalTiles];

		for (int i = 0; i < totalTiles; i++) {
			tilemap >> id >> nome >> caminho >> solido;

			tiles[i].createTile(id, nome, caminho, solido);
		
		}

		tilemap >> idmapa;
		mapId = idmapa;

		for (int l = 0; l < 24; l++) {
			for (int c = 0; c < 32; c++) {
				tilemap >> map[c][l];
			}
		}
			
		tilemap.close();
	}
	else {
		exit(0);
	}
}

int myTilemap::getMapId()
{
	return mapId;
}

int myTilemap::getPos(int &x, int &y)
{
	return map[x][y];
}


myTile myTilemap::getTile(int x, int y)
{
	return tiles[getPos(x, y)];
}

void myTilemap::desenhar()
{
	for (int c = 0; c < 32; c++)
		for (int l = 0; l < 24; l++) {
			getTile(c, l).getSprite().desenhar(c * 32, l * 32);
		}
}

bool myTilemap::getVisited()
{
	return visited;
}

void myTilemap::setVisited(bool v)
{
	visited = v;
}



void myTilemap::setTile(int x, int y, int id)
{
	map[x][y] = id;
}

Sprite myTilemap::getBauSprite()
{
	// retorna sprite do bau fechado
	return tiles[8].getSprite();
}

bool myTilemap::getMonstersDone()
{
	return monstersDone;
}

void myTilemap::setMonstersDone(bool d)
{
	monstersDone = d;
}

void myTilemap::setNMonsters(int n)
{
	
		numMonsters = n;

		m = new Monster[n];

		for (int i = 0; i < numMonsters; i++) {
			int random = uniRandEntre(0, nMonstros - 1);
			inicializaMonstro(i, m_id[random], m_def[random], m_hp[random], m_nome[random], m_sheet[random]);
		}

		monstersDone = true;

}

int myTilemap::getNMonsters()
{
	return numMonsters;
}

void myTilemap::inicializaMonstro(int i, int id, int def, int hp, std::string nome, std::string caminho)
{
	m[i].mInicializar(id, nome, def, hp, caminho);

	int rx, ry;
	do {
		rx = uniRandEntre(1, 29);
		ry = uniRandEntre(1, 21);
	} while (getTile(rx, ry).getId() != 1);

	getMonster(i).setPos(rx, ry);
}

Monster& myTilemap::getMonster(int &i)
{
	return m[i];
}

void myTilemap::readMonster()
{
	int id, def, hp;
	std::string caminho, nome;
	ifstream monstros;
	monstros.open("bin/assets/sprites/monstersfix.txt");

	if (monstros) {
		monstros >> nMonstros;

		m_id = new int[nMonstros];
		m_def = new int[nMonstros];
		m_hp = new int[nMonstros];
		m_sheet = new std::string[nMonstros];
		m_nome = new std::string[nMonstros];


		for (int i = 0; i < nMonstros; i++) {
			monstros >> id >> nome >> def >> hp >> caminho;
			m_id[i] = id;
			m_nome[i] = nome;
			m_def[i] = def;
			m_hp[i] = hp;
			m_sheet[i] = caminho;
		}
	}
}

void myTilemap::setChests()
{
	numBaus = uniRandEntre(2, 2);
	rx = new int[numBaus];
	ry = new int[numBaus];

	for (int i = 0; i < numBaus; i++) {

		do {
			rx[i] = uniRandEntre(1, 29);
			ry[i] = uniRandEntre(1, 21);
		} while (getTile(rx[i], ry[i]).getId() != 1);

		setTile(rx[i], ry[i], 8);
	}
}

void myTilemap::setOpenChest(int x, int y)
{
	setTile(x, y, 7);
}

int myTilemap::getNumBaus()
{
	return numBaus;
}

int myTilemap::getrx(int i)
{
	return rx[i];
}

int myTilemap::getry(int i)
{
	return ry[i];
}

bool myTilemap::isEnd()
{
	return end;
}

void myTilemap::setEnd(bool b)
{
	this->end = b;
}

