#include "myTile.h"



myTile::myTile()
{
}


myTile::~myTile()
{
}

void myTile::createTile(int id, std::string nome, std::string caminho, bool isSolid)
{
	this->id = id;
	this->nome = nome;
	this->caminho = caminho;
	this->isSolid = isSolid;
	sprite.setSpriteSheet(nome);
}
