#include "Itens.h"



Itens::Itens()
{
	inBag = false;
	used = false;
	primeirox = 200;
	y = 650;
}


Itens::~Itens()
{
}

void Itens::use()
{
	used = true;
}


// id do item, não do tipo de item.
void Itens::create(int id, std::string nome, std::string caminho, int bonusHP, int bonusMaxHP, int bonusDef, int bonusAtk)
{
	this->id = id;
	this->nome = nome;
	sprite.setSpriteSheet(nome);
	this->bonusAtk = bonusAtk;
	this->bonusDef = bonusDef;
	this->bonusHP = bonusHP;
	this->bonusMaxHP = bonusMaxHP;
	this->caminho = caminho;

	x = primeirox + (id * 42);
}

bool Itens::isInBag()
{
	return inBag;
}

void Itens::addBag()
{
	inBag = true;
}

Sprite Itens::getSprite()
{
	return sprite;
}

void Itens::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Itens::getX()
{
	return x;
}

int Itens::getY()
{
	return y;
}


