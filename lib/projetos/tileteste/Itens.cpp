#include "Itens.h"



Itens::Itens()
{
	inBag = false;
	used = false;
	primeirox = 310;
	y = 735;
	id = NULL;
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

	x = primeirox + (id * 45);

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

int Itens::getId()
{
	return id;
}

int Itens::gethp()
{
	return bonusHP;
}

int Itens::getmaxhp()
{
	return bonusMaxHP;
}

int Itens::getdef()
{
	return bonusDef;
}

int Itens::getatk()
{
	return bonusAtk;
}

std::string Itens::getNome()
{
	return nome;
}

void Itens::setId(int id)
{
	this->id = id;
}

void Itens::desenhar()
{
	sprite.desenhar(x, y);
}

bool operator<(const Itens & a, const Itens & b)
{
	return a.id < b.id;
}

bool operator==(const Itens & a, const Itens & b)
{
	return a.id == b.id;
}
