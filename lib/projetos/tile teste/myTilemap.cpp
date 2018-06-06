#include "myTilemap.h"



myTilemap::myTilemap()
{
	visited = false;
	first = false;
}


myTilemap::~myTilemap()
{
}

void myTilemap::ler(std::string arquivo)
{
	int id, idmapa;
	bool solido;
	std::string nome, caminho;


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

int myTilemap::getPos(int x, int y)
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

bool myTilemap::getFirst()
{
	return first;
}

void myTilemap::setFirst(bool f)
{
	first = f;
}
