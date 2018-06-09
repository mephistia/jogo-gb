#include "myTile.h"



myTile::myTile()
{
	monster = false;
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

bool myTile::getSolid()
{
	return isSolid;
}

int myTile::getId()
{
	return id;
}

Sprite myTile::getSprite()
{
	
	return sprite;
}

void myTile::setSolid(bool s)
{
	isSolid = s;
}

void myTile::setMonster(bool b)
{
	monster = b;
}

bool myTile::isMonster()
{
	return monster;
}

