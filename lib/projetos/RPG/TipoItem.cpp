#include "TipoItem.h"



TipoItem::TipoItem()
{
}


TipoItem::~TipoItem()
{
}

string TipoItem::getNome()
{
	return nome;
}

int TipoItem::getBonusHP()
{
	return bonusHP;
}

int TipoItem::getBonusDef()
{
	return bonusDef;
}

int TipoItem::getBonusAtk()
{
	return bonusAtk;
}

Sprite TipoItem::getSprite()
{
	return spr;
}

int TipoItem::getId()
{
	return id;
}

void TipoItem::setFile(string & file)
{
	this->file = file;
}

void TipoItem::setId(int & id)
{
	this->id = id;
}

void TipoItem::setNome(string &nome)
{
	this->nome = nome;
}

void TipoItem::setBonusHP(int &HP)
{
	bonusHP = HP;
}

void TipoItem::setBonusDef(int &def)
{
	bonusDef = def;
}

void TipoItem::setBonusAtk(int &atk)
{
	bonusAtk = atk;
}

