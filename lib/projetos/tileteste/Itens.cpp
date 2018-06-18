#include "Itens.h"



Itens::Itens()
{
	inBag = false;
	used = false;
	primeirox = 300;
	y = 730;
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

	addBag();
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

void Itens::desenhar()
{
	sprite.desenhar(x, y);
}

bool operator<(const Itens & a, const Itens & b)
{
	return a.id < b.id;
}
