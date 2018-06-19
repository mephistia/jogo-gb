#include "myTile.h"



myTile::myTile()
{
	monster = false;
	
}


myTile::~myTile()
{
}

void myTile::createTile(int &id, std::string& nome, std::string& caminho, int &isSolid)
{
	this->id = id;
	this->nome = nome;
	this->caminho = caminho;
	if (isSolid == 1) {
		this->isSolid = true;
	}
	else
		this->isSolid = false;

	sprite.setSpriteSheet(nome);

	if (id == 3)
		door = true;

	else if (id == 4)
		door = true;

	else
		door = false;
}

bool &myTile::getSolid()
{
	return isSolid;
}

bool & myTile::getPorta()
{
	return door;
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
	this->isSolid = s;
}

void myTile::setMonster()
{
	monster = true;
}

bool &myTile::isMonster()
{
	return monster;
}

