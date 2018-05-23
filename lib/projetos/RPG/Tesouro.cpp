#include "Tesouro.h"



Tesouro::Tesouro()
{
	gold = 0;
	itemOuOuro = 0;
}


Tesouro::~Tesouro()
{
}

void Tesouro::setSprite(string sheet)
{
	sprite.setSpriteSheet(sheet);
}

void Tesouro::inicializar(string nome, int bonusHP, int bonusDef, int bonusAtk, int id)
{
	item.inicializar(nome, bonusAtk, bonusDef, bonusHP, id);
}

void Tesouro::setGold(int gold)
{
	this->gold = gold;
}

void Tesouro::setObj(ObjetoTileMap * obj)
{
	this->obj = obj;
	obj->setSprite(&sprite);
}

void Tesouro::setPos(float x, float y)
{
	obj->setPos(x, y);
}

int Tesouro::getGold()
{
	return gold;
}

int Tesouro::getIoO()
{
	return itemOuOuro;
}

void Tesouro::setIoO(int i)
{
	itemOuOuro = i;
}

Itens Tesouro::getItem()
{
	return item;
}

float Tesouro::getX()
{
	return obj->getXCentro();
}

float Tesouro::getY()
{
	return obj->getYCentro();
}

Sprite Tesouro::getItemSprite()
{
	return item.getSprite();
}

ObjetoTileMap Tesouro::getObj()
{
	return *obj;
}
