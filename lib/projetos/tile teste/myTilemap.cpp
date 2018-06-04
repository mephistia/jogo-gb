#include "myTilemap.h"



myTilemap::myTilemap()
{
}


myTilemap::~myTilemap()
{
}

void myTilemap::ler(std::string arquivo)
{
	int id;
	bool solido;
	std::string nome, caminho;

	ifstream tilemap(arquivo);
	if (tilemap) {
		tilemap >> totalTiles;
		tilemap >> tileSize;

		tiles = new myTile[totalTiles];

		for (int i = 0; i < totalTiles; i++) {
			tilemap >> id;
			tilemap >> nome;
			tilemap >> caminho;
			tilemap >> solido;

			tiles[i].createTile(id, nome, caminho, solido);

		}
	}
}
